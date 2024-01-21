/**
 * Mary Belleville
 * CS-210
 * Project One: Chada Tech Dual Clocks
 * 24EW3
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <stdexcept>
using namespace std;

// Structure that groups the Time-related variables together in order to pass through inputTime function.
struct Time {
    int hrs;
    int mins;
    int secs;
};

// Declaration of functions to be called prior to being defined.
bool validateTime(int hrs, int mins, int secs);
void displayMenu(int hour, int minutes, int seconds);

// Prints the Chada Tech project logo.
void logo() {

    cout << endl;
    cout << R"(
      _____ _    _          _____            _______ ______ _____ _    _ 
     / ____| |  | |   /\   |  __ \   /\     |__   __|  ____/ ____| |  | |
    | |    | |__| |  /  \  | |  | | /  \       | |  | |__ | |    | |__| |
    | |    |  __  | / /\ \ | |  | |/ /\ \      | |  |  __|| |    |  __  |
    | |____| |  | |/ ____ \| |__| / ____ \     | |  | |___| |____| |  | |
     \_____|_|  |_/_/    \_\_____/_/    \_\    |_|  |______\_____|_|  |_|
                   D U A L     C L O C K S    P R O J E C T)" << endl;
    cout << endl;
};

/**
 * Displays two clocks in both 12-hour and 24-hour format.
 * Displays the menu.
 *
 * @param hours (24-hour format), minutes, seconds
 */
void displayClock(int hour24, int min, int sec) {
    bool isAM;
    int hour12;

    // Conversion from 24-Hour format to 12-Hour format with AM/PM
    if (hour24 < 12 || hour24 == 24) {
        isAM = true;
        if (hour24 % 12 == 0) {
            hour12 = 12;
        }
        else {
            hour12 = hour24;
        }
    }
    else {
        isAM = false;
        if (hour24 % 12 != 0) {
            hour12 = hour24 % 12;
        }
        else {
            hour12 = hour24;
        }
    }

    // Displays output
    cout << endl;
    cout << setfill('*') << setw(26) << "";
    cout << setfill(' ') << setw(10) << "";
    cout << setfill('*') << setw(26) << "" << endl;

    cout << "*     12-Hour Clock      *";
    cout << setfill(' ') << setw(10) << "";
    cout << "*      24-Hour Clock     *" << endl;

    cout << "*      ";
    cout << setw(2) << setfill('0') << hour12 << ":";
    cout << setw(2) << setfill('0') << min << ":";
    cout << setw(2) << setfill('0') << sec << " ";
    if (isAM) {
        cout << "AM";
    }
    else {
        cout << "PM";
    }
    cout << "       *" << "          " << "*        ";
    cout << setw(2) << setfill('0') << hour24 << ":";
    cout << setw(2) << setfill('0') << min << ":";
    cout << setw(2) << setfill('0') << sec << "        *" << endl;

    cout << setfill('*') << setw(26) << "";
    cout << setfill(' ') << setw(10) << "";
    cout << setfill('*') << setw(26) << "" << endl;

    displayMenu(hour24, min, sec);

}

/**
 * Displays the menu that allows a user to either:
 * 1. Add one hour
 * 2. Add one minute
 * 3. Add one second
 * 4. Exit the program
 * 
 * @param hours (24-hour format), minutes, seconds
 */
void displayMenu(int hour, int minutes, int seconds) {
    string menuChoice;

    // Displays output
    cout << endl;
    cout << "MENU OPTIONS:" << endl;
    cout << setfill('*') << setw(26) << "" << endl;
    cout << "* 1 - Add One Hour       *" << endl;
    cout << "* 2 - Add One Minute     *" << endl;
    cout << "* 3 - Add One Second     *" << endl;
    cout << "* 4 - Exit Program       *" << endl;
    cout << setfill('*') << setw(26) << "" << endl;
    cout << endl;

    // Gets user input and reacts to menu choice appropriately.
    getline(cin, menuChoice);
    if (menuChoice == "1") {
        hour = hour + 1;
        cout << "\nYou chose to add one hour. Your new time is:" << endl;
    }
    else if (menuChoice == "2") {
        minutes = minutes + 1;
        cout << "\nYou chose to add one minute. Your new time is:" << endl;
    }
    else if (menuChoice == "3") {
        seconds = seconds + 1;
        cout << "\nYou chose to add one second. Your new time is:" << endl;
    }
    else if (menuChoice == "4") {
        cout << "Goodbye!" << endl;
        exit(0);
    }

    // Time conversion if seconds, minutes, or hours reaches the maximum
    if (seconds == 60) {
        seconds = 0;
        minutes = minutes + 1;
    }

    if (minutes == 60) {
        minutes = 0;
        hour = hour + 1;
    }

    if (hour == 25) {
        hour = 0;
    }

    displayClock(hour, minutes, seconds);

}

/**
 * Gets user-input time for initial conversion.
 *
 * @return structure of hours (24-hour format), minutes, seconds
 */
Time inputTime() {
    string hours, minutes, seconds;
    string userTime;
    bool valid = true;
    int hrs, mins, secs;

    // Do/While loop until validateTime returns True
    do
    {
        // Gets user-input initial time and splits it into hours/minutes/seconds
        cout << "Please enter the initial time in 24-Hour format (hour/min/sec - 00:00:00)" << endl;
        getline(cin, userTime);

        istringstream iss(userTime);
        getline(iss, hours, ':');
        getline(iss, minutes, ':');
        getline(iss, seconds, ':');

        // Removes any leading zeros
        string time[] = { hours, minutes, seconds };

        for (int i = 0; i < 3; i++) {
            if (time[i][0] == '0') {
                time[i] = time[i].substr(1);
            }
        }

        // Converts each string in the array to int
        hrs = stoi(time[0]);
        mins = stoi(time[1]);
        secs = stoi(time[2]);

        // Passes the time to another function to be validated
        valid = validateTime(hrs, mins, secs);
    } 
    while (valid == false);

    // Defining structure paramaters to pass through return
    Time t;
    t.hrs = hrs;
    t.mins = mins;
    t.secs = secs;

    return t;
}

/**
 * Validates user-input time for initial conversion.
 *
 * @param hours (24-hour format), minutes, seconds
 * @throws invalid argument if outside specifications
 * @return bool true/false
 */
bool validateTime(int hrs, int mins, int secs) {

    try {
        if (hrs > 23 || mins > 59 || secs > 59) {
            throw invalid_argument("Invalid time format, please try again.\n");
        }
    }
    catch (invalid_argument& e) {
        cout << e.what() << endl;
        return false;
    }
    return true;

}

/**
 * Main program.
 * Displays logo, allows user to input initial time, then displays the clock.
 */
int main() {

    logo();

    Time t = inputTime();

    displayClock(t.hrs, t.mins, t.secs);

    return 0;
}
