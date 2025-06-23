#ifndef UNTITLED31_ARRAY_H
#define UNTITLED31_ARRAY_H
#define SIZE 10

void enterNumbers(int *numbers);
void displayNumbers(int numbers[]);
void calculateAverage (int *numbers);
void findMaximum (int *numbers);
void findMinimum (int *numbers);
int restoreFromFile(int numbers[]);
void menu();
int saveToFile(int numbers[]);

#endif //UNTITLED31_ARRAY_H