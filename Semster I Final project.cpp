#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <limits>

using namespace std;

bool readInt(const char* prompt, int& out) {
    while (true) {
        cout << prompt;
        if (cin >> out) return true;
        cout << "Invalid input. Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

bool readIntInRange(const char* prompt, int& out, int lo, int hi) {
    while (true) {
        if (readInt(prompt, out)) {
            if (out >= lo && out <= hi) return true;
            cout << "Value must be between " << lo << " and " << hi << ".\n";
        }
    }
}

struct MyTime {
    int choose {};
    void getData() {
        cout << "\nON WHICH TIME YOU WANT TO TRAVEL\n\n";
        cout << "PRESS 1 FOR 11 AM\n";
        cout << "PRESS 2 FOR 10 AM\n";
        cout << "PRESS 3 FOR 9 AM\n";
        readIntInRange("Enter your choice: ", choose, 1, 3);
    }
    void show() {
        cout << "|                                                                         \n";
        if (choose == 1) {
            cout << "|flight time 11 AM                                                        \n";
        } else if (choose == 2) {
            cout << "|flight time 10 AM                                                        \n";
        } else {
            cout << "|flight time 9 AM                                                         \n";
        }
        cout << "|_________________________________________________________________________\n";
        cout << "                  GOOD BYE AND HAVE A SAFE JOURNEY                        \n";
    }
};

struct Booking {
    int num {}, dd {}, mm {}, yyyy {};
    char firstname[60]{}, lastname[60]{}, address[60]{}, c_loc[30]{}, dest[30];

    void getData() {
        cout << setw(40) << "\n\n     ::Please enter the required information for passenger::\n";
        cout << "\nEnter the firstname of passenger: ";
        cin >> firstname;
        cout << "Enter the lastname of passenger: ";
        cin >> lastname;
        cout << "Enter address of passenger: ";
        cin >> address;

        while (true) {
            if (readInt("Enter the number of tickets: ", num) && num > 0) break;
            cout << "Number of tickets must be positive.\n";
        }

        cout << "Enter the current location of passenger (IN CAPITAL LETTERS ONLY): ";
        cin >> c_loc;
        cout << "Enter the destination of passenger (IN CAPITAL LETTERS ONLY): ";
        cin >> dest;

        while (true) {
            cout << "Enter your date (dd mm yyyy): ";
            if (cin >> dd >> mm >> yyyy) {
                if (dd >= 1 && dd <= 31 && mm >= 1 && mm <= 12 && yyyy > 0) break;
                cout << "Invalid date. Please try again.\n";
            } else {
                cout << "Invalid date input. Please use numbers.\n";
                cin.clear();
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        system("CLS"); // Optional: remove if portability desired
    }

    void show() {
        cout << setw(40) << "Your E-Ticket is :\n";
        int t = 1, r = 12345;
        cout << "                           AIRLINE TICKET                                 \n";
        cout << "|Ticket No." << t << "                                Reference No." << r << "\t  \n";
        cout << "|_________________________________________________________________________\n";
        cout << "|Passenger Information :                                                  \n";
        cout << "|Name :" << lastname << " " << firstname << "                                     \n";
        cout << "|Address :" << address << "                                                   \n";
        cout << "|Number of tickets :" << num << "                                             \n";
        cout << "|_________________________________________________________________________\n";
        cout << "|flight Information :\n";
        cout << "|Date :" << dd << " " << mm << " " << yyyy << "\n\n";
        cout << "|BOING 747                                                                \n";
        cout << "|_________________________________________________________________________\n";
        cout << "|Depart :" << c_loc << "                                                      \n";
        cout << "|Arrive :" << dest << "                                                       \n";
        cout << "|*BAGGAGE allowed 40 Kilos                                                \n";
        cout << "|*contact Airline to Confirm baggage allowance                            \n";
        cout << "|_________________________________________________________________________\n";
    }
};

struct Search {
    void searching() {
        cout << "FOLLOWING ARE THE FLIGHTS AVAILABLE\n\n";
        const char l_destination[15][40] = { "KARACHI", "ISLAMABAD", "RAWALPINDI", "HYDERABAD", "LAHORE",
                                             "LONDON", "BERLIN", "DUBAI", "NEW YORK", "BEIJING",
                                             "PARIS", "CAPE TOWN", "TOKYO", "LOS ANGELES", "DOHA" };

        cout << "\n\nFOLLOWING ARE THE DOMESTIC FLIGHTS AVAILABLE\n\n";
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i != j) {
                    cout << "FLIGHT FROM " << l_destination[i] << " TO " << l_destination[j] << "\n";
                }
            }
        }
    }
};

struct Local {
    int option {}, b_seat {}, e_seat {}, ch {}, k {};
    MyTime t1;
    Booking b1;

    void getData() {
        k = 0;
        cout << "\n                     In which AIRLINE you want to travel!! \n\n";
        cout << "1) PIA\n2) EMIRATES\n3) GO AIR\n4) JET AIRWAYS\n";
        readIntInRange("Enter your choice: ", option, 1, 4);

        const char* banners[4] = {
            "WELCOME TO PIA", "WELCOME TO EMIRATES", "WELCOME TO GO AIR", "WELCOME TO JET AIRWAYS"
        };
        cout << setw(40) << "                        ******************************\n";
        cout << setw(40) << "                        *      " << banners[option - 1] << "      *\n";
        cout << setw(40) << "                        ******************************\n";

        cout << setw(40) << "\nTHESE ARE THE PLACES AVAILABLE\n\n";
        const char l_destination[15][40] = { "KARACHI", "ISLAMABAD", "RAWALPINDI", "HYDERABAD", "LAHORE",
                                             "LONDON", "BERLIN", "DUBAI", "NEW YORK", "BEIJING",
                                             "PARIS", "CAPE TOWN", "TOKYO", "LOS ANGELES", "DOHA" };
        for (int i = 0; i < 5; i++) {
            cout << l_destination[i] << "\n";
        }
        b1.getData();

        for (int j = 0; j < 5; j++) {
            if (strcmp(l_destination[j], b1.c_loc) == 0) {
                k++;
            }
        }

        if (k == 1) {
            cout << "\n\n                FLIGHT AVAILABLE ON THIS ROUTE\n";
            b_seat = 30;
            e_seat = 40;
            cout << "\n In which class you want to travel?\n\n";
            cout << setw(60) << "*************************************\n";
            cout << setw(60) << "*     Press 1 for business class    *\n";
            cout << setw(60) << "*     Press 2 for economy class     *\n";
            cout << setw(60) << "*************************************\n\n";
            readIntInRange("Enter your choice: ", ch, 1, 2);
            if (ch == 1) {
                cout << (b_seat > 0 ? "             SEAT AVAILABLE\n" : "             SORRY NO SEAT AVAILABLE\n");
            } else {
                cout << (e_seat > 0 ? "             SEAT AVAILABLE\n" : "             SORRY NO SEAT AVAILABLE\n");
            }
        } else {
            cout << "\n                FLIGHT NOT AVAILABLE ON THIS ROUTE\n";
        }

        t1.getData();
        t1.show();
        b1.show();
    }
};

int main() {
    int ch = 0, ch1 = 0;
    Search s1;
    Local l1;

    cout << "\n\t\t     WELCOME TO AIRWAYS RESERVATION SYSTEM";
    cout << "\n\n\n\t\t          Developed by : ADIL IJAZ";
    cout << "\n\n\t\t                         ABDUL SAMAD";
    cout << "\n\n\t\t                         ABDUL KABEER";
    cout << "\n\n\t\t                         MAJID ALI\n";

    do {
        cout << "\n\t\t\t               ** MAIN MENU **\n";
        cout << "\n\t\t\t\t1. FLIGHT BOOKING";
        cout << "\n\t\t\t\t2. LIST FLIGHTS";
        cout << "\n\t\t\t\t3. EXIT PROGRAM\n";
        readIntInRange("\n\t\t\t\tEnter your choice : ", ch, 1, 3);

        if (ch == 1) {
            l1.getData();
        } else if (ch == 2) {
            s1.searching();
        } else if (ch == 3) {
            cout << "Exiting program...\n";
            break;
        }

        readIntInRange("Do you want to go to the main menu again? (1=YES, 0=NO): ", ch1, 0, 1);
    } while (ch1 == 1);

    return 0;
}