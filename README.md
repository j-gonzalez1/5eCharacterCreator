# 5eCharacterCreator

Adv Programming in C/C++
Final Project
Fall 2020

For my final project, I wrote a character creation program for Dungeons & Dragons. My program has a base class called Adventurer that has three pure virtual methods. The Adventurer class contains an object of the Attack class as a member (Composition). There three derived classes of Adventurer: Fighter, Rogue, and Wizard (Inheritance). They have their own implementations of the Adventurer’s three virtual methods (Polymorphism). 

The user is able to input their name, choose a character class from the main menu, and the program creates a character for the user using a series of vectors and arrays. Some of the data is randomly chosen from the vectors and arrays. The character sheet prints to the screen by passing an ostream instance by reference. The user is then asked to name the character and prompted with the option to save the character sheet (Files) so they can print it out and use it to play Dungeons & Dragons. The character sheet is saved to a txt file in the default directory using the same print function as before. This time, the print function is called with an ofstream instance. The program will allow the user to create/name/save characters until the user chooses to quit from the menu.

I originally planned to have four derived classes but I decided that the Barbarian and the Fighter were too similar so I left out the Barbarian. I added the ability to use the print function to print to the screen and save to a file during programming. It didn’t make sense to me to repeat all of that code so I looked online and found a way to make it work.

Currently, the program creates simplified versions of 5th Edition Dungeons & Dragons characters. I would like to add more functionality and variety to allow users to create fully-formed characters.
