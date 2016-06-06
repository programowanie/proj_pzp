#pragma once
#include <string>
using namespace std;

class Team
{

    string _name;
    int _points;
    int _goals;
    int _offence;
    int _deffence;
    int _experience;

public:

    Team();

    string name() { return _name; }
    int offence() { return _offence; }
    int deffence() { return _deffence; }
    int points() { return _points; }
    int goals() { return _goals; }

    void init(string, string, string);
    static void draw(Team ( &groups)[8][4], Team[] );
    void match (Team &);
    Team match2(Team);
    bool score(Team);
    void sumGoals(Team &, int &, int &);
    void sumPoints(Team &, int, int);
    void description(Team, int, int);
    static void groupPhase(Team (&)[8][4] );
    static void GroupPhaseSummary(Team (&)[8][4], Team (&)[8], Team (&)[8][4]);
    static void pointsTable(Team (&) [8][4]);
    static void quarterFinals(Team[], Team (&)[4]);
    static void semiFinals(Team[], Team(&)[2]);
    static void final(Team[]);
};