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
void moveLocation(int);


int main() {
    srand(time(0));
    displayIntro();
    return 0;
}
void displayIntro() {
    string begin;

    cout<<"------------------------------------------------"<<endl;
    cout<<"                 Detective Game"<<endl;
    cout<<"------------------------------------------------"<<endl<<endl;
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