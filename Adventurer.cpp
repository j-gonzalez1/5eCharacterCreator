//Jose Luis Gonzalez
//CSIS 137
//Final Project
//December 14, 2020


#include "Adventurer.h"


//Constructor
Adventurer::Adventurer(string cName, int age, string race, string background, string alignment, string pName)
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
    
    setCharacterName(cName);
    setCharacterRace();
    setCharacterBackground();
    setBackgroundSkills();
    setCharacterAlignment();
    setCharacterAge();
    setAbilityScores(abilityScores);
    setPlayerName(pName);
    
    strMod = setModifier(characterStrength);
    dexMod = setModifier(characterDexterity);
    conMod = setModifier(characterConstitution);
    intMod = setModifier(characterIntelligence);
    wisMod = setModifier(characterWisdom);
    chaMod = setModifier(characterCharisma);
}

//Destructor
Adventurer::~Adventurer()
{
     
}

//Set Functions
Adventurer& Adventurer::setCharacterName(string cName)
{
    characterName = cName;
    return *this;
}

Adventurer& Adventurer::setCharacterRace()
{
    const string arrayNum[4] = {"Human", "Mountain Dwarf", "High Elf", "Halfling"};
    int RandIndex = rand() % 4;
    characterRace = arrayNum[RandIndex];
    return *this;
}

Adventurer& Adventurer::setCharacterBackground()
{
    const string arrayNum[6] = {"Acolyte", "Criminal", "Folk Hero", "Noble", "Sage", "Soldier"};
    int RandIndex = rand() % 6;
    characterBackground = arrayNum[RandIndex];
    return *this;
}

Adventurer& Adventurer::setCharacterAlignment()
{
    const string arrayNum[6] = {"Lawful Good", "Neutral Good", "Chaotic Good", "Lawful Neutral", "True Neutral", "Chaotic Neutral"};
    int RandIndex = rand() % 6;
    characterAlignment = arrayNum[RandIndex];
    return *this;
}

Adventurer& Adventurer::setCharacterAge()
{
    if (characterRace == "Human")
    {
        int max = 35, min = 16, range;
        range = max-min + 1;
        characterAge = rand()%range + min;
    }
    else if (characterRace == "Mountain Dwarf")
    {
        int max = 175, min = 50, range;
        range = max-min + 1;
        characterAge = rand()%range + min;
    }
    else if (characterRace == "High Elf")
    {
        int max = 375, min = 100, range;
        range = max-min + 1;
        characterAge = rand()%range + min;
    }
    else if (characterRace == "Halfling")
    {
        int max = 75, min = 20, range;
        range = max-min + 1;
        characterAge = rand()%range + min;
    }
    return *this;
}

Adventurer& Adventurer::setPlayerName(string pName)
{
    playerName = pName;
    return *this;
}

Adventurer& Adventurer::setFirstAttack(Attack fA)
{
    firstAttack = fA;
    return *this;
}
Adventurer& Adventurer::setSecondAttack(Attack sA)
{
    secondAttack = sA;
    return *this;
}

string Adventurer::setFileName(string name, int sheet)
{
    sheet++;
    ss << sheet;
    fileName = name + ss.str() + ext;
    return fileName;
}

void Adventurer::setBackgroundSkills()
{
    if (characterBackground == "Acolyte")
    {
        skill0 = "Insight";
        skill1 = "Religion";
        skillMod0 = wisMod;
        skillMod1 = intMod;
    }
    else if (characterBackground == "Criminal")
    {
        skill0 = "Deception";
        skill1 = "Stealth";
        skillMod0 = chaMod;
        skillMod1 = dexMod;
    }
    else if (characterBackground == "Folk Hero")
    {
        skill0 = "Animal Handling";
        skill1 = "Survival";
        skillMod0 = wisMod;
        skillMod1 = wisMod;
    }
    else if (characterBackground == "Noble")
    {
        skill0 = "History";
        skill1 = "Persuasion";
        skillMod0 = getCharacterIntMod();
        skillMod1 = chaMod;
    }
    else if (characterBackground == "Sage")
    {
        skill0 = "Arcana";
        skill1 = "History";
        skillMod0 = intMod;
        skillMod1 = intMod;
    }
    else if (characterBackground == "Soldier")
    {
        skill0 = "Athletics";
        skill1 = "Intimidation";
        skillMod0 = strMod + profBonus;
        skillMod1 = chaMod + profBonus;
    }
}

