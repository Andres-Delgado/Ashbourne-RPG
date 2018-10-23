#include "player.h"
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

void PressEnterp() {
  cin.ignore();
  cout << "\nPress \"Enter\" to continue." << endl;
  cin.get();
}

void Player::SetName(string userName){
  name = userName;
  healthMax = 20;
  health = 20;
  expoints = 0;
  expointsMax = 100;
  level = 1;
  potion = 1;
  gold = 10;
  weapon = "Training Sword (1d4 + 1)";
  return;
}

void Player::SetExp(int userExp){
  switch(level) {
    case 1:
      expoints += userExp;
      cout << userExp << "xp gained!" << endl;
      if (expoints >= 100){
        expoints -= 100;
        LevelUp();
      }
      break;
    case 2:
      expoints += userExp;
      cout << userExp << "xp gained!" << endl;
      if (expoints >= 200){
        expoints -= 200;
        LevelUp();
      }
      break;
    case 3:
      expoints += userExp;
      cout << userExp << "xp gained!" << endl;
      if (expoints >= 300){
        expoints -= 300;
        LevelUp();
      }
      break;
    case 4:
      expoints += userExp;
      cout << userExp << "xp gained!" << endl;
      if (expoints >= 500){
        expoints = 0;
        LevelUp();
      }
      break;
    default:
      break;
  }
  return;
}

void Player::LevelUp(){
  int dice, choice;
  bool decide = false;
  string validate;

  level++;
  cout << "--------------------------\n";
  cout << "YOU HAVE REACHED LEVEL " << level << "!!\n";
  cout << "--------------------------\n" << endl;
  //Sleep(2000);

  // OPTION TO ROLL OR AVG {
  while (!decide) {
    cout << "Gain +6 HP                 (Press \"1\")\n";
    cout << "Roll 1d10 +2 for new HP    (Press \"2\")\n" << endl;
    cout << "Make a selection: ";
    while (!(cin >> choice) || ((choice != 1) && (choice != 2))) {
      cin.clear();
      cin.ignore(100000, '\n');
      cout << "Re-enter a valid option: ";
    }
    cout << "You chose to ";
    if (choice == 1) {cout << "Gain +6 HP.";}
    else {cout << "Roll 1d10 +2 for new HP.";}
    cout << endl;
    //Sleep(1500);
    cout << "Are you sure? Press \"1\" to validate or anything else to choose again: ";
    cin.clear();
    cin >> validate;
    if (validate == "1") {decide = true;}
    else {decide = false;}
    cout << endl << endl;
  }

  if (choice == 1) {
    healthMax += 6;
    cout << "Calculating new HP..." << endl;
    //Sleep(1000);
    cin.clear();
    cin.ignore();
    cout << "Press \"Enter\" to continue." << endl;
    cin.get();
  }
  if (choice == 2) {
    cin.ignore();
    cout << "Press \"Enter\" to roll your dice!" << endl;
    cin.get();
    dice = (rand() % 10) + 1;
    cout << "Rolling...\n";
    //Sleep(1000);
    cout << "You rolled a " << dice << " +2!" << endl;
    cout << "Press \"Enter\" to continue." << endl;
    cin.get();
    healthMax += (dice + 2);
  }
  health = healthMax;
  expointsMax += 100;
  cout << "Your new HP is: " << healthMax << "\n";
  //Sleep(1000);
  cout << "Press \"Enter\" to continue." << endl;
  cin.get();
  return;
}

void Player::Stats(){
  cout << "       " << name << " Lvl: " << level << " (" << expoints << "/" << expointsMax << ") XP \n";
  cout << "_______________________________________|" << endl;
  if (health < 10) {
    cout << "HP:       " << health << "/" << healthMax << "                         |" << endl;
  }
  else {
  cout << "HP:       " << health << "/" << healthMax << "                        |" << endl;
  }

  if (weapon == "Training Sword (1d4 + 1)") {cout << "Weapon:   " << weapon << "     |" << endl;}
  if (weapon == "Steel Longsword (1d4 + 3)") {cout << "Weapon:   " << weapon << "    |" << endl;}
  if (weapon == "Dwarven Waraxe (1d8 + 4)") {cout << "Weapon:   " << weapon << "     |" << endl;}
  if (weapon == "Executioner (1d12 + 8)") {cout << "Weapon:   " << weapon << "       |" << endl;}

  cout << "Potions:  " << potion << " (regains 1/4 health)       |" << endl;
  if (gold < 10) {
    cout << "Gold:     " << gold << "gp                          |" << endl;
  }
  else {
    cout << "Gold:     " << gold << "gp                         |" << endl;
  }

  cout << "_______________________________________|" << endl <<  endl;

}

