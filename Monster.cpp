#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Monster.h"
#include "Player.h"
using namespace std;

void monster_action(int character,int monsterChoice, Data monster[], Data player[]){

    if (monsterChoice == 0)   //monster auto attack if random number generated is 0
    {
        monster[0].DMG = monster[0].ATK - player[0].DEF;
        int AVD = rand() % 101 + player[0].AVD;   //generates random number between 0 and 100, if add up with playerAVD greater than 100, monster attack miss

        if (AVD >=100)
        {
            cout << "Monster attack miss!" << endl;
        }
        else
        {
            player[0].HP -= monster[0].DMG;
            cout << "You have been attacked by the monster! Damage: " << monster[0].DMG << endl;
        }
    }

    else if (monsterChoice == 1 && monster[0].MP >= 20)    //monster uses skills if random number generated is 1
    {
          int monsterSkill = rand() % 2;    //generates random number between 0 and 1 to decide which skill the monster will use, 0 'skill 1' and 1 'skill 2'
          if (monsterSkill == 0)    //monster skill 1 if random number generated is 0
          {
            monster[0].DMG = 80 - player[0].DEF;
            player[0].HP -= monster[0].DMG;
            monster[0].MP -= 20;
            cout << "Monster's SKILL 1! Damage: " << monster[0].DMG << endl;
          }
          else if (monsterSkill == 1)   //monster skill 2 if random number generated is 1
          {
            monster[0].DMG = 65 - player[0].DEF;
            player[0].HP -= monster[0].DMG;
            monster[0].MP -= 15;
            cout << "Monster's SKILL 2! Damage: " << monster[0].DMG << endl;
          }
    }
}
