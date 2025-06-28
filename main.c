C, file-handling, healthcare, blood-bank, CLI, offline-app, beginner, ATS-friendly, resume-project
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addDonor() {
    FILE *fp = fopen(FILE_NAME, "a");
    if (!fp) {
        printf(" Unable to open file.\n");
        return;
    }

    char name[50], bloodGroup[5], date[15];
    getchar();  // Clear newline from buffer

    printf("Enter donor name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove newline

    printf("Enter blood group (e.g., A+, O-):/n ");
    scanf("%s", bloodGroup);

    printf("Enter last donation date (YYYY-MM-DD):\n ");
    scanf("%s", date);

    fprintf(fp, "%s %s %s\n", name, bloodGroup, date);
    fclose(fp);
    printf(" Donor added successfully.\n");
}

void listDonors() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) {
        printf(" No donor records found.\n");
        return;
    }

    char name[50], bloodGroup[5], date[15];
    printf(" All Donors:\n");
    while (fscanf(fp, "%s %s %s", name, bloodGroup, date) != EOF) {
        printf("👤 Name: %s |  Blood Group: %s |  Last Donation: %s\n", name, bloodGroup, date);
    }
    fclose(fp);
}

void searchDonorsByGroup() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) {
        printf(" No donor records found.\n");
        return;
    }

    char searchGroup[5];
    printf("Enter blood group to search:\n ");
    scanf("%s", searchGroup);

    char name[50], bloodGroup[5], date[15];
    int found = 0;
    printf(" Donors with blood group %s:\n", searchGroup);
    while (fscanf(fp, "%s %s %s", name, bloodGroup, date) != EOF) {
        if (strcmp(bloodGroup, searchGroup) == 0) {
            printf(" Name: %s | Last Donation: %s\n", name, date);
            found = 1;
        }
    }

    if (!found) {
        printf(" No donors found with blood group %s.\n", searchGroup);
    }

    fclose(fp);
}

int main() {
    int choice;
    while (1) {
        printf(" Blood Bank Inventory Manager\n");
        printf("1. Add Donor\n");
        printf("2. View All Donors\n");
        printf("3. Search by Blood Group\n");
        printf("0. Exit\n");
        printf("Choose an option:\n ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addDonor(); 
              break;
            case 2: listDonors(); 
              break;
            case 3: searchDonorsByGroup();
              break;
            case 0: printf(" Exiting.\n");
              return 0;
            default:
              printf(" Invalid choice.\n");
        }
    }
}
