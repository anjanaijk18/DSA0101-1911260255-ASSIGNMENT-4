PART 1 – PASS VALUES TO BASE CONSTRUCTORS
    
#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
string name;
int id;

public:
Person(string n, int i) : name(n), id(i)
{
cout << "Person constructor\n";
}

~Person()
{
    cout << "Person destructor\n";
}
};

class Student : virtual public Person
{
protected:
double cgpa;

public:
Student(string n, int i, double c)
: Person(n, i), cgpa(c)
{
cout << "Student constructor\n";
}

~Student()
{
    cout << "Student destructor\n";
}
};

class Staff : virtual public Person
{
protected:
string department;
double salary;

public:
Staff(string n, int i, string d, double s)
: Person(n, i), department(d), salary(s)
{
cout << "Staff constructor\n";
}

~Staff()
{
    cout << "Staff destructor\n";
}
};

class TeachingAssistant : public Student, public Staff
{
public:
TeachingAssistant(string n, int i, double c,
string d, double s)
: Person(n, i),
Student(n, i, c),
Staff(n, i, d, s)
{
cout << "TeachingAssistant constructor\n";
}

~TeachingAssistant()
{
    cout << "TeachingAssistant destructor\n";
}
};

int main()
{
TeachingAssistant ta("Ananya", 101, 8.5,
"CSE", 30000);

return 0;
}

PART 2 – MEMBER CLASSES
    
#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
string name;
int age;

public:
Person(const string& n, int a)
: name(n), age(a)
{
}
};

class Address
{
string city;
int pin;

public:
Address(const string& c, int p)
: city(c), pin(p)
{
}

string getAddress() const
{
    return city + "-" + to_string(pin);
}
};

class Student : public Person
{
long long regNo;
Address home;

public:
Student(string n, int a, long long r,
string c, int p)
: Person(n, a),
regNo(r),
home(c, p)
{
}

void print() const
{
    cout << regNo << " " << name
         << " (" << age << ") "
         << home.getAddress() << endl;
}
};

int main()
{
Student s("Ananya", 19, 1923110001,
"Salem", 636001);

s.print();

return 0;
}
