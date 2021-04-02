//Jose Luis Gonzalez
//CSIS 137
//Final Project
//December 14, 2020


#include "Rogue.h"


//Constructor
Rogue::Rogue(string cName, int age, string race, int classSelection, string alignment, string background, string pName, Attack first, Attack second) : firstAttack(first), secondAttack(second)
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
        {"Acrobatics", "Athletics", "Deception", "Insight", "Intimidation", "Investigation", "Perception", "Performance", "Persuasion", "Sleight of Hand", "Stealth"}
    };
    shuffle(classSkills.begin(), classSkills.end(), random_device());
    
    vector<string> characterEquip
    {
        {"Leather Armor", "Burglar's Pack", "Disguise Kit", "Thieves' Tools", "Crowbar & Hammer", "10 Pitons", "10 ft of String", "5 Candles", "Hooded Lantern", "Deck of Marked Cards", "Pouch with 15 GP"}
        
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
    setFirstAttack(3);
    setSecondAttack(4);
    setClassFeats();
}

//Destructor
Rogue::~Rogue()
{
    
}

//Set Functions
void Rogue::setCharacterClass()
{
    characterClass = "Rogue";
}

void Rogue::setClassSkills(vector<string> classSkills)
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
    skill4 = classSkills[cell];
    while (skill4 == skill3 || skill4 == skill2 || skill4 == getBackgroundSkill1() || skill4 == getBackgroundSkill0())
    {
        skill4 = classSkills[cell++];
    }
    skill5 = classSkills[cell];
    while (skill5 == skill4 || skill5 == skill3 || skill5 == skill2 || skill5 == getBackgroundSkill1() || skill5 == getBackgroundSkill0())
    {
        skill5 = classSkills[cell++];
    }
}

void Rogue::setCharacterEquipment(vector<string> characterEquip)
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

void Rogue::setClassFeats()
{
    feat0 = "Sneak Attack: Once per turn, deal an extra 1d6 damage to one creature you hit, if you have advantage.";
    feat1 = "Thieves' Cant: A secret mix of code, jargon, and dialect that allows you to hide messages in conversation.";
}


//Get Functions
string Rogue::getCharacterClass() const
{
    return characterClass;
}

string Rogue::getCharacterEquip0() const
{
    return equip0;
}

string Rogue::getCharacterEquip1() const
{
    return equip1;
}

string Rogue::getCharacterEquip2() const
{
    return equip2;
}

string Rogue::getCharacterEquip3() const
{
    return equip3;
}

string Rogue::getCharacterEquip4() const
{
    return equip4;
}

string Rogue::getCharacterEquip5() const
{
    return equip5;
}

string Rogue::getCharacterEquip6() const
{
    return equip6;
}

string Rogue::getCharacterEquip7() const
{
    return equip7;
}

string Rogue::getCharacterEquip8() const
{
    return equip8;
}

string Rogue::getCharacterEquip9() const
{
    return equip9;
}

string Rogue::getCharacterEquip10() const
{
    return equip10;
}

string Rogue::getCharacterSkill2() const
{
    return skill2;
}

string Rogue::getCharacterSkill3() const
{
    return skill3;
}

string Rogue::getCharacterSkill4() const
{
    return skill4;
}

string Rogue::getCharacterSkill5() const
{
    return skill5;
}

string Rogue::getClassFeat0() const
{
    return feat0;
}

string Rogue::getClassFeat1() const
{
    return feat1;
}

