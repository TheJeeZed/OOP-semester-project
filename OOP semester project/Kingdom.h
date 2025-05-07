#ifndef KINGDOM_H
#define KINGDOM_H

#include <string>
#include <vector>
#include <memory>
#include <exception>
#include <iostream>

class Leader {
protected:
    std::string name;
    int leadershipPoints;
public:
    Leader(std::string n);
    virtual void makeDecision() = 0;
    virtual ~Leader();
};

class King : public Leader {
public:
    King(std::string n);
    void makeDecision() override;
};

class Commander : public Leader {
public:
    Commander(std::string n);
    void makeDecision() override;
};

template <typename T>
class Resource {
private:
    T quantity;
public:
    Resource();
    void setQuantity(T q);
    T getQuantity() const;
};

class Army {
private:
    int soldiers;
public:
    Army();
    void recruit(int number);
    void train();
};

class Bank {
private:
    double balance;
public:
    Bank();
    void takeLoan(double amount);
    void repayLoan(double amount);
};

class Kingdom {
private:
    std::string kingdomName;
    std::unique_ptr<King> currentKing;
    Army army;
    Bank bank;
public:
    Kingdom(std::string name);
    void startGame();
    void handleEvent();
};

#endif