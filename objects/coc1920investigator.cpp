#include "coc1920investigator.h"

#include "iostream"
#include "string"
#include "vector"

CoC1920Investigator::CoC1920Investigator()
{
}

void CoC1920Investigator::OutputInvestigator()
{
//    std::vector<skillStruct>::iterator skill;

    std::cout << "Outputting Investigator:" << std::endl;
    std::cout << "Character Name: " << this->getCharName() << std::endl;
    std::cout << "Player Name: " << this->getPlayerName() << std::endl;
    std::cout << "Desc.: " << this->getCharDesc() << std::endl;
    std::cout << "Rolled Stats:" << std::endl;
    std::cout << "STR: " << this->getSTR() << std::endl;
    std::cout << "SIZ: " << this->getSIZ() << std::endl;
    std::cout << "CON: " << this->getCON() << std::endl;
    std::cout << "DEX: " << this->getDEX() << std::endl;
    std::cout << "APP: " << this->getAPP() << std::endl;
    std::cout << "POW: " << this->getPOW() << std::endl;
    std::cout << "INT: " << this->getINT() << std::endl;
    std::cout << "EDU: " << this->getEDU() << std::endl;
    std::cout << "Income: $" << this->getIncome() << std::endl;
    std::cout << std::endl << "Derived Stats:" << std::endl;
    std::cout << "Idea: " << this->getIDEA() << std::endl;
    std::cout << "Luck: " << this->getLUCK() << std::endl;
    std::cout << "Know: " << this->getKNOW() << std::endl;
    std::cout << "Sanity: " << this->getSAN() << std::endl;
    std::cout << "HP: " << this->getHP() << std::endl;
    std::cout << "Dmg Bonus:" << this->getDmgBonus() << std::endl;
    std::cout << "Cash: $" << this->getCash() << std::endl;
    std::cout << "Savings: $" << this->getSavings() << std::endl;
    std::cout << "MP: " << this->getMP() << std::endl;
    std::cout << std::endl << "Skills:" << std::endl;
    for ( unsigned int i=0; i < this->skills.size(); i++ )
        std::cout << this->skills[i].desc << " ( " << this->skills[i].baseVal << " + "
                                          << this->skills[i].incrOcpn << " Occupation + "
                                          << this->skills[i].incrPrsn << " Personal Interest )" <<std::endl;

}

