#include "investigator.h"
#include "stdlib.h"
#include "iostream"
#include "sstream"
#include "ctime"

Investigator::Investigator()
{
    srand(time(NULL));
}

void Investigator::setDieRoll( std::string dieString )
{
    this->dieRoll = dieString;
}

std::string Investigator::getDieRoll()
{
    return this->dieRoll;
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

int Investigator::rollDice(int numDice, int numSides)
{
    int output = 0;
    int roll = 0;
    std::string results = "Roll: ";

    for (int x=1; x <= numDice; x++) {
        roll = this->rollDie(numSides);
        output += roll;
        if(x == numDice)
            results = results + intToString(roll);
        else
            results = results + intToString(roll) + " + ";
        std::cout << "Roll #" << x << ": " << roll << " :: " << results << std::endl;
    }
    this->setDieRoll(results);
    return output;
}

int Investigator::rollDie(int numSides)
{
    int output, sides = 0;

    //default roll is a 6-sided die
    sides = ( numSides <= 0 ) ? 6 : numSides;
    output = ( rand() % sides ) + 1;
    return output;
}

std::string Investigator::intToString(int inInt)
{
    std::string output;
    std::stringstream stream;

    stream << inInt;
    output = stream.str();

    return output;
}
