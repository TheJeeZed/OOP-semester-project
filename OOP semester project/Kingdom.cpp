#include "Kingdom.h"
#include <thread>
#include <chrono>
#include <fstream>
#include <cstdlib>

Leader::Leader(std::string n) : name(n), leadershipPoints(100) {}
Leader::~Leader() {}

King::King(std::string n) : Leader(n) {}
void King::makeDecision() {
    std::cout << name << " (King) is making a decision.\n";
}

Commander::Commander(std::string n) : Leader(n) {}
void Commander::makeDecision() {
    std::cout << name << " (Commander) is making a decision.\n";
}

template <typename T>
Resource<T>::Resource() : quantity(0) {}

template <typename T>
void Resource<T>::setQuantity(T q) { quantity = q; }

template <typename T>
T Resource<T>::getQuantity() const { return quantity; }

Army::Army() : soldiers(0) {}

void Army::recruit(int number) {
    if (number < 0) throw std::invalid_argument("Cannot recruit negative soldiers.");
    soldiers += number;
}

void Army::train() {
    std::cout << "Training soldiers... Please wait.\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Training completed.\n";
}

Bank::Bank() : balance(1000.0) {}

void Bank::takeLoan(double amount) {
    if (amount <= 0) throw std::invalid_argument("Loan amount must be positive.");
    balance += amount;
}

void Bank::repayLoan(double amount) {
    if (amount <= 0 || amount > balance) throw std::invalid_argument("Invalid repayment.");
    balance -= amount;
}

Kingdom::Kingdom(std::string name) : kingdomName(name), currentKing(std::make_unique<King>("Arthur")) {}

void Kingdom::startGame() {
    std::cout << "Starting the game for kingdom: " << kingdomName << "\n";
    currentKing->makeDecision();
}

void Kingdom::handleEvent() {
    srand(time(0));
    int event = rand() % 3;
    switch (event) {
    case 0:
        std::cout << "A plague has hit the kingdom!\n";
        break;
    case 1:
        std::cout << "Enemy forces are approaching!\n";
        break;
    case 2:
        std::cout << "Good harvest this season!\n";
        break;
    }
}
