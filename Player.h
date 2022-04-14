#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

struct Data{
    int HP;                                                                          //HP for life
    int MP;                                                                          //MP for skills 
    int ATK;                                                                         //ATK for attack
    int DEF;                                                                         //DEF for defense
    int AVD;                                                                         //AVD for avoid rate
    int CRT;                                                                         //CRT for critical damage 
    int DMG;                                                                         //DMG for damage
};

void player_action(int character,int playerChoice, Data player[], Data monster[]);

#endif
