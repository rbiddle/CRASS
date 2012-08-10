#ifndef COCINVESTIGATOR_H
#define COCINVESTIGATOR_H

#include "string"
#include "investigator.h"

class CoCInvestigator : public Investigator
{
public:
    CoCInvestigator();

private:
    std::string data_occupation;
    std::string data_education;
    std::string data_birthplace;
    std::string data_disorders;
    std::string data_sex;
    std::string data_age;
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
    int stat_sanpts;
    int stat_magic;
    int stat_hp;
};

#endif // COCINVESTIGATOR_H
