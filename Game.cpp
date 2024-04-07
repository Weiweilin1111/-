// Game.cpp

#include"Utils.h"

void Game::run() {
    srand(time(0)); 

    Cat myCat;
    string catName;
    cout << "給你的貓一個名字：";
    cin >> catName;
    myCat.setName(catName);

    while (myCat.isAlive()) {
        cout << "今天有" << myCat.getMoney() << "元，你要幹嘛？" << endl;
        myCat.printStatus();
        cout << "1. 買食物（水10元，肉15元，菜5元）\n2. 買股票（20元/張）\n3. 買彩券（10元/張）\n4. 過到隔天\n";
        int choice;
        cin >> choice;
        
        switch(choice) {
            case 1:
                // 食物
                break;
            case 2:
                // 股票
                break;
            case 3:
                // 彩券
                break;
            case 4:
                cout << "睡覺" << endl;
                myCat.dailyUpdate();
                break;
            default:
                cout << "蛤？給我重選" << endl;
                continue;
        }
    }
}

