#include <stdio.h>
#include "array.h"

void enterNumbers(int *numbers){
    for(int i = 0; i < SIZE; i++){
        printf("numbers[%d] = ", i);
        scanf("%d", numbers+i);
    }
}
void displayNumbers(int numbers[]) {
    int *ptr=NULL;
    ptr=numbers;
    for (int i = 0; i < SIZE; i++) {
        printf("numbers[%d]=%d\n", i, *(numbers +i));
    }
}

void calculateAverage (int *numbers) {
    float sum = 0.0;
    float average;
    for (int i = 0; i < SIZE; i++) {
        sum += *(numbers + i);
    }
    average = sum / SIZE;
    printf("\nAverage: %.2f", average);
}

void findMaximum (int *numbers){
    float max = *numbers;
    for( int i =1; i<SIZE; i++){
        if(*(numbers+i)> max){
            max = *(numbers + i);
        }
    }
    printf("Maximum: %.2f\n\n", max);
}

void findMinimum (int *numbers){
    float min = *numbers;
    for( int i =1; i<SIZE; i++){
        if(*(numbers+i)< min){
            min = *(numbers + i);
        }
    }
    printf("Minimum: %.2f\n\n", min);
}
void menu(){
    printf("0 - Exit\n");
    printf("1 - Enter numbers\n");
    printf("2 - Display numbers\n");
    printf("3 - Find maximum\n");
    printf("4 - Find minimum\n");
    printf("5 - Calculate average\n");
    printf("6 - Save to file\n");
    printf("7 - Restore from file\n");
}


int saveToFile(int numbers[]){
    FILE * fptr = NULL;
    fptr = fopen("../array.txt", "w");
    if (fptr ==  NULL) {
        return 1;
    }
    else {
        for (int i = 0; i < SIZE; i++) {
            fprintf(fptr, "%d\n", numbers[i]);
        }

        fclose(fptr);
        return (0);
    }
}

int restoreFromFile(int numbers[])
{
    FILE *fptr =NULL;
    fptr = fopen("../array.txt","r");
    if(fptr == 0)
    {
        fclose(fptr);
        return 1;
    }
    {
        for(int i=0; i<SIZE; i++)
        {
            if(fscanf(fptr,"%d",&numbers[i]) !=1)
            {
                fclose(fptr);
                return 2;
                }
            }
        fclose(fptr);
        return 0;
    }
}