#include "Utils.h"

Cat::Cat() : name(""), water(80), meat(80), veggie(80), money(100), stocks(0), alive(true) {}

void Cat::dailyUpdate() {
    if (alive) {
        water -= 15;
        meat -= 20;
        veggie -= 25;

        if (water < 40)
            water -= 10;
        if (meat < 40)
            meat -= 10;
        if (veggie < 40)
            veggie -= 10;

        if (water <= 0 || meat <= 0 || veggie <= 0)
            alive = false;

       
        int stockDividend = stocks * 2;
        money += stockDividend;
        cout << "今天的股票分紅：" << stockDividend << "元" << endl;
    }

    money += 50; 
}

void Cat::buyFood(string food, int price, int quantity) {
    if (money >= price * quantity) {
        if (food == "水") {
            water += 30 * quantity;
        } else if (food == "肉") {
            meat += 40 * quantity;
        } else if (food == "菜") {
            veggie += 50 * quantity;
        } else {
            cout << "啥！我們這沒這食物" << endl;
            return;
        }
        money -= price * quantity;
    } else {
        cout << "沒錢惹！" << endl;
    }
}

void Cat::buyStock(int times) {
    int totalPrice = 20 * times;
    if (money >= totalPrice) {
        money -= totalPrice;
        cout << "你購買了" << times << "張股票！每天會有分紅2元。" << endl;
        stocks += times; 
    } else {
        cout << "沒錢惹！" << endl;
    }
}

void Cat::buyLottery(int times) {
    int totalPrice = 10 * times;
    if (money >= totalPrice) {
        money -= totalPrice;
        for (int i = 0; i < times; ++i) {
            if (rand() % 100 < 30) {
                money *= 2; 
                cout << "恭喜中獎！" << endl;
            } else {
                cout << "雪本無歸。" << endl;
            }
        }
    } else {
        cout << "沒錢惹！" << endl;
    }
}

bool Cat::isAlive() {
    return alive;
}

void Cat::printStatus() {
    cout << name << "的健康狀況：" << endl;
    cout << "水：" << water << endl;
    cout << "肉：" << meat << endl;
    cout << "菜：" << veggie << endl;
    cout << "股票份額：" << stocks << endl; 
    cout << "剩餘錢：" << money << "元" << endl;
}

int Cat::getMoney() const {
    return money;
}

void Cat::setName(const string& newName) {
    name = newName;
}
