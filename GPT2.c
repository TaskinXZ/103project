#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct Vehicle {
    char vehicle_id[10];
    char vehicle_name[50];
    char manufacturer_name[50];
    char issue_date[11];
} Vehicle;

struct Vehicle vehicles; // Array to hold vehicles
int vehicle_count = 0; // To track the number of vehicles

// Login credentials
char username[50] = "admin";
char password[50] = "password";

// Function to display header message
void head_Message() {
    printf("\n\n\n<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
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
    int spacing = 37 - length/2;

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
    printf("\n\n\n\n         <~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>         \n");
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

    printf("Enter any key to continue. . . . .\n\n\n\n");
    getche();
    printf("\n");
}

// Function to display the main menu
void menu() {
    int choice;
    head_Message();
    print_Message_in_Center("MAIN MENU");
    printf("1. Add Vehicle\n");
    printf("2. Search Vehicle\n");
    printf("3. View Vehicles\n");
    printf("4. Delete Vehicle\n");
    printf("5. Update Password\n");
    printf("6. Exit\n\n\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Clear input buffer
    while (getchar() != '\n');

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

// Function to validate the name (only letters and spaces allowed)
int is_Name_Valid(const char *name) {
    if (strlen(name) == 0) return 0;  // Empty name is invalid

    for (int i = 0; name[i] != '\0'; i++) {
        if (!(isalpha(name[i]) || name[i] == ' ')) {  // Check for non-letter or non-space characters
            return 0;  // Invalid if a non-letter/space is found
        }
    }

    return 1;  // Valid name
}


// Function to validate the date (dd/mm/yyyy format)
int is_Valid_Date(const char *date) {
    int day, month, year;

    // Check if the date matches dd/mm/yyyy format
    if (sscanf(date, "%2d/%2d/%4d", &day, &month, &year) != 3) {
        return 0;  // Invalid format
    }

    // Validate day, month, and year ranges
    if (month < 1 || month > 12) return 0;  // Month must be between 1 and 12
    if (day < 1 || day > 31) return 0;     // Day must be between 1 and 31

    // Additional simple check for 30-day months
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return 0;
    // February check (for simplicity, assumes non-leap year; you can add leap year check if needed)
    if (month == 2 && day > 28) return 0;
    if (year < 1900) return 0;  // Year should be reasonable (greater than 1900)

    return 1;  // Valid date
}


// Function to add a new vehicle to the database
void addVehicleInDataBase() {
    if (vehicle_count >= MAX_VEHICLES) {
        printf("Database is full, cannot add more vehicles.\n");
        return;
    }

    Vehicle *new_vehicle = &vehicles[vehicle_count]; // Use an array to store vehicles

    printf("\nENTER VEHICLE DETAILS BELOW:\n");
    printf("------------------------------------------------------------------------------------");

    // Input Vehicle ID (ensuring it's a valid integer)
    int valid_input = 0;
    while (!valid_input) {
        printf("\n\nVehicle ID NO = ");
        char id_input[10];
        fgets(id_input, sizeof(id_input), stdin);
        if (sscanf(id_input, "%d", &valid_input) == 1) {
            snprintf(new_vehicle->vehicle_id, sizeof(new_vehicle->vehicle_id), "%d", valid_input); // Store as string
        } else {
            printf("Invalid input! Please enter a valid integer for Vehicle ID.\n");
            valid_input = 0;
        }
    }

    // Input Vehicle Name (validating the name)
    while (1) {
        printf("\n\nVehicle Name = ");
        fgets(new_vehicle->vehicle_name, sizeof(new_vehicle->vehicle_name), stdin);
        // Remove trailing newline
        new_vehicle->vehicle_name[strcspn(new_vehicle->vehicle_name, "\n")] = '\0';
        if (is_Name_Valid(new_vehicle->vehicle_name)) {
            break;
        }
        printf("Invalid input! Please enter a valid vehicle name.\n");
    }

    // Input Manufacturer Name (validating the name)
    while (1) {
        printf("\n\nVehicle Manufacturer Name = ");
        fgets(new_vehicle->manufacturer_name, sizeof(new_vehicle->manufacturer_name), stdin);
        // Remove trailing newline
        new_vehicle->manufacturer_name[strcspn(new_vehicle->manufacturer_name, "\n")] = '\0';
        if (is_Name_Valid(new_vehicle->manufacturer_name)) {
            break;
        }
        printf("Invalid input! Please enter a valid manufacturer name.\n");
    }

    // Input Issue Date (validating the date)
    while (1) {
        printf("\n\nVehicle issued date by Manufacturer (day/month/year): ");
        fgets(new_vehicle->issue_date, sizeof(new_vehicle->issue_date), stdin);
        // Remove trailing newline
        new_vehicle->issue_date[strcspn(new_vehicle->issue_date, "\n")] = '\0';
        if (is_Valid_Date(new_vehicle->issue_date)) {
            break;
        }
        printf("Invalid input! Please enter a valid date in dd/mm/yyyy format.\n");
    }

    // Increment vehicle count
    vehicle_count++;

    // Confirm success and display the added vehicle details
    printf("\n\n\nVehicle added successfully!\n");
    printf("\nVehicle id: %s\n", new_vehicle->vehicle_id);
    printf("\nVehicle Name: %s\n", new_vehicle->vehicle_name);
    printf("\nManufacturer Name: %s\n", new_vehicle->manufacturer_name);
    printf("\nVehicle issued date by Manufacturer (day/month/year) = %s\n", new_vehicle->issue_date);
}




// Function to search for a vehicle by name
void searchVehicles() {

    print_Message_in_Center("SEARCH VEHICLES");

    char search_name[50];
    printf("Enter vehicle name to search: ");
    scanf(" %[^\n]%*c", search_name);

    for (int i = 0; i < vehicle_count; i++) {
        if (strcmp(vehicles[i].vehicle_name, search_name) == 0) {
            printf("Vehicle id: %s\n", vehicles[i].vehicle_id);
            printf("Vehicle Name: %s\n", vehicles[i].vehicle_name);
            printf("Manufacturer Name: %s\n", vehicles[i].manufacturer_name);
            printf("Vehicle issued date by Manufacturer (day/month/year) = %s\n", vehicles[i].issue_date);
            return;
        }
    }
    printf("No Record.\n");
}

// Function to view all stored vehicles
void viewVehicles() {

    print_Message_in_Center("VIEW VEHICLE DETAILS");

    if (vehicle_count == 0) {
        printf("No Record.\n");
        return;
    }

    for (int i = 0; i < vehicle_count; i++) {
        printf("Vehicle id: %s\n", vehicles[i].vehicle_id);
        printf("Vehicle Name: %s\n", vehicles[i].vehicle_name);
        printf("Manufacturer Name: %s\n", vehicles[i].manufacturer_name);
        printf("Vehicle issued date by Manufacturer (day/month/year) = %s\n", vehicles[i].issue_date);
        printf("\n");
    }
}

// Function to delete a vehicle by ID
void deleteVehicles() {

    print_Message_in_Center("Delete Vehicle Details");

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

    print_Message_in_Center("Update Credentials");

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
    head_Message();

    char input_username[50], input_password[50];
    int attempts = 3;

    print_Message_in_Center("Login");

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
