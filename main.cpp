//Jose Luis Gonzalez
//CSIS 137
//Final Project
//December 14, 2020

#include "Fighter.h"
#include "Rogue.h"
#include "Wizard.h"

int main()
{
    Attack first, second;
    int sheetNum = 0;
    char selection;
    ofstream outFile;
    string characterName;
    string playerName;
    
    cout << "Welcome to the D&D Character Creation Program!" << endl
         << "----------------------------------------------\n" << endl
    << "Please enter your name: " << endl;
    getline(cin, playerName);
    
    do
    {
        cout << endl
        << "Choose a character class: " << endl
        << "1) Make a Fighter" << endl
        << "2) Make a Rogue" << endl
        << "3) Make a Wizard" << endl
        << "Q) Quit." << endl
        << "Please make a selection: \n" << endl;
        cin >> selection;
        cin.ignore();
        
        
        if (selection == '1')
        {
            Fighter newAdv("Character Name", 100, "Race", 1, "Background", "Alignment", playerName, 1, 2);
            newAdv.setCharacterClass();
            newAdv.print(cout);
            cout << endl;
            
            cout << "What would you like to name your character? \n" << endl;
            getline(cin, characterName);
            cout << endl;
            cout << endl;
            newAdv.setCharacterName(characterName);
            newAdv.print(cout);
            cout << endl;
            
            cout << "Would you like to save your character? Y or N? \n" << endl;
            cin >> selection;
            cin.ignore();
            if (selection == 'y' || selection == 'Y')
            {
                outFile.open(newAdv.setFileName(characterName, sheetNum), ios::out);
                sheetNum++;
                newAdv.print(outFile);
                outFile.close();
                cout << "\n" << characterName << " has been save to " << characterName << sheetNum <<".txt\n" << endl;
            }
            cout << endl;
            
        }
        else if (selection == '2')
        {
            Rogue newAdv("Character Name", 100, "Race", 1, "Background", "Alignment", playerName, 3, 4);
            newAdv.setCharacterClass();
            newAdv.print(cout);
            cout << endl;
            
            cout << "What would you like to name your character? \n" << endl;
            getline(cin, characterName);
            cout << endl;
            cout << endl;
            newAdv.setCharacterName(characterName);
            newAdv.print(cout);
            cout << endl;
            
            cout << "Would you like to save your character? Y or N? \n" << endl;
            cin >> selection;
            cin.ignore();
            if (selection == 'y' || selection == 'Y')
            {
                outFile.open(newAdv.setFileName(characterName, sheetNum), ios::out);
                sheetNum++;
                newAdv.print(outFile);
                outFile.close();
                cout << "\n" << characterName << " has been save to " << characterName << sheetNum <<".txt\n" << endl;
            }
            cout << endl;
        }
        else if (selection == '3')
        {
            Wizard newAdv("Character Name", 100, "Race", 1, "Background", "Alignment", playerName);
            newAdv.setCharacterClass();
            newAdv.print(cout);
            cout << endl;
            
            cout << "What would you like to name your character? \n" << endl;
            getline(cin, characterName);
            cout << endl;
            cout << endl;
            newAdv.setCharacterName(characterName);
            newAdv.print(cout);
            cout << endl;
            
            cout << "Would you like to save your character? Y or N? \n" << endl;
            cin >> selection;
            cin.ignore();
            if (selection == 'y' || selection == 'Y')
            {
                outFile.open(newAdv.setFileName(characterName, sheetNum), ios::out);
                sheetNum++;
                newAdv.print(outFile);
                outFile.close();
                cout << "\n" << characterName << " has been save to " << characterName << sheetNum <<".txt\n" << endl;
            }
            cout << endl;
        }
        else if (selection != 'q' && selection != 'Q')
        {
            cout << "Invalid selection.\n" << endl;
        }
    }while (selection != 'q' && selection != 'Q');
    {
        cout << "You have chosen to quit. Thank you for using the program!" << endl;
    }

    return 0;
}
