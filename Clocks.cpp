// Mary Belleville. CS-210. Project One. 24EW3.

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

void displayMenu() {

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

int main() {
    string userTime;
    string hours, minutes, seconds;

    cout << "Please enter the initial time in 24-Hour format (hour/min/sec - 00:00:00)" << endl;
    getline(cin, userTime);

    istringstream iss(userTime);
    getline(iss, hours, ':');
    getline(iss, minutes, ':');
    getline(iss, seconds, ':');

    // Testing
    cout << "Hours: " << hours << endl;
    cout << "Minutes: " << minutes << endl;
    cout << "Seconds: " << seconds << endl;

    displayClock();

    return 0;
}
