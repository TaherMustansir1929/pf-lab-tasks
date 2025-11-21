#include <stdio.h>
#include <string.h>


#define MAX_STR_LEN 50
#define MAX_FLIGHTS 10

typedef struct {
    char flightNumber[MAX_STR_LEN];
    char departureCity[MAX_STR_LEN];
    char destinationCity[MAX_STR_LEN];
    char date[MAX_STR_LEN]; 
    int totalSeats;
    int availableSeats;
} Flight;

void displayFlightDetails(const Flight *flight) {
    printf("\n--- Flight Details ---\n");
    printf("Flight No: %s\n", flight->flightNumber);
    printf("Route: %s to %s\n", flight->departureCity, flight->destinationCity);
    printf("Date: %s\n", flight->date);
    printf("Total Seats: %d\n", flight->totalSeats);
    printf("Available Seats: %d\n", flight->availableSeats);
    printf("Status: %s\n", flight->availableSeats > 0 ? "Seats Available" : "Fully Booked");
    printf("----------------------\n");
}

int bookSeat(Flight *flight) {
    if (flight->availableSeats > 0) {
        flight->availableSeats--; 
        printf("\n*** SUCCESS! ***\n");
        printf("Seat successfully booked on Flight %s.\n", flight->flightNumber);
        printf("New available seats: %d\n", flight->availableSeats);
        return 1;
    } else {
        printf("\n*** FAILED ***\n");
        printf("Booking failed for Flight %s. No seats available.\n", flight->flightNumber);
        return 0;
    }
}

int main() {
    
    Flight flights[MAX_FLIGHTS];
    int flightCount = 0;

    
    
    
    strcpy(flights[flightCount].flightNumber, "PL101");
    strcpy(flights[flightCount].departureCity, "New York (JFK)");
    strcpy(flights[flightCount].destinationCity, "London (LHR)");
    strcpy(flights[flightCount].date, "2025-12-15");
    flights[flightCount].totalSeats = 180;
    flights[flightCount].availableSeats = 5; 
    flightCount++;

    
    strcpy(flights[flightCount].flightNumber, "TR459");
    strcpy(flights[flightCount].departureCity, "Paris (CDG)");
    strcpy(flights[flightCount].destinationCity, "Tokyo (NRT)");
    strcpy(flights[flightCount].date, "2025-12-16");
    flights[flightCount].totalSeats = 250;
    flights[flightCount].availableSeats = 250; 
    flightCount++;
    
    
    strcpy(flights[flightCount].flightNumber, "CX888");
    strcpy(flights[flightCount].departureCity, "Hong Kong (HKG)");
    strcpy(flights[flightCount].destinationCity, "Los Angeles (LAX)");
    strcpy(flights[flightCount].date, "2025-12-17");
    flights[flightCount].totalSeats = 300;
    flights[flightCount].availableSeats = 0; 
    flightCount++;
    
    printf("FLIGHT INFORMATION MANAGEMENT SYSTEM (C)\n");
    printf("Total Flights Managed: %d\n\n", flightCount);
    

    
    printf("\n--- DEMONSTRATION 1: Initial Status of Flight %s ---\n", flights[0].flightNumber);
    displayFlightDetails(&flights[0]);

    
    printf("\n--- DEMONSTRATION 2: Successful Booking on Flight %s ---\n", flights[0].flightNumber);
    bookSeat(&flights[0]);
    
    
    printf("\n--- DEMONSTRATION 3: Status of Flight %s After Booking ---\n", flights[0].flightNumber);
    displayFlightDetails(&flights[0]);
    
    
    printf("\n--- DEMONSTRATION 4: Booking remaining 4 seats ---\n");
    for (int i = 0; i < 4; i++) {
        bookSeat(&flights[0]);
    }

    
    printf("\n--- DEMONSTRATION 5: Attempting booking on fully booked Flight %s ---\n", flights[0].flightNumber);
    bookSeat(&flights[0]);

    
    printf("\n--- DEMONSTRATION 6: Status of Fully Booked Flight %s ---\n", flights[2].flightNumber);
    displayFlightDetails(&flights[2]);
    
    
    printf("\n--- DEMONSTRATION 7: Attempting booking on Flight %s ---\n", flights[2].flightNumber);
    bookSeat(&flights[2]);


    return 0;
}