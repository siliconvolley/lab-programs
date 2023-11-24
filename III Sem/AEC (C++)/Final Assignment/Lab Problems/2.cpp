#include<bits/stdc++.h>
using namespace std;

int main(){
    int testcases;
    cout<<"Enter number of Test Cases: ";
    cin>>testcases;							//Entering the number of Test Cases
    while(testcases--){
        int m, h, ans;
        cout<<"Enter the mass and height: ";
        cin>>m>>h;
        ans = m/(h*h);                      //Calculating the Body-Mass Index
        if(ans <= 18)
            cout<<1<<endl;
        else if(ans >= 19 && ans <= 24)     //Categorising the BMI
            cout<<2<<endl;
        else if(ans >= 25 && ans <= 29)
            cout<<3<<endl;
        else
            cout<<4<<endl;
    }
}