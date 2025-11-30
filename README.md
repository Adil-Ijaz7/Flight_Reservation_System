# Flight Reservation System (Console C++)

A simple console-based Flight Reservation System developed as a Semester I final project. It allows users to:
- View available flights (sample domestic routes listed)
- Book a flight (select airline, route, class, date, and time)
- Generate a basic textual e-ticket

## Features

- Airline selection (PIA, Emirates, Go Air, Jet Airways)
- Origin/destination route availability check (sample static data)
- Class availability (Business / Economy seat simulation)
- Time selection (9 AM, 10 AM, 11 AM)
- Basic passenger info capture
- E-ticket summary output

## Tech Stack

- Language: C++
- Standard library only (iostream, iomanip, cstring, cstdlib)

## Building

Compile with any C++ compiler:

```bash
g++ -std=c++11 "Semster I Final project.cpp" -o flight_app
./flight_app
```

On Windows (MinGW):

```bat
g++ "Semster I Final project.cpp" -o flight_app.exe
flight_app.exe
```

## Usage Flow

1. Start program.
2. Choose:
   - 1: Flight Booking
   - 2: List Flights
   - 3: Exit
3. If booking:
   - Select airline
   - Provide passenger info
   - Choose class
   - Choose travel time
   - View generated e-ticket
4. You are prompted whether to return to main menu.

## Input Validation (New Improvements)

The updated version now includes robust input validation:
- Menu choices validated (must be integers in allowed range)
- Date validated (day 1–31, month 1–12, year > 0)
- Time selection enforced (1–3)
- Ticket count must be positive
- Class and airline choices restricted to valid options
- Graceful handling of non-numeric input

## Potential Future Improvements

- Replace C-style `char[]` with `std::string`
- Persist bookings to file or database
- Dynamic flight list loading
- Seat decrement logic
- Enhanced date/time validation (leap year, month lengths)
- Unit tests
- Colorized console output

## Sample Output (Abbreviated)

```
WELCOME TO AIRWAYS RESERVATION SYSTEM
** MAIN MENU **
1. FLIGHT BOOKING
2. LIST FLIGHTS
3. EXIT PROGRAM
Enter your choice :
```

## Authors

- Adil Ijaz
- Abdul Samad
- Abdul Kabeer
- Majid Ali

## License

Released under the MIT License. See [LICENSE](LICENSE) for details.
