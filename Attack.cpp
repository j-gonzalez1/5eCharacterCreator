//Jose Luis Gonzalez
//CSIS 137
//Final Project
//December 14, 2020


#include "Attack.h"


//Overloaded <<
ostream& operator<<(ostream& output, const Attack& a)
{
    
    output << setw(12) << " " + a.attackName <<setw(11) << "|" + a.range + " |  " << setw(2) << a.toHit << "  |  " << setw(3) << a.damage << "   |";
    return output;
}

//Consructor
Attack::Attack(int cClass)
{
    vector<vector<string>> weapons
    {
        {" Longsword ", "  Melee  ", "+2", "1d8", "Versatile (1d10)"},
        {"  Handaxe  ", " 20/60 ft", "+2", "1d6", "Light, thrown"},
        {"   Punch   ", "  Melee  ", "+2", " 1 ", ""},
        {"   Rapier  ", "  Melee  ", "+2", "1d8", "Finesse"},
        {"  Shortbow ", "80/320 ft", "+2", "1d6", "Quiver of 20 arrows"},
        {"  Dagger   ", " 20/60 ft", "+2", "1d4", "Finesse, light, thrown"},
        {"  Staff    ", "  Melee  ", "+2", "1d6", "Versatile (1d8)"},
    };

    setAttackName (weapons[cClass][0]);
    setRange (weapons[cClass][1]);
    setToHit (weapons[cClass][2]);
    setDamage (weapons[cClass][3]);
    setNotes (weapons[cClass][4]);
}

//Destructor
Attack::~Attack()
{
    
}

//Set Functions
Attack& Attack::setAttackName (string aName)
{
    attackName = aName;
    return *this;
}

Attack& Attack::setAbility (string aAbility)
{
    ability = aAbility;
    return *this;
}

Attack& Attack::setRange (string aRange)
{
    range = aRange;
    return *this;
}

Attack& Attack::setToHit (string aToHit)
{
    toHit = aToHit;
    return *this;
}

Attack& Attack::setDamage (string aDamage)
{
    damage = aDamage;
    return *this;
}

Attack& Attack::setDamageType (string aDamageType)
{
    damageType = aDamageType;
    return *this;
}

Attack& Attack::setNotes (string aNotes)
{
    notes = aNotes;
    return *this;
}


//Get Functions
string Attack::getAttackName () const
{
    return attackName;
}
string Attack::getAbility () const
{
    return ability;
}
string Attack::getRange () const
{
    return range;
}
string Attack::getToHit () const
{
    return toHit;
}
string Attack::getDamage () const
{
    return damage;
}
string Attack::getDamageType () const
{
    return damageType;
}
string Attack::getNotes () const
{
    return notes;
}

void Attack::print () const
{
    cout << attackName << "|" << ability << "|" << range << "|" << toHit << "|" << damage << "|" << damageType
         << "\n" << notes << endl;
}
