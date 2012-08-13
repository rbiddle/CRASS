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
};

#endif // COC1920INVESTIGATOR_H
