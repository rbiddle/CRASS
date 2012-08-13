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
<<<<<<< HEAD
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
=======
    //TODO: Save Investigator file in <<format>> at <<location>>
>>>>>>> Updt for Core/1920 CoC Chargen & Dice Breakout
}
