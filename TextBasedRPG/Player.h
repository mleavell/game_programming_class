#include <string>

//#ifndef PLAYER_H
//#define PLAYER_H

using namespace std;

class Player {
private:
	string className;
	string name;
	float health;
	float minHealth;
	float maxHealth;
	float healthMax;
	float mana;
	float minMana;
	float maxMana;
	float manaMax;
	float manaRegenPerTurn;
	float minManaRegenPerTurn;
	float maxManaRegenPerTurn;
	float dodgeChance;
	float dodgeManaCost;
	int killCount;
	bool alive;

	void Teemo(string n);
	void Human(string n);
	void Darius(string n);
	void Soraka(string n);

public:
	Player(string name, int playerClass);

	struct Attack {
		string attackName;
		float manaCost;
		float damage;
	} playerAttack;

	struct Heal {
		string healName;
		float manaCost;
		float damageHealed;
	} playerHeal;

	float randRange(float min, float max);
	string getName();
	string getAttackName();
	string getClassName();
	string getHealName();
	float getHealth();
	float getHealthMax();
	float getMana();
	float getManaMax();
	float getManaRegen();
	float getDodgeChance();
	float getAttackStrength();
	float getAttackManaCost();
	float getHealManaCost();
	float getDodgeManaCost();
	float getHealStrength();
	int getKillCount();
	bool autoSkipTurn();
	bool attemptDodge();
	bool canDodge();
	void dodge();
	bool canAttack();
	void attack(Player &target);
	void attack();
	void increaseKills();
	bool canHeal();
	void heal();
	bool isAlive();
	void checkIfDead();
	void regenMana();
};

//#endif