//Jose Luis Gonzalez
//CSIS 137
//Final Project
//December 14, 2020

#ifndef Attack_h
#define Attack_h

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class Attack
{
    friend ostream& operator<<(ostream&, const Attack&);
    
private:
    string attackName;
    string ability;
    string range;
    string toHit;
    string damage;
    string damageType;
    string notes;
    vector<vector<string>> weapons;
    
public:
    Attack(int = 0);
    ~Attack();
    Attack& setAttackName (string);
    Attack& setAbility (string);
    Attack& setRange (string);
    Attack& setToHit (string);
    Attack& setDamage (string);
    Attack& setDamageType (string);
    Attack& setNotes (string);
    
    string getAttackName () const;
    string getAbility () const;
    string getRange () const;
    string getToHit () const;
    string getDamage () const;
    string getDamageType () const;
    string getNotes () const;
    
    void print () const;
};

#endif /* Attack_h */
