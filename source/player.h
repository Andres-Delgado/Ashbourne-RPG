#include <string>
using namespace std;

class Player {
private:
  string name;
  int health;
  int healthMax;
  int expoints;
  int expointsMax;
  int level;
  int potion;
  int gold;
  string weapon;
public:
  void SetName(string userName);
  void SetExp(int userExp);
  void SetGold();
  void LevelUp();
  void Stats();
  int Attack();

  string GetName();
  string GetHealth();
  string GetExpoints();
  string GetLevel();
  string GetPotion();
  string GetGold();

  void SetPotion(int userPotion);
  void SetWeapon(int userWeapon);
  void SetGold(int userGold);
  void SetHealth(int userHealth);

  void UsePotion();
  void Loot(int enemy);

  int PlayerMenu();
  void DungeonTitle();
  void DungeonMenu();
  void Dungeon(int dung);
  void Dragon();
  void Lair();
  void Store();

  int Death();
  void Damage(int userDamage);

};
