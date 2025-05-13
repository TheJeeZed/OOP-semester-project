#include "Trade.h"

Market::Market() {
    inflationRate = 1.0f;
    goods.push_back({ WOOD, 100, 5.0f });
    goods.push_back({ STONE, 100, 5.0f });
    goods.push_back({ IRON, 50, 15.0f });
    goods.push_back({ FOOD, 100, 5.0f });
}
void Market::fluctuatePrices() {
    for (int i = 0; i < goods.size(); i++) {
        float factor = ((rand() % 40) - 20) / 100.0f + 1.0f; 
        goods[i].price *= factor;
        if (goods[i].price < 0) goods[i].price = 10;
    }
    std::cout << "Market prices have changed due to supply/demand shifts." << std::endl;
}
void Market::trade(ResourceType type, int amount, bool buying) {
    int item = 0;
    for (int i = 0; i < goods.size(); i++) {
        if (goods[i].type == type) {
            item = i;
            break;
        }
    }
    Good& g = goods[item];
    float total = g.price * amount;
    if (buying) {
        if (g.quantity < amount) {
            switch (g.type) {
            case WOOD:
                std::cout << "Not enough Wood in stock." << std::endl;
                break;
            case STONE:
                std::cout << "Not enough Stone in stock." << std::endl;
                break;
            case IRON:
                std::cout << "Not enough Iron in stock." << std::endl;
                break;
            case FOOD:
                std::cout << "Not enough Food in stock." << std::endl;
                break;
            }
            return;
        }
        g.quantity -= amount;
        switch (g.type) {
        case WOOD:
            std::cout << "Bought " << amount << " units of Wood for " << total << " gold." << std::endl;
            break;
        case STONE:
            std::cout << "Bought " << amount << " units of Stone for " << total << " gold." << std::endl;
            break;
        case IRON:
            std::cout << "Bought " << amount << " units of Iron for " << total << " gold." << std::endl;
            break;
        case FOOD:
            std::cout << "Bought " << amount << " units of Food for " << total << " gold." << std::endl;
            break;
        }
    }
    else {
        g.quantity += amount;
        switch (g.type) {
        case WOOD:
            std::cout << "Sold " << amount << " units of Wood for " << total << " gold." << std::endl;
            break;
        case STONE:
            std::cout << "Sold " << amount << " units of Stone for " << total << " gold." << std::endl;
            break;
        case IRON:
            std::cout << "Sold " << amount << " units of Iron for " << total << " gold." << std::endl;
            break;
        case FOOD:
            std::cout << "Sold " << amount << " units of Food for " << total << " gold." << std::endl;
            break;
        }
    }
}
void Market::imposeSanction() {
    for (int i = 0; i < goods.size(); i++) {
        goods[i].price *= 1.5f;
    }
    std::cout << "Trade sanction imposed! Prices spiked." << std::endl;
}
void Market::showMarket() {
    std::cout << std::endl << "Market Prices:" << std::endl;
    for (int i = 0; i < goods.size(); i++) {
        switch (goods[i].type) {
        case WOOD:
            std::cout << "Wood" << " - Quantity: " << goods[i].quantity << ", Price: " << goods[i].price << std::endl;
            break;
        case STONE:
            std::cout << "Stone" << " - Quantity: " << goods[i].quantity << ", Price: " << goods[i].price << std::endl;
            break;
        case IRON:
            std::cout << "Iron" << " - Quantity: " << goods[i].quantity << ", Price: " << goods[i].price << std::endl;
            break;
        case FOOD:
            std::cout << "Food" << " - Quantity: " << goods[i].quantity << ", Price: " << goods[i].price << std::endl;
            break;
        }
    }
}
float Market::getPrice(ResourceType type) {
    for (int i = 0; i < goods.size(); i++) {
        if (goods[i].type == type) return goods[i].price;
    }
    return 0.0f;
}

