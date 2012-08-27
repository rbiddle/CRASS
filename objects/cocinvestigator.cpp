#include "cocinvestigator.h"
#include "string"
#include "math.h"
#include "sstream"

#include "iostream"

CoCInvestigator::CoCInvestigator()
{
    this->data_occupation = "";
    this->data_education = "";
    this->data_birthplace = "";
    this->data_disorders = "";
    this->data_sex = "";
    this->data_age = 0;
    this->data_residence = "";
    this->data_familyfriends = "";
    this->data_insanities = "";
    this->data_injuries = "";
    this->data_scars = "";
    this->data_history = "";
    this->data_income = 0;
    this->data_cash = 0.00;
    this->data_savings = 0.00;
    this->data_property = "";
    this->data_realestate = "";
    this->data_gear = "";
    this->data_tomes = "";
    this->data_artifacts = "";
    this->data_spells = "";
    this->stat_str = 0;
    this->stat_con = 0;
    this->stat_siz = 0;
    this->stat_dex = 0;
    this->stat_app = 0;
    this->stat_san = 0;
    this->stat_int = 0;
    this->stat_pow = 0;
    this->stat_edu = 0;
    this->stat_idea = 0;
    this->stat_luck = 0;
    this->stat_know = 0;
    this->stat_dmgbonus = "";
    this->stat_mp = 0;
    this->stat_hp = 0;
    this->stat_currsan = 0;
    this->stat_currmp = 0;
    this->stat_currhp = 0;
}

void CoCInvestigator::setStats()
{
    //Create character with randomly generated stats:
    this->setStats( dice.rollDice(3,6)
                   ,dice.rollDice(3,6)
                   ,dice.rollDice(2,6)+6
                   ,dice.rollDice(3,6)
                   ,dice.rollDice(3,6)
                   ,dice.rollDice(2,6)+6
                   ,dice.rollDice(3,6)
                   ,dice.rollDice(3,6)+3
                    );
}

void CoCInvestigator::setStats(int iSTR, int iCON, int iSIZ, int iDEX, int iAPP, int iINT, int iPOW, int iEDU)
{
    //Create character with set stats

    //rolled stats:
    this->setSTR(iSTR);
    this->setCON(iCON);
    this->setSIZ(iSIZ);
    this->setDEX(iDEX);
    this->setAPP(iAPP);
    this->setINT(iINT);
    this->setPOW(iPOW);
    this->setEDU(iEDU);

    this->setCurrSan( this->getSAN() );
    this->setCurrHP( this->getHP() );
    this->setCurrMP( this->getMP() );
}

void CoCInvestigator::setSTR( int iVal ) {
    this->stat_str = iVal;

    //recalc damage bonus
    this->setDmgBonus(this->calcDmgBonus());
}

int CoCInvestigator::getSTR() {
    return this->stat_str;
}

void CoCInvestigator::setCON( int iVal ) {

    this->stat_con = iVal;

    //Recalc HP
    int totConSiz = this->getCON() + this->getSIZ();
    this->setHP( ceil(((double)totConSiz) / 2.00) );\
    //Reset Curr HP
    if (this->getCurrHP() > this->getHP() )
        this->setCurrHP( this->getHP() );
}

int CoCInvestigator::getCON() {
    return this->stat_con;
}

void CoCInvestigator::setSIZ( int iVal ) {
    this->stat_siz = iVal;

    //recalc Damage Bonus
    this->setDmgBonus(this->calcDmgBonus());

    //recalc HP
    int totConSiz = this->getCON() + this->getSIZ();
    this->setHP( ceil(((double)totConSiz) / 2.00) );
    //Reset Curr HP
    if (this->getCurrHP() > this->getHP() )
        this->setCurrHP( this->getHP() );
}

int CoCInvestigator::getSIZ() {
    return this->stat_siz;
}

void CoCInvestigator::setDEX( int iVal ) {
    this->stat_dex = iVal;
    if ( this->getSkillPts("dodge") < (iVal * 2) )
        this->setSkillBase("dodge", iVal * 2);
}

int CoCInvestigator::getDEX() {
    return this->stat_dex;
}

void CoCInvestigator::setAPP( int iVal ) {
    this->stat_app = iVal;
}

int CoCInvestigator::getAPP() {
    return this->stat_app;
}

void CoCInvestigator::setINT( int iVal ) {
    this->stat_int = iVal;
    this->setIDEA( (this->getINT() * 5) );

    this->setPrsnPts(this->getINT() * 10);
}

int CoCInvestigator::getINT() {
   return this->stat_int;
}

