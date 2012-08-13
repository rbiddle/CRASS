#ifndef DICEROLLER_H
#define DICEROLLER_H

#include "string"

class DiceRoller
{
public:
    DiceRoller();
    std::string getDieRoll();
    int rollDice ( int numDice, int numSides );
    int parseDice ( std::string strFormula );

private:
    std::string dieRoll;
    void setDieRoll( std::string dieString );
    int rollDie( int numSides );
    std::string intToString(int inInt);

};

#endif // DICEROLLER_H
