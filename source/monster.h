#include <string>
using namespace std;

class Monster {
private:
  string name;
  int health;
  int healthMax;
  int level;
public:
  void Init(int enemy);

  int Attack();
  int GetHealth();
  int GetMaxHealth();
  string GetName();
  int GetLevel();

  void SetHealth(int userHealth);
  void Damage(int userDamage);

  int Death();

};
