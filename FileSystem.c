#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a file
void createFile(char* filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return;
    }
    printf("File %s created successfully.\n", filename);
    fclose(fp);
}

// Function to write to a file
void writeToFile(char* filename, char* content) {
    FILE *fp = fopen(filename, "a"); // Use 'a' for append mode
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    fprintf(fp, "%s", content);
    printf("Content written to %s.\n", filename);
    fclose(fp);
}

// Function to read from a file
void readFromFile(char* filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }
    int ch; 
    printf("Contents of %s:\n", filename);
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    if (ferror(fp)) {
        perror("Read error");
    }
    printf("\n");
    fclose(fp);
}

int main(void) {
    char filename[256];
    char content[512];
    int choice;
    
    printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin);
    
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') {
        filename[len - 1] = '\0';
    }
    
    while (1) {
        printf("\n--- File Operations Menu ---\n");
        printf("1. Create file\n");
        printf("2. Write to file\n");
        printf("3. Read from file\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        getchar(); 
        
        switch (choice) {
            case 1:
                createFile(filename);
                break;
            case 2:
                printf("Enter content to write: ");
                fgets(content, sizeof(content), stdin);
                writeToFile(filename, content);
                break;
            case 3:
                readFromFile(filename);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
