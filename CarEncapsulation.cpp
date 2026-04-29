#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string model;
    int year;
    double speed;

public:
    void setModel(string m) { model = m; }
    void setYear(int y) { year = y; }
    void setSpeed(double s) { speed = s; }

    string getModel() const { return model; }
    int getYear() const { return year; }
    double getSpeed() const { return speed; }

    void display() const
    {
        cout << "Model: " << model
             << " | Year: " << year
             << " | Speed: " << speed << " km/h" << endl;
    }
};

int main()
{
    Car c;
    c.setModel("BMW M5");
    c.setYear(2024);
    c.setSpeed(320);

    c.display();
    cout << "Retrieved model: " << c.getModel() << endl;

    return 0;
}