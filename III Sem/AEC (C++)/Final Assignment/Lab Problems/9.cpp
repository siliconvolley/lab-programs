#include <bits/stdc++.h>
using namespace std;

int main(){
    int testcases, j;
    cout<<"Enter number of Test Cases: ";
    cin>>testcases;                         //Entering the number of Test Cases
    while(testcases--){
        int n;
        cin>>n;                             //Entering the number of students in the class
        int a[n];
        for(int i=0 ; i<n ;i++)
            cin >> a[i];                    //Entering the marks of each student
        int lower, higher;  
        int flag=0;
        for(int i=0 ; i<n ;i++){            //Outer Loop to give the number of students boasting
            lower=0;
            higher=0; 
            for( j=0 ; j<n ;j++)            //Inner Loop to iterate among each student
            {
                if(a[j] > a[i])
                    higher++;               //Counting the number of students with lower marks
                if(a[j] <= a[i])
                    lower++;                //Counting the number of students with higher marks
            }
            if(lower>higher)
                flag++;
        }
        cout << flag <<endl;
    }
    return 0;
}
