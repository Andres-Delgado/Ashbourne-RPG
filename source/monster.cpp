#include "monster.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cctype>
//#include <Windows.h>
using namespace std;

void PressEnterm() {
  cin.ignore();
  cout << "Press \"Enter\" to continue.";
  cin.get();
}

void Monster::Init(int enemy) {
  switch (enemy) {
    case 1:
      name = "Dragon Whelp";
      health = healthMax = 10;
      level = 1;
      break;
    case 2:
      name = "Small Drake";
      health = healthMax = 20;
      level = 3;
      break;
    case 3:
      name = "Dragon";
      health = healthMax = 50;
      level = 5;
      break;
  }
}

int Monster::Attack() {
  int dmg;
  //
  // ((1d5 + 1d5) / 2) + range
  // Min bell curve, starts at 1
  //        .:|,_
  // 1=12%, 2=28%, 3=36%, 4=20%, 5=4%

  // ((1d2 /2) + (1d2 /2) + (1d2 /2) + (1d2 /2)) + range
  // Classic bell curve, starts at 0
  //        .:|:.
  // 0=6.25%, 1=25%, 2=37.5%, 3=25%, 4=6.25%

  // (((1d4 / 2) + (1d8 / 4))) + range ***********
  // more Drastic minbell, starts at 0
  // 0=9.38%, 1=31.25%, 2=37.50%, 3=18.75%, 4=3.13%

  if (name == "Dragon Whelp"){
    dmg = ((rand() % 4) + 1) / 2;
    dmg += ((rand() % 8) + 1) / 4;
    dmg += 1;                       // 1-5 Drastic Curve
    cout << "Dragon Whelp attacks you with a tail whip..." << endl;
    //Sleep(2000);
    cout << "It deals " << dmg << " Damage!";
  }

  if (name == "Small Drake"){
    dmg = ((rand() % 4) + 1) / 2;
    dmg += ((rand() % 8) + 1) / 4;
    dmg += 3;                       // 3-7 Drastic Curve
    cout << "Small Drake attacks you with scorch..." << endl;
    //Sleep(2000);
    cout << "It deals " << dmg << " Damage!";
  }

  if (name == "Dragon"){
    dmg = ((rand() % 4) + 1) / 2;
    dmg += ((rand() % 8) + 1) / 4;
    dmg += 7;                       // 7-11 Drastic Curve
    cout << "Dragon Whelp attacks you with Fire Breath..." << endl;
    //Sleep(2000);
    cout << "It deals " << dmg << " Damage!";
  }
  cout << endl << endl;
  //Sleep(1500);
  return dmg;
}

int Monster::GetHealth() {return health;}

int Monster::GetMaxHealth() {return healthMax;}

string Monster::GetName() {return name;}

int Monster::GetLevel() {return level;}

void Monster::Damage(int userDamage) {health -= userDamage;}

int Monster::Death(){
  if (health <= 0) {
    cout << name << " has died!\n" << endl;
    //Sleep(1000);
    return 1;
  }
  else {return 0;}
}