void Diplomacy::formAlliance(const std::string& kingdom) {
    for (int i = 0; i < alliances.size(); i++) {
        if (alliances[i].first == kingdom) {
            alliances[i].second.first = true;
            std::cout << "Alliance formed with " << kingdom << std::endl;
            break;
        }
    }
}
void Diplomacy::breakAlliance(const std::string& kingdom) {
    for (int i = 0; i < alliances.size(); i++) {
        if (alliances[i].first == kingdom) {
            alliances[i].second.first = false;
            std::cout << "Alliance broken with " << kingdom << std::endl;
            break;
        }
    }
}
void Diplomacy::requestTrade(const std::string& kingdom) {
    for (int i = 0; i < alliances.size(); i++) {
        if (alliances[i].first == kingdom) {
            alliances[i].second.second = rand() % 2;
            if (alliances[i].second.second) {
                std::cout << "Trade deal accepted by " << kingdom << std::endl;
            }
            else {
                std::cout << "Trade deal rejected or faked by " << kingdom << std::endl;
            }
            break;
        }
    }
}
void Diplomacy::imposeSanctionOn(const std::string& kingdom) {
    for (int i = 0; i < alliances.size(); i++) {
        if (alliances[i].first == kingdom) {
            alliances[i].second.second = false;
            break;
        }
    }
    std::cout << "Sanction imposed on " << kingdom << ". All trade blocked." << std::endl;
}
void Diplomacy::showDiplomaticStatus() {
    std::cout << std::endl << "Diplomatic Status:" << std::endl;
    for (int i = 0; i < alliances.size(); i++) {
        std::cout << alliances[i].first << ": Alliance " << (alliances[i].second.first ? "Active" : "Broken") << ", Trade " << (alliances[i].second.second ? "Yes" : "No") << std::endl;
    }
}
void Diplomacy::addKingdom(const std::string& kingdom) {
    alliances.push_back({ kingdom, {false, false} });
}

void MultiplayerChat::sendMessage(const std::string& from, const std::string& msg) {
    std::string entry = from + ":" + msg;
    messageLog.push_back(entry);
    std::cout << entry << std::endl;
}
void MultiplayerChat::showChatHistory() {
    std::cout << std::endl << "Chat Log:" << std::endl;
    for (int i = 0; i < messageLog.size(); i++) {
        std::cout << messageLog[i] << std::endl;
    }
}

Resource::Resource() {
    resources[WOOD] = 100;
    resources[STONE] = 100;
    resources[IRON] = 100;
    resources[FOOD] = 200;
}
void Resource::produceResources(ResourceType type, int amount) {
    resources[type] += amount;
}
bool Resource::consumeResources(ResourceType type, int amount) {
    if (resources[type] >= amount) {
        resources[type] -= amount;
        return true;
    }
    std::cout << "Not enough resources to spend!" << std::endl;
    return false;
}
void Resource::addResource(ResourceType type, int amount) {
    resources[type] += amount;
}
int& Resource::getResourceAmount(ResourceType type) {
    return resources[type];
}
int Resource::getResourceAmount(ResourceType type) const {
    return resources[type];
}
void Resource::printResources() const {
    std::cout << "Resources" << std::endl;
    std::cout << "- Wood :" << resources[WOOD] << std::endl;
    std::cout << "- Stone :" << resources[STONE] << std::endl;
    std::cout << "- Iron :" << resources[IRON] << std::endl;
    std::cout << "- Food :" << resources[FOOD] << std::endl;
    std::cout << "===============================" << std::endl;
}

