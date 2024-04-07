#ifndef CAT_H
#define CAT_H

#include <string>

class Cat {
private:
    std::string name;
    int water;
    int meat;
    int veggie;
    int money;
    int stocks; 
    bool alive;

public:
    Cat();
    void dailyUpdate();
    void buyFood(std::string food, int price, int quantity);
    void buyStock(int times);
    void buyLottery(int times);
    bool isAlive();
    void printStatus();
    int getMoney() const;
    void setName(const std::string& newName);
};

#endif 
