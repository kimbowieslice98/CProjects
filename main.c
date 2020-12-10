//
//  main.c
//  airline project
//
//  Created by kimberly scirotto on 3/28/19.
//  Copyright © 2019 kimberly scirotto. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    

    FlightCount = read_flight(FlightNumber,FlightCityOrigin,FlightCityDestination, FlightDate, FlightTime, FlightSeats, FlightCount);
    ReservationCount = read_reservation(ReservationCount, ReservationCode, ReservationFlightNumber, LastName, FirstName, SeatType, SeatCost);
    menu(FlightNumber, FlightCityOrigin, FlightCityDestination, FlightDate, FlightTime, FlightSeats, FlightCount, ReservationCode, LastName, FirstName, SeatType, SeatCost, ReservationCount,  ReservationFlightNumber);

    Exit_program(FlightNumber, FlightCityOrigin, FlightCityDestination, FlightDate, FlightTime, FlightSeats, FlightCount, ReservationCode, LastName, FirstName, SeatType, SeatCost, ReservationCount,  ReservationFlightNumber);
    return 0;
}
int read_flight(int FlightNumber[],char FlightCityOrigin[][20],char FlightCityDestination[][20], char FlightDate[][20], char FlightTime[][20],int FlightSeats[], int FlightCount)
{ 
    printf("Executing read_flight\n");
    FILE *fptr;
    int value1, value6 = 0;
    char value2[20],value3[20],value4[20],value5[20];
    /*  open the file for reading */
    fptr = fopen("/Users/huxsgirl/Library/Autosave Information/CSC124 HW1/kimhw3/airline project/airline project/flightc.txt", "r");
    if (!fptr)
    {
        printf("Cannot open file \n");
        return 1;
    }
    while(fscanf(fptr,"%d %s %s %s %s %d",&value1,value2,value3,value4,value5,&value6) != EOF )
     {
        FlightCount = FlightCount + 1;
        FlightNumber[FlightCount]=value1;
        strcpy(FlightCityOrigin[FlightCount],value2);
        strcpy(FlightCityDestination[FlightCount],value3);
        strcpy(FlightDate[FlightCount],value4);
        strcpy(FlightTime[FlightCount],value5);
        FlightSeats[FlightCount]=value6;
        
     }
    fclose(fptr);
    return FlightCount;
}

int read_reservation(int ReservationCount, int ReservationCode[], int ReservationFlightNumber[], char LastName[][20], char FirstName[][20], char SeatType[][20], double SeatCost[])
{
    printf("Executing read_reservation\n");
    FILE *fptr;
    int value1, value2;
    char value3[20],value4[20],value5[20];
    double value6 = 0.0;
    /*  open the file for reading */
    fptr = fopen("/Users/huxsgirl/Library/Autosave Information/CSC124 HW1/kimhw3/airline project/airline project/reservationc.txt", "r");
    if (!fptr)
    {
        printf("Cannot open file \n");
        return 1;
    }
    while(fscanf(fptr,"%d %d %s %s %s %lf",&value1, &value2,value3,value4,value5,&value6) != EOF )
    {
        ReservationCount = ReservationCount + 1;
        ReservationCode[ReservationCount]= value1;
        ReservationFlightNumber[ReservationCount] = value2;
        strcpy(LastName[ReservationCount], value3);
        strcpy(FirstName[ReservationCount], value4);
        strcpy(SeatType[ReservationCount], value5);
        SeatCost[ReservationCount] = value6;
    }
    fclose(fptr);
    return ReservationCount;
}

int menu(int FlightNumber[],char FlightCityOrigin[][20],char FlightCityDestination[][20], char FlightDate[][20], char FlightTime[][20],int FlightSeats[], int FlightCount,int ReservationCode[], char LastName[][20],char FirstName[][20],char SeatType[][20],double SeatCost[],int ReservationCount, int ReservationFlightNumber[] )
{
    int selection;
    printf("ACME Airline System\n\n");
    printf("1. Add/modify Flight Information\n");
    printf("2. Add/modify Reservation Information\n");
    printf("3. Report Section\n");
    printf("4. Exit Airline System\n\n");
    printf("Please make your selection: ");
    scanf("%d",&selection);
    while(selection != 4){
        if(selection == 1){
            FlightCount = Modify_flight( FlightNumber, FlightCityOrigin, FlightCityDestination,  FlightDate,  FlightTime, FlightSeats,  FlightCount);
        }
        if(selection == 2){
            ReservationCount = Modify_reservation(ReservationCount, ReservationCode, ReservationFlightNumber, LastName, FirstName, SeatType, SeatCost);
        }
        if(selection == 3){
            Report(FlightNumber,FlightCityOrigin,FlightCityDestination, FlightDate, FlightTime, FlightSeats, FlightCount,ReservationCode, LastName, FirstName, SeatType, SeatCost, ReservationCount, ReservationFlightNumber);
        }
        printf("ACME Airline System\n\n");
        printf("1. Add/modify Flight Information\n");
        printf("2. Add/modify Reservation Information\n");
        printf("3. Report Section\n");
        printf("4. Exit Airline System\n\n");
        printf("Please make your selection: ");
        scanf("%d",&selection);
    }
    return selection;
    
}

