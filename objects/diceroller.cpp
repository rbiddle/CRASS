#include "diceroller.h"
#include "stdlib.h"
#include "ctime"
#include "sstream"
#include "iostream"

DiceRoller::DiceRoller()
{
    srand(time(NULL));
}

void DiceRoller::setDieRoll( std::string dieString )
{
    this->dieRoll = dieString;
}

std::string DiceRoller::getDieRoll()
{
    return this->dieRoll;
}

int DiceRoller::rollDice(int numDice, int numSides)
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
    }
    this->setDieRoll(results);
    return output;
}

int DiceRoller::parseDice(std::string strFormula)
{
    //TODO: Implement
    std::cout << "Function parseDice in DiceRoller not implemented.  Formula: " << strFormula << std::endl;
    return 0;
}

int DiceRoller::rollDie(int numSides)
{
    int output, sides = 0;

    //default roll is a 6-sided die
    sides = ( numSides <= 0 ) ? 6 : numSides;
    output = ( rand() % sides ) + 1;
    return output;
}

std::string DiceRoller::intToString(int inInt)
{
    std::string output;
    std::stringstream stream;

    stream << inInt;
    output = stream.str();

    return output;
}
