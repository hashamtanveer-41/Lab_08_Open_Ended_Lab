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
   // displayIntro();
    // while (gameRunning) {
    //     int choice = showMenu(stage);
    //     switch (choice) {
    //         case 1:
    //             moveLocation(energy, stage);
    //             break;
    //         case 2:
    //             showStats(energy, reputation);
    //             break;
    //         case 3:
    //             if (stage == 1) stageOne(energy, reputation, clues);
    //             else if (stage == 2)stageTwo(energy, reputation, clues);
    //             else stageThree(energy, reputation, clues);
    //             break;
    //         case 4: break;
    //         case 5:
    //             if (stage==3) stageThree(energy, reputation, clues);
    //             else cout << "Keep searching for more clues!\n";
    //             break;
    //         case 6:
    //             cout<<"Thank you for playing."<<endl;
    //             gameRunning=false;
    //             break;
    //     }
    // }
    showStats(energy, reputation);
    stageOne(energy, reputation, clues);
        return 0;

}
void displayIntro(){
    string begin;

    cout<<"\033[1;33m------------------------------------------------\033[0m"<<endl;
    cout<<"                 \033[33;44m Detective Game \033[0m"<<endl;
    cout<<"\033[1;33m------------------------------------------------\033[0m"<<endl<<endl;
    cout<<"-------------------Scenario---------------------"<<endl;
    cout << "Welcome detective to case of emerald heirloom.You are detective Sherlock holmes methodical investigator \n"
            "famous for solving murder mysteries. \n"
            "It is a foggy night at Ravenhurst Manor. Lord Oliver Sterling has been found dead \n"
            "in his locked study. The only thing missing is the family’s prized Emerald Heirloom.\n"
            "You are called to uncover the hidden truth before dawn.\n"
            "Time is short, energy is limited and every wrong decision will cost you \n"
            "your reputation.\n"<<endl;
    cout<<"(Press any key to continue)";
    cin>>begin;
    cout<<"--------------------Objective---------------------"<<endl;
    cout<<"Your goal is to investigate the manor, question suspects and uncover \n"
          "clues to find the real killer before your energy runs out.\n"<<endl;
    cout<<"(Press any key to continue)";
    cin>>begin;
    cout<<"-------------------Game Instructions------------------"<<endl;
    cout<<"Player is suggested to follow the following rules: \n"
          "1. Type the number for your chosen action (1-5)\n"
          "2. Moving between rooms or investigating consumes Energy.\n"
          "3. Making correct deductions increases Reputation\n"
          "4. Collect clues to strengthen your final accusation.\n"
          "5. Wrong choices or running out of Energy means you lose.\n"<<endl;
    cout<<"(Press any key to continue)";
    cin>>begin;
    cout<<"-------------------Character and Location Introduction------------------"<<endl;
    cout<<"Following are short introductions about characters: \n"
          "\t1.Lady Evelyn Sterling (the widow): Calm but distant\n"
          "\t2. Arthur Bellamy (the butler): loyal but secretive\n "
          "Following is info about Ravenhurst Manor Locations: \n"
          "\t1.The Grand Hall(base)\n"
          "\t2.The Study Room (crime scene)\n"
          "\t3.The dining Room(suspect area)\n"
          "\t4.The Garden Path(hidden clue area)\n"<<endl;
    cout<<"(Press any key to continue)";
    cin>>begin;
}
int showMenu(int stage) {
    int choice;
    cout << "\nChoose your next action:\n"
    "1. Move to another location\n"
    "2. Check your current status\n"
     "3. Investigate the area\n"
     "4. Talk to a suspect\n";
    if (stage==3) cout<<"5. Make a final accusation\n";
    else cout<<"5.Continue investigation\n";
     cout<<"6. Exit Game\n";
    cout<<"Enter your choice(1 to 6): "<<endl;
    cin>>choice;
    while (choice<1||choice>6) {
        cout<<"Invalid action.Enter your choice: "<<endl;
        cin>>choice;
    }
    return choice;
}
void moveLocation(int& energy, int& stage) {
    int choice;
    cout<<"Select the location: \n"
          "1. Study Room \n"
          "2. Dining Room \n"
          "3. Garden Path \n";
    cout<<"Enter your choice: "<<endl;
    cin>> choice;
    while (choice<1||choice>3) {
        cout<<"Invalid choice. Enter your choice: "<<endl;
        cin>> choice;
    }
     energy -=5;
    if (energy<=10)cout<<"You are feeling exhausted. Solve as soon as possible. ";
    switch (choice) {
        case 1:
            cout<<"You have entered Study Room. The air is humid and tense."<<endl;
            if (stage==1) {
                cout<<"You will start your first interrogation."<<endl;
                stage =1;
            }
            break;
        case 2:
            cout<<"You are in Dining room. The staff manager stands by nervously."<<endl;
            if (stage<2) {
                stage=2;
                cout<<"Suspect interrogation stage has unlocked.";
            }
            break;
        case 3:
            cout<<"You follow the path to the garden. Its cold air blowing...."<<endl;
            if (stage<3) {
                stage = 3;
                cout<<"Final stage: The truth is waiting! "<<endl;
            }
            break;
    }
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