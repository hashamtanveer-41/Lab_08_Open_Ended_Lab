#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayIntro();
int showMenu(int);
void stageOne(int &, int &, int []);
void stageTwo(int &, int &, int []);
void stageThree(int, int, int []);
bool playAgain();
void showStats(int, int);
void moveLocation(int&, int&);

// Global Variables
int energy = 100;
int reputation = 50;
int clues[3] = {0, 0, 0};
int stage = 1;
bool gameRunning = true;

int main() {
    srand(time(0));
        return 0;

}

void stageOne(int &energy, int &reputation, int clues[]){
    cout<<"\nYou are outside the study room.\n";
    cout<<"How do you want to enter?\n";
    cout<<"\n\n1. Ask the Buttler for the key? \033[1;33m(You may lose Energy)\033[0m\n";
    cout<<"2. Try to pich the lock \033[1;33m(you may lose Reputation and Energy)\033[0m\n";
    cout<<"\nReply with 1 or 2 to choose from the above: ";
    int choice;
    cin>>choice;
    switch(choice){
        case 1:
            energy -=3;
            cout<<"Buttler reluctantly hands you the key \033[1;31m(Your Energy decreased by 3)\033[0m\n";
            
            break;
        case 2:
            bool success;
            int random_value = rand() % 100;
            random_value < 70 ? success = true : success = false;
            if (success)
            {
                reputation += 5;
                energy -+ 5;
                cout<<"\n \033[1;32mNICE JOB!\033[0m You were successfull in picking the lock \033[1;32m(Your Reputation raied by 5)\033[0m\n";
                cout<<"You lost some energy in picking the lock \033[1;31m(You energy decreased by 5)\033[0m\n";
            }
            else {
                reputation -=10;
                energy -= 10;
                cout<<"\033[1;31mYou fail to pick the lock and damage the door.\033[0m\n";
                cout<<"\033[1;31myour Energy and Reputation decreased by 10\033[0m\n";
            }

             
    }
    cout<<"\n\nNear Lord Sterling’s desk lies a damp handkerchief embroidered with initials in the room (Clue 1)";
    clues[0] = 1;
    cout<<"\n\nYou are now searching the drawers....\n\n";
    int foundClue2 = rand() % 2;
    if (foundClue2 == 1)
    {   clues[1] =1;
        cout<< "discover a ledger hidden under a false drawer. (Clue 2)\n";
        cout<<"\033[1;32m(Your Reputation increased by 10)\033[0m";
    }
    else{
        cout<<"\nYou search the drawers, but find nothing unusual.";
    }
    

}
void showStats(int energy, int reputation){
    cout<<"---------Detective Status----------\n";
    cout<<"|\033[1;32m    Energy: "<<energy<<"                   \033[0m|"<<endl;
    cout<<"|\033[1;33m    Reputation: "<<reputation<<"                \033[0m|"<<endl;
    cout<<"------------------------------------";
}