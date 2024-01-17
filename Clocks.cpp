// Mary Belleville. CS-210. Project One. 24EW3.

#include <iostream>
#include <iomanip>
using namespace std;

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
}

int main() {

    displayClock();

    return 0;
}
