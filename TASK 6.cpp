#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <iomanip>
using namespace std;

// Abstract base class
class Vehicle
{
protected:
string regNo;
double dailyRate;
bool rented;

public:
Vehicle(string r, double rate)
: regNo(r), dailyRate(rate), rented(false) {}

virtual double rentalCharge(int days) const = 0;

virtual void display() const = 0;

virtual ~Vehicle() {}

string getRegNo() const
{
    return regNo;
}

bool isRented() const
{
    return rented;
}

bool rent()
{
    if(rented)
        return false;

    rented = true;
    return true;
}

void returnVehicle()
{
    rented = false;
}

double totalCharge(int days, int lateDays) const
{
    return rentalCharge(days) +
           lateDays * dailyRate * 0.5;
}
};

// Bicycle class
class Bicycle : public Vehicle
{
public:
Bicycle(string r, double rate)
: Vehicle(r, rate) {}

double rentalCharge(int days) const override
{
    return dailyRate * days;
}

void display() const override
{
    cout << "Bicycle: " << regNo
         << " | Rate: " << dailyRate
         << " | Status: "
         << (rented ? "Rented" : "Available")
         << endl;
}
};

// Common motor vehicle class
class MotorVehicle : public Vehicle
{
protected:
string serviceDate;

public:
MotorVehicle(string r, double rate, string date)
: Vehicle(r, rate), serviceDate(date) {}
};

// Fuel-based vehicle class
class FuelVehicle : public MotorVehicle
{
protected:
double fuelLevel;
double fuelUsed;
double pricePerLitre;

public:
FuelVehicle(string r, double rate, string date,
double level, double used, double price)
: MotorVehicle(r, rate, date),
fuelLevel(level), fuelUsed(used),
pricePerLitre(price) {}

double rentalCharge(int days) const override
{
    return dailyRate * days +
           fuelUsed * pricePerLitre;
}
};

// Two-wheeler class
class TwoWheeler : public FuelVehicle
{
public:
TwoWheeler(string r, double rate, string date,
double level, double used, double price)
: FuelVehicle(r, rate, date, level, used, price) {}

void display() const override
{
    cout << "Two-Wheeler: " << regNo
         << " | Fuel: " << fuelLevel
         << " | Service: " << serviceDate
         << " | Status: "
         << (rented ? "Rented" : "Available")
         << endl;
}
};

// Car class
class Car : public FuelVehicle
{
int seats;

public:
Car(string r, double rate, string date,
double level, double used, double price,
int s)
: FuelVehicle(r, rate, date, level, used, price),
seats(s) {}

void display() const override
{
    cout << "Car: " << regNo
         << " | Seats: " << seats
         << " | Fuel: " << fuelLevel
         << " | Service: " << serviceDate
         << " | Status: "
         << (rented ? "Rented" : "Available")
         << endl;
}
};

// Common electric vehicle class
class ElectricVehicle : public MotorVehicle
{
protected:
double batteryLevel;
double batteryCapacity;
double energyUsed;
double pricePerKWh;

public:
ElectricVehicle(string r, double rate, string date,
double level, double capacity,
double used, double price)
: MotorVehicle(r, rate, date),
batteryLevel(level), batteryCapacity(capacity),
energyUsed(used), pricePerKWh(price) {}

double rentalCharge(int days) const override
{
    return dailyRate * days +
           energyUsed * pricePerKWh;
}
};

// Electric car class
class ElectricCar : public ElectricVehicle
{
public:
ElectricCar(string r, double rate, string date,
double level, double capacity,
double used, double price)
: ElectricVehicle(r, rate, date, level,
capacity, used, price) {}

void display() const override
{
    cout << "Electric Car: " << regNo
         << " | Battery: " << batteryLevel
         << "/" << batteryCapacity
         << " kWh | Service: " << serviceDate
         << " | Status: "
         << (rented ? "Rented" : "Available")
         << endl;
}
};

// New vehicle type added without modifying old classes
class ElectricBus : public ElectricVehicle
{
public:
ElectricBus(string r, double rate, string date,
double level, double capacity,
double used, double price)
: ElectricVehicle(r, rate, date, level,
capacity, used, price) {}

void display() const override
{
    cout << "Electric Bus: " << regNo
         << " | Battery: " << batteryLevel
         << "/" << batteryCapacity
         << " kWh | Service: " << serviceDate
         << " | Status: "
         << (rented ? "Rented" : "Available")
         << endl;
}
};

// Fleet management functions
void listVehicles(const vector<unique_ptr<Vehicle>>& fleet)
{
cout << "\nVEHICLE FLEET\n";

for(const auto& v : fleet)
    v->display();
}

int main()
{
vector<unique_ptr<Vehicle>> fleet;

fleet.push_back(make_unique<Bicycle>(
    "BIKE101", 100));

fleet.push_back(make_unique<TwoWheeler>(
    "BIKE202", 300, "2026-12-20",
    5, 2, 105));

fleet.push_back(make_unique<Car>(
    "CAR303", 1500, "2026-12-25",
    20, 5, 105, 5));

fleet.push_back(make_unique<ElectricCar>(
    "EV404", 2000, "2026-12-30",
    80, 100, 20, 8));

// Extension: add a new electric bus
fleet.push_back(make_unique<ElectricBus>(
    "BUS505", 3000, "2027-01-10",
    150, 200, 30, 8));

cout << fixed << setprecision(2);

listVehicles(fleet);

cout << "\nRENTAL TEST\n";

string search = "CAR303";

for(auto& v : fleet)
{
    if(v->getRegNo() == search)
    {
        if(v->rent())
        {
            cout << search << " rented successfully\n";

            cout << "Rental charge for 2 days: Rs. "
                 << v->rentalCharge(2) << endl;

            cout << "Total with 1 late day: Rs. "
                 << v->totalCharge(2, 1) << endl;

            v->returnVehicle();

            cout << "Vehicle returned successfully\n";
        }
        else
        {
            cout << "Vehicle already rented\n";
        }
    }
}

listVehicles(fleet);

return 0;
}
