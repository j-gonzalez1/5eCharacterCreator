//Jose Luis Gonzalez
//CSIS 137
//Final Project
//December 14, 2020


#ifndef Rogue_h
#define Rogue_h

#include "Adventurer.h"

class Rogue: public Adventurer
{
    private:
        Attack firstAttack;
        Attack secondAttack;
        string characterClass;
        string equip0;
        string equip1;
        string equip2;
        string equip3;
        string equip4;
        string equip5;
        string equip6;
        string equip7;
        string equip8;
        string equip9;
        string equip10;
    
        string skill2;
        string skill3;
        string skill4;
        string skill5;
        string feat0;
        string feat1;
        vector<string> classSkills;
        vector<string> characterEquip;
    
    public:
        Rogue(string = "", int = 0, string = "", int = 0, string = "", string = "", string = "", Attack=Attack(), Attack=Attack());
        ~Rogue();
        virtual void setCharacterClass();
        virtual void setClassSkills(vector<string>);
        virtual void setCharacterEquipment(vector<string>);
        void setClassFeats();
        
        string getCharacterClass() const;
        string getCharacterEquip0() const;
        string getCharacterEquip1() const;
        string getCharacterEquip2() const;
        string getCharacterEquip3() const;
        string getCharacterEquip4() const;
        string getCharacterEquip5() const;
        string getCharacterEquip6() const;
        string getCharacterEquip7() const;
        string getCharacterEquip8() const;
        string getCharacterEquip9() const;
        string getCharacterEquip10() const;
    
        string getCharacterSkill2() const;
        string getCharacterSkill3() const;
        string getCharacterSkill4() const;
        string getCharacterSkill5() const;
        string getClassFeat0() const;
        string getClassFeat1() const;
        virtual void print(ostream&) const;
};

#endif /* Rogue_h */
