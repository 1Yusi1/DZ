#include <iostream>
#include <memory>

class Enemy{
public:
    virtual void infoEnemy() const = 0;
    virtual ~Enemy() = default;
};

class Minion : public Enemy {
public:
    void infoEnemy() const override {
        std::cout << "Your enemy is the minion\n";
    }
    ~Minion() override {}
};

class Orc : public Enemy {
public:
    void infoEnemy() const override {
        std::cout << "Your enemy is the orc\n";
    }
    ~Orc() override {}
};

class Enviroment{
public:
    virtual void infoEnviroment() const = 0;
};

class Field : public Enviroment {
public:
    void infoEnviroment() const override{
        std::cout << "The place to fight is the field\n";
    }
};

class Volcano : public Enviroment {
public:
    void infoEnviroment() const override{
        std::cout << "The place to fight is the volcano\n";
    }
};

class LevelFactory{
public:
    virtual std::unique_ptr<Enemy> addEnemy() = 0;
    virtual std::unique_ptr<Enviroment> addEnviroment() = 0;
};

class EasyLevel : public LevelFactory {
public:
    std::unique_ptr<Enemy> addEnemy(){
        return std::make_unique<Minion>();
    }

    std::unique_ptr<Enviroment> addEnviroment(){
        return std::make_unique<Field>();
    }
};

class HardLevel : public LevelFactory {
public:
    std::unique_ptr<Enemy> addEnemy(){
        return std::make_unique<Orc>();
    }

    std::unique_ptr<Enviroment> addEnviroment(){
        return std::make_unique<Volcano>();
    }
};

class Level {
private:
    std::unique_ptr<Enemy> enemy;
    std::unique_ptr<Enviroment> enviroment;
public:
    Level(LevelFactory& factory){
        enemy = factory.addEnemy();
        enviroment = factory.addEnviroment();
    }

    void printInfo() const{
        enemy->infoEnemy();
        enviroment->infoEnviroment();
    }
};

int main(){
    EasyLevel easy;
    Level level1(easy);
    level1.printInfo();

    std::cout << "\n";

    HardLevel hard;
    Level level2(hard);
    level2.printInfo();
}