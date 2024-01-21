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

bool validateTime(int hrs, int mins, int secs);
void displayMenu(int hour, int minutes, int seconds);

void displayClock(int hour24, int min, int sec) {
    bool isAM;
    int hour12;

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

void displayMenu(int hour, int minutes, int seconds) {
    string menuChoice;

    cout << endl;
    cout << "MENU OPTIONS:" << endl;
    cout << setfill('*') << setw(26) << "" << endl;
    cout << "* 1 - Add One Hour       *" << endl;
    cout << "* 2 - Add One Minute     *" << endl;
    cout << "* 3 - Add One Second     *" << endl;
    cout << "* 4 - Exit Program       *" << endl;
    cout << setfill('*') << setw(26) << "" << endl;
    cout << endl;

    getline(cin, menuChoice);

    if (menuChoice == "1") {
        hour = hour + 1;
    }
    else if (menuChoice == "2") {
        minutes = minutes + 1;
    }
    else if (menuChoice == "3") {
        seconds = seconds + 1;
    }
    else if (menuChoice == "4") {
        cout << "Goodbye!" << endl;
        exit(0);
    }

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

Time inputTime() {
    string hours, minutes, seconds;
    string userTime;
    bool temp = true;
    int hrs, mins, secs;

    do
    {
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

        hrs = stoi(time[0]);
        mins = stoi(time[1]);
        secs = stoi(time[2]);

        temp = validateTime(hrs, mins, secs);
    } while (temp == false);

    Time t;
    t.hrs = hrs;
    t.mins = mins;
    t.secs = secs;

    return t;
}

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

int main() {

    Time t = inputTime();

    displayClock(t.hrs, t.mins, t.secs);

    return 0;
}
