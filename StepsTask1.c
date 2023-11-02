#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here
char line[1024];
FITNESS_DATA data[1024];
char** result_date;
char** result_time;
int* result_steps;
int x = 0;
char Char_steps[100];
// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }

    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {
    FILE* file = fopen("./FitnessData_2023.csv", "r"); // Open the csv file to read.
    if (file == NULL) {
        printf("Can't open the file.\n");
        return 1;
    }

    result_date = (char**)malloc(1024 * sizeof(char*));
    result_time = (char**)malloc(1024 * sizeof(char*));
    result_steps = (int*)malloc(1024 * sizeof(int));

    if (result_date == NULL || result_time == NULL || result_steps == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < 1024; i++) {
        result_date[i] = (char*)malloc(30 * sizeof(char));
        result_time[i] = (char*)malloc(30 * sizeof(char));
    }

    if (fgets(line, sizeof(line), file)) {
        do {
            tokeniseRecord(line, ",", data[x].date, data[x].time, Char_steps); //Read the data, and value the three data.
            result_steps[x] = atoi(Char_steps); // Store each data into different lists.
            strcpy(result_date[x], data[x].date);
            strcpy(result_time[x], data[x].time);
            x++; // Read the next
        } while (fgets(line, sizeof(line), file));
    }

    fclose(file);

    for (int i = 0; i < 3; i++) { // Output the first three data.
        printf("%s/%s/%d\n", result_date[i], result_time[i], result_steps[i]);
    }
    
    for (int i = 0; i < 1024; i++) {
        free(result_date[i]);
        free(result_time[i]);
    }
    free(result_date);
    free(result_time);
    free(result_steps);

    return 0;
}