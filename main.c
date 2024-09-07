#include<stdio.h>
#include<stdlib.h>
#include<string.h>  // Include this for using strcspn()


// Structer Defining  Section 
typedef struct ContactVriable
{
    char name[50];
    char number[50];
    char email[50];
} cv;


// Function Declaration Section 
void addContacts();
void displayContacts();
void resetContacts();



// Main Function Section 
int main(int argc, char const *argv[])
{
    int choice;
    int error = 0;

    while (1)
    {
        printf("\n");
        printf("-------------------------------\n");
        printf("###############################\n");
        printf("Add Contact (1)\n");
        printf("Show Contact (2)\n");
        printf("Delete All Contact (3)\n");
        printf("Exit Contact Manager (4)\n");
        printf("###############################\n");
        printf("-------------------------------\n");
        printf("\n");

        printf("Enter you choice: ");
        scanf("%d", &choice);
        printf("\n");

        if (choice == 1)
        {
            addContacts();
        }else if (choice == 2)
        {
            displayContacts();
        }else if (choice == 3)
        {
            resetContacts();
        }else if (choice == 4)
        {
            printf("Exiting...");
            break;
        }else
        {
            printf("Invalid Input. Please try again!");

            error += 1;
            if (error == 5)
            {
                break;
            }

        }
    }

    return 0;
}


// Function Defining  Section 

void addContacts(){
    // declier structer varibale
    cv contact;

    // Input user details 
    fflush(stdin);
    printf("Enter you name: ");
    fgets(contact.name, sizeof(contact.name), stdin);

    printf("Enter you Number: ");
    fgets(contact.number, sizeof(contact.number), stdin);

    printf("Enter you Email: ");
    fgets(contact.email, sizeof(contact.email), stdin);

    // User Input append the file 
    FILE *file;
    file = fopen("contact.txt", "a");
    if(file == NULL){
        printf("Error opening file!\n");
    }
    else{
        fprintf(file,"%s", contact.name);
        fprintf(file,"%s", contact.number);
        fprintf(file,"%s", contact.email);
        fprintf(file,"\n");

        fclose(file);
    }
    printf("\nSuccessfully added you information\n");
}

void displayContacts() {
    // Declare structure variable
    cv contact;

    // Open the file in read mode
    FILE *file;
    file = fopen("contact.txt", "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Read contacts from the file
    while (fgets(contact.name, sizeof(contact.name), file) != NULL) {
        // Remove newline character from the name (if any)
        contact.name[strcspn(contact.name, "\n")] = '\0';

        // Skip empty lines
        if (strlen(contact.name) == 0) {
            continue;
        }

        // Read the number
        if (fgets(contact.number, sizeof(contact.number), file) != NULL) {
            contact.number[strcspn(contact.number, "\n")] = '\0';
        }

        // Read the email
        if (fgets(contact.email, sizeof(contact.email), file) != NULL) {
            contact.email[strcspn(contact.email, "\n")] = '\0';
        }

        // Print the contact information
        printf("Name: %s\n", contact.name);
        printf("Number: %s\n", contact.number);
        printf("Email: %s\n\n", contact.email);
    }

    // Close the file
    fclose(file);
}

void resetContacts(){
    // Open the file in write mode Cz Write mode remove all Existing text
    FILE *file;
    file = fopen("contact.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
        }
    // Close the file
    fclose(file);
    printf("Successfully Remove All Contacts");
}