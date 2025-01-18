#include <stdio.h>
#include <string.h>

void welcome_Message();
void head_Message();
void print_Message_in_Center(char title[40]);
void headMessage_andCenter(char title[40]);
void addVehicleInDataBase();
void searchVehicle();
void viewVehicles();
void deleteVehicle();
void menu();
void updateCredential();
//void login();

struct addVehicle
{
    char vehicleID[20];
    char vehicleName[50];
    char manufacturerName[50];
    char issuedDate[15];
};

int is_Name_Valid(char *name)
{
    int i;
    if(strlen(name) == 0)
    {
        return 0; // Invalid if the name is empty
    }

    // Check if each character is a valid letter or space
    for(i = 0; name[i]; i++)
    {
        if(!((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || name[i] == ' '))
        {
            return 0; // Invalid if a character is not a letter or space
        }
    }

    // Ensure the name is not just spaces
    int allSpaces = 1;
    for(i = 0; name[i]; i++)
    {
        if(name[i] != ' ')
        {
            allSpaces = 0;
            break;
        }
    }

    if(allSpaces)
    {
        return 0; // Invalid if the name is only spaces
    }

    return 1; // Valid name
}

int is_Valid_Date(char *date)
{
    int day = 0, month = 0, year = 0;
    int i, j, k, part = 0;
    char temp[5] = {0}; // Buffer to store each part (day, month, year)

    // Parse the date string manually
    for(i = 0; date[i]; i++)
        {
        if(date[i] >= '0' && date[i] <= '9')
        {
            j = 0; // Reset temp buffer index for each new part
            // Collect the digits into the temp buffer using a for loop
            for(; date[i] >= '0' && date[i] <= '9' && j < 4; i++)
            {
                temp[j] = date[i];
                j++;
            }
            temp[j] = '\0'; // Null-terminate the string
            if(part == 0)
            {
                // Convert to integer for day
                day = 0;
                for (k = 0; temp[k]; k++) {
                    day = day * 10 + (temp[k] - '0');
                }
            } else if (part == 1){
                // Convert to integer for month
                month = 0;
                for (k = 0; temp[k]; k++) {
                    month = month * 10 + (temp[k] - '0');
                }
            } else if (part == 2){
                // Convert to integer for year
                year = 0;
                for (k = 0; temp[k]; k++)
                {
                    year = year * 10 + (temp[k] - '0');
                }
            }
            part++;
            i--; // Adjust the loop index to stay in place after processing digits
        } else if (date[i] == '/'){
            continue; // Skip the delimiter '/'
        } else{
            return 0; // Invalid character in the date string
        }
    }

    // Validate the month (must be between 1 and 12)
    if (month < 1 || month > 12){
        return 0;
    }

    // Validate the year (reasonable four-digit number, e.g., greater than 1900)
    if (year <= 1900){
        return 0;
    }

    // Days in each month (no leap year consideration)
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Validate the day (must be within the valid range for the given month)
    if (day < 1 || day > days_in_month[month - 1]){
        return 0;
    }

    return 1; // Valid date
}



void addVehicleInDataBase()
{
    struct addVehicle newVehicle;
    //int validName = 0, validDate = 0;
    printf("ENTER VEHICLE DETAILS BELOW:\n");


    printf("Vehicle ID NO = ");
    scanf("%s", newVehicle.vehicleID);
    for(;;)
    {
        printf("Vehicle Name = ");
        scanf("%s", newVehicle.vehicleName);
        if(is_Name_Valid(newVehicle.vehicleName))
        {
            break;
        }
    }

    for(;;)
    {
        printf("Vehicle Manufacturer Name = ");
        scanf("%s", newVehicle.manufacturerName);
        if(is_Name_Valid(newVehicle.manufacturerName))
        {
            break;
        }
    }

    for(;;)
    {
        printf("Vehicle issued date by Manufacturer (day/month/year) : ");
        scanf("%s", newVehicle.issuedDate);
        if(is_Valid_Date(newVehicle.issuedDate))
        {
            break;
        }
    }

}

void searchVehicle(struct addVehicle *newVehicle)
{
    int vehicleCount;
    char searchName[50];
    int found = 0, i;
    printf("Enter the name of the vehicle to search: ");
    scanf("%s", searchName);

    for(i = 0; i < vehicleCount; i++)
    {
        struct addVehicle *currentVehicle = newVehicle + i;
        if(strcmp(currentVehicle[i].vehicleName, searchName) == 0)
        {
            printf("Vehicle ID = %s\n", currentVehicle[i].vehicleID);
            printf("Vehicle Name = %s\n", currentVehicle[i].vehicleName);
            printf("Vehicle Manufacturer Name = %s\n", currentVehicle[i].manufacturerName);
            printf("Vehicle issued date by Manufacturer (day/month/year) : %s\n", currentVehicle[i].issuedDate);
            found = 1;
            break;
        }
    if(found == 0)
        {
        printf("No Record Found.\n");
    }
    }
}

void viewVehicles(struct addVehicle *newVehicle)
{
    int vehicleCount, i, found = 0;
    if(vehicleCount == 0)
    {
        printf("No record.\n");
    }
    printf("All Stored Vehicle Details:\n");


        for(i = 0; i < vehicleCount; i++)
        {
            struct addVehicle *currentVehicle = newVehicle + i;
            printf("Vehicle Count = %d\n", i+1);

            printf("Vehicle ID = %s\n", currentVehicle[i].vehicleID);
            printf("Vehicle Name = %s\n", currentVehicle[i].vehicleName);
            printf("Vehicle Manufacturer Name = %s\n", currentVehicle[i].manufacturerName);
            printf("Vehicle issued date by Manufacturer (day/month/year) : %s\n", currentVehicle[i].issuedDate);
            found = 1;
            break;
        }
}

void deleteVehicle(struct addVehicle *currentVehicle)
{
    print_Message_in_Center("Delete Vehicle Details");


    char vehicleID[10];
    int i, vehicle_count;
    printf("Enter Vehicle ID to delete: ");
    scanf("%s", vehicleID);

    int found = 0;
    for (i = 0; i < vehicle_count; i++) {
        if (strcmp(currentVehicle[i].vehicleID, vehicleID) == 0) {
            // Shift all elements after the deleted one
            for (int j = i; j < vehicle_count - 1; j++) {
                currentVehicle[j] = currentVehicle[j + 1];
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

void updatePassword() {
    printf("Updating password...\n");
}

int main() {
    char title[40] = "Something";

    headMessage_andCenter(title);
    welcome_Message();
    //login();
    menu();

    return 0;
}

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
    printf("         <~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>         \n\n\n\n\n\n");

    printf("Enter any key to continue. . . . .\n\n\n\n\n");
}

void headMessage_andCenter(char title[40]) {
    head_Message();
    print_Message_in_Center(title);

}

void head_Message() {
    printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
    printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
    printf("<~><~><~><~>                                                   <~><~><~><~>\n");
    printf("<~><~><~><~>             Vehicle Management System             <~><~><~><~>\n");
    printf("<~><~><~><~>                                                   <~><~><~><~>\n");
    printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
    printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n\n\n");
}

void print_Message_in_Center(char title[40]) {
    int length = strlen(title);
    int spacing = 48 - length;

    printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
    printf("                                                                           \n");


    for (int i = 0; i < spacing; i++) {
        printf(" ");
    }

    printf("%s\n", title);
    printf("                                                                           \n");
    printf("<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n\n\n");
}

void menu()
{
    int choice, vehicleCount;
    char searchName, vehicleID;

    for(;;)
    {
        //print_Message_in_Center();
        head_Message();
        printf("1. Add Vehicle\n");
        printf("2. Search Vehicle\n");
        printf("3. View Vehicles\n");
        printf("4. Delete Vehicle\n");
        printf("5. Update Password\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            addVehicleInDataBase();
            break;
        case 2:
            searchVehicle(searchName);
            break;
        case 3:
            viewVehicles(vehicleCount);
            break;
        case 4:
            deleteVehicle(vehicleID);
            break;
        case 5:
            updatePassword();
            break;
        case 6:
            exit(0);

        }
    }
}

/*void updateCredential(){

    char userName[40];
    printf("New Username: ");
    gets(userName);

    char userPassword[40];
    printf("New Password: ");
    gets(userPassword);

    printf("Your password has been changed successfully.");

}


void login(){

    char storedUsername[40], storedPassword[40];


    char userPassword[40];
    char userName[40];

    printf("Enter Username: ");
    gets(storedUsername);
    printf("Enter Password: ");
    gets(storedPassword);


    updateCredential(storedUsername, storedPassword);


    if (strcmp(userName, storedUsername) == 0 && strcmp(userPassword, storedPassword) == 0) {
        printf("Login successful.\n");
    }
}*/