void CoC1920Investigator::setIncome(int iVal)
{
    double dSavings = iVal * 5;
    double dCash = iVal / 2;  //technically savings / 10, but ((income * 5)/10) = income/2

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

void CoC1920Investigator::setDefaultSkills()
{
    this->skills.push_back( this->makeSkill("dodge","Dodge",this->getDEX()*2) );
    this->skills.push_back( this->makeSkill("ownlanguage","Own Language",this->getEDU()*5) );

    this->skills.push_back( this->makeSkill("accounting","Accounting",10) );
    this->skills.push_back( this->makeSkill("anthropology","Anthropology",1) );
    this->skills.push_back( this->makeSkill("archaeology","Archaeology",1) );
    this->skills.push_back( this->makeSkill("art","Art",5) );
    this->skills.push_back( this->makeSkill("astronomy","Astronomy",1) );
    this->skills.push_back( this->makeSkill("bargain","Bargain",5) );
    this->skills.push_back( this->makeSkill("biology","Biology",1) );
    this->skills.push_back( this->makeSkill("chemistry","Chemistry",1) );
    this->skills.push_back( this->makeSkill("climb","Climb",40) );
    this->skills.push_back( this->makeSkill("conceal","Conceal",15) );
    this->skills.push_back( this->makeSkill("craft","Craft",5) );
    this->skills.push_back( this->makeSkill("creditrating","Credit Rating",15) );
    this->skills.push_back( this->makeSkill("cthulhumythos","Cthulhu Mythos",0) );
    this->skills.push_back( this->makeSkill("disguise","Disguise",1) );
    this->skills.push_back( this->makeSkill("driveauto","Drive Auto",20) );
    this->skills.push_back( this->makeSkill("electrrepair","Electronic Repair",10) );
    this->skills.push_back( this->makeSkill("fasttalk","Fast Talk",5) );
    this->skills.push_back( this->makeSkill("firstaid","First Aid",30) );
    this->skills.push_back( this->makeSkill("geology","Geology",1) );
    this->skills.push_back( this->makeSkill("hide","Hide",10) );
    this->skills.push_back( this->makeSkill("history","History",20) );
    this->skills.push_back( this->makeSkill("jump","Jump",25) );
    this->skills.push_back( this->makeSkill("law","Law",5) );
    this->skills.push_back( this->makeSkill("libraryuse","Library Use",25) );
    this->skills.push_back( this->makeSkill("listen","Listen",25) );
    this->skills.push_back( this->makeSkill("locksmith","Locksmith",1) );
    this->skills.push_back( this->makeSkill("martialarts","Martial Arts",1) );
    this->skills.push_back( this->makeSkill("mechrepair","Mechanical Repair",20) );
    this->skills.push_back( this->makeSkill("medicine","Medicine",5) );
    this->skills.push_back( this->makeSkill("naturalhistory","Natural History",10) );
    this->skills.push_back( this->makeSkill("navigate","Navigate",10) );
    this->skills.push_back( this->makeSkill("occult","Occult",5) );
    this->skills.push_back( this->makeSkill("oprhvymch","Operate Heavy Machinary",1) );
    this->skills.push_back( this->makeSkill("otherlanguage1","Other Language #1",1) );
    this->skills.push_back( this->makeSkill("otherlanguage2","Other Language #2",1) );
    this->skills.push_back( this->makeSkill("otherlanguage3","Other Language #3",1) );
    this->skills.push_back( this->makeSkill("persuade","Persuade",15) );
    this->skills.push_back( this->makeSkill("pharmacy","Pharmacy",1) );
    this->skills.push_back( this->makeSkill("photography","Photography",10) );
    this->skills.push_back( this->makeSkill("physics","Physics",1) );
    this->skills.push_back( this->makeSkill("pilot","Pilot",1) );
    this->skills.push_back( this->makeSkill("psychoanalysis","Psychoanalysis",1) );
    this->skills.push_back( this->makeSkill("psychology","Psychology",5) );
    this->skills.push_back( this->makeSkill("ride","Ride",5) );
    this->skills.push_back( this->makeSkill("sneak","Sneak",10) );
    this->skills.push_back( this->makeSkill("spothidden","Spot Hidden",25) );
    this->skills.push_back( this->makeSkill("swim","Swim",25) );
    this->skills.push_back( this->makeSkill("throw","Throw",25) );
    this->skills.push_back( this->makeSkill("track","Track",10) );
    this->skills.push_back( this->makeSkill("handgun","Handgun",20) );
    this->skills.push_back( this->makeSkill("machinegun","Machine Gun",15) );
    this->skills.push_back( this->makeSkill("rifle","Rifle",25) );
    this->skills.push_back( this->makeSkill("shotgun","Shotgun",30) );
    this->skills.push_back( this->makeSkill("smg","SMG",15) );
    this->skills.push_back( this->makeSkill("fist","Fist",50) );
    this->skills.push_back( this->makeSkill("grapple","Grapple",25) );
    this->skills.push_back( this->makeSkill("headbutt","Head Butt",10) );
    this->skills.push_back( this->makeSkill("kick","Kick",25) );
}

void CoC1920Investigator::create1920Investigator()
{
    //Create character with randomly generated stats:
    this->create1920Investigator( "Character Name"
                                 ,"Player Name"
                                 ,dice.rollDice(3,6)
                                 ,dice.rollDice(3,6)
                                 ,dice.rollDice(2,6)+6
                                 ,dice.rollDice(3,6)
                                 ,dice.rollDice(3,6)
                                 ,dice.rollDice(2,6)+6
                                 ,dice.rollDice(3,6)
                                 ,dice.rollDice(3,6)+3
                                 ,0
                                );
}

void CoC1920Investigator::create1920Investigator(std::string sCharName, std::string sPlayerName, int iSTR, int iCON, int iSIZ, int iDEX, int iAPP, int iINT, int iPOW, int iEDU, int iIncome)
{
    this->setStats(iSTR, iCON, iSIZ, iDEX, iAPP,iINT, iPOW, iEDU);
    this->setPlayerName(sPlayerName);
    this->setCharName(sCharName);
    if(iIncome == 0)
        this->setIncome();
    else
        this->setIncome(iIncome);
    this->setDefaultSkills();
}
