#include <string>
#include <random>
#include <iostream>

#include "time.h"
#include "Player.h"

using namespace std;

void Player::Teemo(string n) {
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

void Player::Human(string n) {
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

void Player::Darius(string n) {
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

void Player::Soraka(string n) {
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


Player::Player(string name, int playerClass) {
	srand(time(NULL));
	if (playerClass == 0) {
		Teemo(name);
	}
	else if (playerClass == 1) {
		Human(name);
	}
	else if (playerClass == 2) {
		Darius(name);
	}
	else if (playerClass == 3) {
		Soraka(name);
	}
	else {
		cout << "Class not found" << endl;
	}
}

float Player::randRange(float min, float max) {
	return min + ((float)rand() / (float)RAND_MAX) * (max - min);
}

string Player::getName() {
	return name;
}

string Player::getAttackName() {
	return playerAttack.attackName;
}

string Player::getClassName() {
	return className;
}

string Player::getHealName() {
	return playerHeal.healName;
}

float Player::getHealth() {
	return health;
}

float Player::getHealthMax() {
	return healthMax;
}

float Player::getMana() {
	return mana;
}

float Player::getManaMax() {
	return manaMax;
}

float Player::getManaRegen() {
	return manaRegenPerTurn;
}

float Player::getDodgeChance() {
	return dodgeChance;
}

float Player::getAttackStrength() {
	return playerAttack.damage;
}

float Player::getAttackManaCost() {
	return playerAttack.manaCost;
}

float Player::getHealManaCost() {
	return playerHeal.manaCost;
}

float Player::getDodgeManaCost() {
	return dodgeManaCost;
}

float Player::getHealStrength() {
	return playerHeal.damageHealed;
}

int Player::getKillCount() {
	return killCount;
}

bool Player::autoSkipTurn() {
	return false;
}

bool Player::attemptDodge() {
	return randRange(0.0, 100.0) < getDodgeChance() * 100.0;
}

bool Player::canDodge() {
	return mana >= dodgeManaCost;
}

void Player::dodge() {
	mana -= dodgeManaCost;
}

bool Player::canAttack() {
	return mana >= playerAttack.manaCost;
}

void Player::attack(Player &target) {
	target.health -= playerAttack.damage;
	mana -= playerAttack.manaCost;
	if (target.health <= 0) {
		target.alive = false;
	}
}

void Player::attack() {
	mana -= playerAttack.manaCost;
}

void Player::increaseKills() {
	killCount++;
}

bool Player::canHeal() {
	return mana >= playerHeal.manaCost;
}

void Player::heal() {
	health += playerHeal.damageHealed;
	mana -= playerHeal.manaCost;
	if (health > healthMax) {
		health = healthMax;
	}
}

bool Player::isAlive() {
	return alive;
}

void Player::checkIfDead() {
	cout << getName() << " is Alive" << endl;
}

void Player::regenMana() {
	mana += manaRegenPerTurn;
	if (mana > manaMax) {
		mana = manaMax;
	}
}

/*int main() {
	return 0;
}*/