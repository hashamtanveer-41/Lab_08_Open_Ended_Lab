# Detective Game: The Case of Emerald Heirloom

## Team Members
* **Asfand Khan (554959)** - Worked on Stage 2 and 3 logic (Garden and Dining room) and made the flowcharts.
* **Hasham Tanveer (573341)** - Managed the GitHub repository, fixed merge conflicts, and did the final testing.
* **Muhammad Hamza (553436)** - Worked on Stage 1, the main menu, and the lock-picking probability logic.

## Overview
This is a text-based detective game we made for our FoCP Lab project. The player takes the role of "Sherlock Holmes" to solve a murder case and find a missing heirloom.

The game has three main stages. You have to make the right choices to keep your **Reputation** high and manage your **Energy**. If your energy runs out or you make too many wrong accusations, you lose the game.

## Game Flow

1. **Introduction**
   The game starts with the displayIntro() function which explains the story, introduces the characters (Lady Evelyn and Arthur), and shows the rules.

2. **Main Menu**
   We used a while loop to keep the game running. The player can choose to move locations, check their stats, or talk to suspects using a switch statement.

3. **The Stages**
   * **Stage 1 (Study Room):** You have to enter the room. You can ask for a key or try to pick the lock. We used the rand() function to give a 70% chance of success for picking the lock.
   * **Stage 2 (Dining Room):** You interrogate the suspects. If you ask the wrong questions, they get angry and you lose reputation.
   * **Stage 3 (Garden Path):** This is where you find the final clues like footprints.

4. **Final Accusation**
   To win, you need to collect three specific clues: the Handkerchief, the Ledger, and the Footprints. If you have them all stored in the clues array, you can accuse the Butler and win.

## How the Code Works

* **Functions:** We split the code into functions like stageOne(), stageTwo(), and showStats() so the main function is clean and so the program has modularity as per the Open ended lab requirements.
* **Pass-by-Reference:** We used pass-by-reference so that when energy is lost inside a stage function, it updates the real variable in the main game loop.
* **Arrays:** We used a simple array called clues[4] to keep track of what evidence the player has found.
* **Random Numbers:** We used srand(time(0)) to seed the random number generator. This makes sure the lock-picking result is different every time you play.

## Challenges
The main issue we had to make such modular program working because we had to call different functions in main as well as a function called inside another function. Such complex calls make th Game flow a bit difficult t oraganize but at last we had it done. And now it has a consistent flow.

Also, we thought not to make the game boring so we added some ANSI color codes (like making text red or yellow) to make the warnings stand out.
