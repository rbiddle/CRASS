#include "coc1920investigator.h"

#include "iostream"

CoC1920Investigator::CoC1920Investigator()
{
}

void CoC1920Investigator::OutputInvestigator()
{
    std::cout << "Outputting Investigator:" << std::endl;
    std::cout << "STR: " << this->getSTR() << std::endl;
    std::cout << "SIZ: " << this->getSIZ() << std::endl;
    std::cout << "CON: " << this->getCON() << std::endl;
    std::cout << "DEX: " << this->getDEX() << std::endl;
    std::cout << "APP: " << this->getAPP() << std::endl;
    std::cout << "POW: " << this->getPOW() << std::endl;
    std::cout << "INT: " << this->getINT() << std::endl;
    std::cout << "EDU: " << this->getEDU() << std::endl;
    std::cout << "Income: $" << this->getIncome() << std::endl;
    std::cout << std::endl << "Derived Stats:";
    std::cout << "Idea: " << this->getIDEA() << std::endl;
    std::cout << "Luck: " << this->getLUCK() << std::endl;
    std::cout << "Know: " << this->getKNOW() << std::endl;
    std::cout << "Sanity: " << this->getSAN() << std::endl;
    std::cout << "HP: " << this->getHP() << std::endl;
    std::cout << "Dmg Bonus:" << this->getDmgBonus() << std::endl;
    std::cout << "Cash: $" << this->getCash() << std::endl;
    std::cout << "Savings: $" << this->getSavings() << std::endl;
    std::cout << "MP: " << this->getMP() << std::endl;
}

void CoC1920Investigator::setIncome(int iVal)
{
    double dCash = iVal;
    double dSavings = iVal * 5;

    this->data_income = iVal;
    this->setCash(dCash);
    this->setSavings(dSavings);
}

void CoC1920Investigator::setIncome()
{
    int randomIncome = dice.rollDice(1,10);
    switch(randomIncome) {
        case 1:
            this->setIncome(1500);
            break;
        case 2:
            this->setIncome(2500);
            break;
        case 3:
        case 4:
            this->setIncome(3500);
            break;
        case 5:
            this->setIncome(4500);
            break;
        case 6:
            this->setIncome(5500);
            break;
        case 7:
            this->setIncome(6500);
            break;
        case 8:
            this->setIncome(7500);
            break;
        case 9:
            this->setIncome(10000);
            break;
        case 10:
            this->setIncome(20000);
            break;
    }
}

void CoC1920Investigator::setCash(double dVal)
{
    this->data_cash = dVal;
}

void CoC1920Investigator::setSavings(double dVal)
{
    this->data_savings = dVal;
}
