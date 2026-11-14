#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Staff
{
protected:
string name;
int id;

public:
Staff(string n, int i)
{
name = n;
id = i;
}

virtual double pay() const = 0;

virtual void display() const
{
    cout << name << " (ID: " << id << ") ";
}

virtual ~Staff() {}
};

class Professor : public Staff
{
private:
double basic, research;

public:
Professor(string n, int i, double b, double r)
: Staff(n, i)
{
basic = b;
research = r;
}

double pay() const override
{
    return basic + basic * 0.42 + research;
}

void display() const override
{
    Staff::display();
    cout << "Professor Salary: Rs. " << pay() << endl;
}
};

class LabAssistant : public Staff
{
private:
double basic, da;

public:
LabAssistant(string n, int i, double b, double d)
: Staff(n, i)
{
basic = b;
da = d;
}

double pay() const override
{
    return basic + basic * 0.42 + da;
}

void display() const override
{
    Staff::display();
    cout << "Lab Assistant Salary: Rs. " << pay() << endl;
}
};

class GuestFaculty : public Staff
{
private:
double hours, rate;

public:
GuestFaculty(string n, int i, double h, double r)
: Staff(n, i)
{
hours = h;
rate = r;
}

double pay() const override
{
    return hours * rate;
}

void display() const override
{
    Staff::display();
    cout << "Guest Faculty Salary: Rs. " << pay() << endl;
}
};

int main()
{
vector<Staff*> staff;

staff.push_back(new Professor("Arun", 101, 40000, 5000));
staff.push_back(new LabAssistant("Priya", 102, 25000, 3000));
staff.push_back(new GuestFaculty("Kumar", 103, 20, 800));

cout << "STAFF PAYROLL DETAILS\n\n";

for(Staff* s : staff)
{
    s->display();
}

for(Staff* s : staff)
{
    delete s;
}

return 0;
}
