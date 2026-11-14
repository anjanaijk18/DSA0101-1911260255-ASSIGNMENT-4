#include <iostream>
using namespace std;

struct Account
{
double rate() const
{
return 1.5;
}

virtual double income() const
{
    return 2.5;
}

virtual ~Account()
{
    cout << "Account destroyed\n";
}
};

struct SeniorAccount : Account
{
double* history;

SeniorAccount()
{
    history = new double[100];
}

double rate() const
{
    return 4.0;
}

double income() const override
{
    return 4.0;
}

~SeniorAccount() override
{
    delete[] history;
    cout << "SeniorAccount destroyed\n";
}
};

int main()
{
Account* accounts[2];

accounts[0] = new Account;
accounts[1] = new SeniorAccount;

cout << "ACCOUNT DETAILS\n";

for(int i = 0; i < 2; i++)
{
    cout << "Income: "
         << accounts[i]->income() << endl;
}

cout << "\nOBJECT SLICING TEST\n";

Account copy = SeniorAccount();

cout << "Copied account income: "
     << copy.income() << endl;

cout << "\nDELETING OBJECTS\n";

for(int i = 0; i < 2; i++)
{
    delete accounts[i];
}

return 0;
}
