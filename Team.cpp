#include "Team.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Team::Team()
{
   _points = 0;
   _goals = 0;
   _experience = 0;
}

void Team::init(string temp1, string temp2, string temp3)
{
    _name = temp1;
    _offence = atoi(temp2.c_str());
    _deffence = atoi(temp3.c_str());
}

void Team::draw(Team (&groups)[8][4], Team teams[32])
{
    int numbersTaken[32];
    int number;

    for(int i = 0; i < 32; i++)
    {
        numbersTaken[i] = 0;
    }


    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            do
            {
                number = rand()%32;
            }while(numbersTaken[number]);
            numbersTaken[number] = 1;

            groups[i][j] = teams[number];
        }
    }
}

bool Team::score(Team second)
{
    int luck = rand()%3-1;
    float chance = this->_offence*luck - 0.8*second._deffence;

    return ( chance > 0 ? true : false );
}


void Team::sumGoals(Team & second, int & firstGoals, int & secondGoals)
{

    for(int i = 0; i < 6; i++)
    {
        if (this->score(second) == true)
        {
            this->_goals++;
            firstGoals++;
        }
    }

    for(int i = 0; i < 6; i++)
    {
        if (second.score(*this) == true)
        {
            second._goals++;
            secondGoals++;
        }
    }
}

void Team::sumPoints(Team & second, int firstGoals, int secondGoals)
{
    if (firstGoals > secondGoals)
    this->_points+=3;

    else if (firstGoals < secondGoals)
    second._points+=3;

    else
    {
        this->_points++;
        second._points++;
    }
}

void Team::description(Team second, int firstGoals, int secondGoals)
{
    cout << this->_name << " : " << second._name << endl;
    cout << firstGoals << " : " << secondGoals << endl << endl;
}

void Team::match(Team & second)
{
    int firstGoals = 0, secondGoals = 0;

    this->sumGoals(second, firstGoals, secondGoals);
    this->sumPoints(second, firstGoals, secondGoals);
}

Team Team::match2(Team second)
{
    int firstGoals = 0, secondGoals = 0;
    this->score(second);
    second.score(*this);

    if(firstGoals == secondGoals)
    {
        do
        {
            for(int i = 0; i < 5; i++)
            {
                if (this->score(second) == true)
                firstGoals++;
            }

            for(int i = 0; i < 5; i++)
            {
                if (second.score(*this) == true)
                secondGoals++;
            }
        } while(firstGoals == secondGoals);

    }
    this->description(second, firstGoals, secondGoals);
    return (firstGoals > secondGoals ? (*this) : second );
}

void Team::groupPhase(Team (&groups)[8][4])
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 3; k > j; k--)
            {
                groups[i][j].match(groups[i][k]);
            }
        }
    }
}

void Team::GroupPhaseSummary(Team (&groups)[8][4], Team (&quarterFinals)[8], Team (&sortedGroups)[8][4])
{
    int max, goals, first, second, third, fourth;

    for(int i = 0; i < 8; i++)
    {
        max = groups[i][0]._points;
        goals = groups[i][0]._goals;
        first = 0, second = 0, third = 0, fourth = 0;

        for(int j = 1; j < 4; j++)
        {
            if( groups[i][j]._points > max)
            {
                second = first;
                max = groups[i][j]._points;
                goals = groups[i][j]._goals;
                first = j;
            }

            else if (groups[i][j]._points == max)
            {
                if(groups[i][j]._goals > goals)
                {
                    second = first;
                    max = groups[i][j]._points;
                    goals = groups[i][j]._goals;
                    first = j;
                }
                else
                    second = j;
            }

            else if(groups[i][j]._points < max && groups[i][j]._points > second)
                second = j;
        }

        quarterFinals[i] = groups[i][first];
        sortedGroups[i][0] = groups[i][first];
        sortedGroups[i][1] = groups[i][second];

        while(third == first || third == second)
            third++;
        while(fourth == first || fourth == second || fourth == third)
            fourth++;

        if(groups[i][third]._points > groups[i][fourth]._points)
        {
            sortedGroups[i][2] = groups[i][third];
            sortedGroups[i][3] = groups[i][fourth];
        }
        else
        {
            sortedGroups[i][2] = groups[i][fourth];
            sortedGroups[i][3] = groups[i][third];
        }
        if(sortedGroups[i][1]._points < sortedGroups[i][2]._points)
        {
            Team tmp;
            tmp = sortedGroups[i][2];
            sortedGroups[i][2] = sortedGroups[i][1];
            sortedGroups[i][1] = tmp;
        }
    }
}

void Team::pointsTable(Team (&sortedGroups)[8][4])
{
    for(int i = 0; i < 8; i++)
    {
        cout << "* GROUP " << i+1 << " *"<< endl;
        for(int j = 0; j < 4; j++)
        {
            cout << sortedGroups[i][j]._name << " " << sortedGroups[i][j]._points << " " << endl;
        }
        cout << endl;
    }
    cout << endl;
}

void Team::quarterFinals(Team quarterFinals[8], Team (& semiFinals)[4])
{
    int numsTaken[8];
    int one, two;

    for(int i = 0; i < 8; i++)
    numsTaken[i] = 0;

    cout << "* QUARTERFINALS *" << endl;

    for(int j = 0; j < 4; j++)
    {
            do
            {
                one = rand()%8;
            }while(numsTaken[one]);
            numsTaken[one] = 1;

            do
            {
                two = rand()%8;
            }while(numsTaken[two]);
            numsTaken[two] = 1;

            semiFinals[j] = quarterFinals[one].match2(quarterFinals[two]);
    }
}

void Team::semiFinals(Team semiFinals[4], Team (& final)[2])
{
    int numsTaken[4] = {0,0,0,0};
    int one, two;

    cout << "* SEMIFINALS *" << endl;

    for(int j = 0; j < 2; j++)
    {
            do
            {
                one = rand()%4;
            }while( numsTaken[one] );
            numsTaken[one] = 1;

            do
            {
                two = rand()%4;
            }while( numsTaken[two] );
            numsTaken[two] = 1;

            final[j] = semiFinals[one].match2(semiFinals[two]);
    }

}

void Team::final(Team final[2])
{
    cout << "* FINAL *" << endl;
    cout << "The winner is: " << (final[0].match2(final[1]))._name << endl;
}