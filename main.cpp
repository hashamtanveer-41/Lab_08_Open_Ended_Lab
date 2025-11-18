/*This is a C++ Detective game which provides the user with the scenario
  of case. The user is given certain options from which he has to choose the
  most appropriate one by using the hints or clues provided. The user plays
  role as detective. The wrong decisions cost the detective energy and loss in
  reputation. The user has to collect all the clues to successfully complete
  the mission.
 */

#include <iostream>
#include <ctime>


using namespace std;

// Functions prototypes declaration
void displayIntro();
int showMenu(int);
void stageOne(int &, int &, int []);
void stageTwo(int &energy, int &reputation, int clues[]);
void stageThree(int &energy, int &reputation, int []);
bool playAgain();
void showStats(int, int);
void moveLocation(int&, int&);

// Global Variables declaration
int energy = 100;
int reputation = 50;
int clues[4] = {0, 0, 0, 0};
int stage = 1;
bool gameRunning = true;

int main() {
    // Using srand for random number generation by using time as a seed
    srand(time(0));
    int choice;
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
    cout << "\033[1;33m------------------------------------------------------\033[0m\n";
    cout << "                     \033[33;44m Detective Game \033[0m\n";
    cout << "\033[1;33m------------------------------------------------------\033[0m\n\n";


    // Displaying scenario of case
    cout<<"-------------------Scenario---------------------"<<endl;
    cout << "Welcome detective to case of emerald heirloom.You are detective Sherlock holmes methodical investigator \n"
            "famous for solving murder mysteries. \n"
            "It is a foggy night at Ravenhurst Manor. Lord Oliver Sterling has been found dead \n"
            "in his locked study room. The only thing missing is the family's prized Emerald Heirloom.\n"
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
void stageOne(int &energy, int &reputation, int clues[]){
    cout<<"-------------------Stage One------------------"<<endl;
    cout<<"\nYou are standing outside the study room.\n";
    cout<<"How do you want to enter?\n";
    cout<<"\n1. Ask the Butler for the key? \033[1;33m(You may lose Energy)\033[0m\n";
    cout<<"2. Try to pitch the lock \033[1;33m(you may lose Reputation and Energy)\033[0m\n";
    cout<<"\nReply with 1 or 2 to choose from the above: ";
    int choice;
    cin>>choice;
    switch(choice){
        case 1:
            energy -=3;
            cout<<"Butler reluctantly hands you the key \033[1;31m(Your Energy decreased by 3)\033[0m\n";

            break;
        case 2:
            bool success;
            int random_value = rand() % 100;
            random_value < 70 ? success = true : success = false;
            if (success)
            {
                reputation += 5;
                energy -= 5;
                cout<<"\n \033[1;32mNICE JOB!\033[0m You were successfull in picking the lock \033[1;32m(Your Reputation raised by 5)\033[0m\n";
                cout<<"You lost some energy in picking the lock \033[1;31m(You energy decreased by 5)\033[0m\n";
            }
            else {
                reputation -=10;
                energy -= 10;
                cout<<"\033[1;31m You fail to pick the lock and damage the door.\033[0m\n";
                cout<<"\033[1;31m Your Energy and Reputation decreased by 10\033[0m\n";
            }
    }
    cout<<"\n\nNear Lord Sterling's desk lies a damp handkerchief embroidered with initials in the room (Clue 1)";
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
void stageTwo(int &energy, int &reputation, int []) {
    int choice;
    cout<<"-------------------Stage Two------------------"<<endl;
    cout << "Lady Evelyn sits quietly at her table"<<endl;
    cout << "Arthur Bellamy sits nearby"<<endl;

    cout << "............Who would you like to talk to?............."<<endl<<endl;
    cout << "1 .Interrogate lady"<<endl;
    cout << "2 .Interrogate Arthur"<<endl;
    cout << "3 .Investigate the dining room"<<endl;
    cout << "4 .Leave the dining"<<endl<<endl;
    cout << "Enter your choice: "<<endl;
    cin >> choice;
    while (choice<1|| choice>4) {
        cout << "Invalid choice. Enter your choice: "<<endl;
        cin >> choice;
    }
    switch (choice) {
        case 1:
            cout << "Go to the lady"<<endl<<endl;
            cout << "1. Ask her about where she was"<<endl;
            cout << "2. Accuse her of the charges"<<endl;
            int decision;
            cout << "Choose an option: "<<endl;
            cin >> decision;
            while (choice<1|| choice>2) {
                cout << "Invalid option. Enter your option: "<<endl;
                cin >> choice;
            }
            if (decision==1){
                if (clues[0]==0) {
                    cout << "She says I was in the resting room. With her voice trembling"<<endl;
                    clues[0]=1;
                    reputation+=20;
                    energy-=10;
                    cout << "clue gained: her voice is trembling"<<endl;
                    cout << "energy wasted = 10 joules"<<endl;
                    cout << "reputation gained = 20"<<endl;
                }
            }
            else if (decision==2){
                cout << "lady becomes angry and refuses to speak"<<endl;
                reputation-=20;
                energy-=10;
                cout << "energy wasted = 10 joules"<<endl;
                cout << "reputation lost = 20"<<endl;

            }

                else {
                    cout << "invalid option selected"<<endl;
                }
                break;

        case 2:
                int decision_1;
            cout << "go to arthur"<<endl<<endl;
            cout << "1 .Ask if he saw anyone in the study room "<<endl;
            cout << "2. Ask about the missing heirloom"<<endl;
                cout << "choose an option"<<endl;
                cin >> decision_1;
                if (decision_1==1){
                    if (clues[1]==0){
                        cout << "I heard footsteps near the study table. But I am not sure"<<endl;
                        clues[1]=1;
                        cout << "clue gained: footsteps near the study table"<<endl;
                        energy-=10;
                        reputation+=20;
                        cout << "energy wasted = 10 joules"<<endl;
                        cout << "reputation gained = 20"<<endl;

                    }
                }
                    else if (decision_1==2){
                        cout << "Arthur looks offended, because detective blamed him"<<endl;
                        energy-=10;
                        reputation-=20;
                        cout << "bad choice"<<endl;
                        cout << "energy wasted = 10 joules"<<endl;
                        cout << "reputation lost = 20"<<endl;;

                    }
                    else {
                        cout << "invalid entry"<<endl;

                    }
            break;

        case 3:
            cout << "detective goes into the dining room, but finds nothing"<<endl;
            energy-=10;
            cout << "energy wasted = 10 joules"<<endl;
            break;

        case 4:
            cout << "detective left the dining"<<endl;
            break;
        default:
            cout << "invalid option entered"<<endl;
    }
    cout << "stage 2 completed. Now on to the garden path"<<endl;

}

void stageThree(int &energy, int &reputation, int[]) {
    cout<<"-------------------Stage Three------------------"<<endl;
    int choice;
    cout << "You have step into the Garden Path."<<endl<<endl;
    cout << "Cold wind brushes past you."<<endl;
    cout << "This is the last chance to prove yourself"<<endl;


    cout << ".............What would you like to do?..............."<<endl<<endl;
    cout << "1. Inspect the muddy footprints"<<endl;
    cout << "2. Examine the broken fence"<<endl;
    cout << "3. Search behind the bushes (waste time)"<<endl;
    cout << "4. Leave the Garden Path (finish investigation)"<<endl;
    cout << "enter the choice"<<endl;
    cin >> choice;

    switch (choice) {
        case 1:
            if (clues[2] == 0) {
                cout << "you followed the muddy footprints."<<endl;
                cout << "they lead away from the Study toward the back fence."<<endl;
                clues[2] = 1;
                reputation += 20;
                energy-=10;
                cout << "energy lost = 10 joules"<<endl;
                cout << "reputation gained = 20"<<endl;
            }
            break;

        case 2:
            if (clues[3] == 0){
                cout << "You inspected the wooden fence."<<endl;
                cout << "The fence is cracked someone forced their way through."<<endl;
                clues[3] = 1;
                reputation += 20;
                energy-=10;
                cout << "energy lost = 10 joules"<<endl;
                cout << "reputation gained = 20"<<endl;
            }
            break;

        case 3:
            cout << "You search the bushes but find nothing useful."<<endl;
            energy-=10;
            cout << "energy lost = 10 joules"<<endl;
            break;

        case 4:
            cout << "You take one last look at the Garden Path. you have done all you could have and collected all the evidences ."<<endl;
            break;

        default:
            cout << "Invalid choice."<<endl;
            break;
    }
    cout << "stage 3 is finished and the game is over";
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
            cout<<"You are standing outside the Study Room. The air is humid and tense."<<endl;
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
    }
}
void showStats(int energy, int reputation){
    cout<<"---------Detective Status----------\n";
    cout<<"|\033[1;32m    Energy: "<<energy<<"                   \033[0m|"<<endl;
    cout<<"|\033[1;33m    Reputation: "<<reputation<<"                \033[0m|"<<endl;
    cout<<"------------------------------------";
}
