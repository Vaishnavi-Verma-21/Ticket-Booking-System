#include <iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;
class Reservation
{
private:
    map<int, bool> seatAvailability;

public:
    Reservation(int numberOfVacantSeats)
    {
        for (int i = 1; i <= numberOfVacantSeats; i++)
        {
            seatAvailability[i] = true;
        }
    }
    void displayAvailableSeats()
    {
        cout << "Available Seats:";
        for (auto pair : seatAvailability)
        {
            if (pair.second)
            {
                cout << pair.first << " ";
            }
        }
        cout<<endl;
    }
    void makeReservation(int seatNumber)
    {
        if ((seatAvailability.find(seatNumber) != seatAvailability.end()) && seatAvailability[seatNumber])
        {
            seatAvailability[seatNumber] = false;
            cout << "Reservation successful for seat number " << seatNumber;
        }
        else
        {
            cout << "Seat Number " << seatNumber << " is not available for reservation";
        }
        cout<<endl;
    }
};
int main()
{
    int seats;
    cout << "Enter the number of seats:";
    cin >> seats;
    Reservation reserve(seats);
    while (true)
    {
        cout << "\n1. Display Available Seats";
        cout << "\n2. Make a Reservation";
        cout << "\n3. Exit";
        cout << "\nEnter your choice:";
        int choice;
        cin >> choice;

        // Handling input error
        if (cin.fail())
        {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            continue;
        }
        
        switch (choice)
        {
        case 1:
            reserve.displayAvailableSeats();
            break;
        case 2:
        {
            cout << "Enter the seat number to reserve: ";
            int seat;
            cin >> seat;
            reserve.makeReservation(seat);
            break;
        }
        case 3:
            cout << "\nExiting the reservation system. Bye!";
            return 0; // Exit from the program
        default:
            cout << "\nInvalid choice. Please enter a valid option."<<endl;
            break;
        }
    }
    return 0;
}
