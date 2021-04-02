//Jose Luis Gonzalez
//CSIS 137
//Final Project
//December 14, 2020


#ifndef Adventurer_h
#define Adventurer_h

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include "Attack.h"
using namespace std;

class Adventurer
{
    
    private:
        int profBonus = 2;
        int characterAge;
        int characterStrength;
        int characterDexterity;
        int characterConstitution;
        int characterIntelligence;
        int characterWisdom;
        int characterCharisma;
        int mod;
        int strMod;
        int dexMod;
        int conMod;
        int intMod;
        int wisMod;
        int chaMod;
        int sheet;
        int skillMod0 = 0;
        int skillMod1 = 0;
        string characterName;
        string characterRace;
        string characterBackground;
        string characterAlignment;
        string characterClass;
        string playerName;
        string skill0;
        string skill1;
        string fileName;
        string ext = ".txt";
        stringstream ss;
        Attack firstAttack;
        Attack secondAttack;
        vector<vector<int>> abilityScores;
        vector<vector<string>> skills;
    
    public:
        Adventurer(string = "", int = 0, string = "", string = "", string = "", string = "");
        ~Adventurer();
    
        Adventurer& setCharacterName(string);
        Adventurer& setCharacterRace();
        Adventurer& setCharacterBackground();
        Adventurer& setCharacterAlignment();
        Adventurer& setCharacterAge();
        Adventurer& setPlayerName(string);
        Adventurer& setFirstAttack(Attack);
        Adventurer& setSecondAttack(Attack);
        string setFileName(string, int);
        void setBackgroundSkills();
        void setAbilityScores(vector<vector<int>>);
        int setModifier(int);
    
        string getCharacterName() const;
        string getCharacterRace() const;
        string getCharacterBackground() const;
        string getCharacterAlignment() const;
        string getPlayerName() const;
        string getFileName();
        int getCharacterAge() const;
        int getProfBonus() const;
        Attack getFirstAttack() const;
        Attack getSecondAttack() const;
    
        int getCharacterStrength() const;
        int getCharacterDexterity() const;
        int getCharacterConstitution() const;
        int getCharacterIntelligence() const;
        int getCharacterWisdom() const;
        int getCharacterCharisma() const;
    
        int getCharacterStrMod() const;
        int getCharacterDexMod() const;
        int getCharacterConMod() const;
        int getCharacterIntMod() const;
        int getCharacterWisMod() const;
        int getCharacterChaMod() const;
    
        int getSkillMod0() const;
        int getSkillMod1() const;
        string getBackgroundSkill0() const;
        string getBackgroundSkill1() const;
    
        virtual void setClassSkills(vector<string>) = 0;
        virtual void setCharacterClass() = 0;
        virtual void print(ostream&) const = 0;
    
};

#endif
