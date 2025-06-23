#include <stdio.h>
#define SIZE 10
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
            sum += *(numbers+i);
        }
        average = sum/SIZE;
        printf("\nAverage: %.2f", average);

    }
int main() {
        int numbers[10]={1,2,3,4,5,6,9,8,3,2};

        enterNumbers(numbers);
        displayNumbers(numbers);
        calculateAverage(numbers);

        return 0;
    }

