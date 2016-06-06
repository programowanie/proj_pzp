#include "Team.h"
#include <time.h>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    srand(time(NULL));

    Team teams[32];

    //przepisywanie z pliku do zmiennych i wyswietlanie
    ifstream file("teams.csv");
    string temp1, temp2, temp3;

    for(int i = 0; i < 32; i++)
    {
        getline(file, temp1, ';');
        getline(file, temp2, ';');
        getline(file, temp3, '\n');

        teams[i].init(temp1, temp2, temp3);
    }
    file.close();

    //losowanie do grup
    Team groups[8][4];
    Team::draw(groups, teams);

    //mecze grupowe
    Team::groupPhase(groups);

    //podsumowanie fazy grupowej
    Team sortedGroups[8][4];
    Team quarterFinals[8];
    Team semiFinals[4];
    Team final[2];

    //faza finalowa
    Team::GroupPhaseSummary(groups, quarterFinals, sortedGroups);
    Team::pointsTable(sortedGroups);
    Team::quarterFinals(quarterFinals, semiFinals);
    Team::semiFinals(semiFinals, final);
    Team::final(final);
}