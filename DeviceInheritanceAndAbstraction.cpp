#include <iostream>
#include <string>
using namespace std;

class Device
{
private:
    string brand;
    double powerConsumption;

public:
    void setBrand(string b) { brand = b; }
    void setPower(double p) { powerConsumption = p; }
    string getBrand() const { return brand; }
    double getPower() const { return powerConsumption; }

    virtual void displayInfo() const
    {
        cout << "Brand: " << brand
             << " | Power: " << powerConsumption << "W";
    }
};

class Laptop : public Device
{
    int ramGB;

public:
    Laptop(string b, double p, int r)
    {
        setBrand(b);
        setPower(p);
        ramGB = r;
    }

    void displayInfo() const override
    {
        Device::displayInfo();
        cout << " | RAM: " << ramGB << "GB [Laptop]" << endl;
    }
};

class Smartphone : public Device
{
    double screenInch;

public:
    Smartphone(string b, double p, double s)
    {
        setBrand(b);
        setPower(p);
        screenInch = s;
    }

    void displayInfo() const override
    {
        Device::displayInfo();
        cout << " | Screen: " << screenInch << "\" [Smartphone]" << endl;
    }
};

int main()
{
    Laptop lap("Dell", 65.0, 16);
    Smartphone smp("Samsung", 18.0, 6.7);

    lap.displayInfo();
    smp.displayInfo();

    return 0;
}