Economy::Economy() {
    debt = 0;
    treasuryGold = 1000;
    inflationRate = 2.0f;
    corruptionLevel = 0.1f;
    marketHealth = 100.0f;
    taxRatePoor = 0.05f;
    taxRateNoble = 0.15f;
    progressiveTax = true;
    marketCrash = false;
    securityExpense = 0;
}
void Economy::setTaxRates(float poorRate, float nobleRate, bool isProgressive) {
    taxRatePoor = poorRate;
    taxRateNoble = nobleRate;
    progressiveTax = isProgressive;
}
void Economy::collectTaxes(int poorPopulation,int noblePopulation) {
    float totalTax = (poorPopulation * 10 * taxRatePoor) + (noblePopulation * 50 * taxRateNoble);
    int corruptionLoss = totalTax * corruptionLevel;
    treasuryGold += (totalTax - corruptionLoss);
    std::cout << "Taxes collected: " << totalTax - corruptionLoss << " (Corruption Loss: " << corruptionLoss << ")" << std::endl;

    if (taxRatePoor + taxRateNoble > 0.4f) {
        inflationRate += 0.5f;
        std::cout << "Over-taxation causing inflation!" << std::endl;
    }
    if (taxRatePoor > 0.2f)
        std::cout << "Poor population may revolt due to high taxation." << std::endl;
    if (taxRateNoble > 0.3f)
        std::cout << "Nobles are furious with excessive taxes." << std::endl;
}
void Economy::simulateInflation() {
    treasuryGold *= (1 - (inflationRate / 100.0));
    std::cout << "Inflation reduced treasury by " << inflationRate << "%." << std::endl;
}
void Economy::increaseCorruption(float amount) {
    corruptionLevel += amount;
    if (corruptionLevel > 1.0f)
        corruptionLevel = 1.0f;
    std::cout << "Corruption increased. Current level: " << corruptionLevel << std::endl;
}
void Economy::setCorruption(float amount) {
    corruptionLevel = amount;
    if (corruptionLevel > 1.0f)
        corruptionLevel = 1.0f;
}
void Economy::triggerRandomEvent() {
    int eventRoll = rand() % 5;
    switch (eventRoll) {
    case 0:
        marketHealth -= 30;
        std::cout << "Trade dispute causes market decline!" << std::endl;
        break;
    case 1:
        treasuryGold += 200;
        std::cout << "Successful trade brings profit." << std::endl;
        break;
    case 2:
        inflationRate += 1.5f;
        std::cout << "Rumors of instability raise inflation." << std::endl;
        break;
    case 3:
        corruptionLevel += 0.05f;
        std::cout << "A bribery scandal shakes the kingdom." << std::endl;
        break;
    case 4:
        marketHealth += 20;
        std::cout << "Market recovery boosts confidence." << std::endl;
        break;
    }
    if (marketHealth > 100) marketHealth = 100;
    if (marketHealth < 0) marketHealth = 0;
}
void Economy::checkMarketCrash() {
    if (marketHealth < 20.0f && !marketCrash) {
        std::cout << "Market has crashed! Treasury takes a massive hit." << std::endl;
        treasuryGold /= 2;
        marketCrash = true;
    }
}
void Economy::displayStatus() {
    std::cout << "Treasury: " << treasuryGold << std::endl;
    std::cout << "Inflation Rate: " << inflationRate << "%" << std::endl;
    std::cout << "Corruption Level: " << corruptionLevel << std::endl;
    std::cout << "Market Health: " << marketHealth << "%" << std::endl;
    std::cout << "Progressive Tax: " << (progressiveTax ? "ON" : "OFF") << std::endl;
    std::cout << "Security Expense/Turn: " << securityExpense << std::endl;
    if (marketCrash)
        std::cout << "Market has recently crashed!" << std::endl;
    std::cout << "Debt: " << debt << std::endl;
}
void Economy::simulateCorruption() {
    int chance = rand() % 100;
    if (chance < corruptionLevel * 100) {
        int stolen = 10 + (rand() % 20);
        treasuryGold -= stolen;
        std::cout << "Officials stole " << stolen << " gold from treasury." << std::endl;
    }

    if (securityExpense > 0) {
        treasuryGold -= securityExpense;
        std::cout << "Spent " << securityExpense << " gold on security expenses." << std::endl;
    }
}
void Economy::simulateLoanTurn() {
    if (debt <= 0) return;
    if (treasuryGold > 10) {
        std::cout << "Returned 10 gold in debt" << std::endl;
        treasuryGold -= 10;
        debt -= 10;
    }
    else {
        std::cout << "NOT enough gold!!" << std::endl;
        inflationRate += 0.01f;
    }
}
void Economy::triggerFraud(FraudEvent event) {
    switch (event) {
    case BANKHEIST: {
        treasuryGold -= 150;
        std::cout << "Bank heist! Lost 150 gold." << std::endl;
        securityExpense += 10;
        break;
    }
    case EMBEZZLMENT: {
        treasuryGold -= 100;
        corruptionLevel += .1;
        std::cout << "Embezzlement detected! Lost 100 gold." << std::endl;
        break;
    }
    case NONE:
    default:
        break;
    }
}
void Economy::audit() {
    const int auditCost = 30;
    if (!spendGold(auditCost)) {
        std::cout << "Audit aborted — not enough funds." << std::endl;
        return;
    }
    std::cout << "Audit initiated. Cost: " << auditCost << " gold." << std::endl;
    if (corruptionLevel >= 0.4) {
        treasuryGold += 20 + (rand() % 30);
        corruptionLevel -= 0.15;
        std::cout << "Audit successful. Recovered  gold. Corruption reduced." << std::endl;
    }
    else {
        std::cout << "No significant corruption found. Public trust improved." << std::endl;
        corruptionLevel -= 0.05;
    }
}
void Economy::normalizedata() {
    if (corruptionLevel < 0) {
        corruptionLevel = 0;
    }
    if (treasuryGold < 0) {
        corruptionLevel += -(treasuryGold) / 100.0;
        treasuryGold = 0;
    }
}
void Economy::takeLoan(int amount, float interest) {
    debt += amount + amount * interest;
    treasuryGold += amount;
}
int Economy::getDebt() {
    return debt;
}
void Economy::addGold(int amount) {
    treasuryGold += amount;
}
bool Economy::spendGold(int amount) {
    if (treasuryGold >= amount) {
        treasuryGold -= amount;
        return true;
    }
    std::cout << "Not enough gold to spend!" << std::endl;
    return false;
}
int& Economy::getGold() {
    return treasuryGold;
}
int Economy::getGold() const {
    return treasuryGold;
}

