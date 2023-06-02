#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100

// Define the structure for a record in the database
struct Record {
    int id;
    char name[50];
    int age;
};

// Function to add a record to the database
void addRecord(struct Record* database, int* recordCount) {
    if (*recordCount >= MAX_RECORDS) {
        printf("The database is full.\n");
        return;
    }

    struct Record newRecord;

    printf("Enter the ID: ");
    scanf(" %d", &newRecord.id);  // Add a space before %d
    printf("Enter the name: ");
    scanf(" %s", newRecord.name);  // Add a space before %s
    printf("Enter the age: ");
    scanf(" %d", &newRecord.age);  // Add a space before %d

    database[*recordCount] = newRecord;
    (*recordCount)++;

    printf("Record added successfully.\n");
}

// Function to display all records in the database
void displayRecords(struct Record* database, int recordCount) {
    if (recordCount == 0) {
        printf("The database is empty.\n");
        return;
    }

    printf("ID\tName\tAge\n");
    for (int i = 0; i < recordCount; i++) {
        printf("%d\t%s\t%d\n", database[i].id, database[i].name, database[i].age);
    }
}

int main() {
    struct Record database[MAX_RECORDS];
    int recordCount = 0;
    int choice;

    while (1) {
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);  // Add a space before %d

        switch (choice) {
            case 1:
                addRecord(database, &recordCount);
                break;
            case 2:
                displayRecords(database, recordCount);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        printf("\n");
    }

    return 0;
}

