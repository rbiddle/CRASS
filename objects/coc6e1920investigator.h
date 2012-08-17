#ifndef COC6E1920INVESTIGATOR_H
#define COC6E1920INVESTIGATOR_H

#include "cocinvestigator.h"

class CoC6e1920Investigator : public CoCInvestigator
{
public:
    CoC6e1920Investigator();

    void setIncome( int iVal );
    void setIncome();
    void setCash( double dVal );
    void setSavings( double dVal );

    void createInvestigator();
    void createInvestigator(std::string sCharName, std::string sPlayerName);
    void createInvestigator(std::string sCharName, std::string sPlayerName, std::string sDesc);
    void createInvestigator(std::string sCharName, std::string sPlayerName, int iSTR, int iCON, int iSIZ, int iDEX, int iAPP, int iINT, int iPOW, int iEDU, int iIncome);

    void saveInvestigator(std::string sFileName);
    void loadInvestigator(std::string sFileName);

private:
    void setDefaultSkills();

};

#endif // COC6E1920INVESTIGATOR_H
