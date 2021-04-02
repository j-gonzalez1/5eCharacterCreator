//Jose Luis Gonzalez
//CSIS 137
//Final Project
//December 14, 2020


#include "Fighter.h"


//Constructor
Fighter::Fighter(string cName, int age, string race, int classSelection, string alignment, string background, string pName, Attack first, Attack second) : firstAttack(first), secondAttack(second)
{
    srand ((unsigned int)time(NULL));
    
    vector<vector<int>> abilityScores
    {
        {15, 14, 13, 12, 10, 8},
        {15, 15, 13, 12, 8, 8},
        {15, 15, 15, 8, 8, 8},
        {15, 13, 12, 11, 11, 11},
        {8, 10, 12, 15, 14, 13},
        {8, 8, 15, 15, 13, 12},
        {8, 8, 15, 15, 15, 8},
        {11, 11, 13, 15, 12, 11},
        {8, 15, 14, 12, 10, 13},
        {8, 15, 12, 13, 8, 15},
        {15, 15, 15, 8, 8, 8},
        {11, 15, 11, 13, 11, 12}
    };
    
    vector<string> classSkills
    {
        {"Acrobatics", "Animal Handling", "Athletics", "History", "Insight", "Intimidation", "Perception", "Survival"}
    };
    shuffle(classSkills.begin(), classSkills.end(), random_device());
    
    vector<string> characterEquip
    {
        {"Scale Mail", "+1 Shield", "Explorer's Pack", "Bedroll & Mess Kit", "Waterskin", "10 Days Rations", "50 ft Hempen rope", "Tinderbox", "10 Torches", "Set of Bone Dice", "Pouch with 10 GP"}
        
    };
    
    setCharacterName(cName);
    setCharacterRace();
    setCharacterClass();
    setCharacterBackground();
    setCharacterAlignment();
    setCharacterAge();
    setPlayerName(pName);
    setAbilityScores(abilityScores);
    setClassSkills(classSkills);
    setCharacterEquipment(characterEquip);
    setFirstAttack(0);
    setSecondAttack(1);
    setClassFeats();
}

//Destructor
Fighter::~Fighter()
{
    
}

//Set Functions
void Fighter::setCharacterClass()
{
    characterClass = "Fighter";
}

void Fighter::setClassSkills(vector<string> classSkills)
{
    int cell = 2;
    skill2 = classSkills[cell];
    while (skill2 == getBackgroundSkill1() || skill2 == getBackgroundSkill0())
    {
        cell++;
        skill2 = classSkills[cell];
    }
    skill3 = classSkills[cell];
    while (skill3 == skill2 || skill3 == getBackgroundSkill1() || skill3 == getBackgroundSkill0())
    {
        cell++;
        skill3 = classSkills[cell];
    }
    
}

void Fighter::setCharacterEquipment(vector<string> characterEquip)
{
    equip0 = characterEquip[0];
    equip1 = characterEquip[1];
    equip2 = characterEquip[2];
    equip3 = characterEquip[3];
    equip4 = characterEquip[4];
    equip5 = characterEquip[5];
    equip6 = characterEquip[6];
    equip7 = characterEquip[7];
    equip8 = characterEquip[8];
    equip9 = characterEquip[9];
    equip10 = characterEquip[10];
}

void Fighter::setClassFeats()
{
    feat0 = "Dueling: When wielding a melee weapon in one hand & no other weapons, you gain a +2 bonus to damage rolls.";
    feat1 = "Second Wind: Once per short rest, you can use a bonus action to regain (1d10 + fighter level) hit points.";
}

//Get Functions
string Fighter::getCharacterClass() const
{
    return characterClass;
}

string Fighter::getCharacterEquip0() const
{
    return equip0;
}

string Fighter::getCharacterEquip1() const
{
    return equip1;
}

string Fighter::getCharacterEquip2() const
{
    return equip2;
}

string Fighter::getCharacterEquip3() const
{
    return equip3;
}

string Fighter::getCharacterEquip4() const
{
    return equip4;
}

string Fighter::getCharacterEquip5() const
{
    return equip5;
}

string Fighter::getCharacterEquip6() const
{
    return equip6;
}

string Fighter::getCharacterEquip7() const
{
    return equip7;
}

string Fighter::getCharacterEquip8() const
{
    return equip8;
}

string Fighter::getCharacterEquip9() const
{
    return equip9;
}

string Fighter::getCharacterEquip10() const
{
    return equip10;
}

string Fighter::getCharacterSkill2() const
{
    return skill2;
}

string Fighter::getCharacterSkill3() const
{
    return skill3;
}

string Fighter::getClassFeat0() const
{
    return feat0;
}

string Fighter::getClassFeat1() const
{
    return feat1;
}