void CoCInvestigator::setPOW( int iVal ) {
    this->stat_pow = iVal;
    this->setLUCK( (this->getPOW() * 5) );
    this->setMP( this->getPOW() );

    this->setSAN( (this->getPOW() * 5) );
// Per 20th edition rule book, Current SAN does not change when POW increases, only SAN Characteristic (p. 101)
// it's unclear if POW decreases, does Current SAN drop as well. It reads (p. 40) that POW*5 is used for the
// SAN Charactaristic and starting SAN, but is not a limiter thereafter.
//    if( this->getCurrSan() > this->getSAN() )
//        this->setCurrSan( this->getSAN() );

    // Magic Points do not decrease if POW goes down, but will not increase until below the new max
    // TODO: if POW goes up, MP is increased pro-rated...
}

int CoCInvestigator::getPOW() {
    return this->stat_pow;
}

void CoCInvestigator::setEDU( int iVal )
{
    this->stat_edu = iVal;
    this->setKNOW( (this->getEDU() * 5) );
    if ( this->getSkillPts("ownlanguage") < (iVal * 5) )
        this->setSkillBase("ownlanguage", iVal * 5);

    this->setOcpnPts(this->getEDU() * 20);

    this->setStartAge( this->getEDU()+6 );
    this->setAge( this->getEDU()+6 );
}

void CoCInvestigator::setEDUNoAge(int iVal)
{
    this->stat_edu = iVal;
    this->setKNOW( (this->getEDU() * 5) );
    if ( this->getSkillPts("ownlanguage") < (iVal * 5) )
        this->setSkillBase("ownlanguage", iVal * 5);

    this->setOcpnPts(this->getEDU() * 20);
}

int CoCInvestigator::getEDU() {
    return this->stat_edu;
}

void CoCInvestigator::setSAN( int iVal ) {
    this->stat_san = iVal;
}

int CoCInvestigator::getSAN() {
    return this->stat_san;
}

void CoCInvestigator::setIDEA( int iVal ) {
    if (iVal >= 100)
        this->stat_idea = 99;
    else
        this->stat_idea = iVal;
}

int CoCInvestigator::getIDEA() {
    return this->stat_idea;
}

void CoCInvestigator::setLUCK( int iVal ) {
    if (iVal >= 100)
        this->stat_luck = 99;
    else
        this->stat_luck = iVal;
}

int CoCInvestigator::getLUCK() {
    return this->stat_luck;
}

void CoCInvestigator::setKNOW( int iVal ) {
    if (iVal >= 100)
        this->stat_know = 99;
    else
        this->stat_know = iVal;
}

int CoCInvestigator::getKNOW() {
    return this->stat_know;
}

void CoCInvestigator::setDmgBonus( std::string iVal ) {
   this->stat_dmgbonus = iVal;
}

std::string CoCInvestigator::getDmgBonus() {
    return this->stat_dmgbonus;
}

std::string CoCInvestigator::getOccupation()
{
    return this->data_occupation;
}

void CoCInvestigator::setOccupation( std::string sVal )
{
    this->data_occupation = sVal;
}

std::string CoCInvestigator::getEducation()
{
    return this->data_education;
}

void CoCInvestigator::setEducation(std::string sVal)
{
    this->data_education = sVal;
}

std::string CoCInvestigator::getBirthplace()
{
    return this->data_birthplace;
}

void CoCInvestigator::setBirthplace(std::string sVal)
{
    this->data_birthplace = sVal;
}

std::string CoCInvestigator::getDisorders()
{
    return this->data_disorders;
}

void CoCInvestigator::setDisorders(std::string sVal)
{
    this->data_disorders = sVal;
}

std::string CoCInvestigator::getSex()
{
    return this->data_sex;
}

void CoCInvestigator::setSex(std::string sVal)
{
    this->data_sex = sVal;
}

int CoCInvestigator::getAge()
{
    return this->data_age;
}

void CoCInvestigator::setAge(int iVal)
{
    this->data_age = iVal;
}

int CoCInvestigator::getStartAge()
{
    return this->data_start_age;
}

void CoCInvestigator::setStartAge(int iVal)
{
    this->data_start_age = iVal;
}

void CoCInvestigator::setHP( int iVal ) {
    this->stat_hp = iVal;
}

int CoCInvestigator::getHP() {
    return this->stat_hp;
}

void CoCInvestigator::setMP( int iVal ) {
    this->stat_mp = iVal;
}

int CoCInvestigator::getMP() {
    return this->stat_mp;
}

void CoCInvestigator::setCurrSan( int iVal ) {
    this->stat_currsan = iVal;
}

