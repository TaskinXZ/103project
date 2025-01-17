#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VEHICLES 100  // Define the maximum number of vehicles

typedef struct Vehicle {
    char vehicle_id[10];
    char vehicle_name[50];
    char manufacturer_name[50];
    char issue_date[11];
} Vehicle;

Vehicle vehicles[MAX_VEHICLES]; // Array to hold vehicles
int vehicle_count = 0; // To track the number of vehicles

// Login credentials
char username[50] = "admin";
char password[50] = "password";

// Function to display header message
void head_Message() {
    printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
    printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
    printf("<~><~><~><~>                                                   <~><~><~><~>\n");
    printf("<~><~><~><~>             Vehicle Management System             <~><~><~><~>\n");
    printf("<~><~><~><~>                                                   <~><~><~><~>\n");
    printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
    printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n\n\n");
}

// Function to print message in the center
void print_Message_in_Center(char *message) {
    int length = strlen(message);
    int spacing = 42 - length;

    printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
    printf("                                                                           \n");


    for (int i = 0; i < spacing; i++) {
        printf(" ");
    }

    printf("%s\n", message);
    printf("                                                                           \n");
    printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n\n\n");
}


// Function to show welcome message
void welcome_Message() {
    printf("         <~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>         \n");
    printf("                                                                           \n");
    printf("               <~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>               \n");
    printf("               <~>                WELCOME                <~>               \n");
    printf("               <~>                  TO                   <~>               \n");
    printf("               <~>                VEHICLE                <~>               \n");
    printf("               <~>              MANAGEMENT               <~>               \n");
    printf("               <~>                SYSTEM                 <~>               \n");
    printf("               <~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>               \n");
    printf("                                                                           \n");
    printf("         <~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>         \n\n\n\n");

    printf("Enter any key to continue. . . . .\n\n\n\n\n");
}

// Function to display the main menu
void menu() {
    int choice;
    head_Message();
    printf("Main Menu\n");
    printf("1. Add Vehicle\n");
    printf("2. Search Vehicle\n");
    printf("3. View Vehicles\n");
    printf("4. Delete Vehicle\n");
    printf("5. Update Password\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1: addVehicleInDataBase(); break;
        case 2: searchVehicles(); break;
        case 3: viewVehicles(); break;
        case 4: deleteVehicles(); break;
        case 5: updateCredential(); break;
        case 6: exitProgram(); break;
        default: printf("Invalid choice.\n"); break;
    }
}

// Function to validate names (Vehicle Name, Manufacturer Name)
int is_Name_Valid(char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!(isalpha(name[i]) || name[i] == ' ')) {
            printf("Invalid name. Only letters and spaces are allowed.\n");
            return 0;
        }
    }
    return 1;
}

// Function to validate date input (dd/mm/yyyy)
int is_Valid_Date(char *date) {
    int day, month, year;
    if (sscanf(date, "%d/%d/%d", &day, &month, &year) != 3) {
        printf("Invalid date format.\n");
        return 0;
    }
    if (month < 1 || month > 12 || day < 1 || day > 31 || year < 1900) {
        printf("Invalid date value.\n");
        return 0;
    }
    return 1;
}

// Function to add a new vehicle to the database
void addVehicleInDataBase() {
    if (vehicle_count >= MAX_VEHICLES) {
        printf("Database is full, cannot add more vehicles.\n");
        return;
    }

    Vehicle *new_vehicle = &vehicles[vehicle_count];
    char vehicle_name[50], manufacturer_name[50], issue_date[11];

    printf("Enter Vehicle ID: ");
    scanf("%s", new_vehicle->vehicle_id);
    printf("Enter Vehicle Name: ");
    scanf(" %[^\n]%*c", vehicle_name);
    if (!is_Name_Valid(vehicle_name)) {
        return;
    }
    strcpy(new_vehicle->vehicle_name, vehicle_name);

    printf("Enter Manufacturer Name: ");
    scanf(" %[^\n]%*c", manufacturer_name);
    if (!is_Name_Valid(manufacturer_name)) {
        return;
    }
    strcpy(new_vehicle->manufacturer_name, manufacturer_name);

    printf("Enter Issue Date (dd/mm/yyyy): ");
    scanf("%s", issue_date);
    if (!is_Valid_Date(issue_date)) {
        return;
    }
    strcpy(new_vehicle->issue_date, issue_date);

    vehicle_count++;
    printf("Vehicle added successfully.\n");
}

// Function to search for a vehicle by name
void searchVehicles() {
    char search_name[50];
    printf("Enter vehicle name to search: ");
    scanf(" %[^\n]%*c", search_name);

    for (int i = 0; i < vehicle_count; i++) {
        if (strcmp(vehicles[i].vehicle_name, search_name) == 0) {
            printf("Vehicle ID: %s\n", vehicles[i].vehicle_id);
            printf("Vehicle Name: %s\n", vehicles[i].vehicle_name);
            printf("Manufacturer Name: %s\n", vehicles[i].manufacturer_name);
            printf("Issue Date: %s\n", vehicles[i].issue_date);
            return;
        }
    }
    printf("No Record.\n");
}

// Function to view all stored vehicles
void viewVehicles() {
    if (vehicle_count == 0) {
        printf("No Record.\n");
        return;
    }

    for (int i = 0; i < vehicle_count; i++) {
        printf("Vehicle ID: %s\n", vehicles[i].vehicle_id);
        printf("Vehicle Name: %s\n", vehicles[i].vehicle_name);
        printf("Manufacturer Name: %s\n", vehicles[i].manufacturer_name);
        printf("Issue Date: %s\n", vehicles[i].issue_date);
        printf("\n");
    }
}

// Function to delete a vehicle by ID
void deleteVehicles() {
    char vehicle_id[10];
    printf("Enter Vehicle ID to delete: ");
    scanf("%s", vehicle_id);

    int found = 0;
    for (int i = 0; i < vehicle_count; i++) {
        if (strcmp(vehicles[i].vehicle_id, vehicle_id) == 0) {
            // Shift all elements after the deleted one
            for (int j = i; j < vehicle_count - 1; j++) {
                vehicles[j] = vehicles[j + 1];
            }
            vehicle_count--;
            printf("Record deleted successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Record not found.\n");
    }
}

// Function to update username and password
void updateCredential() {
    char new_username[50], new_password[50];
    printf("Enter new username: ");
    scanf("%s", new_username);
    printf("Enter new password: ");
    scanf("%s", new_password);

    // Update stored credentials
    strcpy(username, new_username);
    strcpy(password, new_password);

    printf("Your password has been changed successfully.\n");
    printf("Please login again.\n");
    loginPrompt(); // Prompt user to log in again after credential update
}

// Function to display login prompt
int loginPrompt() {
    char input_username[50], input_password[50];
    int attempts = 3;

    while (attempts > 0) {
        printf("Enter username: ");
        scanf("%s", input_username);
        printf("Enter password: ");
        scanf("%s", input_password);

        if (strcmp(input_username, username) == 0 && strcmp(input_password, password) == 0) {
            printf("Login successful!\n");
            return 1;
        } else {
            printf("Invalid username or password. You have %d attempts remaining.\n", --attempts);
        }
    }
    printf("Too many failed attempts. Exiting...\n");
    exit(0);
}

// Function to exit the program
void exitProgram() {
    printf("Thank you for using the Vehicle Management System!\n");
    exit(0);
}

int main() {
    if (!loginPrompt()) {
        return 0;
    }

    welcome_Message();
    while (1) {
        menu();
    }
    return 0;
}
