#include "Trade.h"

Market::Market() {
    inflationRate = 1.0f;
    srand(time(0));
    goods.push_back({ WOOD, 100, 5.0f });
    goods.push_back({ STONE, 100, 5.0f });
    goods.push_back({ IRON, 50, 15.0f });
    goods.push_back({ FOOD, 100, 5.0f });
}
void Market::fluctuatePrices() {
    for (int i = 0; i < goods.size(); i++) {
        float factor = ((rand() % 40) - 20) / 100.0f + 1.0f; // +/-20%
        goods[i].price *= factor;
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

void Diplomacy::formAlliance(const std::string& kingdom) {
    for (int i = 0; i < alliances.size(); i++) {
        if (alliances[i].first == kingdom) {
            alliances[i].second.first = true;
            std::cout << "Alliance formed with " << kingdom << std::endl;
        }
        break;
    }
}
void Diplomacy::breakAlliance(const std::string& kingdom) {
    for (int i = 0; i < alliances.size(); i++) {
        if (alliances[i].first == kingdom) {
            alliances[i].second.first = false;
            std::cout << "Alliance broken with " << kingdom << std::endl;
        }
        break;
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
        }
        break;
    }
}
void Diplomacy::imposeSanctionOn(const std::string& kingdom) {
    for (int i = 0; i < alliances.size(); i++) {
        if (alliances[i].first == kingdom) {
            alliances[i].second.second = false;
        }
        break;
    }
    std::cout << "Sanction imposed on " << kingdom << ". All trade blocked." << std::endl;
}
void Diplomacy::showDiplomaticStatus() {
    std::cout << std::endl << "Diplomatic Status:" << std::endl;
    for (int i = 0; i < alliances.size(); i++) {
        std::cout << alliances[i].first << ": Alliance " << (alliances[i].second.first ? "Active" : "Broken") << ", Trade " << (alliances[i].second.second ? "Yes" : "No") << std::endl;
    }
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

void RandomEvents::triggerRandomEvent() {
    int event = rand() % 10;
    if (event == WAR_THRESHOLD) {
        std::cout << "WAR BREAKS OUT!" << std::endl;
    }
    else if (event == PLAGUE_THRESHOLD) {
        std::cout << "PLAGUE STRIKES!" << std::endl;
    }
    else if (event == FAMINE_THRESHOLD) {
        std::cout << "FAMINE OCCURS!" << std::endl;
    }
}

Resource::Resource() {
    resources[WOOD] = 100;
    resources[STONE] = 100;
    resources[IRON] = 100;
    resources[FOOD] = 200;
}
const int RandomEvents::WAR_THRESHOLD = 7;
const int RandomEvents::PLAGUE_THRESHOLD = 3;
const int RandomEvents::FAMINE_THRESHOLD = 5;

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
void Resource::printResources() const {
    std::cout << "Resources" << std::endl;
    std::cout << "- Wood :" << resources[WOOD] << std::endl;
    std::cout << "- Stone :" << resources[STONE] << std::endl;
    std::cout << "- Iron :" << resources[IRON] << std::endl;
    std::cout << "- Food :" << resources[FOOD] << std::endl;
    std::cout << "===============================" << std::endl;
}

Finance::Finance() : treasuryGold(500), corruptionLevel(10), totalStolenGold(0), securityExpense(0) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}
void Finance::addGold(int amount) {
    treasuryGold += amount;
}
bool Finance::spendGold(int amount) {
    if (treasuryGold >= amount) {
        treasuryGold -= amount;
        return true;
    }
    std::cout << "Not enough gold to spend!" << std::endl;
    return false;
}
int& Finance::getGold() {
    return treasuryGold;
}
void Finance::takeLoan(int amount, int turns, double interest) {
    activeLoans.emplace_back(amount, turns, interest);
    treasuryGold += amount;
    std::cout << "Loan Taken: " << amount << " gold | Repay in " << turns << " turns at " << interest * 100 << "% interest" << std::endl;
}
void Finance::simulateLoanTurn() {
    for (int i = 0; i < activeLoans.size(); i++) {
        if (!activeLoans[i].isDefaulted) {
            activeLoans[i].remainingTurns--;
        }
    }
    checkDefaults();
}
bool Finance::repayLoan(int index) {
    if (index < 0 || index >= activeLoans.size()) return false;
    Loan& loan = activeLoans[index];

    if (loan.isDefaulted) {
        std::cout << "Cannot repay a defaulted loan." << std::endl;
        return false;
    }

    int dueAmount = static_cast<int>(loan.amount * (1.0 + loan.interestRate));
    if (spendGold(dueAmount)) {
        std::cout << "Repaid loan of " << loan.amount << " with " << loan.interestRate * 100 << "% interest (" << dueAmount << ")" << std::endl;
        activeLoans.erase(activeLoans.begin() + index);
        return true;
    }
    return false;
}
void Finance::checkDefaults() {
    for (int i = 0; i < activeLoans.size(); i++) {
        if (activeLoans[i].remainingTurns <= 0 && !activeLoans[i].isDefaulted) {
            activeLoans[i].isDefaulted = true;
            std::cout << "Loan of " << activeLoans[i].amount << " has defaulted! Land and assets may be seized." << std::endl;
            treasuryGold = std::max(0, treasuryGold - 100);
        }
    }
    for (int i = 0; i < activeLoans.size(); i++) {
        if (activeLoans[i].isDefaulted) {
            treasuryGold -= 100;
        }
    }
}
void Finance::simulateCorruption() {
    int chance = rand() % 100;
    if (chance < corruptionLevel) {
        int stolen = 10 + (rand() % 20);
        treasuryGold -= stolen;
        totalStolenGold += stolen;
        std::cout << "Officials stole " << stolen << " gold from treasury." << std::endl;
    }

    if (securityExpense > 0) {
        treasuryGold -= securityExpense;
        std::cout << "Spent " << securityExpense << " gold on security expenses." << std::endl;
    }
}
void Finance::triggerFraud(FraudEvent event) {
    switch (event) {
    case BANKHEIST: {
        treasuryGold -= 150;
        std::cout << "Bank heist! Lost 150 gold." << std::endl;
        securityExpense += 10;
        break;
    }
    case EMBEZZLMENT: {
        treasuryGold -= 100;
        corruptionLevel += 10;
        std::cout << "Embezzlement detected! Lost 100 gold." << std::endl;
        break;
    }
    case NONE:
    default:
        break;
    }
}
void Finance::audit() {
    const int auditCost = 30;
    if (!spendGold(auditCost)) {
        std::cout << "Audit aborted — not enough funds." << std::endl;
        return;
    }
    std::cout << "Audit initiated. Cost: " << auditCost << " gold." << std::endl;
    simulateAuditResult();
}
void Finance::simulateAuditResult() {
    if (corruptionLevel >= 40) {
        treasuryGold += 20 + (rand() % 30);
        corruptionLevel -= (15 - (rand() % 11));
        std::cout << "Audit successful. Recovered  gold. Corruption reduced." << std::endl;
    }
    else {
        std::cout << "No significant corruption found. Public trust improved." << std::endl;
        corruptionLevel -= 5;
    }
}
void Finance::normalizedata() {
    if (corruptionLevel < 0) {
        corruptionLevel = 0;
    }
    if (treasuryGold < 0) {
        corruptionLevel += -(treasuryGold);
        treasuryGold = 0;
    }
}
void Finance::printFinanceReport() const {
    std::cout << "===== Treasury Report =====" << std::endl;
    std::cout << "Gold: " << treasuryGold << std::endl;
    std::cout << "Active Loans: " << activeLoans.size() << std::endl;
    for (size_t i = 0; i < activeLoans.size(); ++i) {
        const auto& loan = activeLoans[i];
        std::cout << " - Loan #" << i + 1
            << " | Amount: " << loan.amount
            << " | Remaining: " << loan.remainingTurns
            << " | Interest: " << loan.interestRate * 100 << "%"
            << " | Status: " << (loan.isDefaulted ? "Defaulted" : "Active") << std::endl;
    }
    std::cout << "Corruption Level: " << corruptionLevel << "/100" << std::endl;
    std::cout << "Total Stolen: " << totalStolenGold << " gold" << std::endl;
    std::cout << "Security Expense/Turn: " << securityExpense << std::endl;
    std::cout << "===========================" << std::endl;
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
void Army::simulateBattle(int& gold, int& food) {
    std::cout << "Battle begins!" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    int losses = rand() % (soldiers / 2);
    soldiers -= losses;
    food -= losses * 2;
    gold -= losses * 3;
    std::cout << "Lost " << losses << " soldiers in battle." << std::endl;
}
void Army::displayStatus() const {
    std::cout << std::endl << "Army Status:" << std::endl;
    std::cout << "Soldiers: " << soldiers << ", Weapons: " << weapons << std::endl;
    if (general) std::cout << "General: " << general->name << (general->corrupt ? " (Corrupt)" : " (Loyal)") << std::endl;
}

Economy::Economy() {
    treasury = 1000.0f;
    inflationRate = 2.0f;
    corruptionLevel = 0.1f;
    marketHealth = 100.0f;
    poorPopulation = 500;
    noblePopulation = 100;
    taxRatePoor = 0.05f;
    taxRateNoble = 0.15f;
    progressiveTax = true;
    marketCrash = false;
    hospitalBudget = 200.0f;
    foodBudget = 150.0f;
    militaryBudget = 250.0f;
}
void Economy::setTaxRates(float poorRate, float nobleRate, bool isProgressive) {
    taxRatePoor = poorRate;
    taxRateNoble = nobleRate;
    progressiveTax = isProgressive;
}
void Economy::collectTaxes() {
    float totalTax = (poorPopulation * 10 * taxRatePoor) + (noblePopulation * 50 * taxRateNoble);
    float corruptionLoss = totalTax * corruptionLevel;
    treasury += (totalTax - corruptionLoss);
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
    treasury *= (1.0f - (inflationRate / 100.0f));
    std::cout << "Inflation reduced treasury by " << inflationRate << "%." << std::endl;
}
void Economy::printMoney(float amount) {
    treasury += amount;
    inflationRate += amount / 1000.0f;
    std::cout << "Printed " << amount << " gold. Inflation increased to " << inflationRate << "%." << std::endl;
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
        treasury += 200;
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
        treasury *= 0.6f;
        marketCrash = true;
    }
}
bool Economy::allocateBudget(float hospital, float food, float military) {
    float total = hospital + food + military;
    if (total > treasury) {
        std::cout << "Not enough treasury funds to allocate this budget." << std::endl;
        return false;
    }
    hospitalBudget += hospital;
    foodBudget += food;
    militaryBudget += military;
    treasury -= total;
    std::cout << "Budget allocated successfully." << std::endl;
    return true;
}
void Economy::showBudgetStatus() {
    std::cout << "Hospital: " << hospitalBudget << std::endl;
    std::cout << "Food: " << foodBudget << std::endl;
    std::cout << "Military: " << militaryBudget << std::endl;
}
void Economy::showEconomyStatus() {
    std::cout << "Treasury: " << treasury << std::endl;
    std::cout << "Inflation Rate: " << inflationRate << "%" << std::endl;
    std::cout << "Corruption Level: " << corruptionLevel << std::endl;
    std::cout << "Market Health: " << marketHealth << "%" << std::endl;
    std::cout << "Progressive Tax: " << (progressiveTax ? "ON" : "OFF") << std::endl;
    showBudgetStatus();
    if (marketCrash)
        std::cout << "Market has recently crashed!" << std::endl;
}
float Economy::getTreasury() const {
    return treasury;
}

King::King(const std::string& name) {
    this->name = name;
    this->popularity = rand() % 100;
    alive = true;
}
void King::displayProfile() const {
    std::cout << "King: " << name << " | Popularity: " << popularity * 100 << "%" << std::endl;
}

Faction::Faction(const std::string& name, float influence) {
    this->name = name;
    this->influence = influence;
    supportsCurrentKing = false;
}

KingElectionSystem::KingElectionSystem() {
    currentKing = nullptr;
    instability = false;
    srand(time(0));
}
void KingElectionSystem::addCandidate(const std::string& name) {
    King k(name);
    candidates.emplace_back(k);
}
void KingElectionSystem::addFaction(const std::string& name, float influence) {
    factions.emplace_back(name, influence);
}
void KingElectionSystem::holdElection() {
    std::cout << std::endl << "Election in progress..." << std::endl;
    std::vector<float> scores(candidates.size(), 0.0f);

    for (int i = 0; i < factions.size(); ++i) {
        int choice = rand() % candidates.size();
        scores[choice] += factions[i].influence;
    }
    int winnerIdx = distance(scores.begin(), max_element(scores.begin(), scores.end()));
    currentKing = &candidates[winnerIdx];
    std::cout << "New King Elected!!!";
    currentKing->displayProfile();

    instability = false;
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
        instability = true;
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
    instability = true;
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
    population = 100;
    foodSupply = 100;
    healthcareLevel = 5;
    jobAvailability = 5;
    classCounts[PEASANT] = 0;
    classCounts[MERCHANT] = 0;
    classCounts[NOBILITY] = 0;
    srand(time(0));
    setDefaultTaxRates();
    for (int i = 0; i < 100; i++) {
        SocialClass sc = static_cast<SocialClass>(rand() % 3);
        classCounts[sc]++;
    }
}
void Population::setDefaultTaxRates() {
    taxRates[PEASANT] = 0.1f;
    taxRates[MERCHANT] = 0.2f;
    taxRates[NOBILITY] = 0.05f;
}
void Population::simulatePlague() {
    int deaths = rand() % 20 + 10;
    for (int i = 0; i < deaths; ++i) {
        SocialClass sc = static_cast<SocialClass>(rand() % 3);
        population--;
        classCounts[sc]--;
    }
    std::cout << "Plague struck! " << deaths << " people died." << std::endl;
}
void Population::simulateFamine() {
    if (foodSupply < population) {
        int deaths = (population - foodSupply) / 2;
        for (int i = 0; i < deaths; ++i) {
            SocialClass sc = static_cast<SocialClass>(rand() % 3);
            population--;
            classCounts[sc]--;
        }
        std::cout << "Famine caused " << deaths << " deaths due to lack of food." << std::endl;
    }
}
void Population::simulateWarCasualties(int deaths) {
    for (int i = 0; i < deaths; ++i) {
        SocialClass sc = static_cast<SocialClass>(rand() % 3);
        population--;
        classCounts[sc]--;
    }
    std::cout << "War casualties: " << deaths << " citizens lost." << std::endl;
}
void Population::simulatePopulationGrowth() {
    if (foodSupply > population && healthcareLevel > 5 && jobAvailability > 5) {
        int growth = rand() % 10 + 5;
        for (int i = 0; i < growth; ++i) {
            SocialClass sc = static_cast<SocialClass>(rand() % 3);
            population++;
            classCounts[sc]++;
        }
        std::cout << "Population grew by " << growth << " new citizens." << std::endl;
    }
    else {
        std::cout << "Conditions not suitable for growth." << std::endl;
    }
}
void Population::adjustTaxRates(float peasant, float merchant, float nobility, float military) {
    taxRates[PEASANT] = peasant;
    taxRates[MERCHANT] = merchant;
    taxRates[NOBILITY] = nobility;
    checkForClassConflict();
}
void Population::checkForClassConflict() {
    if (taxRates[PEASANT] > 0.2f && taxRates[NOBILITY] < 0.1f) {
        std::cout << "Class conflict brewing! Peasants are angry about unfair taxes." << std::endl;
    }
}
void Population::displayStats() const {
    std::cout << std::endl << "Population Stats:" << std::endl;
    std::cout << "Total: " << population << ", Food: " << foodSupply
        << ", Healthcare: " << healthcareLevel << ", Jobs: " << jobAvailability << std::endl;
    std::cout << "Peasants: " << classCounts[PEASANT]
        << ", Merchants: " << classCounts[MERCHANT]
        << ", Nobility: " << classCounts[NOBILITY] << std::endl;
}