int CoCInvestigator::getCurrSan() {
    return this->stat_currsan;
}

void CoCInvestigator::setCurrHP( int iVal ) {
    this->stat_currhp = iVal;
}

int CoCInvestigator::getCurrHP() {
    return this->stat_currhp;
}

void CoCInvestigator::setCurrMP( int iVal ) {
    this->stat_currmp = iVal;
}

int CoCInvestigator::getCurrMP() {
    return this->stat_currmp;
}

std::string CoCInvestigator::calcDmgBonus()
{
    int totStrSiz = this->getSTR() + this->getSIZ();
    std::string output = "";

    if(totStrSiz <= 12){
        output = "-1d6";
    } else if(totStrSiz >= 13 && totStrSiz <= 16){
        output = "-1d4";
    } else if(totStrSiz >= 17 && totStrSiz <= 24){
        output = "0";
    } else if(totStrSiz >= 25 && totStrSiz <= 32){
        output = "+1d4";
    } else if(totStrSiz >= 33 && totStrSiz <= 40){
        output = "+1d6";
    } else if(totStrSiz >= 41 && totStrSiz <= 56){
        output = "+2d6";
    } else if(totStrSiz >= 57 && totStrSiz <= 72){
        output = "+3d6";
    } else if(totStrSiz >= 73 && totStrSiz <= 88){
        output = "+4d6";
    } else {
        //STR + SIZ over 88, calc damage bonus..
        int amtOver88 = totStrSiz - 88;
        int dmgIncreases = ( amtOver88 / 16 ) + 5;
        std::stringstream stream;
        stream << dmgIncreases;
        output = "+" + stream.str() + "d6";
    }
    return output;
}

int CoCInvestigator::getIncome()
{
    return this->data_income;
}

double CoCInvestigator::getCash()
{
    return this->data_cash;
}

double CoCInvestigator::getSavings()
{
    return this->data_savings;
}

int CoCInvestigator::getSkillPts(std::string sSearch)
{
    for ( unsigned int i=0; i < this->skills.size(); i++ )
        if( (this->skills[i].name == sSearch) || (this->skills[i].desc == sSearch) )
            return ( this->skills[i].baseVal + this->skills[i].incrOcpn + this->skills[i].incrPrsn );
    return 0;
}

int CoCInvestigator::getSkillOcpnPts(std::string sSearch)
{
    for ( unsigned int i=0; i < this->skills.size(); i++ )
        if( (this->skills[i].name == sSearch) || (this->skills[i].desc == sSearch) )
            return this->skills[i].incrOcpn;
    return 0;
}

int CoCInvestigator::getSkillPrsnPts(std::string sSearch)
{
    for ( unsigned int i=0; i < this->skills.size(); i++ )
        if( (this->skills[i].name == sSearch) || (this->skills[i].desc == sSearch) )
            return this->skills[i].incrPrsn;
    return 0;
}

int CoCInvestigator::getSkillBasePts(std::string sSearch)
{
    for ( unsigned int i=0; i < this->skills.size(); i++ )
        if( (this->skills[i].name == sSearch) || (this->skills[i].desc == sSearch) )
            return this->skills[i].baseVal;
    return 0;
}

std::vector<skillStruct> CoCInvestigator::getSkillList()
{
    return this->skills;
}

void CoCInvestigator::updtSkillDesc(std::string sName, std::string sDesc)
{
    for ( unsigned int i=0; i < this->skills.size(); i++ )
        if( this->skills[i].name == sName ) {
            this->skills[i].desc = sDesc;
            break;
        }
}

void CoCInvestigator::setSkillBase(std::string sSearch, int iVal)
{
    for ( unsigned int i=0; i < this->skills.size(); i++ )
        if( (this->skills[i].name == sSearch) || (this->skills[i].desc == sSearch) ) {
            this->skills[i].baseVal = iVal;
            break;
        }
}

void CoCInvestigator::incrSkillOcpn(std::string sSearch, int iVal)
{
    for ( unsigned int i=0; i < this->skills.size(); i++ )
        if( (this->skills[i].name == sSearch) || (this->skills[i].desc == sSearch) ) {
            this->skills[i].incrOcpn = iVal;
            break;
        }
}

void CoCInvestigator::incrSkillPrsn(std::string sSearch, int iVal)
{
    for ( unsigned int i=0; i < this->skills.size(); i++ )
        if( (this->skills[i].name == sSearch) || (this->skills[i].desc == sSearch) ) {
            this->skills[i].incrPrsn = iVal;
            break;
        }
}

