#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void makeSound() const = 0; // pure virtual
    virtual void move() const = 0;      // pure virtual

    virtual void describe() const
    {
        makeSound();
        move();
    }

    virtual ~Animal() {}
};

class Lion : public Animal
{
public:
    void makeSound() const override
    {
        cout << "Lion:  ROAR!" << endl;
    }
    void move() const override
    {
        cout << "Lion:  Eats deer and buffalo meat." << endl;
    }
};

class Fish : public Animal
{
public:
    void makeSound() const override
    {
        cout << "Fish:  Blub blub..." << endl;
    }
    void move() const override
    {
        cout << "Fish:  Eats small insects and plankton." << endl;
    }
};

int main()
{
    Animal *animals[] = {
        new Lion(),
        new Fish(),
        new Lion(),
        new Fish()};

    int n = sizeof(animals) / sizeof(animals[0]);

    cout << "--- Animal Polymorphism Demo ---" << endl;
    for (int i = 0; i < n; i++)
    {
        animals[i]->describe();
        cout << endl;
        delete animals[i];
    }

    return 0;
}