//Regular virtual functions
void Rogue::print(ostream& os)const
{
    os <<setw(52)<<"D&D 5E CHARACTER SHEET\n";
    os <<"*-------------------------------------------------------------------------------*"<<endl;
    os <<"| "<<left<<setw(15)<<getCharacterName()<<" // "<<left<<setw(3)<<getCharacterAge()<<right<<setw(55)<<getPlayerName()<<" |"<<endl;
    os <<"| "<<left<<setw(14)<<getCharacterRace()<<" // "<<left<<setw(7)<<getCharacterClass()<<right<<setw(54)<<" |"<<endl;
    os <<"| "<<left<<setw(15)<<getCharacterAlignment()<<" // "<<left<<setw(9)<<getCharacterBackground()<<right<<setw(51)<<" |"<<endl;
    os <<"*-------------------------------------------------------------------------------*"<<endl;
    os <<"|   "<<left<<setw(9)<<"ABILITY"<<setw(11)<<"|"<<setw(16)<<"SKILLS"<<setw(6)<<"|"<<setw(7)<<"AC"<<setw(6)<<"|"<<setw(7)<<"HP"<<setw(6)<<"|"<<setw(7)<<"PP"<<right<<setw(2)<<" |"<<endl;
    os <<"|   "<<left<<setw(9)<<"SCORES"<<setw(11)<<"|"<<setw(16)<<""<<setw(6)<<"|"<<setw(7)<<""<<setw(6)<<"|"<<setw(7)<<""<<setw(6)<<"|"<<setw(7)<<""<<right<<setw(2)<<" |"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(5)<<"|"<<setw(22)<<getBackgroundSkill0()<<setw(6)<<"|"<<setw(7)<<(15+getCharacterDexMod())<<setw(6)<<"|"<<setw(7)<<(10+getCharacterConMod())<<setw(6)<<"|"<<setw(7)<<(10+getCharacterWisMod())<<right<<setw(2)<<" |"<<endl;
    os <<"|    "<<left<<setw(8)<<"STR"<<setw(5)<<"|"<<setw(22)<<getBackgroundSkill1()<<setw(6)<<"|"<<setw(7)<<""<<setw(6)<<"|"<<setw(7)<<""<<setw(6)<<"|"<<setw(7)<<""<<right<<setw(2)<<" |"<<endl;
    os <<"|    "<<right<<setw(2)<<getCharacterStrength()<<left<<setw(6)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterSkill2()<<setw(6)<<"|---------------------------------------|"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterSkill3()<<setw(16)<<"|"<<setw(8)<<"ATTACKS"<<right<<setw(17)<<"|"<<endl;
    os <<"|    "<<left<<setw(8)<<"DEX"<<setw(5)<<"|"<<setw(22)<<getCharacterSkill4()<<setw(1)<<"|"<<setw(20)<<""<<right<<setw(20)<<"|"<<endl;
    os <<"|    "<<right<<setw(2)<<getCharacterDexterity()<<left<<setw(6)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterSkill5()<<"| "<<setw(11) << "  Weapon" <<setw(11) << "|  Range   |To Hit| Damage |"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(27)<<"|"<<setw(9)<<"|"<<setw(7)<<""<<right<<setw(25)<<"|"<<endl;
    os <<"|    "<<left<<setw(8)<<"CON"<<"|--------------------------"<<setw(1)<<"|"<<getFirstAttack()<<endl;
    os <<"|    "<<right<<setw(2)<<getCharacterConstitution()<<setw(7)<<"|"<<setw(18)<<"EQUIPMENT"<<setw(9)<<"|"<<setw(7)<<""<<right<<setw(33)<<"|"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(7)<<"|"<<setw(20)<<""<<setw(1)<<"|"<<left<<getSecondAttack()<<endl;
    os <<"|    "<<left<<setw(8)<<"INT"<<setw(5)<<"|"<<setw(22)<<getCharacterEquip0()<<setw(6)<<"|"<<setw(20)<<""<<right<<setw(15)<<"|"<<endl;
    os <<"|    "<<right<<setw(2)<<getCharacterIntelligence()<<left<<setw(6)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterEquip1()<<setw(16)<<"|---------------------------------------|"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterEquip2()<<setw(13)<<"|"<<setw(22)<<"CLASS FEATURES"<<right<<setw(6)<<"|"<<endl;
    os <<"|    "<<left<<setw(8)<<"WIS"<<setw(5)<<"|"<<setw(22)<<getCharacterEquip3()<<setw(16)<<"|"<<setw(7)<<""<<right<<setw(18)<<"|"<<endl;
    os <<"|    "<<right<<setw(2)<<getCharacterWisdom()<<left<<setw(6)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterEquip4()<<setw(2)<<"|"<<setw(37)<<feat0.substr(0, 37)<<right<<setw(2)<<"|"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterEquip5()<<setw(2)<<"|"<<setw(37)<<feat0.substr(37, 36)<<right<<setw(2)<<"|"<<endl;
    os <<"|    "<<left<<setw(8)<<"CHA"<<setw(5)<<"|"<<setw(22)<<getCharacterEquip6()<<setw(2)<<"|"<<setw(37)<<feat0.substr(74, 36)<<right<<setw(2)<<"|"<<endl;
    os <<"|    "<<right<<setw(2)<<getCharacterCharisma()<<left<<setw(6)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterEquip7()<<setw(16)<<"|"<<setw(7)<<""<<right<<setw(18)<<"|"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterEquip8()<<setw(2)<<"|"<<setw(7)<<feat1.substr(0, 37)<<right<<setw(2)<<"|"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterEquip9()<<setw(2)<<"|"<<setw(37)<<feat1.substr(37, 35)<<right<<setw(2)<<"|"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterEquip10()<<setw(2)<<"|"<<setw(37)<<feat1.substr(73, 36)<<right<<setw(2)<<"|"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(12)<<"|"<<setw(15)<<""<<setw(16)<<"|"<<setw(7)<<""<<right<<setw(18)<<"|"<<endl;
    os <<"*-------------------------------------------------------------------------------*"<<endl;
}
