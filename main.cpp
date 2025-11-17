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
void stageTwo(int &energy, int &reputation, int []);
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

// Global Variables
int energy = 100;
int reputation = 50;
int clues[3] = {0, 0, 0};
int stage = 1;
bool gameRunning = true;

int main() {
    // Using srand for random number generation by using time as a seed
    srand(time(0));
    int choice;
    return 0;


}

void stageTwo(int &energy, int &reputation, int []) {
int choice;

    cout << "you are in the dining room"<<endl<<endl;
    cout << "lady Evelyn sits quietly at her table"<<endl;
    cout << "Arthur Bellamy sits nearby"<<endl;

    cout << "............who would you like to talk to ?............."<<endl<<endl;
    cout << "1 .Interrogate lady"<<endl;
    cout << "2 .Interrogate Arthur"<<endl;
    cout << "3 .Investigate the dining room"<<endl;
    cout << "4 .Leave the dining"<<endl<<endl;
    cout << "Enter the choice"<<endl;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "go to the lady"<<endl<<endl;
            cout << "1. ask her about where she was"<<endl;
            cout << "2. accuse her of the charges"<<endl;
            int decision;
            cout << "choose an option"<<endl;
            cin >> decision;
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