string Player::GetName() {return name;}

int Player::PlayerMenu(){
  for (int i = 0; i < 10; i++){
    cout << "____________";
  }
  cout << endl;
  for (int i = 0; i < 10; i++){
    cout << "------------";
  }

  cout << "             :::      ::::::::  :::    ::: :::::::::   ::::::::  :::    ::: :::::::::  ::::    ::: ::::::::::\n";
  cout << "           :+: :+:   :+:    :+: :+:    :+: :+:    :+: :+:    :+: :+:    :+: :+:    :+: :+:+:   :+: :+:       \n";
  cout << "          +:+   +:+  +:+        +:+    +:+ +:+    +:+ +:+    +:+ +:+    +:+ +:+    +:+ :+:+:+  +:+ +:+       \n";
  cout << "         +#++:++#++: +#++:++#++ +#++:++#++ +#++:++#+  +#+    +:+ +#+    +:+ +#++:++#:  +#+ +:+ +#+ +#++:++#  \n";
  cout << "         +#+     +#+        +#+ +#+    +#+ +#+    +#+ +#+    +#+ +#+    +#+ +#+    +#+ +#+  +#+#+# +#+       \n";
  cout << "         #+#     #+# #+#    #+# #+#    #+# #+#    #+# #+#    #+# #+#    #+# #+#    #+# #+#   #+#+# #+#       \n";
  cout << "         ###     ###  ########  ###    ### #########   ########   ########  ###    ### ###    #### ##########\n";

  for (int i = 0; i < 10; i++){
    cout << "------------";
  }
  cout << endl;
  for (int i = 0; i < 10; i++){
    cout << "____________";
  }
  cout << endl;

  Stats();
  cout << "Enter the Whelp's Cave    (level 1-2)  (Press \"1\")\n";
  cout << "Enter the Drake Cavern    (level 3-4)  (Press \"2\")\n";
  cout << "Enter the Dragon's Lair   (level 5)    (Press \"3\")\n";
  cout << "Enter the General Store                (Press \"4\")\n";
  cout << "Drink potion                           (Press \"5\")\n";
  cout << "Save Game                              (Press \"8\")\n";
  cout << "Exit Ashbourne :'(                     (Press \"0\")" << endl << endl;
  cout << "What would you like to do?\n";
  int j;

  while ( !(cin >> j) || ((j != 1) && (j != 2) && (j != 3) && (j != 4) && (j != 5) && (j != 0))) {
    cout << "Re-enter a valid option: ";
    cin.clear();
    cin.ignore(100000, '\n');
  }
  return j;
}

int Player::Attack(){
  int i;
  if (weapon == "Training Sword (1d4 + 1)"){
    i = (rand() % 4) + 2;
    cout << "You attack with your Training Sword... " << endl;
    //Sleep(2000);
    cout << "It deals " << i << " damage!" << endl;
  }
  if (weapon == "Steel Longsword (1d4 + 3)"){
    i = (rand() % 4) + 4;
    cout << "You attack with your Steel Longsword..." << endl;
    //Sleep(2000);
    cout << "It deals " << i << " damage!" << endl;
  }
  if (weapon == "Dwarven Waraxe (1d8 + 4)"){
    i = (rand() % 8) + 5;
    cout << "You attack with your Dwarven Waraxe... " << endl;
    //Sleep(2000);
    cout << "It deals " << i << " damage!" << endl;
  }
  if (weapon == "Executioner (1d12 + 8)"){
    i = (rand() % 12) + 9;
    cout << "You attack with your Executioner... " << endl;
    //Sleep(2000);
    cout << "It deals " << i << " damage!" << endl;
  }

  cout << endl;
  //Sleep(1000);
  return i;
}

