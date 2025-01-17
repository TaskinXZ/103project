//This is Orlean

#include <stdio.h>
#include <string.h>

void head_Message();
void print_Message_in_Center(char title[40]);
void welcome_Message();

void menu();
void addVehicleInDataBase();
void viewVehicles();
void searchVehicle();
void deleteVehicle();

void headMessage_andCenter(char title[40]);

void updateCredential();


int is_Name_Valid(char *name)
int is_Valid_Date

//void login();

struct vehicle_info {
    char vehicle_name[40];
    char manufacturer_name[40];
    char date[11];
};


int main() {
    char title[40] = "Something";

    headMessage_andCenter(title);
    welcome_Message();
    //login();
    menu();

    return 0;
}

void headMessage_andCenter(char title[40]) {
    head_Message();
    print_Message_in_Center(title);

}

void print_Message_in_Center(char title[40]) {
    int length = strlen(title);
    int spacing = 42 - length;

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
    int choice;
    char searchName;

    for(; ;)
    {
        //print_Message_in_Center();
        head_Message();
        printf("1. Add Vehicle\n");
        printf("2. Search Vehicle\n");
        printf("3. View Vehicles\n");
        printf("4. Delete Vehicle\n");
        printf("5. Update Password\n");
        printf("6. Exit\n\n\n");
        printf("Enter choice: ");
        do {
            choice = getchar();
        } while(ch>1 || ch>6);

        switch(choice)
        {
        case 1:
            addVehicleInDataBase();
            break;
        case 2:
            searchVehicle(searchName);
            break;
        case 3:
            viewVehicles();
            break;
        case 4:
            deleteVehicle();
            break;
        case 5:
            updatePassword();
            break;
        case 6:
            exit(0);

        }
    }
}

int is_Name_Valid(char *name)
{

}

int is_Valid_Date(char *date)
{

}


void addVehicleInDataBase()
{

    printf("\nENTER VEHICLE DETAILS BELOW:\n");
    printf("------------------------------------------------------------------------------------");


    printf("Vehicle ID NO = ");
    int vehicle_id_no;
    scanf("%d", vehicle_id_no);

    for(;;)
    {
        printf("Vehicle Name = ");
        scanf("%s", vehicle_id_no.vehicle_name);
        if(is_Name_Valid(vehicle_id_no.vehicle_name))
            break;
    }

    // for(;;)
    // {
    //     printf("Vehicle Manufacturer Name = ");
    //     scanf("%s", newVehicle.manufacturerName);
    //     if(is_Name_Valid(newVehicle.manufacturerName))
    //         break;
    // }

    // for(;;)
    // {
    //     printf("Vehicle issued date by Manufacturer (day/month/year): ");
    //     scanf("%s", newVehicle.issuedDate);
    //     if(is_Valid_Date(newVehicle.issuedDate))
    //         break;
    // }

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

void deleteVehicle() {
    printf("Deleting a vehicle...\n");
}

void updatePassword() {
    printf("Updating password...\n");
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
    int spacing = 42 - length;

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
    char searchName;

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
            deleteVehicle();
            break;
        case 5:
            updatePassword();
            break;
        case 6:
            exit(1);

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
