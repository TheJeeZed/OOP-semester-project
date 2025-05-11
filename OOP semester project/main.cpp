#include <iostream>
#include <string>
#include <thread>
#include "Trade.h"
using namespace std;

int main() {
    Market market;
    Diplomacy diplomacy;
    MultiplayerChat chat;
    Resource resources;
    Finance finance;
    Army army(20, 500, 200);
    Economy economy;
    KingElectionSystem electionSystem;
    Population population;
    electionSystem.addCandidate("Arthur");
    electionSystem.addCandidate("Cedric");
    electionSystem.addFaction("Nobles", 0.6f);
    electionSystem.addFaction("Peasants", 0.4f);

    bool running = true;
    int choice;

    while (running) {
        cout << "\n==============================\n";
        cout << "Stronghold Main Menu\n";
        cout << "==============================\n";
        cout << "1. Hold King Election\n";
        cout << "2. View King Status\n";
        cout << "3. Manage Economy\n";
        cout << "4. Manage Population\n";
        cout << "5. View Market\n";
        cout << "6. Conduct Trade\n";
        cout << "7. Army Actions\n";
        cout << "8. Finance Report\n";
        cout << "9. Diplomacy\n";
        cout << "10. Chat\n";
        cout << "0. Exit\n> ";
        cin >> choice;

        switch (choice) {
        case 1:
            electionSystem.holdElection();
            break;
        case 2:
            electionSystem.displayCurrentKing();
            break;
        case 3:
            economy.collectTaxes();
            economy.simulateInflation();
            economy.showEconomyStatus();
            break;
        case 4:
            population.simulatePlague();
            population.simulatePopulationGrowth();
            population.displayStats();
            break;
        case 5:
            market.fluctuatePrices();
            market.showMarket();
            break;
        case 6: {
            int type, amount;
            bool buy;
            cout << "Enter Resource Type (0:Wood, 1:Stone, 2:Iron, 3:Food): ";
            cin >> type;
            cout << "Enter Amount: ";
            cin >> amount;
            cout << "Buy (1) or Sell (0)?: ";
            cin >> buy;
            market.trade(static_cast<ResourceType>(type), amount, buy);
            break;
        }
        case 7:
            army.assignGeneral("Leonidas");
            army.produceWeapons(finance.getGold());
            army.feedArmy(resources.getResourceAmount(FOOD));
            army.simulateBattle(finance.getGold(), resources.getResourceAmount(FOOD));
            army.displayStatus();
            break;
        case 8:
            finance.simulateCorruption();
            finance.printFinanceReport();
            break;
        case 9:
            diplomacy.formAlliance("Kingdom of Eldor");
            diplomacy.requestTrade("Kingdom of Eldor");
            diplomacy.showDiplomaticStatus();
            break;
        case 10:
            chat.sendMessage("Player1", "Ready for war?");
            chat.sendMessage("Player2", "Only if you pay first.");
            chat.showChatHistory();
            break;
        case 0:
            running = false;
            break;
        default:
            cout << "Invalid option. Try again.\n";
        }
    }

    cout << "\nGame session ended.\n";
    return 0;
}
