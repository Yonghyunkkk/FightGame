#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
using namespace std;

void player_action(int character,int playerChoice, Data player[], Data monster[]){
     int playerSkillChoice = 0;
     int CRT;
     switch (playerChoice){                                                     //player choice between 1 and 3, different actions

          case 1:
	                                                                         //if the player chooses action 1: auto attack
            CRT = rand() % 101 + player[0].CRT;                                      //generates random number from 0 to 100, if add up with playerCRT greater than 100, then critical hit

            if (CRT > 100)
            {
              player[0].DMG = player[0].ATK * 1.3 - monster[0].DEF;
              monster[0].HP -= player[0].DMG;
              cout << "Critical hit!!! Damage: " << player[0].DMG << endl;
            }

            else
            {
              player[0].DMG = player[0].ATK - monster[0].DEF;
              monster[0].HP -= player[0].DMG;
              cout << "You have attacked the monster! Damage: " << player[0].DMG << endl;
            }
            break;

          case 2:                                                               //if the player chooses action 2: use skills
            cout << "Which skill will you use?" << endl;

            if (character == 1){                                                //if the player chooses character 1
              cout << "1. ALPHA STRIKE (Damage: 90, Mana Required: 40) / 2. JUDGMENT (Damage: 70, Mana Required: 20) / 3. MEDITATE (HP +30, Mana Required: 20)" << endl << endl;
              cout << "Your Choice: ";
              cin >> playerSkillChoice;
              cout << endl;
              switch (playerSkillChoice)
              {                                                                 //player choice between 1 and 3, different skills used
                case 1:                                                         //if the player chooses skill 1 of char 1
                  if (player[0].MP >= 40)
                  {
                    player[0].DMG = 90 - monster[0].DEF;
                    monster[0].HP -= player[0].DMG;
                    player[0].MP -= 40;
                    cout << "Player's ALPHA STRIKE! Damage: " << player[0].DMG << endl;
                  }

                  else
                  {
                    cout << "Not enough MP" << endl;
                  }
                  break;

                case 2:                                                         //if the player chooses skill 2 of char 1
                  if (player[0].MP >= 20)
                  {
                    player[0].DMG = 70 - monster[0].DEF;
                    monster[0].HP -= player[0].DMG;
                    player[0].MP -= 20;
                    cout << "Player's JUDGMENT! Damage: " << player[0].DMG << endl;
                  }
                  else
                  {
                    cout << "Not enough MP" << endl;
                  }
                  break;

                case 3:                                                         //if the player chooses skill 3 of char 1
                  if (player[0].MP >= 20)
                  {
                    player[0].HP += 30;
                    player[0].MP -= 20;
                    cout << "Player's MEDITATE! HP + " << player[0].HP << endl;
                  }
                  else
                  {
                    cout << "Not enough MP" << endl;
                  }
                  break;

                default:
                  cout << "Invalid choice." << endl;
                  break;
              }
            }



            else if (character == 2){                                           //if the player chooses character 2
              cout << "1. ETHEREAL CHAINS (Damage: 80, Mana Required: 50) / 2. DISTORTION (Damage: 40, Mana Required: 30) / 3. SHIELD (HP +40, Mana Required: 20)" << endl << endl;
              cout << "Your Choice: ";
              cin >> playerSkillChoice;
              cout << endl;

              switch (playerSkillChoice){                                       //player choice between 1 and 3, different skills used
                case 1:                                                         //if the player chooses skill 1 of char 1
                  if (player[0].MP >= 50)
                  {
                    player[0].DMG = 80 - monster[0].DEF;
                    monster[0].HP -= player[0].DMG;
                    player[0].MP -= 50;
                    cout << "Player's ETHEREAL CHAINS! Damage: " << player[0].DMG << endl;
                  }

                  else
                  {
                    cout << "Not enough MP" << endl;
                  }
                  break;

                case 2:                                                         //if the player chooses skill 2 of char 2
                  if (player[0].MP >= 30)
                  {
                    player[0].DMG = 40 - monster[0].DEF;
                    monster[0].HP -= player[0].DMG;
                    player[0].MP -= 30;
                    cout << "Player's DISTORTION! Damage: " << player[0].DMG << endl;
                  }
                  else
                  {
                    cout << "Not enough MP" << endl;
                  }
                  break;

                case 3:                                                         //if the player chooses skill 3 of char 2
                  if (player[0].MP >= 20)
                  {
                    player[0].HP += 40;
                    player[0].MP -= 20;
                    cout << "Player's SHIELD! HP + " << player[0].HP << endl;
                  }
                  else {
                    cout << "Not enough MP" << endl;
                  }
                  break;

                default:
                  cout << "Invalid choice." << endl;
                  break;
              }
            }



            else if (character == 3){                                           //if the player chooses character 3
              cout << "1. RAZOR SHURIKEN (Damage: 60, Mana Required: 30) / 2. SHADOW SLASH (Damage: 50, Mana Required: 20) / 3. DODGE (HP +30, Mana Required: 20)" << endl << endl;
              cout << "Your Choice: ";
              cin >> playerSkillChoice;
              cout << endl;

              switch (playerSkillChoice){                                       //player choice between 1 and 3, different skills used
                case 1:                                                         //if the player chooses skill 1 of char 3
                  if (player[0].MP >= 30)
                  {
                    player[0].DMG = 60 - monster[0].DEF;
                    monster[0].HP -= player[0].DMG;
                    player[0].MP -= 30;
                    cout << "Player's RAZOR SHURIKEN! Damage: " << player[0].DMG << endl;
                  }
                  else
                  {
                    cout << "Not enough MP" << endl;
                  }
                  break;

                case 2:                                                         //if the player chooses skill 2 of char 3
                  if (player[0].MP >= 20)
                  {
                    player[0].DMG = 50 - monster[0].DEF;
                    monster[0].HP -= player[0].DMG;
                    player[0].MP -= 20;
                    cout << "Player's SHADOW SLASH! Damage: " << player[0].DMG << endl;
                  }
                  else
                  {
                    cout << "Not enough MP" << endl;
                  }
                  break;

                case 3:                                                         //if the player chooses skill 3 of char 3
                   if (player[0].MP >= 20)
                   {
                    player[0].HP += 30;
                    player[0].MP -= 20;
                    cout << "Player's DODGE! HP + " << player[0].HP << endl;
                  }
                  else
                  {
                    cout << "Not enough MP" << endl;
                  }
                  break;

                default:
                  cout << "Invalid choice." << endl;
                  break;
              }
            }



            else if (character == 4){                                           //if the player chooses character 4
              cout << "1. ICATHIAN RAIN (Damage: 100, Mana Required: 60) / 2. VOID SEEKER (Damage: 80, Mana Required: 40) / 3. HEAL (HP +40, Mana Required: 30)" << endl << endl;
              cout << "Your Choice: ";
              cin >> playerSkillChoice;
              cout << endl;

              switch (playerSkillChoice){                                       //player choice between 1 and 4, different skills used
                case 1:                                                         //if the player chooses skill 1 of char 4
                  if (player[0].MP >= 60)
                  {
                    player[0].DMG = 100 - monster[0].DEF;
                    monster[0].HP -= player[0].DMG;
                    player[0].MP -= 60;
                    cout << "Player's ICATHIAN RAIN! Damage: " << player[0].DMG << endl;
                  }
                  else
                  {
                    cout << "Not enough MP" << endl;
                  }
                  break;

                case 2:                                                         //if the player chooses skill 2 of char 4
                  if (player[0].MP >= 40)
                  {
                    player[0].DMG = 80 - monster[0].DEF;
                    monster[0].HP -= player[0].DMG;
                    player[0].MP -= 40;
                    cout << "Player's VOID SEEKER! Damage: " << player[0].DMG << endl;
                  }
                  else
                  {
                    cout << "Not enough MP" << endl;
                  }
                  break;

                case 3:                                                         //if the player chooses skill 3 of char 4
                   if (player[0].MP >= 30)
                   {
                    player[0].HP += 40;
                    player[0].MP -= 30;
                    cout << "Player's HEAL! HP + " << player[0].HP << endl;
                  }
                  else
                  {
                    cout << "Not enough MP" << endl;
                  }
                  break;

                default:
                  cout << "Invalid choice." << endl;
                  break;
              }
            }

            break;

          case 3:                                                               //if the player chooses action 3: to flee
            cout << "You cannot flee from the monster!" << endl;
            break;
        }
}
