#ifndef COCGASLIGHTINVESTIGATOR_H
#define COCGASLIGHTINVESTIGATOR_H

#include "string"

#include "objects/cocinvestigator.h"

class CoCGaslightInvestigator : public CoCInvestigator
{
public:
    CoCGaslightInvestigator();

    void setIncome( int iVal );
    void setIncome();
    void setCash( double dVal );
    void setSavings( double dVal );

    void saveInvestigator(std::string sFileName);
    void loadInvestigator(std::string sFileName);

private:
    std::string data_socialclass;
    std::string data_addictions;
    std::string data_staff;
    std::string data_clubs;
};

#endif // COCGASLIGHTINVESTIGATOR_H
