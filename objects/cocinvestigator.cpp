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
    //Reset Curr HP?
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
    //Reset Curr HP?
    if (this->getCurrHP() > this->getHP() )
        this->setCurrHP( this->getHP() );
}

int CoCInvestigator::getSIZ() {
    return this->stat_siz;
}

void CoCInvestigator::setDEX( int iVal ) {
    this->stat_dex = iVal;
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
}

int CoCInvestigator::getINT() {
   return this->stat_int;
}

void CoCInvestigator::setPOW( int iVal ) {
    this->stat_pow = iVal;
    this->setLUCK( (this->getPOW() * 5) );
    this->setSAN( (this->getPOW() * 5) );
    this->setMP( this->getPOW() );

    if( this->getCurrSan() > this->getSAN() )
        this->setCurrSan( this->getSAN() );

    // Magic Points do not decrease if POW goes down, but will not increase until below the new max
    // TODO: if POW goes up, MP is increased pro-rated...
}

int CoCInvestigator::getPOW() {
    return this->stat_pow;
}

void CoCInvestigator::setEDU( int iVal ) {
    this->stat_edu = iVal;
    this->setKNOW( (this->getEDU() * 5) );
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
    this->stat_idea = iVal;
}

int CoCInvestigator::getIDEA() {
    return this->stat_idea;
}

void CoCInvestigator::setLUCK( int iVal ) {
    this->stat_luck = iVal;
}

int CoCInvestigator::getLUCK() {
    return this->stat_luck;
}

void CoCInvestigator::setKNOW( int iVal ) {
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

    totStrSiz = 120;

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
