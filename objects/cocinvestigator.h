#ifndef COCINVESTIGATOR_H
#define COCINVESTIGATOR_H

#include "string"
#include "vector"
#include "investigator.h"

struct skillStruct
{
    std::string name;
    std::string desc;
    int baseVal;
    int incrOcpn;
    int incrPrsn;
};

class CoCInvestigator : public Investigator
{
public:
    CoCInvestigator();
    std::string debugOutputInvestigator();

    void setStats();
    void setStats (int iSTR, int iCON, int iSIZ, int iDEX, int iAPP, int iINT, int iPOW, int iEDU);

    void setSTR( int iVal );
    void setCON( int iVal );
    void setSIZ( int iVal );
    void setDEX( int iVal );
    void setAPP( int iVal );
    void setINT( int iVal );
    void setPOW( int iVal );
    void setEDU( int iVal );
    void setEDUNoAge( int iVal );
    void setSAN( int iVal );
    void setIDEA( int iVal );
    void setLUCK( int iVal );
    void setKNOW( int iVal );
    void setHP( int iVal );
    void setMP( int iVal );
    int getSTR();
    int getCON();
    int getSIZ();
    int getDEX();
    int getAPP();
    int getINT();
    int getPOW();
    int getEDU();
    int getSAN();
    int getIDEA();
    int getLUCK();
    int getKNOW();
    int getHP();
    int getMP();
    void setDmgBonus( std::string iVal );
    std::string getDmgBonus();

    std::string getOccupation();
    void setOccupation( std::string sVal);
    std::string getEducation();
    void setEducation( std::string sVal );
    std::string getBirthplace();
    void setBirthplace( std::string sVal );
    std::string getDisorders();
    void setDisorders( std::string sVal );
    std::string getSex();
    void setSex( std::string sVal );
    int getAge();
    void setAge( int iVal );
    int getStartAge();
    void setStartAge( int iVal );

    int getCurrSan();
    int getCurrHP();
    int getCurrMP();
    void setCurrSan( int iVal );
    void setCurrHP( int iVal );
    void setCurrMP( int iVal );

    int getIncome();
    double getCash();
    double getSavings();

    int getSkillPts( std::string sSearch );
    int getSkillOcpnPts( std::string sSearch );
    int getSkillPrsnPts( std::string sSearch );
    int getSkillBasePts( std::string sSearch );
    std::vector<skillStruct> getSkillList();
    void updtSkillDesc( std::string sName, std::string sDesc );
    void setSkillBase( std::string sSearch, int iVal );
    void incrSkillOcpn( std::string sSearch, int iVal );
    void incrSkillPrsn( std::string sSearch, int iVal );
    bool isOccupationalSkill( std::string sSkill );
    void addOccupationalSkill( std::string sSkill );
    void removeOccupationalSkill( std::string sSkill );
    void clearOccupationalSkills();
    int getTotalOcpnPts();
    int getRemainingOcpnPts();
    int getTotalPrsnPts();
    int getRemainingPrsnPts();
    void setOcpnPts( int iVal );
    void setPrsnPts( int iVal );

protected:
    std::string data_occupation;
    std::string data_education;
    std::string data_birthplace;
    std::string data_disorders;
    std::string data_sex;
    int data_age;
    int data_start_age;
    std::string data_residence;
    std::string data_familyfriends;
    std::string data_insanities;
    std::string data_injuries;
    std::string data_scars;
    std::string data_history;
    int data_income;
    double data_cash;
    double data_savings;
    std::string data_property;
    std::string data_realestate;
    std::string data_gear;
    std::string data_tomes;
    std::string data_artifacts;
    std::string data_spells;
    int stat_str;
    int stat_con;
    int stat_siz;
    int stat_dex;
    int stat_app;
    int stat_san;
    int stat_int;
    int stat_pow;
    int stat_edu;
    int stat_idea;
    int stat_luck;
    int stat_know;
    std::string stat_dmgbonus;
    int stat_mp;
    int stat_hp;
    int stat_currsan;
    int stat_currmp;
    int stat_currhp;  // current hit points

    int ocpnPts;  // occupational points
    int prsnPts;  // personal interest points

    std::string calcDmgBonus();

    std::vector<skillStruct> skills;
    skillStruct makeSkill(std::string sName, std::string sDesc, int baseVal);
    std::vector<std::string> occupationSkills;
};

#endif // COCINVESTIGATOR_H
