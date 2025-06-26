#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Enemy{
public:
    Enemy(){}
    Enemy(string name, int health) : name(name), health(health) {}

    virtual int getHealth() {
        return health;
    };
    virtual string getName(){
        return name;
    }

    virtual ~Enemy() = default;
protected:
    string name;
    int health;
};

class Minion : public Enemy {
public:
    Minion() : Enemy("Minion", 10) {}
};

class Boss : public Enemy {
public:
    Boss() : Enemy("Dragon", 100) {}
};

class EnemyDecorator : public Enemy {
public:
    EnemyDecorator(unique_ptr<Enemy> enemy) : enemy_(move(enemy)){}

    int getHealth() override {
        return enemy_->getHealth();
    }

    string getName() override {
        return enemy_->getName();
    }
protected:
    unique_ptr<Enemy> enemy_;
};

class Armor : public EnemyDecorator {
public:
    Armor(unique_ptr<Enemy> enemy) : EnemyDecorator(move(enemy)){}
    int getHealth() override {
        return this->enemy_->getHealth() * 1.3;
    }
};

class Special : public EnemyDecorator {
public:
    Special(unique_ptr<Enemy> enemy) : EnemyDecorator(move(enemy)){}
    string getName() override {
        return "Rare " + this->enemy_->getName();
    }
};


int main(){
    unique_ptr<Enemy> enemy1= make_unique<Minion>();
    enemy1 = make_unique<Armor>(move(enemy1));
    enemy1 = make_unique<Special>(move(enemy1));

    cout << enemy1->getName() << " " << enemy1->getHealth() << endl;

}
