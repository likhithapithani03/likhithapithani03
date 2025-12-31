#include <stdio.h>

int main() {
    FILE *fp;
    char text[100];

    // Write to file
    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(fp, "Hello, this is a test.\n");
    fclose(fp);

    // Read from file
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    printf("\nReading from file:\n");
    while (fscanf(fp, "%s", text) != EOF) {
        printf("%s ", text);
    }
    fclose(fp);

    // Append to file
    fp = fopen("data.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(fp, "\nAppended line of text.");
    fclose(fp);

    printf("\n\nData appended successfully!\n");

    return 0;
}
