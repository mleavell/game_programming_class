#include <string>
#include <random>
#include <time.h>

#ifndef _Player
#define _Player
#endif

using namespace std;

class Player {
private:
    void Teemo (string n) {
        minHealth = 75.0;
        maxHealth = 100.0;
        minMana = 150.0;
        maxMana = 175.0;
        minManaRegenPerTurn = 35.0;
        maxManaRegenPerTurn = 50.0;
        dodgeChance = 0.30;
        dodgeManaCost = 25;
        playerAttack.attackName = "dart";
        playerAttack.manaCost = 20.0;
        playerAttack.damage = 40.0;
        playerHeal.healName = "jungle medicine";
        playerHeal.manaCost = 30.0;
        playerHeal.damageHealed = 30.0;
        alive = true;
        killCount = 0;
        className = "Teemo";
        name = n;
        healthMax = randRange(minHealth, maxHealth);
        health = healthMax;
        manaMax = randRange(minMana, maxMana);
        mana = manaMax;
        manaRegenPerTurn = randRange(minManaRegenPerTurn, maxManaRegenPerTurn);
    }

    void Human (string n) {
        minHealth = 100.0;
        maxHealth = 130.0;
        minMana = 50.0;
        maxMana = 80.0;
        minManaRegenPerTurn = 15.0;
        maxManaRegenPerTurn = 20.0;
        dodgeChance = 0.20;
        dodgeManaCost = 30;
        playerAttack.attackName = "rock";
        playerAttack.manaCost = 20.0;
        playerAttack.damage = 40.0;
        playerHeal.healName = "bandage";
        playerHeal.manaCost = 30.0;
        playerHeal.damageHealed = 30.0;
        alive = true;
        killCount = 0;
        className = "Human";
        name = n;
        healthMax = randRange(minHealth, maxHealth);
        health = healthMax;
        manaMax = randRange(minMana, maxMana);
        mana = manaMax;
        manaRegenPerTurn = randRange(minManaRegenPerTurn, maxManaRegenPerTurn);
    }

    void Darius (string n) {
        minHealth = 100;
        maxHealth = 120.0;
        minMana = 150.0;
        maxMana = 175.0;
        minManaRegenPerTurn = 35.0;
        maxManaRegenPerTurn = 50.0;
        dodgeChance = 0.30;
        dodgeManaCost = 25;
        playerAttack.attackName = "cards";
        playerAttack.manaCost = 20.0;
        playerAttack.damage = 40.0;
        playerHeal.healName = "gems";
        playerHeal.manaCost = 40.0;
        playerHeal.damageHealed = 40.0;
        alive = true;
        killCount = 0;
        className = "Darius";
        name = n;
        healthMax = randRange(minHealth, maxHealth);
        health = healthMax;
        manaMax = randRange(minMana, maxMana);
        mana = manaMax;
        manaRegenPerTurn = randRange(minManaRegenPerTurn, maxManaRegenPerTurn);
    }

    void Soraka (string n) {
        minHealth = 50.0;
        maxHealth = 75.0;
        minMana = 150.0;
        maxMana = 175.0;
        minManaRegenPerTurn = 35.0;
        maxManaRegenPerTurn = 50.0;
        dodgeChance = 0.30;
        dodgeManaCost = 25;
        playerAttack.attackName = "dart";
        playerAttack.manaCost = 25.0;
        playerAttack.damage = 45.0;
        playerHeal.healName = "jungle medicine";
        playerHeal.manaCost = 30.0;
        playerHeal.damageHealed = 30.0;
        alive = true;
        killCount = 0;
        className = "Teemo";
        name = n;
        healthMax = randRange(minHealth, maxHealth);
        health = healthMax;
        manaMax = randRange(minMana, maxMana);
        mana = manaMax;
        manaRegenPerTurn = randRange(minManaRegenPerTurn, maxManaRegenPerTurn);
    }

public:
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

    Player (string name, int playerClass) {
        srand(time(NULL));
        if (playerClass == 0) {
            Teemo(name);
        } else if (playerClass == 1) {
            Human(name);
        } else if (playerClass == 2) {
            Darius(name);
        } else if (playerClass == 3) {
            Soraka(name);
        } else {
            cout << "Class not found" << endl;
        }
    }

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

    float randRange (float min, float max) {
        return min + ((float) rand() / (float) RAND_MAX) * (max - min);
    }

    string getName () {
        return name;
    }

    string getAttackName () {
        return playerAttack.attackName;
    }

    string getClassName () {
        return className;
    }

    string getHealName () {
        return playerHeal.healName;
    }    

    float getHealth () {
        return health;
    }

    float getHealthMax () {
        return healthMax;
    }

    float getMana () {
        return mana;
    }

    float getManaMax () {
        return manaMax;
    }

    float getManaRegen () {
        return manaRegenPerTurn;
    }

    float getDodgeChance () {
        return dodgeChance;
    }

    float getAttackStrength () {
        return playerAttack.damage;
    }

    float getAttackManaCost () {
        return playerAttack.manaCost;
    }

    float getHealManaCost () {
        return playerHeal.manaCost;
    }

    float getDodgeManaCost () {
        return dodgeManaCost;
    }

    float getHealStrength () {
        return playerHeal.damageHealed;
    }

    int getKillCount () {
        return killCount;
    }

    bool autoSkipTurn () {
        return false;
    }

    bool attemptDodge () {
        return randRange(0.0, 100.0) < getDodgeChance() * 100.0;
    }

    bool canDodge () {
        return mana >= dodgeManaCost;
    }

    void dodge () {
        mana -= dodgeManaCost;
    }

    bool canAttack () {
        return mana >= playerAttack.manaCost;
    }

    void attack (Player &target) {
        target.health -= playerAttack.damage;
        mana -= playerAttack.manaCost;
        if (target.health <= 0) {
            target.alive = false;
        }
    }

    void attack () {
        mana -= playerAttack.manaCost;
    }

    void increaseKills () {
        killCount++;
    }

    bool canHeal () {
        return mana >= playerHeal.manaCost;
    }

    void heal () {
        health += playerHeal.damageHealed;
        mana -= playerHeal.manaCost;
        if (health > healthMax) {
            health = healthMax;
        }
    }

    bool isAlive () {
        return alive;
    }

    void checkIfDead () {
        cout << getName() << " is Alive" << endl;
    }

    void regenMana () {
        mana += manaRegenPerTurn;
        if (mana > manaMax) {
            mana = manaMax;
        }
    }
};