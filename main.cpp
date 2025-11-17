/*This is a C++ Detective game which provides the user with the scenario
  of case. The user is given certain options from which he has to choose the
  most appropriate one by using the hints or clues provided. The user plays
  role as detective. The wrong decisions cost the detective energy and loss in
  reputation. The user has to collect all the clues to successfully complete
  the mission.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Functions prototypes declaration
void displayIntro();
int showMenu(int);
void stageOne(int &, int &, int []);
void stageTwo(int &, int &, int []);
void stageThree(int, int, int []);
bool playAgain();
void showStats(int, int);
void moveLocation(int&, int&);

// Global Variables declaration
int energy = 100;
int reputation = 50;
int clues[3] = {0, 0, 0};
int stage = 1;
bool gameRunning = true;

int main() {
    // Using srand for random number generation by using time as a seed
    srand(time(0));
    // Displaying game information by calling displayIntro function
    displayIntro();
    // Entering loop until user intentionally exits the game
    while (gameRunning) {
        // Displaying menu and taking the choice of user and storing it in choice
        int choice = showMenu(stage);
        // Using switch case to execute respective case according to choice of user
        switch (choice) {
            case 1:
                // Changing location by calling moveLocation function
                moveLocation(energy, stage);
                break;
            case 2:
                // Displaying the reputation and energy of detective
                showStats(energy, reputation);
                break;
            case 3:
                // Executing respective stage according to the user choice
                if (stage == 1) stageOne(energy, reputation, clues);
                else if (stage == 2)stageTwo(energy, reputation, clues);
                else stageThree(energy, reputation, clues);
                break;
            case 4: // Talking to suspect
                break;
            case 5:
                // Continuing investigation except in stage 3 we make final accusation
                if (stage==3) stageThree(energy, reputation, clues);
                else cout << "Keep searching for more clues!\n";
                break;
            case 6:
                // Exiting the game
                cout<<"Thank you for playing."<<endl;
                gameRunning=false;
                break;
        }
    }
        return 0;

}
// Displaying game information to user. Information includes scenario, objective, game instructions, character and
// location information. After each section user is prompted to enter any key to proceed.
void displayIntro(){
    string begin;
    // Displaying header of detective game
    cout<<"------------------------------------------------"<<endl;
    cout<<"                 Detective Game"<<endl;
    cout<<"------------------------------------------------"<<endl<<endl;

    // Displaying scenario of case
    cout<<"-------------------Scenario---------------------"<<endl;
    cout << "Welcome detective to case of emerald heirloom.You are detective Sherlock holmes methodical investigator \n"
            "famous for solving murder mysteries. \n"
            "It is a foggy night at Ravenhurst Manor. Lord Oliver Sterling has been found dead \n"
            "in his locked study room. The only thing missing is the family’s prized Emerald Heirloom.\n"
            "You are called to uncover the hidden truth before dawn.\n"
            "Time is short, energy is limited and every wrong decision will cost you \n"
            "your reputation.\n"<<endl;
    // Prompting the user any key and then press enter to proceed to next section
    cout<<"(Press any key and enter to continue)";
    cin>>begin;

    // Displaying Objective of case
    cout<<"--------------------Objective---------------------"<<endl;
    cout<<"Your goal is to investigate the manor, question suspects and uncover \n"
          "clues to find the real killer before your energy runs out.\n"<<endl;
    cout<<"(Press any key and enter to continue)";
    cin>>begin;

    // Displaying game instructions which the user must follow
    cout<<"-------------------Game Instructions------------------"<<endl;
    cout<<"Player is suggested to follow the following rules: \n"
          "1. Type the number for your chosen action (1-5)\n"
          "2. Moving between rooms or investigating consumes Energy.\n"
          "3. Making correct deductions increases Reputation\n"
          "4. Collect clues to strengthen your final accusation.\n"
          "5. Wrong choices or running out of Energy means you lose.\n"
          "6. To make final accusations, you have to complete all the locations.\n"<<endl;
    cout<<"(Press any key and enter to continue)";
    cin>>begin;

    // Displaying information of Characters and Locations in house
    cout<<"-------------------Character and Location Introduction------------------"<<endl;
    cout<<"Following are short introductions about characters: \n"
          "\t1.Lady Evelyn Sterling (the widow): Calm but distant\n"
          "\t2. Arthur Bellamy (the butler): loyal but secretive\n "
          "Following is info about Ravenhurst Manor Locations: \n"
          "\t1.The Grand Hall(base)\n"
          "\t2.The Study Room (crime scene)\n"
          "\t3.The dining Room(suspect area)\n"
          "\t4.The Garden Path(hidden clue area)\n"<<endl;
    cout<<"(Press any key and enter to continue)";
    cin>>begin;
}

// This function displays the menu to the user and prompts him/her to make the choice and returns the choice
int showMenu(int stage) {
    int choice;
    // Displaying menu to the user
    cout << "\nChoose your next action:\n"
    "1. Move to another location\n"
    "2. Check your current status\n"
     "3. Investigate the area\n"
     "4. Talk to a suspect\n";
    if (stage==3) cout<<"5. Make a final accusation\n";
    else cout<<"5.Continue investigation\n";
     cout<<"6. Exit Game\n";
    // Prompting user to enter his/her choice
    cout<<"Enter your choice(1 to 6): "<<endl;
    cin>>choice;
    // Validating the input of the user
    while (choice<1||choice>6) {
        cout<<"Invalid action.Enter your choice: "<<endl;
        cin>>choice;
    }
    return choice;
}

// This function enables the user to move to other locations of house. Function displays the different locations
// and prompts the user to choose the locations
void moveLocation(int& energy, int& stage) {
    int choice;
    // Displaying the locations
    cout<<"Select the location: \n"
          "1. Study Room \n"
          "2. Dining Room \n"
          "3. Garden Path \n";
    // Prompting the user to enter the desired location
    cout<<"Enter your choice: "<<endl;
    cin>> choice;
    // Validating the input of the user
    while (choice<1||choice>3) {
        cout<<"Invalid choice. Enter your choice: "<<endl;
        cin>> choice;
    }
    // Depleting energy as moving to new location will cost some amount of energy
     energy -=5;
    // Checking if the energy is less than a certain level then the user is unable to move to new location
    if (energy<=10)cout<<"You are feeling exhausted. Solve as soon as possible. ";
    // Executing specific case according to the choice of the user
    switch (choice) {
        case 1:
            // Entering the study room.
            cout<<"You have entered Study Room. The air is humid and tense."<<endl;
            if (stage==1) {
                cout<<"You will start your first interrogation."<<endl;
                // Assigning the value of stage to 1
                stage =1;
            }
            break;
        case 2:
            // Entering the user to Dining room
            cout<<"You are in Dining room. The staff manager stands by nervously."<<endl;
            if (stage<2) {
                // Assigning the value of stage to 2
                stage=2;
                cout<<"Suspect interrogation stage has unlocked.";
            }
            break;
        case 3:
            // Entering the Garden
            cout<<"You follow the path to the garden. Its cold air blowing...."<<endl;
            if (stage<3) {
                // Assigning the value of stage to 3
                stage = 3;
                cout<<"Final stage: The truth is waiting! "<<endl;
            }
            break;
    }
}