bool CoCInvestigator::isOccupationalSkill(std::string sSkill)
{
    for ( unsigned int i=0; i < this->occupationSkills.size(); i++ )
        if( (this->occupationSkills.at(i) == sSkill) ) {
            return true;
        }
    return false;
}

void CoCInvestigator::addOccupationalSkill(std::string sSkill)
{
    this->occupationSkills.push_back(sSkill);
}

void CoCInvestigator::removeOccupationalSkill(std::string sSkill)
{
    for ( unsigned int i=0; i < this->occupationSkills.size(); i++ )
        if( (this->occupationSkills.at(i) == sSkill) ) {
            this->occupationSkills.erase(this->occupationSkills.begin()+i);
        }
}

void CoCInvestigator::clearOccupationalSkills()
{
    this->occupationSkills.clear();
}

int CoCInvestigator::getTotalOcpnPts()
{
    return this->ocpnPts;
}

int CoCInvestigator::getRemainingOcpnPts()
{
    int spentPts = 0;
    for ( unsigned int i=0; i < this->skills.size(); i++ )
        spentPts += this->skills[i].incrOcpn;
    return ( this->getTotalOcpnPts() - spentPts );
}

int CoCInvestigator::getTotalPrsnPts()
{
    return this->prsnPts;
}

int CoCInvestigator::getRemainingPrsnPts()
{
    int spentPts = 0;
    for ( unsigned int i=0; i < this->skills.size(); i++ )
        spentPts += this->skills[i].incrPrsn;
    return ( this->getTotalPrsnPts() - spentPts );
}

void CoCInvestigator::setOcpnPts(int iVal)
{
    this->ocpnPts = iVal;
}

void CoCInvestigator::setPrsnPts(int iVal)
{
    this->prsnPts = iVal;
}

skillStruct CoCInvestigator::makeSkill(std::string sName, std::string sDesc, int baseVal)
{
    skillStruct output;
    output.name = sName;
    output.desc = sDesc;
    output.baseVal = baseVal;
    output.incrOcpn = 0;
    output.incrPrsn = 0;
    return output;
}

std::string CoCInvestigator::debugOutputInvestigator()
{
    std::stringstream stream;

    stream << "Outputting Investigator:" << std::endl;
    stream << "  Character Name: " << this->getCharName() << std::endl;
    stream << "  Player Name: " << this->getPlayerName() << std::endl;
    stream << "  Desc.: " << this->getCharDesc() << std::endl;
    stream << "  Occupation: " << this->getOccupation() << std::endl;
    stream << "  Rolled Stats:" << std::endl;
    stream << "    STR: " << this->getSTR() << std::endl;
    stream << "    SIZ: " << this->getSIZ() << std::endl;
    stream << "    CON: " << this->getCON() << std::endl;
    stream << "    DEX: " << this->getDEX() << std::endl;
    stream << "    APP: " << this->getAPP() << std::endl;
    stream << "    POW: " << this->getPOW() << std::endl;
    stream << "    INT: " << this->getINT() << std::endl;
    stream << "    EDU: " << this->getEDU() << std::endl;
    stream << "    Income: $" << this->getIncome() << std::endl;
    stream << "  Derived Stats:" << std::endl;
    stream << "    Idea: " << this->getIDEA() << std::endl;
    stream << "    Luck: " << this->getLUCK() << std::endl;
    stream << "    Know: " << this->getKNOW() << std::endl;
    stream << "    Sanity: " << this->getSAN() << std::endl;
    stream << "    HP: " << this->getHP() << std::endl;
    stream << "    Dmg Bonus:" << this->getDmgBonus() << std::endl;
    stream << "    Cash: $" << this->getCash() << std::endl;
    stream << "    Savings: $" << this->getSavings() << std::endl;
    stream << "    MP: " << this->getMP() << std::endl;
    stream << "  Skill Points: " << std::endl;
    stream << "    Occupational: " << this->getRemainingOcpnPts() << " remain out of " << this->getTotalOcpnPts() << " total points" << std::endl;
    stream << "    Personal Interest: " << this->getRemainingPrsnPts() << " remain out of " << this->getTotalPrsnPts() << " total points" << std::endl;
    stream << "  Skills:" << std::endl;
    for ( unsigned int i=0; i < this->skills.size(); i++ )
        stream << "    " << this->skills[i].desc << ": " << this->getSkillPts(this->skills[i].name) << " ( "
                         << this->skills[i].baseVal << " Base + "
                         << this->skills[i].incrOcpn << " Occupation + "
                         << this->skills[i].incrPrsn << " Personal Interest )" <<std::endl;
    stream << "==========================================" << std::endl;

    return stream.str();
}
