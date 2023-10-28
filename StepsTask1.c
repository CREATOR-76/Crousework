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
char stepsStr[10];
char result[1024][30];//Set up a array to hold the data.
int x=0;
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

    if (file == NULL) {
        printf("Can't open the file.\n");
        return 1;
    }//To face the situation that can't find the file.

    if (fgets(line, sizeof(line), file)) {
        snprintf(stepsStr, sizeof(stepsStr), "%d", data.steps);//Turn the steps in fit
        do {
            tokeniseRecord(line, ",", data.date, data.time, stepsStr);
            snprintf((char *) &result[x], sizeof(result[x]), "%s/%s/%s\n",data.date, data.time, stepsStr);//Put the result into the result[],and use it in the future step.
            x++;//Read the next
        }while(fgets(line, sizeof(line), file));

        for (int i = 0; i < 3; i++) {                     //Output the first three data.
            printf("%s",result[i]);
        }
    }

    fclose(file);
    return 0;
}


