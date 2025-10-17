#include <iostream>
#include <cstring>
using namespace std;

class Train {
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];
    static int trainCount;  // Static member to track number of trains

public:
    // Default Constructor
    Train() {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
        trainCount++;
    }

    // Parameterized Constructor
    Train(int number, const char* name, const char* src, const char* dest, const char* time) {
        trainNumber = number;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }

    // Destructor
    ~Train() {
        trainCount--;
    }

    // Getters
    int getTrainNumber() { return trainNumber; }
    const char* getTrainName() { return trainName; }
    const char* getSource() { return source; }
    const char* getDestination() { return destination; }
    const char* getTrainTime() { return trainTime; }

    // Setters
    void setTrainNumber(int number) { trainNumber = number; }
    void setTrainName(const char* name) { strcpy(trainName, name); }
    void setSource(const char* src) { strcpy(source, src); }
    void setDestination(const char* dest) { strcpy(destination, dest); }
    void setTrainTime(const char* time) { strcpy(trainTime, time); }

    // Method to input train details
    void inputTrainDetails() {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore(); // to clear buffer
        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);
        cout << "Enter Source: ";
        cin.getline(source, 50);
        cout << "Enter Destination: ";
        cin.getline(destination, 50);
        cout << "Enter Train Time (HH:MM): ";
        cin.getline(trainTime, 10);
    }

    // Method to display train details
    void displayTrainDetails() {
        cout << "\nTrain Number: " << trainNumber
             << "\nTrain Name: " << trainName
             << "\nSource: " << source
             << "\nDestination: " << destination
             << "\nTrain Time: " << trainTime << endl;
    }

    // Static method to get count of Train objects
    static int getTrainCount() {
        return trainCount;
    }
};

// Initialize static member
int Train::trainCount = 0;

// Main function to test the class
int main() {
    cout << "===== Train Management System =====\n";

    Train t1; // Default constructor
    t1.inputTrainDetails();

    Train t2(102, "Express Line", "Ahmedabad", "Surat", "06:30"); // Parameterized constructor

    cout << "\n--- Train Details ---\n";
    t1.displayTrainDetails();
    t2.displayTrainDetails();

    cout << "\nTotal Trains Created: " << Train::getTrainCount() << endl;

    
}