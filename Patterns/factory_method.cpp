#include <iostream>
#include <memory>

class Level {

public:
    virtual void createEnemy() = 0;
};

class EasyLevel : public Level {
public:
    void createEnemy() override{
        std::cout << "create minions\n";
    }
};

class HardLevel : public Level {
public:
    void createEnemy() override{
        std::cout << "create BOSS\n";
    }
};

int main(){
    HardLevel level1;
    EasyLevel level2;
    level1.createEnemy();
    level2.createEnemy();

}