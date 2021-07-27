/*
20DCS010
Siddharth Chaudhary
22-07-2021

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// defining the maximum possible size
// We can adjust this according to N  and also increase it if collision occurs
#define MAXSIZE 1000
// Maximum size of Each App name is taken as 20 as well as the type
#define MAXWORDLENGTH 20

// I am targeting the memory as the key point to determine if the app with the given name exist or not
// A key with memory 0 tells that app at that index does not exists

// defining struct of each app
struct app
{
    char *name;
    char *type;
    int memory;
};
// this function generates the hashkey according to ascii value of characters and there positions
int app_hash_key(char *appName)
{
    int sum = 0;
    for (int i = 0; i < strlen(appName); i++)
    {
        sum += appName[i] * (i + 1); // character ascii *(position)
    }
    return sum % MAXSIZE; // converging index to max size
}
// Menu function to display menu and take input and work accordingly
int menu()
{
    int choice;
    printf("\n\n Enter \n");
    printf("1. For adding a record of an app\n");
    printf("2. For searching an app on app store\n");
    printf("3. For display details of the app found in step 2\n");
    printf("4. Delete an app \n");
    printf("5. Display the details of all the apps present\n");
    printf("6. QUIT\n");
    scanf("%d", &choice);
    return choice;
}
// Function to add a new app in the list
void AddApp(struct app *app_table)
{
    char app_name[MAXWORDLENGTH], app_type[MAXWORDLENGTH];
    // taking input the name of the app
    printf("Enter the name of the app ");
    scanf("%s", app_name);

    int key = app_hash_key(app_name); // calling the function to generate hashkey acccording to name
    app_table[key].name = (char *)malloc(sizeof(char) * strlen(app_name));
    strcpy(app_table[key].name, app_name);

    // Taking input other details

    printf("Enter the type of the app ");
    scanf("%s", app_type);

    app_table[key].type = (char *)malloc(sizeof(char) * strlen(app_type));
    strcpy(app_table[key].type, app_type);

    printf("Enter the size of the app ");
    scanf("%d", &app_table[key].memory);
}
// function to search according to given name
int SearchApp(struct app *app_table)
{
    // taking app name as input
    char app_name[MAXWORDLENGTH];
    printf("Enter the app name ");
    scanf("%s", app_name);
    int key = app_hash_key(app_name);
    if (app_table[key].memory == 0)
    {
        printf("Sorry, we cannot find any results matching ");
        return -1;
    }
    else
    {
        printf("Search Found"); // if found then returning its key
        return key;
    }
}
// Print the searched Word
void printSearch(struct app *app_table, int key)
{

    printf("\nName: %s\n", app_table[key].name);
    printf("Type: %s\n", app_table[key].type);
    printf("Memory: %d\n", app_table[key].memory);
}
// Function to delete the app
void deleteApp(struct app *app_table)
{
    char app_name[MAXWORDLENGTH];

    printf("Enter the name of the app to be deleted ");
    scanf("%s", app_name);
    int key = app_hash_key(app_name);
    if (app_table[key].memory == 0)
    {
        printf("Sorry this app does not exists");
    }
    else
    {
        // if found then we are making its memory 0,name as null and type also as null
        printf("%s deleted ", app_table[key].name);
        strcpy(app_table[key].name, "\0");
        strcpy(app_table[key].type, "\0");
        app_table[key].memory = 0;
    }
}
// function to display details of all the apps present
void display(struct app *app_table)
{
    for (int i = 0; i < MAXSIZE; i++)
    {
        if (app_table[i].memory != 0)
        {
            printf("Name : %s\nType: %s\nMemory : %d\n\n", app_table[i].name, app_table[i].type, app_table[i].memory);
        }
    }
}
// MAIN FUNCTION OR THE DRIVER FUNCTION
int main()
{
    struct app app_table[MAXSIZE];
    // initialising the memory of all apps as 0
    for (int i = 0; i < MAXSIZE; i++)
    {
        app_table[i].memory = 0;
    }

    int k = -1;

    while (1)
    {

        int choice = menu(); // printing the menu and getting choice by calling menu function
        switch (choice)
        { // switch case to perform the function according to given choice
        case 1:
            AddApp(app_table);
            break;
        case 2:
            k = SearchApp(app_table);
            break;
        case 3:
            if (k == -1)
                printf(" APP is not seached first search");
            else
                printSearch(app_table, k);
            break;
        case 4:
            deleteApp(app_table);
            break;
        case 5:
            display(app_table);
            break;
        case 6:
            exit(1);
            // any other value will print the menu again
        default:
            break;

        } // ending of switch case
    }     // ending of infinite while loop
} // Ending of the main function

/*
    Executing commands
    gcc 20DCS010.c -o 20DCS010
    .\20DCS010
    
*/