#include "monster.h"
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

void PressEnter() {
  cin.ignore();
  cout << "Press \"Enter\" to continue.";
  cin.get();
}

void Player::DungeonTitle(){
  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  for (int i = 0; i < 10; i++){cout << "____________";}
  for (int i = 0; i < 10; i++){cout << "------------";}
  cout << endl;

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

  cout << "_______________________________________|" <<  endl;



}

void Player::DungeonMenu(){

}

void Player::Dragon() {




  
}

void Player::Dungeon(int dung) {

  int k = 0;
  for (int i = 0; i < 5; i++){
    Monster monster;
    monster.Init(dung);
    cout << "\n\nA " << monster.GetName() << " Appears!" << endl;
    //Sleep(1000);
    cout << "Get ready for battle!" << endl << endl;
    //Sleep(2000);
    while ((health > 0) && (monster.GetHealth() > 0)){
      int j;

      DungeonTitle();
      cout << monster.GetName() << " Lvl: " << monster.GetLevel() << endl;
      cout <<   "    HP " << monster.GetHealth() << "/" << monster.GetMaxHealth() << endl << endl;
      cout << "Attack           (Press \"1\")" << endl;
      cout << "Drink Potion     (Press \"2\")" << endl;
      cout << "Retreat to Town  (Press \"0\")" << endl << endl;
      cout << endl << endl << endl << endl << endl << "Choose an option: ";

    //  DungeonMenu();

      while ( !(cin >> j) || ((j != 1) && (j != 2) && (j != 0))) {
        cout << "Re-enter a valid option: ";
        cin.clear();
        cin.ignore(10000, '\n');
      }

      switch (j){
        case 1:
          monster.Damage(Attack());
          if (monster.Death() == 1){
            Loot(dung);
            break;
          }
          else {
            Damage(monster.Attack());
            break;
          }
        case 2:
          UsePotion();
          Damage(monster.Attack());
          break;
        case 0:
          int retreatInput;
          cout << "You can retreat but the enemy will take an opportunity attack..." << endl;
          //Sleep(1500);
          cout << "Press \"0\" to retreat or anything else to keep fighting: " << endl;
          ///////////////////
          /////////////////
          ///////////////   VALIDATE
          cin >> retreatInput;
          if (retreatInput == 0) {
            Damage(monster.Attack());
            k = 1;
          }
          break;
        default:
          break;
      }
      if (k == 1){break;}
    }
    if (Death() == 1){break;}
    if (k == 1){break;}
  }
  return;
}

void Player::Store(){
  bool leaveStore = false;
  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  Stats();
  cout << "Welcome to the General Store, please take your time...\n";
  //Sleep(2000);

  while (!leaveStore){
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    Stats();

    cout << "Welcome to the General Store, please take your time...\n\n";

    cout << "Potion (regains 1/4 health)  10gp  (Press \"1\")\n";
    cout << "Steel Longsword  (1d4 + 3)   20gp  (Press \"2\")\n";
    cout << "Dwarven Waraxe   (1d8 + 4)   40gp  (Press \"3\")\n";
    cout << "Executioner      (1d12 + 8)  60gp  (Press \"4\")\n";
    cout << "Leave the Store                    (Press \"0\")" << endl << endl;

    cout << "Make a selection: ";
    int i;
    while (!(cin >> i) || ((i != 1) && (i != 2) && (i != 3) && (i != 4) && (i != 0))) {
      cout << "\nRe-enter a valid option: ";
      cin.clear();
      cin.ignore(100000, '\n');
    }
    cout << endl;

    string choice;
    int buy, cost;
    switch (i){
      case 1:
        cout << "How many potions would you like to buy? ";
        while (!(cin >> buy)) {
          cout << "Re-enter a valid option: ";
          cin.clear();
          cin.ignore(100000, '\n');
        }
        if (buy == 0) {
          cout << "You did not buy any potions." << endl;
          break;
        }
        cost = 10 * buy;
        if (cost > gold) {
          cout << "You do not have en9ough gp for that!\n";
          //Sleep(1500);
          cout << "Choose smaller quantity or pick a different item." << endl;
        }
        else {
          gold -= cost;
          SetPotion(buy);
        }
        break;
      case 2:
        if (gold < 20){
          cout << "You do not have enough gp for that!\n";
          //Sleep(1500);
          cout << "Come back when you have more gp to purchase this item..." << endl;
        }
        else {
          cout << "Are you sure you want to make this purchase? \n";
          //Sleep(1500);
          cout << "Press \"2\" again to confirm or anything else to return to the store menu: ";
          cin.clear();
          cin >> choice;
          if (choice == "2") {
            gold -= 20;
            SetWeapon(1);
          }
          else {cout << "Returning to the General Store menu..." << endl;}
        }
        break;
      case 3:
        if (gold < 40) {
          cout << "You do not have enough gp for that!\n";
          //Sleep(1500);
          cout << "Come back when you have more gp to purchase this item..." << endl;
        }
        else {
          cout << "Are you sure you want to make this purchase? \n";
          //Sleep(1500);
          cout << "Press \"3\" again to confirm or anything else to return to the store menu: ";
          cin >> choice;
          if (choice == "3") {
            gold -= 40;
            SetWeapon(2);
          }
          else {cout << "Returning to the General Store menu..." << endl;}
        }
        break;
      case 4:
        if (gold < 60) {
          cout << "You do not have enough gp for that!\n";
          //Sleep(1500);
          cout << "Come back when you have more gp to purchase this item..." << endl;
        }
        else {
          cout << "Are you sure you want to make this purchase? \n";
          //Sleep(1500);
          cout << "Press \"4\" again to confirm or anything else to return to the store menu: ";
          cin >> choice;
          if (choice == "4") {
            gold -= 60;
            SetWeapon(3);
          }
          else {cout << "Returning to the General Store menu..." << endl;}
        }
        break;
      case 0:
        leaveStore = true;
        cout << endl << "You leave the store and go back to town..." << endl;
        break;
      default:
        break;
    }
    //Sleep(1500);
    cin.ignore();
    cout << "\nPress \"Enter\" to continue." << endl;
    cin.get();
  }
  return;
}
