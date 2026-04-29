#include <iostream>
#include <string>
using namespace std;

class Device
{
protected:
    string brand;
    double price;

public:
    Device(string b, double p) : brand(b), price(p) {}

    virtual double calculateDiscount() const
    {
        return price * 0.05; // 5% default
    }

    virtual void display() const
    {
        cout << brand
             << " | Price: Rs." << price
             << " | Discount: Rs." << calculateDiscount() << endl;
    }

    virtual ~Device() {}
};

class Laptop : public Device
{
public:
    Laptop(string b, double p) : Device(b, p) {}

    double calculateDiscount() const override
    {
        return price * 0.10; // 10%
    }
};

class Smartphone : public Device
{
public:
    Smartphone(string b, double p) : Device(b, p) {}

    double calculateDiscount() const override
    {
        return price > 50000 ? price * 0.15 : price * 0.08;
    }
};

int main()
{
    Device *devices[] = {
        new Laptop("Dell XPS", 90000),
        new Smartphone("Samsung S24", 80000),
        new Smartphone("Realme 12", 20000),
        new Device("Generic Dev", 15000)};

    int n = sizeof(devices) / sizeof(devices[0]);

    cout << "--- Discount Summary ---" << endl;
    for (int i = 0; i < n; i++)
    {
        devices[i]->display();
        delete devices[i];
    }

    return 0;
}