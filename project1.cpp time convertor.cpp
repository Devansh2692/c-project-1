#include <iostream>
using namespace std;

class TimeConverter {
public:
    // Function to convert seconds to HH:MM:SS
    void secondsToTime() {
        int totalSeconds;
        cout << "Enter total seconds: ";
        cin >> totalSeconds;

        int hours = totalSeconds / 3600;
        int minutes = (totalSeconds % 3600) / 60;
        int seconds = totalSeconds % 60;

        cout << "HH:MM:SS => " << hours << ":" 
             << minutes << ":" << seconds << endl;
    }

    // Function to convert HH:MM:SS to seconds
    void timeToSeconds() {
        int hours, minutes, seconds;
        cout << "Enter hours: ";
        cin >> hours;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter seconds: ";
        cin >> seconds;

        int totalSeconds = (hours * 3600) + (minutes * 60) + seconds;
        cout << "Total seconds: " << totalSeconds << endl;
    }
};

int main() {
    TimeConverter tc;
    int choice;

    cout << "===== TIME CONVERTER =====" << endl;
    cout << "1. Convert Seconds to HH:MM:SS" << endl;
    cout << "2. Convert HH:MM:SS to Seconds" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    switch (choice) {
        case 1:
            tc.secondsToTime();
            break;
        case 2:
            tc.timeToSeconds();
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

   
}