void Adventurer::setAbilityScores(vector<vector<int>> abilityScores)
{
    int RandIndex = rand() % 12;
    
    if (characterRace == "Human")
    {
        characterStrength = abilityScores[RandIndex][0] + 1;
        characterDexterity = abilityScores[RandIndex][1] + 1;
        characterConstitution = abilityScores[RandIndex][2] + 1;
        characterIntelligence = abilityScores[RandIndex][3] + 1;
        characterWisdom = abilityScores[RandIndex][4] + 1;
        characterCharisma = abilityScores[RandIndex][5] + 1;
    }
    else if (characterRace == "Mountain Dwarf")
    {
        characterStrength = abilityScores[RandIndex][0] + 2;
        characterDexterity = abilityScores[RandIndex][1];
        characterConstitution = abilityScores[RandIndex][2] + 2;
        characterIntelligence = abilityScores[RandIndex][3];
        characterWisdom = abilityScores[RandIndex][4];
        characterCharisma = abilityScores[RandIndex][5];
    }
    else if (characterRace == "High Elf")
    {
        characterStrength = abilityScores[RandIndex][0];
        characterDexterity = abilityScores[RandIndex][1] + 2;
        characterConstitution = abilityScores[RandIndex][2];
        characterIntelligence = abilityScores[RandIndex][3] + 1;
        characterWisdom = abilityScores[RandIndex][4];
        characterCharisma = abilityScores[RandIndex][5];
    }
    else if (characterRace == "Halfling")
    {
        characterStrength = abilityScores[RandIndex][0];
        characterDexterity = abilityScores[RandIndex][1] + 2;
        characterConstitution = abilityScores[RandIndex][2];
        characterIntelligence = abilityScores[RandIndex][3];
        characterWisdom = abilityScores[RandIndex][4];
        characterCharisma = abilityScores[RandIndex][5] + 1;
    }
}

int Adventurer::setModifier(int score)
{
    if (score > 7 && score < 10)
    {
        mod = -1;
    }
    else if (score > 9 && score < 12)
    {
        mod = 0;
    }
    else if (score > 11 && score < 14)
    {
        mod = +1;
    }
    else if (score > 13 && score < 16)
    {
        mod = +2;
    }
    else if (score > 15 && score < 18)
    {
        mod = +3;
    }
    else if (score > 17 && score < 20)
    {
        mod = +4;
    }
    else if (score > 20)
    {
        mod = +5;
    }
    else
    {
        mod = -9;
    }
    return mod;
}


//Get Functions
string Adventurer::getCharacterName() const
{
    return characterName;
}

string Adventurer::getCharacterRace() const
{
    return characterRace;
}

string Adventurer::getCharacterBackground() const
{
    return characterBackground;
}

string Adventurer::getCharacterAlignment() const
{
    return characterAlignment;
}

string Adventurer::getPlayerName() const
{
    return playerName;
}

string Adventurer::getFileName()
{
    return fileName;
}

int Adventurer::getCharacterAge() const
{
    return characterAge;
}

int Adventurer::getProfBonus() const
{
    return profBonus;
}

Attack Adventurer::getFirstAttack() const
{
    return firstAttack;
}

Attack Adventurer::getSecondAttack() const
{
    return secondAttack;
}

int Adventurer::getCharacterStrength() const
{
    return characterStrength;
}

int Adventurer::getCharacterDexterity() const
{
    return characterDexterity;
}

int Adventurer::getCharacterConstitution() const
{
    return characterConstitution;
}

int Adventurer::getCharacterIntelligence() const
{
    return characterIntelligence;
}

int Adventurer::getCharacterWisdom() const
{
    return characterWisdom;
}

int Adventurer::getCharacterCharisma() const
{
    return characterCharisma;
}

int Adventurer::getCharacterStrMod() const
{
    return strMod;
}

int Adventurer::getCharacterDexMod() const
{
    return dexMod;
}

int Adventurer::getCharacterConMod() const
{
    return conMod;
}

int Adventurer::getCharacterIntMod() const
{
    return intMod;
}

int Adventurer::getCharacterWisMod() const
{
    return wisMod;
}

int Adventurer::getCharacterChaMod() const
{
    return chaMod;
}

int Adventurer::getSkillMod0() const
{
    return dexMod;
}

int Adventurer::getSkillMod1() const
{
    return skillMod1;
}

string Adventurer::getBackgroundSkill0() const
{
    return skill0;
}

string Adventurer::getBackgroundSkill1() const
{
    return skill1;
}