//Virtual functions
void Fighter::print(ostream& os)const
{
    os <<setw(52)<<"D&D 5E CHARACTER SHEET\n";
    os <<"*-------------------------------------------------------------------------------*"<<endl;
    os <<"| "<<left<<setw(15)<<getCharacterName()<<" // "<<left<<setw(3)<<getCharacterAge()<<right<<setw(55)<<getPlayerName()<<" |"<<endl;
    os <<"| "<<left<<setw(14)<<getCharacterRace()<<" // "<<left<<setw(7)<<getCharacterClass()<<right<<setw(54)<<" |"<<endl;
    os <<"| "<<left<<setw(15)<<getCharacterAlignment()<<" // "<<left<<setw(9)<<getCharacterBackground()<<right<<setw(51)<<" |"<<endl;
    os <<"*-------------------------------------------------------------------------------*"<<endl;
    os <<"|   "<<left<<setw(9)<<"ABILITY"<<setw(11)<<"|"<<setw(16)<<"SKILLS"<<setw(6)<<"|"<<setw(7)<<"AC"<<setw(6)<<"|"<<setw(7)<<"HP"<<setw(6)<<"|"<<setw(7)<<"PP"<<right<<setw(2)<<" |"<<endl;
    os <<"|   "<<left<<setw(9)<<"SCORES"<<setw(11)<<"|"<<setw(16)<<""<<setw(6)<<"|"<<setw(7)<<""<<setw(6)<<"|"<<setw(7)<<""<<setw(6)<<"|"<<setw(7)<<""<<right<<setw(2)<<" |"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(5)<<"|"<<setw(16)<<getBackgroundSkill0()<<setw(6)<<""<<setw(6)<<"|"<<setw(7)<<(15+getCharacterDexMod())<<setw(6)<<"|"<<setw(7)<<(10+getCharacterConMod())<<setw(6)<<"|"<<setw(7)<<(10+getCharacterWisMod())<<right<<setw(2)<<" |"<<endl;
    os <<"|    "<<left<<setw(8)<<"STR"<<setw(5)<<"|"<<setw(22)<<getBackgroundSkill1()<<setw(6)<<"|"<<setw(7)<<""<<setw(6)<<"|"<<setw(7)<<""<<setw(6)<<"|"<<setw(7)<<""<<right<<setw(2)<<" |"<<endl;
    os <<"|    "<<right<<setw(2)<<getCharacterStrength()<<left<<setw(6)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterSkill2()<<setw(6)<<"|---------------------------------------|"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterSkill3()<<setw(16)<<"|"<<setw(8)<<"ATTACKS"<<right<<setw(17)<<"|"<<endl;
    os <<"|    "<<left<<setw(8)<<"DEX"<<setw(7)<<"|"<<setw(20)<<""<<setw(1)<<"|"<<setw(20)<<""<<right<<setw(20)<<"|"<<endl;
    os <<"|    "<<right<<setw(2)<<getCharacterDexterity()<<left<<setw(6)<<""<<setw(7)<<"|"<<setw(20)<<""<<"| "<<setw(11) << "  Weapon" <<setw(11) << "|  Range   |To Hit| Damage |"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(27)<<"|"<<setw(9)<<"|"<<setw(7)<<""<<right<<setw(25)<<"|"<<endl;
    os <<"|    "<<left<<setw(8)<<"CON"<<"|--------------------------"<<setw(1)<<"|"<<getFirstAttack()<<endl;
    os <<"|    "<<right<<setw(2)<<getCharacterConstitution()<<setw(7)<<"|"<<setw(18)<<"EQUIPMENT"<<setw(9)<<"|"<<setw(7)<<""<<right<<setw(33)<<"|"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(7)<<"|"<<setw(20)<<""<<setw(1)<<"|"<<left<<getSecondAttack()<<endl;
    os <<"|    "<<left<<setw(8)<<"INT"<<setw(5)<<"|"<<setw(22)<<getCharacterEquip0()<<setw(6)<<"|"<<setw(20)<<""<<right<<setw(15)<<"|"<<endl;
    os <<"|    "<<right<<setw(2)<<getCharacterIntelligence()<<left<<setw(6)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterEquip1()<<setw(16)<<"|---------------------------------------|"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterEquip2()<<setw(13)<<"|"<<setw(22)<<"CLASS FEATURES"<<right<<setw(6)<<"|"<<endl;
    os <<"|    "<<left<<setw(8)<<"WIS"<<setw(5)<<"|"<<setw(22)<<getCharacterEquip3()<<setw(16)<<"|"<<setw(7)<<""<<right<<setw(18)<<"|"<<endl;
    os <<"|    "<<right<<setw(2)<<getCharacterWisdom()<<left<<setw(6)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterEquip4()<<setw(2)<<"|"<<setw(37)<<feat0.substr(0, 37)<<right<<setw(2)<<"|"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterEquip5()<<setw(2)<<"|"<<setw(37)<<feat0.substr(38, 36)<<right<<setw(2)<<"|"<<endl;
    os <<"|    "<<left<<setw(8)<<"CHA"<<setw(5)<<"|"<<setw(22)<<getCharacterEquip6()<<setw(2)<<"|"<<setw(37)<<feat0.substr(74, 36)<<right<<setw(2)<<"|"<<endl;
    os <<"|    "<<right<<setw(2)<<getCharacterCharisma()<<left<<setw(6)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterEquip7()<<setw(16)<<"|"<<setw(7)<<""<<right<<setw(18)<<"|"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterEquip8()<<setw(2)<<"|"<<setw(7)<<feat1.substr(0, 37)<<right<<setw(2)<<"|"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterEquip9()<<setw(2)<<"|"<<setw(37)<<feat1.substr(38, 33)<<right<<setw(2)<<"|"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterEquip10()<<setw(2)<<"|"<<setw(37)<<feat1.substr(71, 36)<<right<<setw(2)<<"|"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(12)<<"|"<<setw(15)<<""<<setw(16)<<"|"<<setw(7)<<""<<right<<setw(18)<<"|"<<endl;
    os <<"*-------------------------------------------------------------------------------*"<<endl;
}
