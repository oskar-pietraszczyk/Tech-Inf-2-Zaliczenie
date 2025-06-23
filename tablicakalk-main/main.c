#include <stdio.h>
#include "array.h"
#define SIZE 10

int main() {
    int numbers[10]={1,2,3,4,5,6,9,8,3,2};
    int errorCode=0;
    int option;

    while(1){
        menu();
        scanf("%d", &option);
        if(option == 0){
            break;
        }


        switch (option) {
            case 0:
                break;
            case 1:
                enterNumbers(numbers);
                break;
            case 2:
                displayNumbers(numbers);
                break;
            case 3:
                findMaximum(numbers);
                break;
            case 4:
                findMinimum(numbers);
                break;
            case 5:
                calculateAverage(numbers);
                break;
            case 6:
                errorCode = saveToFile(numbers);
                if (errorCode == 0){
                    printf("Numbers saved\n");
                }
                else{
                    printf("Numbers are not saved\n");
                }
                break;
            case 7:
                errorCode = restoreFromFile(numbers);
                if (errorCode == 0)
                {
                    printf("Numbers resaved\n");
                }
                else
                {
                    printf("Numbers are not resaved\n");
                }
                break;
            default:
                printf("Choose correct option\n");
                break;
        }
    }
    return 0;
}








//Litwo! Ojczyzno moja! ty jesteś jak zdrowie.

//Kto cię stracił. Dziś piękność twą w całej ozdobie

//idzę i opisuję, bo tęsknię po tobie.