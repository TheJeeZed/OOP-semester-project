//// main.cpp — Stronghold Game Entry with Menu + Save/Load
//#include <iostream>
//#include <string>
//#include <thread>
//#include <fstream>
//#include <vector>
//#include "Trade.h" // Includes Market, Diplomacy, MultiplayerChat, etc.
//using namespace std;
//
//void saveGame(int gold, int food, int population, int treasury, const vector<string>& logs) {
//    ofstream file("savegame.txt");
//    if (!file) {
//        cout << "Failed to save game.\n";
//        return;
//    }
//    file << gold << "\n" << food << "\n" << population << "\n" << treasury << "\n";
//    for (const auto& log : logs) file << log << "\n";
//    file.close();
//    cout << "Game saved successfully.\n";
//}
//
//void loadGame(int& gold, int& food, int& population, int& treasury, vector<string>& logs) {
//    ifstream file("savegame.txt");
//    if (!file) {
//        cout << "No saved game found.\n";
//        return;
//    }
//    logs.clear();
//    file >> gold >> food >> population >> treasury;
//    string line;
//    getline(file, line);
//    while (getline(file, line)) logs.push_back(line);
//    file.close();
//    cout << "Game loaded successfully.\n";
//}
//
//int main() {
//    srand(time(0));
//    Market market;
//    Diplomacy diplomacy;
//    MultiplayerChat chat;
//    Resource resources;
//    Army army(20, 500, 200);
//    Economy economy;
//    KingElectionSystem electionSystem;
//    Population population;
//    vector<string> messageLog;
//
//    electionSystem.addCandidate("Arthur");
//    electionSystem.addCandidate("Cedric");
//    electionSystem.addFaction("Nobles", 0.6f);
//    electionSystem.addFaction("Peasants", 0.4f);
//
//    bool running = true;
//    int choice;
//
//    while (running) {
//        cout << "\n==============================\n";
//        cout << "Stronghold Main Menu\n";
//        cout << "==============================\n";
//        cout << "1. Hold King Election\n";
//        cout << "2. View King Status\n";
//        cout << "3. Manage Economy\n";
//        cout << "4. Manage Population\n";
//        cout << "5. View Market\n";
//        cout << "6. Conduct Trade\n";
//        cout << "7. Army Actions\n";
//        cout << "8. Finance Report\n";
//        cout << "9. Diplomacy\n";
//        cout << "10. Chat\n";
//        cout << "11. Save Game\n";
//        cout << "12. Load Game\n";
//        cout << "13. View Message Log\n";
//        cout << "0. Exit\n> ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            electionSystem.holdElection();
//            break;
//        case 2:
//            electionSystem.displayCurrentKing();
//            break;
//        case 3:
//            economy.collectTaxes(population.getpoor(), population.getnoble());
//            economy.simulateInflation();
//            economy.displayStatus();
//            break;
//        case 4:
//            population.simulatePlague();
//            population.simulatePopulationGrowth();
//            population.displayStats();
//            break;
//        case 5:
//            market.fluctuatePrices();
//            market.showMarket();
//            break;
//        case 6: {
//            int type, amount;
//            bool buy;
//            cout << "Enter Resource Type (0:Wood, 1:Stone, 2:Iron, 3:Food): ";
//            cin >> type;
//            cout << "Enter Amount: ";
//            cin >> amount;
//            cout << "Buy (1) or Sell (0)?: ";
//            cin >> buy;
//            market.trade(static_cast<ResourceType>(type), amount, buy);
//            break;
//        }
//        case 7:
//            army.assignGeneral("Leonidas");
//            army.produceWeapons(economy.getGold());
//            army.feedArmy(resources.getResourceAmount(FOOD));
//            army.simulateBattle(economy.getGold(), resources.getResourceAmount(FOOD));
//            army.displayStatus();
//            break;
//        case 8:
//            economy.simulateCorruption();
//            break;
//        case 9:
//            diplomacy.formAlliance("Kingdom of Eldor");
//            diplomacy.requestTrade("Kingdom of Eldor");
//            diplomacy.showDiplomaticStatus();
//            break;
//        case 10: {
//            string from, msg;
//            cout << "From: ";
//            cin.ignore();
//            getline(cin, from);
//            cout << "Message: ";
//            getline(cin, msg);
//            chat.sendMessage(from, msg);
//            messageLog.push_back(from + ": " + msg);
//            break;
//        }
//        case 11:
//            saveGame(economy.getGold(), resources.getResourceAmount(FOOD), population.getpoor() + population.getnoble(), economy.getGold(), messageLog);
//            break;
//        case 12:
//            int g, f, p;
//            int t;
//            loadGame(economy.getGold(), resources.getResourceAmount(FOOD), p, t, messageLog);
//            break;
//        case 13:
//            cout << "\nMessage Log:\n";
//            for (const auto& msg : messageLog) cout << msg << endl;
//            break;
//        case 0:
//            running = false;
//            break;
//        default:
//            cout << "Invalid option. Try again.\n";
//        }
//    }
//
//    cout << "\nGame session ended.\n";
//    return 0;
//}
