#include<bits/stdc++.h>
using namespace std;

int main(){
    int testcases;
    cout<<"Enter number of Test Cases: ";
    cin>>testcases;                         //Entering number of test cases
    while(testcases--){
        int n, m, k;
        cin>>n>>m>>k;                    //Entering number of friends, maximum capacity in the course & enrolled students
        if((n+k) <= m)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}