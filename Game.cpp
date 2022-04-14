#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Monster.h"
using namespace std;

int main(){
    int character = 0, trial = 1;
    srand(time(0));                                                                  //for random number generating

    Data *player;                                                                    //create a dynamic array for the player
    player = new Data[1];

    Data *monster;
    monster = new Data[1];                                                           //create a dynamic array for the monster

    cout << "=======WELCOME TO THE FIGHT GAME.=======" << endl << endl;
        cout << "Choose a character." << endl << "1.KNIGHT 2.MAGE 3.ASSASSIN 4.SHOOTER" << endl << endl;
        cout << "Your choice: ";
        cin >> character;
        cout << endl;
        while (true){                                                          //player choice between 1 and 4, different characters
          if (character == 1)
          {
            cout << "You have chosen the KNIGHT." << endl;
            player[0].HP=500;
            player[0].MP=100;
            player[0].ATK=50;
            player[0].DEF=20;
            player[0].AVD=10;
            player[0].CRT=30;
            break;
          }

          else if (character == 2)
          {
            cout << "You have chosen the MAGE." << endl;
            player[0].HP=250;
            player[0].MP=200;
            player[0].ATK=20;
            player[0].DEF=10;
            player[0].AVD=10;
            player[0].CRT=20;
            break;
          }

          else if (character == 3)
          {
            cout << "You have chosen the ASSASSIN." << endl;
            player[0].HP=350;
            player[0].MP=120;
            player[0].ATK=40;
            player[0].DEF=15;
            player[0].AVD=20;
            player[0].CRT=25;
            break;
          }

          else if (character == 4)
          {
            cout << "You have chosen the SHOOTER." << endl;
            player[0].HP=300;
            player[0].MP=130;
            player[0].ATK=60;
            player[0].DEF=10;
            player[0].AVD=10;
            player[0].CRT=20;
            break;
          }

          else
          {
            cout << "Invalid choice. Please choose again." << endl;
          }

    }


    cout << "HP: " << player[0].HP << endl << "MP: " << player[0].MP << endl << "Attack: " << player[0].ATK << endl << "Defense: " << player[0].DEF << endl << "Avoid: " << player[0].AVD << endl << "Critical: " << player[0].CRT << endl << "============================================" << endl;

    int choice = rand() % 3 + 1;                                                    //generated random number between 1 and 3 to decide which monster will appear
    switch (choice){
      case 1:                                                                       //monster 1 appears if random number generated is 1
        cout << "A wild ZOMBIE has appeared!" << endl;
        monster[0].HP= 450;
        monster[0].MP= 100;
        monster[0].ATK= 30;
        monster[0].DEF= 20;
        break;

      case 2:                                                                       //monster 2 appears if random number generated is 2
        cout << "A wild GOLEM has appeared!" << endl;
        monster[0].HP= 470;
        monster[0].MP= 20;
        monster[0].ATK= 40;
        monster[0].DEF= 30;
        break;

      case 3:                                                                       //monster 3 appears if random number generated is 3
        cout << "A wild OAK has appeared!" << endl;
        monster[0].HP= 430;
        monster[0].MP= 60;
        monster[0].ATK= 60;
        monster[0].DEF= 10;
        break;
    }
    cout << "Monster HP: " << monster[0].HP << endl << "Monster MP: " << monster[0].MP << endl << "Monster Attack: " << monster[0].ATK << endl << "Monster Defense: " << monster[0].DEF << endl;

    int playerChoice;
    int playerSkillChoice;

    while (player[0].HP > 0 && monster[0].HP > 0){
        cout << "============================================" << endl;
        cout << "Remaining player HP: " << player[0].HP << endl << "Remaining player MP: " << player[0].MP << endl << endl;
        cout << "Remaining monster HP: " << monster[0].HP << endl << "Remaining monster MP: " << monster[0].MP << endl;
        cout << "============================================" << endl;
        cout << "What action will the player take?" << endl << "1.AUTO ATTACK 2.SKILLS 3.FLEE" << endl << endl;

        ofstream fout;
        fout.open("Game_Status.txt", ios::app);

        if (fout.fail()){                                                          //check if there is no error in the file, exit if so
         cout << "File does not exist" << endl;
         exit(1);
        }
        cout << "Your Choice: ";
        cin >> playerChoice;
        cout << endl;

        player_action(character, playerChoice, player, monster);                   //calls the function to choose an action for the player

        int monsterChoice = rand() % 2;                                                //generates random number between 0 and 1 to decide which action the monster will take, 0 auto attack and 1 use skills
        monster_action(character,monsterChoice,monster,player);                              //calls the function to choose an action for the monster

        fout << "Trial: " << trial << endl;
        fout << "Player HP: " << player[0].HP << " " << " Player MP: " << player[0].MP << endl;
        fout << "Monster HP: " << monster[0].HP << " " << " Monster MP: " << monster[0].MP << endl;

        trial += 1;

        fout.close();    //close file
    }


    if (monster[0].HP <= 0){                                                      //monster hp below 0
        cout << "You have defeated the monster!" << endl << "VICTORY!" << endl << "Game Terminated." << endl;
    }

    else if (player[0].HP <= 0){                                                  //player hp below 0
        cout << "You have been defeated by the monster!" << endl << "DEFEAT!" << endl << "Game Terminated." << endl;
    }

    delete [] player;                                                             //use delete to free the dynamic array
    delete [] monster;

    return 0;

}

// 파일 분리 .h .cpp makefile 아몰랑 용현이가 알아서 하겠지.. (req.5)
// File input/output (loading/saving game status) 아몰랑 용현이가 알아서 하곘지..(req.2,4)
// readme.md 업데이트 Compilation and execution instructions ('Quick start' of the game)
// video demonstration
