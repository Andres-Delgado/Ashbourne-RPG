#include "player.h"
#include "monster.h"
//#include "resource.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <Windows.h>
using namespace std;

void Title(){
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

    for (int i = 0; i < 10; i++){
    cout << "____________";
  }
  cout << endl << endl;
  return;
}

int main() {
  srand(time(NULL));

  Title();
  Player noob;
  string userName;

  cout << "Welcome to the town of Ashbourne. You are here to restore peace back to the town, and hope to the people.\n";
  cout <<"What is your name adventurer? ";
  ///////////////////
  /////////////////
  ///////////////   VALIDATE AND SET PARAMETERS
  cin >> userName;
  noob.SetName(userName);
  cout << endl;

  Sleep(1000);
  cout << "Welcome " << noob.GetName() << ", you are our last hope... Please defeat the Dragon that has been terrorizing our town!\n";
  Sleep(3000);
  cout << "You can find the dragon in it's lair..." << endl;
  Sleep(2500);
  cout << "But you will need to go through the lower level dungeons to level up before attempting to kill the dragon.\n\n";
  Sleep(2000);
  cin.ignore();
  cout << "Press \"Enter\" to continue.";
  cin.get();

  int i= 9;
  while ( i != 0) {
    string validate;
    i = noob.PlayerMenu();
    switch (i) {
      case 1:
        noob.Dungeon(1);
        if (noob.Death() == 1) {
          cout << "YOU HAVE DIED!\nRestart the game to try again\n";
          Sleep(2000);
          i = 0;
        }
        break;
      case 2:
        noob.Dungeon(2);
        if (noob.Death() == 1) {
          cout << "YOU HAVE DIED!\nRestart the game to try again\n";
          Sleep(2000);
          i = 0;
        }
        break;
      case 3:
      noob.Dragon();
      if (noob.Death() == 1) {
        cout << "YOU HAVE DIED!\nRestart the game to try again\n";
        Sleep(2000);
        i = 0;
      }
        break;
      case 4:
        noob.Store();
        break;
      case 5:
        noob.UsePotion();
        break;
      case 0:
        cout << "Are you sure you want to exit the game?" << endl;
        Sleep(500);
        cout << "You will lose all progress..." << endl;
        Sleep(500);
        cout << "Press \"0\" again to exit or anything else to stay: ";
        cin.clear();
        cin >> validate;
        if (validate == "0") {i = 0;}
        else {i = 1;}
        break;
      default:
        break;
    }


  }

  cout << "\nGoodbye " << noob.GetName() << ",\n";
  Sleep(500);
  cout << "You will be missed..." << endl << endl;
  Sleep(200);
  cout << "Close the game or press any button to exit: ";

  cin.ignore();
  cin.get();
  return 0;

}
