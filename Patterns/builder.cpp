#include <iostream>
#include <memory>
#include <string>

using namespace std;


//Возможно вместо строчек добавить всё-таки объекты
class Level {
public:
    Level(){}

    Level(string enemy, string map, string color) : 
            enemy_(enemy), map_(map), color_(color) {}

    void setEnemy(string enemy){
        enemy_ = enemy;
    }

    void setMap(string map){
        map_ = map;
    }

    void setColor(string color){
        color_ = color;
    }

    void printInfo(){
        cout <<"Info Level\nEnemy: " << enemy_ 
             <<"\nMap: " << map_
             <<"\nColor: " << color_;
    }

private:
    string enemy_;
    string map_;
    string color_;
};

class LevelBuilder {
public:
    void createLevel(){
        level = new Level();
    }
    virtual LevelBuilder* setEnemy() = 0;
    virtual LevelBuilder* setMap() = 0;
    virtual LevelBuilder* setColor() = 0;
    Level* getResult() {
        return level;
    }
    virtual ~LevelBuilder() {
        delete level;
    }
protected:
    Level* level;
};

class EasyLevelBuilder : public LevelBuilder {
public:
    EasyLevelBuilder() : LevelBuilder(){}

    LevelBuilder* setEnemy() override {
        this->level->setEnemy("Minion");
        return this;
    }

    LevelBuilder* setMap() override {
        this->level->setMap("Field");
        return this;
    }

    LevelBuilder* setColor() override {
        this->level->setColor("Green");
        return this;
    }
};

class HardLevelBuilder : public LevelBuilder {
public:
    HardLevelBuilder() : LevelBuilder(){}

    LevelBuilder* setEnemy() override {
        this->level->setEnemy("Dragon");
        return this;
    }

        LevelBuilder* setMap() override {
        this->level->setMap("Volcano");
        return this;
    }

        LevelBuilder* setColor() override {
        this->level->setColor("Red");
        return this;
    }
};

class Director {
public:
    Level* buildLevel(LevelBuilder* builder){
        builder->createLevel();
        builder->setEnemy()->setMap()->setColor();
        return builder->getResult();
    }
};

int main(){
    Director* director = new Director();
    LevelBuilder* builder = new EasyLevelBuilder();
    Level* newLevel = director->buildLevel(builder);
    newLevel->printInfo();

    builder = new HardLevelBuilder();
    newLevel = director->buildLevel(builder);
    newLevel->printInfo();

    delete newLevel;
    delete builder;
    delete director;

}