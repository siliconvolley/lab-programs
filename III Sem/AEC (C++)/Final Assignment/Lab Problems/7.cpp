#include<bits/stdc++.h>
using namespace std;

int main(){
    int testcases;
    cout<<"Enter number of Test Cases: ";
    cin>>testcases;                         //Entering the number of Test Cases
    while(testcases--){
        int n, min;
        cin>>n;                             //Entering the number of Horses in the Stable
        int s[n];
        for(int i=0; i<n; i++){
            cin>>s[i];                      //Entering the skills of each horse
        }
        sort(s, s + n, greater<int>());     //Sorting the array in decending order
        min = s[0] - s[1];
        for(int i=1; i<(n-1); i++){
            if((s[i]-s[i+1]) < min)       //Calculating the minimum difference between each of the skills (array numbers)
                min = s[i]-s[i+1];
        }
        cout<<min<<endl;
    }
}