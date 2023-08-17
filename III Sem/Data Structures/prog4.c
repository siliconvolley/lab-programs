#include<stdio.h>
//Grouping of given Numbers

void main(){
    int max, j, list[18] = {3, 22, 12, 6, 10, 34, 65, 29, 9, 30, 81, 4, 5, 19, 20, 57, 44, 89};

    for(int i=1; i<18; i++){
        max = list[i];
        j = i - 1;       
        while(j>0 && list[j]>max){          
            list[j+1] = list[j];
            j--;
        }
        list[j+1] = max;
    }
    
    printf("Group 1: \n");
    for(int j=0; j<18; j++){
        if(list[j] > 0 && list[j] < 10)
            printf("%d ", list[j]);
    }
        
    printf("\n\nGroup 2: \n");
    for(int j=0; j<18; j++){
        if(list[j] >= 10 && list[j] <= 19)
            printf("%d ", list[j]);
    }

    printf("\n\nGroup 3: \n");
    for(int j=0; j<18; j++){
        if(list[j] >= 20 && list[j] <= 29)
            printf("%d ", list[j]);
    }

    printf("\n\nGroup 4: \n");
    for(int j=0; j<18; j++){
        if(list[j] >= 30)
            printf("%d ", list[j]);
    }
}

