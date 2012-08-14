#include "investigator.h"
#include "iostream"
#include "sstream"

#include "objects/diceroller.h"

Investigator::Investigator()
{
    dice = DiceRoller();
}

std::string Investigator::getCharName()
{
    return this->data_charname;
}

void Investigator::setCharName( std::string inName )
{
    this->data_charname = inName;
}

std::string Investigator::getPlayerName()
{
    return this->data_playername;
}

void Investigator::setPlayerName( std::string inName )
{
    this->data_playername = inName;
}

std::string Investigator::getCharDesc()
{
    return this->data_desc;
}

void Investigator::setCharDesc( std::string inDesc )
{
    this->data_desc = inDesc;
}

void Investigator::saveCharacter(std::string format, std::string location)
{
    //TODO: Save Investigator file in <<format>> at <<location>>
}