General::General(const std::string& name) {
    this->name = name;
    corrupt = rand() % 100 < 25;
}

Army::Army(int soldiers, int gold, int food) {
    this->soldiers = soldiers;
    blacksmiths = 2;
    weapons = 1;
    general = nullptr;
    moral = 100;
    srand(time(0));
}
void Army::recruitSoldiers(int& population, int& gold, int count) {
    if (count > population || count * 20 > gold || count > weapons) {
        std::cout << "Not enough resources to recruit." << std::endl;
        return;
    }
    population -= count;
    gold -= count * 10;
    std::this_thread::sleep_for(std::chrono::seconds(count * 2));
    std::cout << "Recruited " << count << " soldiers." << std::endl;
}
void Army::assignGeneral(const std::string& name) {
    general = new General(name);
    std::cout << "General " << name << "assigned. " << (general->corrupt ? "(Corrupt)" : "(Loyal)") << std::endl;
}
void Army::produceWeapons(int& gold) {
    int produced = blacksmiths * 5;
    weapons += produced;
    gold -= produced * 2;
    std::cout << "Produced " << produced << " weapons." << std::endl;
}
void Army::feedArmy(int& food) {
    if (food < soldiers) {
        std::cout << "Food shortage! Morale dropping." << std::endl;
        moral -= soldiers * 0.1;
    }
    else {
        food -= soldiers;
        moral += soldiers * 0.05;
        std::cout << "Army fed." << std::endl;
    }
}
void Army::checkMorale() {
    int deserters = 0;
    std::cout << "Moral is: " << moral << std::endl;
    if (moral < 30) {
        deserters = rand() % soldiers / 2;
        soldiers -= deserters;
        std::cout << deserters << " soldiers have deserted due to low morale." << std::endl;
    }
}
General* Army::getGeneral() const {
    return general;
}
void Army::displayStatus() const {
    std::cout << std::endl << "Army Status:" << std::endl;
    std::cout << "Soldiers: " << soldiers << ", Weapons: " << weapons << std::endl;
    if (general) std::cout << "General: " << general->name << (general->corrupt ? " (Corrupt)" : " (Loyal)") << std::endl;
}
void Army::simulateTwoPlayerBattle(Army& opponent, int& attackerGold, int& attackerFood, int& defenderGold, int& defenderFood, int& attackerPopulation, int& defenderPopulation) {
    std::cout << "Battle between armies begins!" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    float attackerStrength = soldiers * (weapons / (float)(soldiers + 1)) * (moral / 100.0f);
    if (general && !general->corrupt) attackerStrength *= 1.2f;
    else if (general && general->corrupt) attackerStrength *= 0.8f;
    float defenderStrength = soldiers * (weapons / (float)(soldiers + 1)) * (moral / 100.0f);
    if (opponent.general && !opponent.general->corrupt) defenderStrength *= 1.2f;
    else if (opponent.general && opponent.general->corrupt) defenderStrength *= 0.8f;
    float totalStrength = attackerStrength + defenderStrength;
    int attackerLosses = (defenderStrength / totalStrength) * soldiers * (rand() % 50 + 50) / 100.0f;
    int defenderLosses = (attackerStrength / totalStrength) * opponent.soldiers * (rand() % 50 + 50) / 100.0f;
    attackerLosses = std::max(1,attackerLosses);
    defenderLosses = std::max(1,defenderLosses);
    soldiers -= attackerLosses;
    opponent.soldiers -= defenderLosses;
    attackerGold -= attackerLosses * 3;
    attackerFood -= attackerLosses * 2;
    defenderGold -= defenderLosses * 3;
    defenderFood -= defenderLosses * 2;
    attackerPopulation -= attackerLosses;
    defenderPopulation -= defenderLosses;
    moral -= attackerLosses * 0.1f;
    opponent.moral -= defenderLosses * 0.1f;
    if (moral < 0) moral = 0;
    if (opponent.moral < 0) opponent.moral = 0;
    std::cout << "Attacker lost " << attackerLosses << " soldiers. Defender lost " << defenderLosses << " soldiers." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
}
Army::~Army() {
    delete general;
}

