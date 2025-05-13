#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <thread>
#include <chrono>
#include "Trade.h"

using namespace std;

int main() {
    srand(time(0));
    MultiplayerChat chat;
    Vector<string> messageLog;
    Vector<Player> players;
    players.push_back(Player("Eldor")); 
    players.push_back(Player("Varnholt"));
    players.push_back(Player("Sylvaris"));
    players.push_back(Player("Drakmere"));
    players.push_back(Player("Ironhold"));

    for (auto& player : players) {
        player.electionSystem.addCandidate("King_" + player.name + "_1");
        player.electionSystem.addCandidate("King_" + player.name + "_2");
        player.electionSystem.addFaction("Nobles_" + player.name, 0.6f);
        player.electionSystem.addFaction("Peasants_" + player.name, 0.4f);
        player.electionSystem.holdElection();
    }

    int turn = 0;
    bool gameRunning = true;
    while (gameRunning) {
        turn++;
        for (auto& player : players) {
            Event::playerTurn(player, players, chat, messageLog, turn);
        }

        int activeCount = 0;
        Player* lastPlayer = nullptr;
        for (const auto& player : players) {
            if (player.active) {
                activeCount++;
                lastPlayer = const_cast<Player*>(&player);
            }
        }
        system("cls");
        cout << "\n=== End of Turn " << turn << " ===\n";
        cout << "Kingdom Status:\n";
        for (const auto& player : players) {
            int pop = player.population.getpoor() + player.population.getnoble();
            cout << player.name << " - Gold: " << player.economy.getGold()
                << ", Food: " << player.resources.getResourceAmount(FOOD)
                << ", Population: " << pop
                << (player.active ? "" : " (Eliminated)") << "\n";
        }
        this_thread::sleep_for(chrono::seconds(2));

        if (activeCount <= 1) {
            gameRunning = false;
            if (activeCount == 1) {
                cout << "\n!!! " << lastPlayer->name << " is the last kingdom standing and wins the game! !!!\n";
            }
            else {
                cout << "\n!!! All kingdoms have been eliminated! No winner! !!!\n";
            }
        }
    }

    cout << "\nSimulation ended after " << turn << " turns.\n";
    return 0;
}