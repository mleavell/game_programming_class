#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;

class SeimRPG {

private:
    vector<Player> players;

    string requestInput () {
        string input = "";
        getline(cin, input);
        return input;
    }

public:
    void print (string str) {
        cout << str << endl;
    }

    void printAfter (string str) {
        cout << endl << str;
    }

    void printBlank () {
        cout << endl;
    }

    void takeMove (Player &player) {
        print(player.getName() + ",");
        print("Would you like to 'attack', 'heal', or 'skip turn'?");
        printAfter("Move choice: ");

        string choice = requestInput();
        printBlank();
        if(choice.compare("attack") == 0) {
            attack(player);
        } else if (choice.compare("heal") == 0) {
            heal(player);
        } else if (choice.compare("skip turn") == 0) {
            skipTurn(player);
        } else {
            takeMove(player);
        }
    }

    void attack (Player &player) {
        if(player.canAttack()) {
            print("Type the number of the person to attack.");
            bool foundSelf = false;
            int myIndex = -1;
            for(int i = 0; i < players.size(); i++) {
                if(players[i].getName().compare(player.getName())==0) {
                    foundSelf = 1;
                    myIndex = i;
                } else {
                    if (foundSelf) {
                        print(to_string(i-1) + " " + players[i].getName());
                    } else {
                        print(to_string(i) + " " + players[i].getName()); 
                    }
                }
            }
            int victimIndex = -1;
            printAfter("Victim Number: ");
            cin>>victimIndex;
            cin.ignore(1000, '\n');
            if(victimIndex>=myIndex) {
                victimIndex++;
            }
            if(victimIndex < 0 || victimIndex > (players.size() -1)) {
                print("Invalid victim number");
                printBlank();
                attack(player);
            } else {
                printBlank();
                attackPlayer(player, players[victimIndex]);
            }
        }
        printBlank();
        player.regenMana();
    }

    void attackPlayer(Player &player, Player &target) {
        bool attackTarget = true;
        if(target.canDodge() && askDodge(target)) {
            if(target.attemptDodge()) {
                attackTarget = false;
                target.dodge();
                player.attack();
                print(player.getName() + " tried to attack " +
                    target.getName() + " and missed");
            } else {
                print("Dodge failed");
            }
        }
        if(attackTarget) {
            print(player.getName() + " attacked " + target.getName() +
                " with " + player.getAttackName());
            player.attack(target);
            if(!target.isAlive()) {
                player.increaseKills();
                print(player.getName() + " killed " + target.getName()); 
                for(int o = 0; o < players.size(); o++) {
                    if(players[o].getName().compare(target.getName()) == 0) {
                        vector<Player> newPlayers;
                        for(int s = 0; s < o; s++) {
                            newPlayers.push_back(players[s]);
                        }
                        for(int t = o+1; t < players.size(); t++) {
                            newPlayers.push_back(players[t]);
                        }
                        players = newPlayers;
                    }
                }
            } else {
                print(target.getName() + " now has " + to_string(target.getHealth()) + "/" +
                    to_string(target.getHealthMax()) + " health");
            }
        }
    }

    bool askDodge(Player &player) {
        print(player.getName() + ", do you want to try to dodge? yes or no?");
        printBlank();
        string choice = requestInput();
        if(choice.compare("yes") == 0) {
            return true;
        } else if(choice.compare("no") == 0) {
            return false;
        } else {
            print("yes or no only");
            printBlank();
            return askDodge(player);
        }
    }

    void heal(Player &player) {
        if(player.canHeal()) {
            player.heal();
            print(player.getName() + " used " + player.getHealName());  
        } else {
            print("Not enough mana");
        }
        printBlank();
        player.regenMana();
    }

    void skipTurn(Player &player) {
        player.regenMana();
        cout << player.getName() << " chose to skip turn" << endl;
        cout << endl;
    }

    void victory() {
        print(players.front().getName() + " has won");
        printBlank();
        printPlayerStats(players.front());
    }

    void createCharacter(string name, int playerClass) {
        Player player(name, playerClass);
        players.push_back(player);
    }

    void printPlayerStats (Player &player) {
        print("Name: " + player.getName());
        print("You are a " + player.getClassName());
        print("Attack Strength: " + to_string(player.getAttackStrength()));
        print("  Attack Mana Cost: " + to_string(player.getAttackManaCost()));
        print("Heal Strength: " + to_string(player.getHealStrength()));
        print("Dodge Chance: " + to_string((player.getDodgeChance() * 100.0)) + "%");
        print("  Dodge Mana Cost: " + to_string(player.getDodgeManaCost()));
        print("Health: " + to_string(player.getHealth()) + "/" + to_string(player.getHealthMax()));
        print("  Heal Mana Cost: " + to_string(player.getHealManaCost()));
        print("Mana: " + to_string(player.getMana()) + "/" + to_string(player.getManaMax()));
        print("  Mana Regen per Turn: " + to_string(player.getManaRegen()));
        print("Kills: " + to_string(player.getKillCount()));
    }

    int getClassIndex (string playerClass) {
        if(playerClass.compare("Teemo") == 0) {
            return 0;
        } else if (playerClass.compare("Human") == 0) {
            return 1;
        } else if (playerClass.compare("Darius") == 0) {
            return 2;
        } else if (playerClass.compare("Soraka") == 0) {
            return 3;
        } else {
            return -1;
        }
    }

    void printCharacters () {
        print("Teemo");
        print("Human");
        print("Darius");
        print("Soraka");
    }

    void playerCreation (string name) {
        int classType = -1;
        do {
            print("You may be one of the three following classes:");
            printCharacters();
            printBlank();
            print("Which class do you want: ");
            classType = getClassIndex(requestInput());
            printBlank();
        } while( classType < 0);
        printBlank();
        createCharacter(name, classType);
        printPlayerStats(players.back());
        printBlank();
    }

    int main () {
        printBlank();
        for(int i = 0; i < 2; i++) {
            string name = "";
            do {
                print("What is your name: ");
                name = requestInput();
                printBlank();
            } while( name.compare("") == 0);

            playerCreation(name);
        }

        for(int j = 2; j < 8; j++) {

            print("What is your name: ");
            string name = requestInput();
            if( name.compare("") == 0 || name.compare("Done") == 0) {
                printBlank();
                break;
            }
            printBlank();

            playerCreation(name);
        }

        while(players.size() > 1) {
            for(int k = 0; k < players.size(); k++) {
                int numPlayersBefore = players.size();
                printBlank();
                printBlank();
                printBlank();
                printPlayerStats(players[k]);
                takeMove(players[k]);
            }
            cout << endl;

            for(int m = 0; m < players.size(); m++) {
                players[m].checkIfDead();
            }
            cout << endl;
        }
        printBlank();
        printBlank();
        printBlank();
        victory();
        return 0;
    }
};

int main () {
    SeimRPG rpg;
    return rpg.main();
}