King::King() {
    name = "";
    popularity = 0;
    alive = 0;
}
King::King(const std::string& name) {
    this->name = name;
    this->popularity = rand() % 100;
    alive = true;
}
void King::displayProfile() const {
    std::cout << "King: " << name << " | Popularity: " << popularity * 100 << "%" << std::endl;
}

Faction::Faction() {
    name = "";
    influence = 0;
    supportsCurrentKing = 0;
}
Faction::Faction(const std::string& name, float influence) {
    this->name = name;
    this->influence = influence;
    supportsCurrentKing = false;
}

KingElectionSystem::KingElectionSystem() {
    currentKing = nullptr;
}
void KingElectionSystem::addCandidate(const std::string& name) {
    King k(name);
    candidates.push_back(k);
}
void KingElectionSystem::addFaction(const std::string& name, float influence) {
    Faction F(name, influence);
    factions.push_back(F);
}
void KingElectionSystem::holdElection() {
    std::cout << std::endl << "Election in progress..." << std::endl;
    Vector<float> scores(candidates.size(), 0.0f);

    for (int i = 0; i < factions.size(); ++i) {
        int choice = rand() % candidates.size();
        scores[choice] += factions[i].influence;
    }
    int winnerIdx = std::distance(scores.begin(), std::max_element(scores.begin(), scores.end()));
    currentKing = &candidates[winnerIdx];
    std::cout << "New King Elected!!!";
    currentKing->displayProfile();
}
void KingElectionSystem::simulateBlackmail() {
    if (!currentKing) return;
    float damage = static_cast<float>(rand() % 15) / 100.0f;
    currentKing->popularity -= damage;
    std::cout << "Blackmail scandal reduced popularity by " << damage * 100 << "%." << std::endl;
}
void KingElectionSystem::simulateBribery() {
    if (!currentKing) return;
    float bribeEffect = static_cast<float>(rand() % 10) / 100.0f;
    currentKing->popularity += bribeEffect;
    std::cout << "Bribery increased king's popularity by " << bribeEffect * 100 << "%." << std::endl;
}
void KingElectionSystem::simulateAssassination() {
    if (!currentKing || !currentKing->alive) return;
    int chance = rand() % 100;
    if (chance < 20) {
        currentKing->alive = false;
        std::cout << "The king has been assassinated! Chaos ensues." << std::endl;
    }
    else {
        std::cout << "Assassination attempt failed." << std::endl;
    }
}
void KingElectionSystem::checkCoupRisk() {
    if (!currentKing) return;
    if (currentKing->popularity < 0.3f) {
        std::cout << "Coup possibility rising! Nobles and generals are discontent." << std::endl;
    }
}
void KingElectionSystem::kingDiedInBattle() {
    if (!currentKing) return;
    currentKing->alive = false;
    std::cout << "The king has fallen in battle! A power vacuum destabilizes the realm." << std::endl;
}
void KingElectionSystem::displayCurrentKing() const {
    if (!currentKing) {
        std::cout << "No king currently rules the kingdom." << std::endl;
    }
    else if (!currentKing->alive) {
        std::cout << "The previous king " << currentKing->name << " is deceased." << std::endl;
    }
    else {
        currentKing->displayProfile();
    }
}