int Player::Death() {
  if (health <= 0) {return 1;}
  else {return 0;}
}

void Player::Damage(int userDamage){health -= userDamage;}

void Player::UsePotion(){
  if (potion == 0){
    cout << "You're out of potions!\n";
    //Sleep(1000);
    cout << "Buy more at the General Store.\n";
    //Sleep(3000);
    return;
  }
  if (health == healthMax){
    cout << "You already have full health!\n";
    //Sleep(1500);
    return;
  }

  int healthGain = healthMax / 4;
  potion -= 1;
  cout << "You drink a Health Potion...\n";
  //Sleep(1000);
  if((health + healthGain) >= healthMax){
    cout << "You regained " << healthMax - health << " HP!\n\n";
    health = healthMax;
  }
  else {
    cout << "You regained " << healthGain << " HP!\n\n";
    health += healthGain;
  }
  //Sleep(2000);
  return;
}

void Player::Loot(int enemy){
  int j;
  switch (enemy) {
    // WHELP
    case 1:
      if (level > 2) {SetExp(5);} // if over-lvl +5xp
      else {SetExp(20);}          // else +20xp
      j = (rand() % 5) + 2;
      j += (rand() % 5) + 2;      // 4-12 8avg 0.2
      if (level > 2) {j /= 4;}    // gp/4 if over-lvl
      cout << "The Whelp dropped: " << j << "gp!" << endl;
      gold += j;

      if (level > 2) {j = (rand() % 30);} // if over-lvl 1/30 chance
      else {j = (rand() % 20);}           // else 1/20 chance
      if (j == 0){
        //Sleep(1000);
        cout << "It also dropped a potion!" << endl;
        potion += 1;
      }
      //Sleep(2000);
      break;

    // DRAKE
    case 2:
      if (level > 4) {SetExp(20);} // if max-lvl +15xp
      else {SetExp(40);}          // else +30xp
      j = (rand() % 6) + 2;
      j += (rand() % 6) + 3;    // 5-15 10avg 0.17
      if (level > 4) {j /= 2;}  // gp/2 if max-lvl
      cout << "The Drake dropped: " << j << "gp!" << endl;
      gold += j;

      if (level > 4) {j = (rand() % 30);} // if max-lvl 1/30 chance
      else {j = (rand() % 20);}           // else 1/20 chance
      if (j == 0){
        //Sleep(1000);
        cout << "It also dropped a potion!" << endl;
        potion += 1;
      }
      //Sleep(2000);
      break;

    //DRAGON
    case 3:
      break;
    default:
      break;
  }
  cout << "Press \"Enter\" to continue.";
  cin.ignore();
  cin.get();
  return;
}

void Player::SetPotion(int userPotion){
  int newPotion;
  newPotion = userPotion;
  if (newPotion == 1){
    cout << "You aquired " << newPotion << " new potion!";
  }
  else {
    cout << "You aquired " << newPotion << " new potions!";
  }
  cout << endl;
  potion += newPotion;
  return;
}

void Player::SetWeapon(int userWeapon){
  if (userWeapon == 1){
    cout << "\nYou purchased the Steel Longsword!\n";
    //Sleep(1000);
    cout << "Its damage is (1d4 +3) with a range of 4-7 damage!";
    weapon = "Steel Longsword (1d4 + 3)";
  }
  if (userWeapon == 2){
    cout << "\nYou purchased the Dwarven Waraxe!\n";
    //Sleep(1000);
    cout << "Its damage is (1d8 +4) with a range of 4-12 damage!";
    weapon = "Dwarven Waraxe (1d8 + 4)";
  }
  if (userWeapon == 3){
    cout << "\nYou purchased the Executioner!\n";
    //Sleep(1000);
    cout << "Its damage is (1d12 +8) with a range of 8-20 damage!";
    weapon = "Executioner (1d12 + 8)";
  }
  cout << endl;
  return;
}

void Player::SetGold() {gold += 50;}
