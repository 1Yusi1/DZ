#include <iostream>
#include <memory>
#include <string>

using namespace std;

class EnemyPrototype {
public:
    EnemyPrototype(int healt, int power, string name)
                    :  _health(healt), _power(power), _name(name) {}

    EnemyPrototype(EnemyPrototype* enemy){
        this->_health = enemy->_health;
        this->_power = enemy->_power;
        this->_name = enemy->_name;
    }

    virtual EnemyPrototype* clone() = 0;

    virtual string ToString() {
        return _name + '\n' + to_string(_health) + '\n' + to_string(_power);
    }

protected:
    int _health;
    int _power;
    string _name;
};

class Minion : public EnemyPrototype{
public:
    Minion(int health, int power, string name, string color) : EnemyPrototype(health, power, name), _color(color){}

    Minion(EnemyPrototype* enemy, string color) : EnemyPrototype(enemy) {
        this->_color = color;
    }

    EnemyPrototype* clone() override {
        return new Minion(this, this->_color);
    }

    string ToString() override {
        return "Minion\n" + EnemyPrototype::ToString() + '\n' + _color;
    }

protected:
    string _color;
};

class Goblin : public EnemyPrototype{
public:
    Goblin(int health, int power, string name, string weapon) : EnemyPrototype(health, power, name), _weapon(weapon){}

    Goblin(EnemyPrototype* enemy, string weapon) : EnemyPrototype(enemy) {
        this->_weapon = weapon;
    }

    EnemyPrototype* clone() override {
        return new Goblin(this, this->_weapon);
    }

    string ToString() override {
        return "Goblin\n" + EnemyPrototype::ToString() + '\n' + _weapon;
    }
    
protected:
    string _weapon;
};

int main() {
    Minion* minion = new Minion(10, 10, "mini", "yellow");

    Minion* minion_clone = static_cast<Minion*>(minion->clone());

    cout << minion->ToString() << endl;
    cout << "copy\n";
    cout << minion_clone->ToString() << endl;

    EnemyPrototype* goblin = new Goblin(10, 20, "Gar", "bow");
    cout << goblin->clone()->ToString() << endl;

    delete minion;
    delete minion_clone;
    delete goblin;
}
