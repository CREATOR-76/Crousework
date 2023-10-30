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
FITNESS_DATA data;
char result_date[1024][30];//Set up an array to hold the data.
char result_time[1024][30];
int result_steps[1024];
int x=0;
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
        FILE *file = fopen("./FitnessData_2023.csv", "r"); // Open the csv file to read.

        if (fgets(line, sizeof(line), file)) {
            do {
                snprintf(Char_steps, sizeof(Char_steps), "%d", data.steps); // Exchange the steps from int to char.

                tokeniseRecord(line, ",", data.date, data.time, Char_steps); //Read the data, and value the three data.

                int Int_steps = atoi(Char_steps); // Store each data into different lists.
                result_steps[x] = Int_steps;
                strcpy(result_date[x], data.date);
                strcpy(result_time[x], data.time);

                x++; // Read the next
            } while (fgets(line, sizeof(line), file));
        }

        for (int i = 0; i < 3; i++) { // Output the first three data.
            printf("%s/%s/%d\n", result_date[i], result_time[i], result_steps[i]);
        }

        fclose(file);
        return 0;
}