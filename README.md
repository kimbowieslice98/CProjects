# CProjects
> Flight Reservation

## General info
The idea of this program was to create a way for users to alter their flight through a simulated menu. The menu consisted of the following options: add flight, delete flight, modify flight, and exit. The purpose of this program was to emulate a real application that allows flight alterations.

## Technologies
* Xcode 12.3

## Setup
The only thing needed in this program for it to run successfully is to make sure the two text files, reservationc and flightc, are downloaded into Xcode.

## Code Examples
int read_flight(int FlightNumber[],char FlightCityOrigin[][20],char FlightCityDestination[][20], char FlightDate[][20], char FlightTime[][20],int FlightSeats[], int FlightCount);
int read_reservation(int ReservationCount, int ReservationCode[], int ReservationFlightNumber[], char LastName[][20], char FirstName[][20], char SeatType[][20], double SeatCost[]);
int menu(int FlightNumber[],char FlightCityOrigin[][20],char FlightCityDestination[][20], char FlightDate[][20], char FlightTime[][20],int FlightSeats[], int FlightCount,int ReservationCode[], char LastName[][20],char FirstName[][20],char SeatType[][20],double SeatCost[],int ReservationCount, int ReservationFlightNumber[] );
int Modify_flight(int FlightNumber[],char FlightCityOrigin[][20],char FlightCityDestination[][20], char FlightDate[][20], char FlightTime[][20],int FlightSeats[], int FlightCount);
int Modify_reservation(int ReservationCount, int ReservationCode[], int ReservationFlightNumber[], char LastName[][20], char FirstName[][20], char SeatType[][20], double SeatCost[]);
void Report(int FlightNumber[],char FlightCityOrigin[][20],char FlightCityDestination[][20], char FlightDate[][20], char FlightTime[][20],int FlightSeats[], int FlightCount,int ReservationCode[], char LastName[][20],char FirstName[][20],char SeatType[][20],double SeatCost[],int ReservationCount, int ReservationFlightNumber[]);
void Exit_program(int FlightNumber[],char FlightCityOrigin[][20],char FlightCityDestination[][20], char FlightDate[][20], char FlightTime[][20],int FlightSeats[], int FlightCount,int ReservationCode[], char LastName[][20],char FirstName[][20],char SeatType[][20],double SeatCost[],int ReservationCount, int ReservationFlightNumber[] );

int main(int argc, const char * argv[])
{
  //flight section
    int FlightNumber[100];
    char FlightCityOrigin[100][20];
    char FlightCityDestination[100][20];
    char FlightDate[100][20];
    char FlightTime[100][20];
    int FlightSeats[100];
    int FlightCount = -1;
    
    
    
    //reservation section
    int ReservationCode[100];
    int ReservationFlightNumber[100];
    char LastName[100][20];
    char FirstName[100][20];
    char SeatType[100][20];
    double SeatCost[100];
    int ReservationCount=-1;
    
## Features
List of features ready 
* Allows user to enter in all their info for their flight to start to make changes to their flight.

To-do list:
* No further improvement to be made.

## Status
Project is: _finished_: The program performs the actions it is supposed to, so no further updates need to be completed.
