#ifndef INVESTIGATOR_H
#define INVESTIGATOR_H

#include "string"
#include "objects/diceroller.h"

class Investigator
{
public:
    Investigator();

    std::string getCharName();
    void setCharName( std::string inName );
    std::string getPlayerName();
    void setPlayerName( std::string inName );
    std::string getCharDesc();
    void setCharDesc( std::string inDesc );

    virtual void saveInvestigator(std::string sFileName) = 0;
    virtual void loadInvestigator(std::string sFileName) = 0;

protected:
    std::string data_charname;
    std::string data_playername;
    std::string data_desc;
    DiceRoller dice;

};

#endif // INVESTIGATOR_H
