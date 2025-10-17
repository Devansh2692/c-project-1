#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string vehicleID, manufacturer, model;
    int year;
    static int totalVehicles;

public:
    Vehicle() : vehicleID(""), manufacturer(""), model(""), year(0) { totalVehicles++; }
    Vehicle(string id, string manu, string mod, int yr) : vehicleID(id), manufacturer(manu), model(mod), year(yr) { totalVehicles++; }
    virtual ~Vehicle() { totalVehicles--; }

    // Getters and setters
    void setVehicleID(string id) { vehicleID = id; }
    void setManufacturer(string m) { manufacturer = m; }
    void setModel(string m) { model = m; }
    void setYear(int y) { year = y; }

    string getVehicleID() const { return vehicleID; }
    string getManufacturer() const { return manufacturer; }
    string getModel() const { return model; }
    int getYear() const { return year; }

    static int getTotalVehicles() { return totalVehicles; }

    virtual void displayInfo() const {
        cout << "Vehicle ID: " << vehicleID << "\nManufacturer: " << manufacturer
             << "\nModel: " << model << "\nYear: " << year << endl;
    }
};

int Vehicle::totalVehicles = 0;

// ----------------------------------
// Car - Single Inheritance
class Car : public Vehicle {
protected:
    string fuelType;

public:
    Car() : fuelType("") {}
    Car(string id, string manu, string mod, int yr, string fuel)
        : Vehicle(id, manu, mod, yr), fuelType(fuel) {}

    void setFuelType(string fuel) { fuelType = fuel; }
    string getFuelType() const { return fuelType; }

    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

// ----------------------------------
// ElectricCar - Multilevel Inheritance
class ElectricCar : public Car {
protected:
    int batteryCapacity; // in kWh

public:
    ElectricCar() : batteryCapacity(0) {}
    ElectricCar(string id, string manu, string mod, int yr, string fuel, int battery)
        : Car(id, manu, mod, yr, fuel), batteryCapacity(battery) {}

    void setBatteryCapacity(int cap) { batteryCapacity = cap; }
    int getBatteryCapacity() const { return batteryCapacity; }

    void displayInfo() const override {
        Car::displayInfo();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};

// ----------------------------------
// Aircraft - Another Base Class
class Aircraft {
protected:
    int flightRange; // in kilometers

public:
    Aircraft() : flightRange(0) {}
    Aircraft(int range) : flightRange(range) {}

    void setFlightRange(int range) { flightRange = range; }
    int getFlightRange() const { return flightRange; }

    virtual void displayAircraftInfo() const {
        cout << "Flight Range: " << flightRange << " km" << endl;
    }
};

// ----------------------------------
// FlyingCar - Multiple Inheritance
class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar() {}
    FlyingCar(string id, string manu, string mod, int yr, string fuel, int range)
        : Car(id, manu, mod, yr, fuel), Aircraft(range) {}

    void displayInfo() const {
        Car::displayInfo();
        Aircraft::displayAircraftInfo();
    }
};

// ----------------------------------
// SportsCar - Multilevel from ElectricCar
class SportsCar : public ElectricCar {
private:
    int topSpeed; // in km/h

public:
    SportsCar() : topSpeed(0) {}
    SportsCar(string id, string manu, string mod, int yr, string fuel, int battery, int speed)
        : ElectricCar(id, manu, mod, yr, fuel, battery), topSpeed(speed) {}

    void setTopSpeed(int speed) { topSpeed = speed; }
    int getTopSpeed() const { return topSpeed; }

    void displayInfo() const override {
        ElectricCar::displayInfo();
        cout << "Top Speed: " << topSpeed << " km/h" << endl;
    }
};

// ----------------------------------
// Sedan - Hierarchical Inheritance from Car
class Sedan : public Car {
public:
    Sedan() {}
    Sedan(string id, string manu, string mod, int yr, string fuel)
        : Car(id, manu, mod, yr, fuel) {}

    void displayInfo() const override {
        cout << "--- Sedan ---" << endl;
        Car::displayInfo();
    }
};

// ----------------------------------
// SUV - Hierarchical Inheritance from Car
class SUV : public Car {
public:
    SUV() {}
    SUV(string id, string manu, string mod, int yr, string fuel)
        : Car(id, manu, mod, yr, fuel) {}

    void displayInfo() const override {
        cout << "--- SUV ---" << endl;
        Car::displayInfo();
    }
};

