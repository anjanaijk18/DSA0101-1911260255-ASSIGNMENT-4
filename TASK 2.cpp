#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int id;
    string phone;

public:
    Person()
    {
        name = "Unknown";
        id = 0;
        phone = "Not given";
    }
};

class Student : virtual public Person
{
protected:
    string programme;
    double cgpa;

public:
    Student()
    {
        programme = "CSE";
        cgpa = 8.5;
    }
};

class Staff : virtual public Person
{
protected:
    string department;
    double salary;

public:
    Staff()
    {
        department = "Computer Science";
        salary = 30000;
    }
};

class TeachingAssistant : public Student, public Staff
{
public:
    TeachingAssistant()
    {
        name = "Anjanai";
        id = 101;
        phone = "9876543210";
    }

    void display()
    {
        cout << "Teaching Assistant Details\n";
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Phone: " << phone << endl;
        cout << "Programme: " << programme << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

class ResearchScholar : public Student
{
private:
    double fellowship;

public:
    ResearchScholar()
    {
        fellowship = 15000;
    }

    void display()
    {
        cout << "\nResearch Scholar Details\n";
        cout << "Programme: " << programme << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Fellowship: " << fellowship << endl;
    }
};

int main()
{
    TeachingAssistant ta;
    ta.display();

    ResearchScholar rs;
    rs.display();

    return 0;
}
