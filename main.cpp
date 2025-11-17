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

        return 0;
}
