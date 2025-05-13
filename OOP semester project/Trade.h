#pragma once
#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <thread>

template<class A, class B>
class Pair {
public:
    A first;
    B second;
};

template<class T>
class Vector {
private:
    T* data;
    int s;
public:
    Vector() {
        data = nullptr;
        s = 0;
    }
    Vector(int size, T value) {
        s = size;
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = value;
        }
    }
    int size() const {
        return s;
    }
    void push_back(const T& value) {
        s++;
        T* temp = new T[s];
        for (int i = 0; i < s - 1; i++) {
            temp[i] = data[i];
        }
        temp[s - 1] = value;
        delete[] data;
        data = temp;
    }
    T* begin() {
        return data;
    }
    T* end() {
        return data + s;
    }
    void erase(int index) {
        if (index < 0 || index >= s) return;
        T* temp = new T[s - 1];
        for (int i = 0; i < index; ++i)
            temp[i] = data[i];
        for (int i = index + 1; i < s; ++i)
            temp[i - 1] = data[i];
        delete[] data;
        data = temp;
        --s;
    }
    T* erase(T* pos) {
        if (pos < begin() || pos >= end()) return end();
        int index = pos - data;
        T* temp = new T[s - 1];
        for (int i = 0; i < index; ++i)
            temp[i] = data[i];
        for (int i = index + 1; i < s; ++i)
            temp[i - 1] = data[i];
        delete[] data;
        data = temp;
        --s;
        return data + index; 
    }
    T& operator[](size_t index) {
        return data[index];
    }
    const T& operator[](size_t index) const {
        return data[index];
    }
    Vector(const Vector& other) {
        s = other.s;
        data = new T[s];
        for (int i = 0; i < s; ++i)
            data[i] = other.data[i];
    }
    Vector& operator=(const Vector& other) {
        if (this == &other) return *this;
        delete[] data;
        s = other.s;
        data = new T[s];
        for (int i = 0; i < s; ++i)
            data[i] = other.data[i];
        return *this;
    }
    ~Vector() {
        delete[] data;
    }
    bool empty() {
        return (s == 0);
    }
};

enum ResourceType { WOOD, STONE, IRON, FOOD };
enum FraudEvent { NONE, BANKHEIST, EMBEZZLMENT };

class Good {
public:
    ResourceType type;
    int quantity;
    float price;
};
class Market {
private:
    Vector<Good> goods;
    float inflationRate;

public:
    Market();
    void fluctuatePrices();
    void trade(ResourceType type, int amount, bool buying);
    void imposeSanction();
    void showMarket();
    float getPrice(ResourceType type);
};
class Diplomacy {
private:
    Vector<Pair<std::string, Pair<bool,bool>>> alliances;
public:
    void formAlliance(const std::string& kingdom);
    void breakAlliance(const std::string& kingdom);
    void requestTrade(const std::string& kingdom);
    void imposeSanctionOn(const std::string& kingdom);
    void showDiplomaticStatus();
    void addKingdom(const std::string& kingdom);
};
class MultiplayerChat {
private:
    Vector<std::string> messageLog;

public:
    void sendMessage(const std::string& from, const std::string& msg);
    void showChatHistory();
};
class Resource {
private:
    int resources[4];
public:
    Resource();
    void produceResources(ResourceType type, int amount);
    bool consumeResources(ResourceType type, int amount);
    void addResource(ResourceType type, int amount);
    int& getResourceAmount(ResourceType type);
    int getResourceAmount(ResourceType type) const;
    void printResources() const;
};
class Economy {
private:
    float inflationRate;
    float corruptionLevel;
    float marketHealth;
    float taxRatePoor;
    float taxRateNoble;
    bool progressiveTax;
    bool marketCrash;
    int securityExpense;
    int treasuryGold;
    int debt;
public:
    Economy();
    void collectTaxes(int poorPopulation, int noblePopulation);
    void setTaxRates(float poorRate, float nobleRate, bool isProgressive);
    void simulateInflation();
    void triggerRandomEvent();
    void checkMarketCrash();
    void increaseCorruption(float amount);
    void setCorruption(float amount);
    void displayStatus();
    void simulateCorruption();
    void simulateLoanTurn();
    void triggerFraud(FraudEvent event);
    void audit();
    void normalizedata();
    void takeLoan(int amount, float interest);
    int getDebt();
    void addGold(int amount);
    bool spendGold(int amount);
    int& getGold();
    int getGold() const;
};
class General {
public:
    std::string name;
    bool corrupt;

    General(const std::string& name);
};
class Army {
private:
    int soldiers;
    int blacksmiths;
    General* general;
    int weapons;
    float moral;
public:
    Army(int soldiers, int gold, int food);
    void recruitSoldiers(int& population, int& gold, int count);
    void assignGeneral(const std::string& name);
    void produceWeapons(int& gold);
    void feedArmy(int& food);
    void checkMorale();
    General* getGeneral() const;
    void displayStatus() const;
    void simulateTwoPlayerBattle(Army& opponent, int& attackerGold, int& attackerFood, int& defenderGold, int& defenderFood, int& attackerPopulation, int& defenderPopulation);
    ~Army();
};
class King {
public:
    std::string name;
    float popularity;
    bool alive;
    King();
    King(const std::string& name);
    void displayProfile() const;
};
class Faction {
public:
    std::string name;
    float influence; // 0 to 1
    bool supportsCurrentKing;
    Faction();
    Faction(const std::string& name, float influence);
};
class KingElectionSystem {
private:
    Vector<King> candidates;
    Vector<Faction> factions;
    King* currentKing;

public:
    KingElectionSystem();
    void addCandidate(const std::string& name);
    void addFaction(const std::string& name, float influence);
    void holdElection();
    void simulateBribery();
    void simulateBlackmail();
    void simulateAssassination();
    void checkCoupRisk();
    void kingDiedInBattle();
    void displayCurrentKing() const;
};
class Population {
private:
    int population;
    int foodSupply;
    int healthcareLevel;
    int jobAvailability;
    int nobels;
    int peasents;
public:
    Population();
    void setPopulation(int pop, int peas, int nob);
    void simulatePlague();
    void simulateFamine();
    void simulateWarCasualties(int deaths);
    void simulatePopulationGrowth();
    void displayStats() const;
    int getpoor() const;
    int getnoble() const;
};
class Player {
public:
    std::string name;
    Market market;
    Diplomacy diplomacy;
    Resource resources;
    Army army;
    Economy economy;
    KingElectionSystem electionSystem;
    Population population;
    bool active;
    Player();
    Player(const std::string& n);
};
class Event {
public:
    static void triggerRandomEvent(Player& player);
    static std::string getStringInput(const std::string& prompt);
    static void clearInputBuffer();
    static int displayMainMenu(const std::string& playerName);
    static int getIntInput(const std::string& prompt, int min, int max);
    static void handleArmy(Player& player, const Vector<Player>& players);
    static void handleEconomy(Player& player);
    static void handleTrade(Player& player);
    static void handleDiplomacy(Player& player, const Vector<Player>& players);
    static void handleCommunication(Player& player, MultiplayerChat& chat, Vector<std::string>& messageLog);
    static void playerTurn(Player& player, const Vector<Player>& players, MultiplayerChat& chat, Vector<std::string>& messageLog, int turn);
};
