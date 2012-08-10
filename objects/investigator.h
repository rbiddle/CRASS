#ifndef INVESTIGATOR_H
#define INVESTIGATOR_H

#include "string"

class Investigator
{
public:
    Investigator();
    std::string getDieRoll();
    int rollDice ( int numDice, int numSides );
    std::string getRollResult();

    std::string getCharName();
    void setCharName( std::string inName );
    std::string getPlayerName();
    void setPlayerName( std::string inName );
    std::string getCharDesc();
    void setCharDesc( std::string inDesc );

private:
    std::string dieRoll;
    void setDieRoll( std::string dieString );
    int rollDie( int numSides );
    std::string intToString(int inInt);

    std::string data_charname;
    std::string data_playername;
    std::string data_desc;

};

#endif // INVESTIGATOR_H