Population::Population() {
    foodSupply = 100;
    healthcareLevel = 5;
    jobAvailability = 5;
    population = 0;
    peasents = 0;
    nobels = 0;
    for (int i = 0; i < 100; i++) {
        population++;
        if (rand() % 2)peasents++;
        else nobels++;
    }
}
void Population::setPopulation(int pop, int peas, int nob) {
    population = pop;
    peasents = peas;
    nobels = nob;
}
void Population::simulatePlague() {
    int deaths = rand() % 20 + 10;
    for (int i = 0; i < deaths; ++i) {
        population--;
        if (rand() % 2)peasents--;
        else nobels--;
    }
    std::cout << "Plague struck! " << deaths << " people died." << std::endl;
}
void Population::simulateFamine() {
    if (foodSupply < population) {
        int deaths = (population - foodSupply) / 2;
        for (int i = 0; i < deaths; ++i) {
            population--;
            if (rand() % 2)peasents--;
            else nobels--;
        }
        std::cout << "Famine caused " << deaths << " deaths due to lack of food." << std::endl;
    }
}
void Population::simulateWarCasualties(int deaths) {
    for (int i = 0; i < deaths; ++i) {
        population--;
        if (rand() % 2)peasents--;
        else nobels--;
    }
    std::cout << "War casualties: " << deaths << " citizens lost." << std::endl;
}
void Population::simulatePopulationGrowth() {
    if (foodSupply > population && healthcareLevel > 5 && jobAvailability > 5) {
        int growth = rand() % 10 + 5;
        for (int i = 0; i < growth; ++i) {
            population++;
            if (rand() % 2)peasents++;
            else nobels++;
        }
        std::cout << "Population grew by " << growth << " new citizens." << std::endl;
    }
    else {
        std::cout << "Conditions not suitable for growth." << std::endl;
    }
}
void Population::displayStats() const {
    std::cout << std::endl << "Population Stats:" << std::endl;
    std::cout << "Total: " << population << ", Food: " << foodSupply
        << ", Healthcare: " << healthcareLevel << ", Jobs: " << jobAvailability << std::endl;
    std::cout << "Peasants: " << peasents
        << ", Nobility: " << nobels << std::endl;
}
int Population::getpoor() const {
    return peasents;
}
int Population::getnoble() const {
    return nobels;
}

Player::Player() : name(""), army(20, 500, 200), active(true) {}
Player::Player(const std::string& n) : name(n), army(20, 500, 200), active(true) {}