int Modify_flight(int FlightNumber[],char FlightCityOrigin[][20],char FlightCityDestination[][20], char FlightDate[][20], char FlightTime[][20],int FlightSeats[], int FlightCount)
{
    printf("Executing Modify flight\n");
    int choice, selection = 0;

    
    printf("1. Add Flight\n2. Delete Flight\n3. Modify Flight\n4. Exit this menu");
    scanf("%d", &choice);
    while(choice != 4)
    {
        //Add Flight
        if(choice  == 1){
            FlightCount = FlightCount + 1;
            printf("enter new flight number\n");
            scanf("%d", &FlightNumber[FlightCount]);
            
            printf("enter new flight city origin\n");
            scanf("%s", FlightCityOrigin[FlightCount]);
            
            printf("enter new flight city destination\n");
            scanf("%s", FlightCityDestination[FlightCount]);
            
            printf("enter new flight date\n");
            scanf("%s", FlightDate[FlightCount]);
            
            printf("enter new flight time\n");
            scanf("%s", FlightTime[FlightCount]);
            
            printf("enter new flight seats\n");
            scanf("%d", &FlightSeats[FlightCount]);
        }
        //Delete Flight
        if(choice == 2){
            int deleteChoice = 0;
            printf("Enter Flight Number you want to delete");
            scanf("%d", &deleteChoice);
            for(int i = 0; i < FlightCount; i++ ){
                selection = i;
                if(deleteChoice == FlightNumber[i]){
                    for(int x = selection;x <= FlightCount-1;++x){
                        FlightNumber[x] = FlightNumber[x+1];
                        strcpy(FlightCityOrigin[x], FlightCityOrigin[x+1]);
                        strcpy(FlightCityDestination[x], FlightCityDestination[x+1]);
                        strcpy(FlightDate[x], FlightDate[x+1]);
                        strcpy(FlightTime[x], FlightTime[x+1]);
                        FlightSeats[x] = FlightSeats[x+1];
                    }
                    FlightCount = FlightCount - 1;
                }
            }
        }
        //Modify Flight
        if(choice == 3){
            int modChoice = 0;
            printf("Enter Flight Number you want to modify");
            scanf("%d", &modChoice);
            for(int i = 0; i < FlightCount; i++ ){
                if(modChoice == FlightNumber[i]){
                    printf("enter new flight number");
                    scanf("%d", &FlightNumber[i]);
                    
                    printf("enter new flight city origin");
                    scanf("%s", FlightCityOrigin[i]);
                    
                    printf("enter new flight city destination");
                    scanf("%s", FlightCityDestination[i]);
                    
                    printf("enter new flight date");
                    scanf("%s", FlightDate[i]);
                    
                    printf("enter new flight time");
                    scanf("%s", FlightTime[i]);
                    
                    printf("enter new flight seats");
                    scanf("%d", &FlightSeats[i]);
                }
            }
        }
        printf("1. Add Flight\n2. Delete Flight\n3. Modify Flight\n4. Exit this menu");
        scanf("%d", &choice);
    }
    return FlightCount;
}
int Modify_reservation(int ReservationCount, int ReservationCode[], int ReservationFlightNumber[], char LastName[][20], char FirstName[][20], char SeatType[][20], double SeatCost[]){
    int choice, selection = 0;
    printf("1. Add Reservation\n2. Delete Reservation\n3. Modify Reservation\n4. Exit this menu");
    scanf("%d", &choice);
    while(choice != 4)
    {
        //Add Reservation
        if(choice  == 1){
            ReservationCount = ReservationCount + 1;
            printf("enter new reservation code\n");
            scanf("%d", &ReservationCode[ReservationCount]);
            
            printf("enter new Reservation Flight Number\n");
            scanf("%d", &ReservationFlightNumber[ReservationCount]);
            
            printf("enter new last name\n");
            scanf("%s", LastName[ReservationCount]);
            
            printf("enter new first name\n");
            scanf("%s", FirstName[ReservationCount]);
            
            printf("enter new seat type\n");
            scanf("%s", SeatType[ReservationCount]);
            
            printf("enter new reservation seat cost\n");
            scanf("%lf", &SeatCost[ReservationCount]);
        }
        //Delete Flight
        if(choice == 2){
            int deleteChoice = 0;
            printf("Enter Reservation Code you want to delete");
            scanf("%d", &deleteChoice);
            for(int i = 0; i < ReservationCount; i++ ){
                selection = i;
                if(deleteChoice == ReservationCode[i]){
                    for(int x = selection;x <= ReservationCount-1;++x){
                        ReservationCode[x] = ReservationCode[x+1];
                        ReservationFlightNumber[x] = ReservationFlightNumber[x+1];
                        strcpy(LastName[x], LastName[x+1]);
                        strcpy(FirstName[x], FirstName[x+1]);
                        strcpy(SeatType[x], SeatType[x+1]);
                        SeatCost[x] = SeatCost[x+1];
                    }
                    ReservationCount = ReservationCount - 1;
                }
            }
        }
        //Modify Flight
        if(choice == 3){
            int modChoice = 0;
            printf("Enter Reservation code you want to modify");
            scanf("%d", &modChoice);
            for(int i = 0; i < ReservationCount; i++ ){
                if(modChoice == ReservationCode[i]){
                    printf("enter new Reservation code");
                    scanf("%d", &ReservationCode[i]);
                    
                    printf("enter new reservation flight number");
                    scanf("%d", &ReservationFlightNumber[i]);
                    
                    printf("enter new last name");
                    scanf("%s", LastName[i]);
                    
                    printf("enter new first name");
                    scanf("%s", FirstName[i]);
                    
                    printf("enter new seat type");
                    scanf("%s", SeatType[i]);
                    
                    printf("enter new seat cost");
                    scanf("%lf", &SeatCost[i]);
                }
            }
        }
        printf("1. Add Flight\n2. Delete Flight\n3. Modify Flight\n4. Exit this menu");
        scanf("%d", &choice);
    }
    return ReservationCount;
}
void Report(int FlightNumber[],char FlightCityOrigin[][20],char FlightCityDestination[][20], char FlightDate[][20], char FlightTime[][20],int FlightSeats[], int FlightCount,int ReservationCode[], char LastName[][20],char FirstName[][20],char SeatType[][20],double SeatCost[],int ReservationCount, int ReservationFlightNumber[] ){
    int x = 0;
    int flightNumberInput;
    char seattype[20];
    int ReportSelection = 0 ;
    printf("1. All Flight Info \n 2. All Reservation Info \n 3. Value of Reservations of Specific Type \n 4. All Reservations on Specific Flight \n 5. View all flights from city \n 6. Specific reservation infomation \n 7. Summary of all flights \n 8. Report 8 \n 9. Exit Report Menu \n ");
    scanf("%d", &ReportSelection);
    while(ReportSelection != 9)
    {
        if(ReportSelection == 1)
        {
            for(x = 0; x <= FlightCount; ++x ){
                printf("%d %s %s %s %s %d \n ", FlightNumber[x], FlightCityOrigin[x], FlightCityDestination[x], FlightDate[x], FlightTime[x], FlightSeats[x]);
             }
        }
        else if(ReportSelection == 2)
        {
            for(x = 0; x <= ReservationCount; ++x ){
                printf("%d %d %s %s %s %lf \n ", ReservationCode[x], ReservationFlightNumber[x], LastName[x], FirstName[x], SeatType[x], SeatCost[x]);
            }
        }
        else if(ReportSelection == 3)
        {
            printf("Enter type of seat\n");
            scanf("%s", seattype);
            for(x = 0; x <= ReservationCount; ++x ){
                if ( strcmp(seattype, SeatType[x]) == 0){
                    printf("%d %d %s %s %s %lf \n ", ReservationCode[x], ReservationFlightNumber[x], LastName[x], FirstName[x], SeatType[x], SeatCost[x]);
                }
            }
        }
        else if(ReportSelection == 4)
        {
            printf("Enter Flight Number\n");
            scanf("%d", &flightNumberInput);
            for(x = 0; x <= ReservationCount; ++x ){
               // printf("%d", x);
                if(flightNumberInput == ReservationFlightNumber[x]){
                    printf("%d %d %s %s %s %lf \n ", ReservationCode[x], ReservationFlightNumber[x], LastName[x], FirstName[x], SeatType[x], SeatCost[x]);
                }
            }
        }
        else if(ReportSelection == 5)
        {
            char cityInput[20];
            printf("Enter city to view flights leaving here:");
            scanf("%s", cityInput);
            for(x = 0; x <= FlightCount; ++x ){
                if(strcmp(cityInput, FlightCityOrigin[x]) == 0){
                    printf("%d %s %s %s %s %d \n ", FlightNumber[x], FlightCityOrigin[x], FlightCityDestination[x], FlightDate[x], FlightTime[x], FlightSeats[x]);
                }
            }
        }
        else if(ReportSelection == 6){
            int resCode;
            printf("Enter the Reservation Code to view: ");
            scanf("%d", &resCode);
            for(x = 0; x <= ReservationCount; ++x ){
                if(resCode == ReservationCode[x]){
                    printf("%d %d %s %s %s %lf \n ", ReservationCode[x], ReservationFlightNumber[x], LastName[x], FirstName[x], SeatType[x], SeatCost[x]);
                }
            }        }
        else if(ReportSelection == 7){
            for(x = 0; x <= FlightCount; ++x ){
                printf("%d %s %s %s %s %d \n *************************************** \n", FlightNumber[x], FlightCityOrigin[x], FlightCityDestination[x], FlightDate[x], FlightTime[x], FlightSeats[x]);
                for(int j = 0; j <= ReservationCount; ++j){
                    if(ReservationFlightNumber[j] == FlightNumber[x]){
                        printf("%d %d %s %s %s %lf \n ", ReservationCode[j], ReservationFlightNumber[j], LastName[j], FirstName[j], SeatType[j], SeatCost[j]);                    }
                }
                printf(" *************************************** \n");
            }
        }
        else if(ReportSelection == 8){
            {
                char cityInput[20];
                printf("Enter city to see flights heading there:");
                scanf("%s", cityInput);
                for(x = 0; x <= FlightCount; ++x ){
                    if(strcmp(cityInput, FlightCityDestination[x]) == 0){
                        printf("%d %s %s %s %s %d \n ", FlightNumber[x], FlightCityOrigin[x], FlightCityDestination[x], FlightDate[x], FlightTime[x], FlightSeats[x]);
                    }
                }
            }
        }
        printf("1. All Flight Info \n 2. All Reservation Info \n 3. Value of Reservations of Specific Type \n 4. All Reservations on Specific Flight \n 5. View all flights from city \n 6. Specific reservation infomation \n 7. Summary of all flights \n 8. Enter city to see flights to that city \n 9. Exit Report Menu \n ");
        scanf("%d", &ReportSelection);
        
    }
}
void Exit_program(int FlightNumber[],char FlightCityOrigin[][20],char FlightCityDestination[][20], char FlightDate[][20], char FlightTime[][20],int FlightSeats[], int FlightCount,int ReservationCode[], char LastName[][20],char FirstName[][20],char SeatType[][20],double SeatCost[],int ReservationCount, int ReservationFlightNumber[] )
{
    printf("Executing Exit porgram\n");
    //Flight
    FILE *fptr = fopen("/Users/huxsgirl/Library/Autosave Information/CSC124 HW1/kimhw3/airline project/airline project/flightc.txt", "w");
    if(fptr == NULL){
        printf("Error!");
        exit(1);
    }
    for(int i = 0; i <= FlightCount + 1; ++i){
        if(i == FlightCount)
            fprintf(fptr, "%d %s %s %s %s %d\n", FlightNumber[i], FlightCityOrigin[i], FlightCityDestination[i], FlightDate[i], FlightTime[i], FlightSeats[i]);
        else
            fprintf(fptr, "%d %s %s %s %s %d \n", FlightNumber[i], FlightCityOrigin[i], FlightCityDestination[i], FlightDate[i], FlightTime[i], FlightSeats[i]);
    }
    fclose(fptr);
    //Reservation
    FILE *fpt = fopen("/Users/huxsgirl/Library/Autosave Information/CSC124 HW1/kimhw3/airline project/airline project/reservationc.txt", "w");
    if(fpt == NULL){
        printf("Error!");
        exit(1);
    }
    for(int i = 0; i <= ReservationCount + 1; ++i ){
        if(i == ReservationCount)
            fprintf(fpt, "%d %d %s %s %s %lf\n", ReservationCode[i], ReservationFlightNumber[i], LastName[i], FirstName[i], SeatType[i], SeatCost[i]);
        else
            fprintf(fpt, "%d %d %s %s %s %lf\n", ReservationCode[i],  ReservationFlightNumber[i], LastName[i], FirstName[i], SeatType[i], SeatCost[i]);
    }
    fclose(fpt);
}


