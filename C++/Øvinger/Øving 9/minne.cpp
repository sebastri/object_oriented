#include "minne.h"


void fillInFibonacciNumbers(int result[], int length){
    if (length == 1){
        result[0] = 0;
    }
    else if (length == 0){
        
    }
    else if (length > 1)
    {
        result[0] = 0;
        result[1] = 1;
        for ( int i = 2; i < length; i++)
        {
        result[i] = result[i-1] + result[i-2];
        }    
    }
   
}

void printArray(int arr[], int length){
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
}

void createFibonacci(){
    int n = 0;
    cout << "Hvor mange tall skal genereres?" << endl;
    cin >> n;

    int *numbers = new int[n];
    for (int i = 0; i < n; i++)
    {
        fillInFibonacciNumbers(numbers, n);
    }
    printArray(numbers, n);
    delete[] numbers;
    numbers = nullptr;
    
}