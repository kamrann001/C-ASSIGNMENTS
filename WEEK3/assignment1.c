#include <stdio.h>
void swapArrays(int a1[], int a2[], int len);
void print2DArr(int *arr2D[],int rows, int columns);

int main()
{
    int a1[] = {1,2,3,4,5};
    int a2[] = {0,0,0,0,0};
    int len = sizeof(a1)/sizeof(int);
    int *arr2D[2] = {a1,a2};


    print2DArr(arr2D, 2, len);
    swapArrays(a1, a2, len);
    print2DArr(arr2D, 2, len);
}
void swapArrays(int a1[], int a2[], int len){
    for(int i = 0; i < len; i++){		//we use for loop to change elements of 2 arrays one by one 
        int a = a1[i];						
        a1[i] = a2[i];
        a2[i] = a;
    }   
};
void print2DArr(int *arr2D[], int rows, int columns) {
    for (int i = 0; i < rows; i++){ 		//we use nested for loop to print all the elements of 2D array
        for(int j = 0; j < columns; j++){	//in a flattened shape
            printf("%d", arr2D[i][j]);
            if((i+1)*(j+1) != rows*columns) printf(" "); //here we tell the program to put \n at the end instead of empty space
        else printf("\n");  
        }
    }   
}; 
