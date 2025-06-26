#include <string>
#include <iostream>

using namespace std;

class Database {
public:
    static Database& getInstance() {
        if(!instance){
            instance = new Database();
        }
        return *instance;
    }

    static void someOperation(){
        cout << "for example, an sql query" << endl;
    }

private:
    static Database* instance;

    Database(){}
};

Database* Database::instance = nullptr;

int main(){
    Database& data = Database::getInstance();
    data.someOperation();
}