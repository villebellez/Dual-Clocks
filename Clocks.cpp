// Mary Belleville. CS-210. Project One. 24EW3.

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <stdexcept>
using namespace std;

struct Time {
    int hrs;
    int mins;
    int secs;
};

void validateTime(int hrs, int mins, int secs);

void displayMenu() {

    // TODO: Make functional
    cout << endl;
    cout << "MENU OPTIONS:" << endl;
    cout << setfill('*') << setw(26) << "" << endl;
    cout << "* 1 - Add One Hour       *" << endl;
    cout << "* 2 - Add One Minute     *" << endl;
    cout << "* 3 - Add One Second     *" << endl;
    cout << "* 4 - Exit Program       *" << endl;
    cout << setfill('*') << setw(26) << "" << endl;

}

void displayClock(string hour24 = "00", string hour12 = "12", string min = "00", string sec = "00", string ampm = "AM") {
   
    // Testing Display
    cout << setfill('*') << setw(26) << "";
    cout << setfill(' ') << setw(10) << "";
    cout << setfill('*') << setw(26) << "" << endl;
    cout << "*     12-Hour Clock      *";
    cout << setfill(' ') << setw(10) << "";
    cout << "*      24-Hour Clock     *" << endl;
    cout << "*      " << hour12 << ":" << min << ":" << sec << " " << ampm << "       *";
    cout << setfill(' ') << setw(10) << "";
    cout << "*        " << hour24 << ":" << min << ":" << sec << " " << "       *" << endl;
    cout << setfill('*') << setw(26) << "";
    cout << setfill(' ') << setw(10) << "";
    cout << setfill('*') << setw(26) << "" << endl;

    displayMenu();
}

 Time inputTime() {
    string hours, minutes, seconds;
    string userTime;

    cout << "Please enter the initial time in 24-Hour format (hour/min/sec - 00:00:00)" << endl;
    getline(cin, userTime);

    istringstream iss(userTime);
    getline(iss, hours, ':');
    getline(iss, minutes, ':');
    getline(iss, seconds, ':');

    string time[] = { hours, minutes, seconds };

    for (int i = 0; i < 3; i++) {
        if (time[i][0] == '0') {
            time[i] = time[i].substr(1);
        }
    }

    int hrs = stoi(time[0]);
    int mins = stoi(time[1]);
    int secs = stoi(time[2]);

    validateTime(hrs, mins, secs);

    Time t;
    t.hrs = hrs;
    t.mins = mins;
    t.secs = secs;

    return t;
}

void validateTime(int hrs, int mins, int secs) {

    try {
        if (hrs > 23 || mins > 59 || secs > 59) {
            throw invalid_argument("Invalid time format, please try again.\n");
        }
    }
    catch (invalid_argument& e) {
        cout << e.what() << endl;
        inputTime();
    }

}

void Clock12(int hours, int minutes, int seconds) {
    int hr12, min12, sec12;
    bool isAM;

    if (hours < 12 || hours == 24) {
        isAM = true;
    }
    else {
        isAM = false;
    }

    hr12 = hours % 12;
    min12 = minutes;
    sec12 = seconds;

    // TESTING
    cout << setw(2) << setfill('0') << hr12 << ":"; 
    cout << setw(2) << setfill('0') << min12 << ":"; 
    cout << setw(2) << setfill('0') << sec12 << " ";
    
    if (isAM) {
        cout << "AM" << endl;
    }
    else {
        cout << "PM" << endl;
    }
}

int main() {
    Time t = inputTime();

    Clock12(t.hrs, t.mins, t.secs);

    displayClock();

    return 0;
}
