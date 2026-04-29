#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int rollNumber;

public:
    Student(string n, int r) : name(n), rollNumber(r) {}

    void display() const
    {
        cout << "Name: " << name
             << ", Roll No: " << rollNumber << endl;
    }
};

int main()
{
    Student students[] = {
        Student("Alice", 101),
        Student("Bob", 102),
        Student("Charlie", 103)};

    int n = sizeof(students) / sizeof(students[0]);

    cout << "--- Student Records ---" << endl;
    for (int i = 0; i < n; i++)
        students[i].display();

    return 0;
}