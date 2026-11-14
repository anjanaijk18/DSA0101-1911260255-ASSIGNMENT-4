TASK 5.1 – FOUR WAYS TO REACH AN OBJECT
  
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Cart
{
string items[10];
double prices[10];
int n = 0;
double discount = 0;

public:

// TODO 1: Add item and return *this
Cart& add(string item, double price)
{
    if(n < 10)
    {
        items[n] = item;
        prices[n] = price;
        n++;
    }
    return *this;
}

// TODO 2: Set discount using this->
Cart& setDiscount(double discount)
{
    this->discount = discount;
    return *this;
}

double total() const
{
    double t = 0;

    for(int i = 0; i < n; i++)
        t += prices[i];

    return t * (100 - discount) / 100;
}
};

int main()
{
// 1. Direct access by object name
Cart c;
c.add("Rice", 60);

// 2. Access through pointer using ->
Cart* p = &c;
p->add("Dal", 120);

// 3. Access through reference
Cart& r = c;
r.add("Oil", 180);
r.setDiscount(10);

cout << fixed << setprecision(2);
cout << "Cart Total: " << c.total() << endl;

// 4. Dynamically allocated object
Cart* dynamicCart = new Cart;
dynamicCart->add("Milk", 50);
cout << "Dynamic Cart Total: "
     << dynamicCart->total() << endl;

delete dynamicCart;

return 0;
}

TASK 5.2 – CHANGE THE REQUIREMENT 

#include <iostream>
using namespace std;

class Cart
{
public:
int id;
double amount;

Cart(int i, double a)
{
    id = i;
    amount = a;
}
};

int main()
{
Cart c1(101, 500);
Cart c2(102, 750);
Cart c3(103, 900);

Cart* carts[3] = {&c1, &c2, &c3};

cout << "CUSTOMER CARTS\n";

for(int i = 0; i < 3; i++)
{
    cout << "Customer " << carts[i]->id
         << " Total = " << carts[i]->amount << endl;
}

cout << "\nUSING POINTER ARITHMETIC\n";

Cart** p = carts;

for(int i = 0; i < 3; i++)
{
    cout << "Customer " << (p + i)->operator->()->id
         << endl;
}

return 0;
}

