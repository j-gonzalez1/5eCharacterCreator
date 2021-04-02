//Jose Luis Gonzalez
//CSIS 137
//Final Project
//December 14, 2020


#include "Wizard.h"


//Constructor
Wizard::Wizard(string cName, int age, string race, int classSelection, string alignment, string background, string pName, Attack first, Attack second) : firstAttack(first), secondAttack(second)
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
        {"Arcana", "History", "Insight", "Investigation", "Medicine", "Religion"}
    };
    shuffle(classSkills.begin(), classSkills.end(), random_device());
    
    vector<string> characterEquip
    {
        {"Spellbook", "Scholar's Pack", "Book of Lore", "Pen & Bottle of ink", "Parchment Sheets", "Herbalism Kit", "Brass Orb", "Small Bag of Sand", "Small Knife", "Component Pouch", "Purse With 25 GP"}
    };
    
    vector<string> cantrips
    {
        {"Acid Splash", "Blade Ward", "Chill Touch", "Dancing Lights", "Firebolt", "Friends", "Light", "Mage Hand", "Mending", "Message"}
    };
    shuffle(cantrips.begin(), cantrips.end(), random_device());
    
    vector<string> spells
    {
        {"Alarm", "Burning Hands", "Chromatic Orb", "Color Spray", "Disguise Self", "Feather Fall", "Fog Cloud", "Identify", "Jump", "Mage Armor", "Magic Missile", "Shield", "Sleep", "Thunderwave", "Witch Bolt"}
    };
    shuffle(spells.begin(), spells.end(), random_device());
    
        setCharacterName(cName);
        setCharacterRace();
        setCharacterClass();
        setCharacterBackground();
        setCharacterAlignment();
        setCharacterAge();
        setPlayerName(pName);
        setAbilityScores(abilityScores);
        setClassSkills(classSkills);
        setCantrips(cantrips);
        setSpells(spells);
        setCharacterEquipment(characterEquip);
        setFirstAttack(5);
        setSecondAttack(6);
}

//Destructor
Wizard::~Wizard()
{
    
}

//Set Functions
void Wizard::setCharacterClass()
{
    characterClass = "Wizard";
}

void Wizard::setClassSkills(vector<string> classSkills)
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

void Wizard::setCantrips(vector<string> cantrips)
{
    int cell = 1;
    cantrip0 = cantrips[cell];
    cell++;
    cantrip1 = cantrips[cell];
    while (cantrip1 == getCantrip0())
    {
        cell++;
        cantrip1 = cantrips[cell];
    }
    cantrip2 = cantrips[cell];
    while (cantrip2 == getCantrip1() || cantrip2 == getCantrip0())
    {
        cell++;
        cantrip2 = cantrips[cell];
    }
}

void Wizard::setSpells(vector<string> spells)
{
    int cell = 1;
    spell0 = spells[cell];
    cell++;
    spell1 = spells[cell];
    while (spell1 == getSpell0())
    {
        cell++;
        spell1 = spells[cell];
    }
    spell2 = spells[cell];
    while (spell2 == getSpell1() || spell2 == getSpell0())
    {
        cell++;
        spell2 = spells[cell];
    }
    spell3 = spells[cell];
    while (spell3 == getSpell2() || spell3 == getSpell1() || spell3 == getSpell0())
    {
        cell++;
        spell3 = spells[cell];
    }
}

void Wizard::setCharacterEquipment(vector<string> characterEquip)
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

//Get Functions
string Wizard::getCharacterClass() const
{
    return characterClass;
}

string Wizard::getCharacterEquip0() const
{
    return equip0;
}

string Wizard::getCharacterEquip1() const
{
    return equip1;
}

string Wizard::getCharacterEquip2() const
{
    return equip2;
}

string Wizard::getCharacterEquip3() const
{
    return equip3;
}

string Wizard::getCharacterEquip4() const
{
    return equip4;
}

string Wizard::getCharacterEquip5() const
{
    return equip5;
}

string Wizard::getCharacterEquip6() const
{
    return equip6;
}

string Wizard::getCharacterEquip7() const
{
    return equip7;
}

string Wizard::getCharacterEquip8() const
{
    return equip8;
}

string Wizard::getCharacterEquip9() const
{
    return equip9;
}

string Wizard::getCharacterEquip10() const
{
    return equip10;
}

string Wizard::getCharacterSkill2() const
{
    return skill2;
}

string Wizard::getCharacterSkill3() const
{
    return skill3;
}

string Wizard::getCantrip0() const
{
    return cantrip0;
}

string Wizard::getCantrip1() const
{
    return cantrip1;
}

string Wizard::getCantrip2() const
{
    return cantrip2;
}

string Wizard::getSpell0() const
{
    return spell0;
}

string Wizard::getSpell1() const
{
    return spell1;
}

string Wizard::getSpell2() const
{
    return spell2;
}

string Wizard::getSpell3() const
{
    return spell3;
}


//Regular virtual functions
void Wizard::print(ostream& os)const
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
    os <<"|   "<<left<<setw(9)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterEquip2()<<setw(14)<<"|"<<setw(23)<<"SPELLCASTING"<<right<<setw(4)<<"|"<<endl;
    os <<"|    "<<left<<setw(8)<<"WIS"<<setw(5)<<"|"<<setw(22)<<getCharacterEquip3()<<setw(16)<<"|"<<setw(7)<<""<<right<<setw(18)<<"|"<<endl;
    os <<"|    "<<right<<setw(2)<<getCharacterWisdom()<<left<<setw(6)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterEquip4()<<setw(2)<<"|"<<setw(14)<< "Spell Attack +"<<setw(2)<<(getProfBonus()+getCharacterIntMod())<<setw(12)<<" Spell Save DC "<<setw(2)<<(8+getProfBonus()+getCharacterIntMod())<<right<<setw(6)<<"|"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterEquip5()<<setw(2)<<"|"<<setw(37)<<""<<right<<setw(2)<<"|"<<endl;
    os <<"|    "<<left<<setw(8)<<"CHA"<<setw(5)<<"|"<<setw(22)<<getCharacterEquip6()<<setw(2)<<"|"<<setw(38)<<"Cantrips // "+getCantrip0()+", "+getCantrip1()+","<<setw(1)<<"|"<<endl;
    os <<"|    "<<right<<setw(2)<<getCharacterCharisma()<<left<<setw(6)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterEquip7()<<setw(14)<<"|"<<setw(26)<<getCantrip2()<<setw(1)<<"|"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterEquip8()<<setw(2)<<"|"<<setw(7)<<""<<right<<setw(32)<<"|"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterEquip9()<<setw(2)<<"|"<<setw(38)<<"Spells // "+getSpell0()+", "+getSpell1()+","<<setw(1)<<"|"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(5)<<"|"<<setw(22)<<getCharacterEquip10()<<setw(12)<<"|"<<setw(28)<<getSpell2()+", "+getSpell3()<<setw(1)<<"|"<<endl;
    os <<"|   "<<left<<setw(9)<<""<<setw(12)<<"|"<<setw(15)<<""<<setw(16)<<"|"<<setw(7)<<""<<right<<setw(18)<<"|"<<endl;
    os <<"*-------------------------------------------------------------------------------*"<<endl;
}
