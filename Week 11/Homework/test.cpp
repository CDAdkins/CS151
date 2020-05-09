#include <iostream>
using namespace std;

class Creature {

};

class Animal : public Creature {
    protected:
        int num = 5;

    public:
        virtual int getInt() = 0;
};

class Cat : public Animal {
    public:
        virtual int getInt() {
            return this->num;
        }
};

int main() {
    Animal *pAnimal;
    pAnimal = new Cat;
    Cat c;
}