// inheritance_example.cpp
// Demonstrates Inheritance: Hierarchical + Multilevel inheritance

#include <iostream>
#include <string>
using namespace std;

// ---------- Base Class ----------
class Vehicle {
protected:   // protected so derived classes can access directly
    string brand;
    int maxSpeed;

public:
    Vehicle(string b, int speed) : brand(b), maxSpeed(speed) {
        cout << "[Vehicle constructor called for " << brand << "]\n";
    }

    void honk() {
        cout << brand << " says: Beep Beep!\n";
    }

    void showDetails() {
        cout << "Brand: " << brand << " | Max Speed: " << maxSpeed << " km/h\n";
    }

    ~Vehicle() {
        cout << "[Vehicle destructor called for " << brand << "]\n";
    }
};

// ---------- Derived Class 1 (Hierarchical Inheritance) ----------
class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(string b, int speed, int doors)
        : Vehicle(b, speed), numDoors(doors) {   // calling base constructor
        cout << "[Car constructor called]\n";
    }

    void showCarDetails() {
        showDetails();   // inherited method
        cout << "Number of Doors: " << numDoors << "\n";
    }
};

// ---------- Derived Class 2 (Hierarchical Inheritance) ----------
class Bike : public Vehicle {
private:
    bool hasGear;

public:
    Bike(string b, int speed, bool gear)
        : Vehicle(b, speed), hasGear(gear) {
        cout << "[Bike constructor called]\n";
    }

    void showBikeDetails() {
        showDetails();   // inherited method
        cout << "Has Gear: " << (hasGear ? "Yes" : "No") << "\n";
    }
};

// ---------- Multilevel Inheritance Example ----------
class SportsCar : public Car {
private:
    int topSpeedBoost;

public:
    SportsCar(string b, int speed, int doors, int boost)
        : Car(b, speed, doors), topSpeedBoost(boost) {
        cout << "[SportsCar constructor called]\n";
    }

    void showSportsCarDetails() {
        showCarDetails();   // inherited from Car
        cout << "Top Speed Boost: +" << topSpeedBoost << " km/h\n";
    }
};

int main() {
    cout << "----- Car Object -----\n";
    Car myCar("Toyota", 180, 4);
    myCar.showCarDetails();
    myCar.honk();   // inherited from Vehicle

    cout << "\n----- Bike Object -----\n";
    Bike myBike("Yamaha", 150, true);
    myBike.showBikeDetails();
    myBike.honk();  // inherited from Vehicle

    cout << "\n----- SportsCar Object (Multilevel Inheritance) -----\n";
    SportsCar mySportsCar("Ferrari", 250, 2, 50);
    mySportsCar.showSportsCarDetails();
    mySportsCar.honk();

    cout << "\n----- End of main, destructors will now fire -----\n";
    return 0;
}
