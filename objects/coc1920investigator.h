#ifndef COC1920INVESTIGATOR_H
#define COC1920INVESTIGATOR_H

#include "cocinvestigator.h"

class CoC1920Investigator : public CoCInvestigator
{
public:
    CoC1920Investigator();
    void OutputInvestigator();
    void setIncome( int iVal );
    void setIncome();
    void setCash( double dVal );
    void setSavings( double dVal );
    void create1920Investigator();
    void create1920Investigator(std::string sCharName, std::string sPlayerName, int iSTR, int iCON, int iSIZ, int iDEX, int iAPP, int iINT, int iPOW, int iEDU, int iIncome);

private:
    void setDefaultSkills();

};

#endif // COC1920INVESTIGATOR_H
