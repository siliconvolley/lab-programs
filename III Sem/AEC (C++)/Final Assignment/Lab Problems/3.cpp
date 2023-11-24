#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of Integers: ";
    cin>>n;                                 //Entering the number of Integers
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];                          //Entering the Integers into an Array
    }
    while(n--)
        cout<<a[n]<<" ";                    //Printing the Integers in the reverse order
    cout<<endl;
}