void Event::triggerRandomEvent(Player& player) {
    int event = rand() % 10;
    if (event == 0) {
        player.economy.triggerRandomEvent();
    }
    if (event == 1) {
        player.population.simulatePlague();
    }
    else if (event == 2) {
        player.economy.simulateInflation();
    }
    else if (event == 3) {
        player.population.simulateFamine();
    }
    else if (event == 4) {
        player.population.simulatePopulationGrowth();
    }
}
std::string Event::getStringInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input.empty() ? "No message" : input;
}
void Event::clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(10000000, '\n');
}
int Event::getIntInput(const std::string& prompt, int min, int max) {
    int input;
    while (true) {
        std::cout << prompt;
        if (std::cin >> input && input >= min && input <= max) {
            clearInputBuffer();
            return input;
        }
        std::cout << "Invalid input. Enter a number between " << min << " and " << max << "." << std::endl;
        clearInputBuffer();
    }
}
int Event::displayMainMenu(const std::string& playerName) {
    system("cls");
    std::cout << std::endl;
    std::cout << "=== " << playerName << "'s Turn ===" << std::endl;
    std::cout << "1. Manage Economy" << std::endl;
    std::cout << "2. Trade Resources" << std::endl;
    std::cout << "3. Diplomacy" << std::endl;
    std::cout << "4. Manage Army" << std::endl;
    std::cout << "5. Communication" << std::endl;
    std::cout << "6. Skip Turn" << std::endl;
    return getIntInput("Choose an action (1-6): ", 1, 6);
}
void Event::handleArmy(Player& player, const Vector<Player>& players){
    int attackerPopulation, defenderPopulation, count, population, kingdomChoice;
    Vector<int> activeIndices;
    Player& opponent = player;
    while (true) {
        std::system("cls");
        std::cout << std::endl;
        std::cout << "=== Army Menu ===" << std::endl;
        std::cout << "1. Recruit Soldiers" << std::endl;
        std::cout << "2. Produce Weapons" << std::endl;
        std::cout << "3. Feed Army" << std::endl;
        std::cout << "4. Battle Another Kingdom" << std::endl;
        std::cout << "5. View Army Status" << std::endl;
        std::cout << "6. Back" << std::endl;
        int choice = getIntInput("Choose an option (1-6): ", 1, 6);
        if (choice == 6)break;
        switch (choice) {
        case 1:
            count = getIntInput("Enter number of soldiers to recruit (1-10): ", 1, 10);
            population = player.population.getpoor() + player.population.getnoble();
            player.army.recruitSoldiers(population, player.economy.getGold(), count);
            player.population.setPopulation(population, player.population.getpoor(), player.population.getnoble());
            break;
        case 2:
            if (!player.army.getGeneral()) {
                player.army.assignGeneral("General_" + player.name);
            }
            player.army.produceWeapons(player.economy.getGold());
            break;
        case 3:
            player.army.feedArmy(player.resources.getResourceAmount(FOOD));
            break;
        case 4:
            std::cout << "Available kingdoms to battle:" << std::endl;
            for (int i = 0; i < players.size(); i++) {
                if (players[i].active && players[i].name != player.name) {
                    activeIndices.push_back(i);
                    std::cout << i + 1 << ". " << players[i].name << std::endl;
                }
            }
            if (activeIndices.empty()) {
                std::cout << "No other active kingdoms to battle." << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
                return;
            }
            kingdomChoice = getIntInput("Choose a kingdom to battle (1-" + std::to_string(activeIndices.size()) + "): ", 1, activeIndices.size());
            opponent = const_cast<Player&>(players[activeIndices[kingdomChoice - 1]]);
            if (!player.army.getGeneral()) {
                player.army.assignGeneral("General_" + player.name);
            }
            if (!opponent.army.getGeneral()) {
                opponent.army.assignGeneral("General_" + opponent.name);
            }
            attackerPopulation = player.population.getpoor() + player.population.getnoble();
            defenderPopulation = opponent.population.getpoor() + opponent.population.getnoble();
            player.army.simulateTwoPlayerBattle(opponent.army, player.economy.getGold(), player.resources.getResourceAmount(FOOD),
                opponent.economy.getGold(), opponent.resources.getResourceAmount(FOOD),
                attackerPopulation, defenderPopulation);
            player.population.setPopulation(attackerPopulation, player.population.getpoor(), player.population.getnoble());
            opponent.population.setPopulation(defenderPopulation, opponent.population.getpoor(), opponent.population.getnoble());
            break;
        case 5:
            player.army.displayStatus();
            break;
        }
        std::cout << player.name << " performed army action." << std::endl;
        player.army.displayStatus();
        std::this_thread::sleep_for(std::chrono::seconds(2));
        if (choice != 5) return;
    }
}
void Event::handleEconomy(Player& player) {
    while (true) {
        system("cls");
        std::cout << std::endl;
        std::cout << "=== Economy Menu ===" << std::endl;
        player.economy.displayStatus();
        std::cout << "1. Collect Taxes" << std::endl;
        std::cout << "2. Take 100 Gold As Loan" << std::endl;
        std::cout << "3. Back" << std::endl;
        int choice = getIntInput("Choose an option (1-3): ", 1, 3);
        switch (choice)
        {
        case 1:
            player.economy.collectTaxes(player.population.getpoor(), player.population.getnoble());
            std::cout << player.name << " collected taxes." << std::endl;
            player.economy.displayStatus();
            std::this_thread::sleep_for(std::chrono::seconds(2));
            return;
        case 2:
            player.economy.takeLoan(100.0f, 0.1f);
            std::cout << player.name << " took a loan of 100 gold with 10% interest." << std::endl;
            player.economy.displayStatus();
            std::this_thread::sleep_for(std::chrono::seconds(2));
            return;
        }
        if (choice == 3)break;
    }
}
void Event::handleTrade(Player& player) {
    player.market.showMarket();
    std::cout << "Resources:" << std::endl;
    player.resources.printResources();
    std::cout << "Gold: " << player.economy.getGold() << std::endl;
    int type = getIntInput("Choose resource (0: Wood, 1: Stone, 2: Iron, 3: Food): ", 0, 3);
    ResourceType resourceType = static_cast<ResourceType>(type);
    int amount = getIntInput("Enter amount to trade (1-10): ", 1, 10);
    int buySell = getIntInput("Buy (1) or Sell (0)? ", 0, 1);
    bool buy = buySell == 1;
    float price = player.market.getPrice(resourceType);
    if (buy && player.economy.getGold() >= amount * price) {
        player.economy.spendGold(amount * price);
        player.resources.addResource(resourceType, amount);
    }
    else if (!buy && player.resources.getResourceAmount(resourceType) >= amount) {
        player.resources.consumeResources(resourceType, amount);
        player.economy.addGold(amount * price);
    }
    else {
        std::cout << "Insufficient gold or resources." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return;
    }
    player.market.trade(resourceType, amount, buy);
    std::this_thread::sleep_for(std::chrono::seconds(2));
}
void Event::handleDiplomacy(Player& player, const Vector<Player>& players) {
    int allianceAction;
    while (true) {
        system("cls");
        std::cout << std::endl;
        std::cout << "=== Diplomacy Menu ===" << std::endl;
        std::cout << "1. Form/Break Alliance" << std::endl;
        std::cout << "2. Request Trade" << std::endl;
        std::cout << "3. Impose Sanction" << std::endl;
        std::cout << "4. View Diplomatic Status" << std::endl;
        std::cout << "5. Back" << std::endl;
        int choice = getIntInput("Choose an option (1-5): ", 1, 5);
        if (choice == 5) break;
        Vector<int> activeIndices;
        std::cout << "Available kingdoms:" << std::endl;
        for (int i = 0; i < players.size(); i++) {
            if (players[i].active && players[i].name != player.name) {
                activeIndices.push_back(i);
                std::cout << i + 1 << ". " << players[i].name << std::endl;
            }
        }
        if (activeIndices.empty()) {
            std::cout << "No other active kingdoms." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            return;
        }
        int kingdomChoice = getIntInput("Choose a kingdom (1-" + std::to_string(activeIndices.size()) + "): ", 1, activeIndices.size());
        Player& other = const_cast<Player&>(players[activeIndices[kingdomChoice - 1]]);
        player.diplomacy.addKingdom(other.name);
        switch (choice) {
        case 1:
            allianceAction = getIntInput("1. Form Alliance, 2. Break Alliance: ", 1, 2);
            if (allianceAction == 1) {
                player.diplomacy.formAlliance(other.name);
            }
            else {
                player.diplomacy.breakAlliance(other.name);
            }
            break;
        case 2:
            player.diplomacy.requestTrade(other.name);
            break;
        case 3:
            player.diplomacy.imposeSanctionOn(other.name);
            player.market.imposeSanction();
            break;
        case 4:
            player.diplomacy.showDiplomaticStatus();
        }
        std::cout << player.name << " performed diplomatic action." << std::endl;
        player.diplomacy.showDiplomaticStatus();
        std::this_thread::sleep_for(std::chrono::seconds(2));
        if (choice != 4) return;
    }
}
void Event::handleCommunication(Player& player, MultiplayerChat& chat, Vector<std::string>& messageLog) {
    while (true) {
        system("cls");
        std::cout << std::endl;
        std::cout << "=== Communication Menu ===" << std::endl;
        std::cout << "1. Send Message" << std::endl;
        std::cout << "2. View Message Log" << std::endl;
        std::cout << "3. Back" << std::endl;
        int choice = Event::getIntInput("Choose an option (1-3): ", 1, 3);
        if (choice == 1) {
            std::string msg = getStringInput("Enter message: ");
            chat.sendMessage(player.name, msg);
            messageLog.push_back(player.name + ": " + msg);
            std::cout << player.name << " sent a chat message." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        else if (choice == 2) {
            std::cout << std::endl;
            std::cout << "Message Log:" << std::endl;
            if (messageLog.empty()) std::cout << "No messages." << std::endl;
            else for (const auto& msg : messageLog) std::cout << msg << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        else {
            break;
        }
    }
}
void Event::playerTurn(Player& player, const Vector<Player>& players, MultiplayerChat& chat, Vector<std::string>& messageLog, int turn) {
    if (!player.active) return;
    system("cls");
    std::cout << std::endl;
    std::cout << "=== Turn " << turn << ": " << player.name << "'s Status ===" << std::endl;
    player.economy.displayStatus();
    player.economy.simulateLoanTurn();
    player.resources.printResources();
    player.population.displayStats();
    player.army.displayStatus();
    bool turnConsumed = false;
    while (!turnConsumed) {
        int action = displayMainMenu(player.name);
        switch (action) {
        case 1:
            handleEconomy(player);
            turnConsumed = true;
            break;
        case 2:
            handleTrade(player);
            std::cout << player.name << " conducted trade." << std::endl;
            turnConsumed = true;
            break;
        case 3:
            handleDiplomacy(player, players);
            std::cout << player.name << " engaged in diplomacy." << std::endl;
            turnConsumed = true;
            break;
        case 4: 
            handleArmy(player, players);
            std::cout << player.name << " managed army." << std::endl;
            turnConsumed = true;
            break;
        case 5:
            handleCommunication(player, chat, messageLog);
            break;
        case 6:
            std::cout << player.name << " skipped their turn." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            turnConsumed = true;
            break;
        }
    }
    triggerRandomEvent(player);
    player.population.displayStats();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    int totalPopulation = player.population.getpoor() + player.population.getnoble();
    if (totalPopulation <= 0) {
        player.active = false;
        std::cout << "!!! " << player.name << " has been eliminated due to zero population! !!!" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

