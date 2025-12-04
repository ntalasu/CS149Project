#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get a filename from the user
void getFilename(char *filename, int size) {
    printf("Enter filename: ");
    fgets(filename, size, stdin);
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') {
        filename[len - 1] = '\0';
    }
}

// Function to create a file
void createFile(char* filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return;
    }
    printf("File '%s' created successfully.\n", filename);
    fclose(fp);
}

// Function to write to a file
void writeToFile(char* filename, char* content) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    fprintf(fp, "%s", content);
    printf("Content written to '%s'.\n", filename);
    fclose(fp);
}

// Function to read a file
void readFromFile(char* filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }
    int ch;
    printf("Contents of '%s':\n", filename);
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    printf("\n");
    fclose(fp);
}

// Search for a file
void searchFile(char* filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File '%s' not found.\n", filename);
        return;
    }
    printf("File '%s' exists!\n", filename);
    fclose(fp);
}

// Close a file pointer safely
void closeFile(FILE *fp) {
    if (fp == NULL) {
        printf("No file is currently open.\n");
        return;
    }
    if (fclose(fp) == 0) {
        printf("File closed successfully.\n");
    } else {
        printf("Error closing file!\n");
    }
}

int main(void) {
    int choice;
    char filename[256];
    char content[512];

    FILE *openFile = NULL;   // Track currently open file
    char openFilename[256];  // Track name of opened file

    while (1) {
        printf("\n--- File Operations Menu ---\n");
        printf("1. Create file\n");
        printf("2. Write to file\n");
        printf("3. Read from file\n");
        printf("4. Search file\n");
        printf("5. Open file \n");
        printf("6. Close open file\n");
        printf("7. Exit\n");
        printf("Choose an option (1-7): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n'); // clear wrong input
            continue;
        }
        getchar(); 

        switch (choice) {

            case 1: // Create
                getFilename(filename, sizeof(filename));
                createFile(filename);
                break;

            case 2: // Write
                getFilename(filename, sizeof(filename));
                printf("Enter content to write: ");
                fgets(content, sizeof(content), stdin);
                writeToFile(filename, content);
                break;

            case 3: // Read
                getFilename(filename, sizeof(filename));
                readFromFile(filename);
                break;

            case 4: // Search
                getFilename(filename, sizeof(filename));
                searchFile(filename);
                break;

            case 5: // Open file 
                if (openFile != NULL) {
                    printf("A file is already open. Close it first.\n");
                    break;
                }
                getFilename(filename, sizeof(filename));
                openFile = fopen(filename, "r");
                if (openFile == NULL) {
                    printf("Error opening file!\n");
                } else {
                    strcpy(openFilename, filename);
                    printf("File '%s' opened successfully.\n", filename);
                }
                break;

            case 6: // Close
                closeFile(openFile);
                openFile = NULL;
                break;

            case 7: // Exit
                if (openFile != NULL) fclose(openFile);
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid option!\n");
        }
    }
}

