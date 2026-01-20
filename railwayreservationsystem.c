#include<stdio.h>
#include<string.h>

struct Passenger {
    char name[50];
    int age;
    char seatType[20];
};
struct Ticket {
    char from[30];
    char to[30];
    char date[20];
    char trainName[50];
    char travelClass[30];
    int numPassengers;
    float totalAmount;
    struct Passenger psgList[10];
};

int main() {
    struct Ticket t; 
    
    char booking[10];
    int trainChoice, classChoice, choice = 0;
    int seatOption;
    float amount = 0;

    printf("=============================================\n");
    printf("      TRACK & RIDE EXPRESS - BOOK TICKET\n");
    printf("=============================================\n\n");

    printf("Select Journey Details:\n");

    printf("From : ");
    scanf("%s", t.from); 

    printf("To : ");
    scanf("%s", t.to);

    printf("Date of Journey (DD/MM/YYYY): ");
    scanf("%s", t.date);

    printf("Number of Passengers: ");
    scanf("%d", &t.numPassengers);

    for(int i = 0; i < t.numPassengers; i++) {
        printf("\nEnter details for passenger %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", t.psgList[i].name); 
        
        printf("Age: ");
        scanf("%d", &t.psgList[i].age);
        
        printf("Preferred seat type (1: Upper, 2: Middle, 3: Lower): ");
        scanf("%d", &seatOption);
        
        if(seatOption == 1) 
            strcpy(t.psgList[i].seatType, "Upper");
        else if(seatOption == 2) 
            strcpy(t.psgList[i].seatType, "Middle");
        else 
            strcpy(t.psgList[i].seatType, "Lower");
    }

    printf("\nSelect Class:\n");
    printf("1. First Class AC\n2. Second Class AC\n3. Third Class AC\n4. Sleeper\n");
    printf("Enter choice: ");
    scanf("%d", &classChoice);

    switch (classChoice) {
        case 1: strcpy(t.travelClass, "First Class AC"); choice = 1; break;
        case 2: strcpy(t.travelClass, "Second Class AC"); choice = 2; break;
        case 3: strcpy(t.travelClass, "Third Class AC"); choice = 3; break;
        case 4: strcpy(t.travelClass, "Sleeper"); choice = 4; break;
        default: printf("Invalid choice!\n"); return 0;
    }
 
    printf("\nAvailable Trains:\n");
    printf("1. Rajdhani Express (%s to %s)\n", t.from, t.to);
    printf("2. Shatabdi Express (%s to %s)\n", t.from, t.to);
    printf("3. Banglore Rajdhani Express (%s to %s)\n", t.from, t.to);
    printf("4. Amarnath Express (%s to %s)\n", t.from, t.to);
    printf("5. Vande Bharat Express (%s to %s)\n", t.from, t.to);
    printf("6. Tejas Express (%s to %s)\n", t.from, t.to);
    printf("Enter train choice: ");
    scanf("%d", &trainChoice);

    if (trainChoice == 1) 
       strcpy(t.trainName, "Rajdhani Express");
    else if (trainChoice == 2) 
       strcpy(t.trainName, "Shatabdi Express");
    else if (trainChoice == 3) 
       strcpy(t.trainName, "Banglore Rajdhani Express");
    else if (trainChoice == 4) 
       strcpy(t.trainName, "Amarnath Express");
    else if (trainChoice == 5) 
       strcpy(t.trainName, "Vande Bharat Express");
    else if (trainChoice == 6) 
       strcpy(t.trainName, "Tejas Express");
    else {
        printf("Invalid train choice!\n");
        return 0;
    }

    if (trainChoice == 1) 
    { 
        if(choice == 1) amount = 5390.00;
        else if(choice == 2) amount = 4340.00;
        else if(choice == 3) amount = 3000.00;
        else amount = 1200.00;
    }
    else if (trainChoice == 2) 
    { 
        if(choice == 1) amount = 3330.00;
        else if(choice == 2) amount = 2020.00;
        else if(choice == 3) amount = 1520.00;
        else amount = 990.00;
    }
    else if (trainChoice == 3) 
    { 
        if(choice == 1) amount = 3300.00;
        else if(choice == 2) amount = 2810.00;
        else if(choice == 3) amount = 1960.00;
        else amount = 980.00;
    }    
    else if (trainChoice == 4) 
    { 
        if(choice == 1) amount = 4900.00;
        else if(choice == 2) amount = 3330.00;
        else if(choice == 3) amount = 2150.00;
        else amount = 1100.00;
    }    
    else if (trainChoice == 5) 
    { 
        if(choice == 1) amount = 4000.00;
        else if(choice == 2) amount = 3200.00;
        else if(choice == 3) amount = 1500.00;
        else amount = 1020.00;
    }
    else if (trainChoice == 6) 
    { 
        if(choice == 1) amount = 4750.00;
        else if(choice == 2) amount = 3652.00;
        else if(choice == 3) amount = 1965.00;
        else amount = 1600.00;
    }

    printf("\nPrice per ticket: %.2f\n", amount);
    printf("Confirm booking? (yes/no): ");
    scanf("%s", booking);

    if(strcmp(booking, "yes") == 0 || strcmp(booking, "YES") == 0 || strcmp(booking, "y") == 0) {
        t.totalAmount = t.numPassengers * amount;

        printf("\n---------------------------------------------\n");
        printf("           BOOKING SUMMARY\n");
        printf("---------------------------------------------\n");
        
        for(int i = 0; i < t.numPassengers; i++) {
            printf("Passenger %d: %s (Age: %d) - Seat: %s\n", 
                   i+1, t.psgList[i].name, t.psgList[i].age, t.psgList[i].seatType);
        }

        printf("---------------------------------------------\n");
        printf("Train Name     : %s\n", t.trainName);
        printf("Route          : %s to %s\n", t.from, t.to);
        printf("Date           : %s\n", t.date);
        printf("Class          : %s\n", t.travelClass);
        printf("Total Amount   : %.2f\n", t.totalAmount);
        printf("---------------------------------------------\n");
        printf("\nPayment Successful!\n");
        printf("Your e-ticket has been confirmed.\n");
        printf("Thank you for choosing Track & Ride Express!\n");
        printf("---------------------------------------------\n");
    }
    else {
        printf("\nBooking Cancelled.\n");
        printf("THANK YOU FOR VISITING\n");
    }
    
    return 0;
}