#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string vehicleID;
    string manufacturer;
    string model;
    int year;

    // Static member to count total vehicles
    static int totalVehicles;

public:
    // Default Constructor
    Vehicle() {
        vehicleID = "";
        manufacturer = "";
        model = "";
        year = 0;
        totalVehicles++;
    }

    // Parameterized Constructor
    Vehicle(string id, string manu, string mod, int yr) {
        vehicleID = id;
        manufacturer = manu;
        model = mod;
        year = yr;
        totalVehicles++;
    }

    // Destructor
    ~Vehicle() {
        totalVehicles--;
    }

    // Getters
    string getVehicleID() const { return vehicleID; }
    string getManufacturer() const { return manufacturer; }
    string getModel() const { return model; }
    int getYear() const { return year; }

    // Setters
    void setVehicleID(const string& id) { vehicleID = id; }
    void setManufacturer(const string& manu) { manufacturer = manu; }
    void setModel(const string& mod) { model = mod; }
    void setYear(int yr) { year = yr; }

    // Static method to get total vehicles
    static int getTotalVehicles() {
        return totalVehicles;
    }

    // Optional: Display vehicle info
    void displayInfo() const {
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

// Initialize static member
int Vehicle::totalVehicles = 0;

