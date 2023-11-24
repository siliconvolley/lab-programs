#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;

int main(){
    vector<int> numbers {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};

    cout<<"Un-sorted Array: ";
    for(int x : numbers)
        cout<<x<<" ";
    cout<<endl<<endl;

    sort(numbers.begin(), numbers.end());

    cout<<"Sorted Array: ";
    for(int x : numbers)
        cout<<x<<" ";
    cout<<endl<<endl;

    list<int> List {78, 90, 56 ,8};
    for(int x : List)
        cout<<x<<" ";
    cout<<endl;

    sort(List, List.);
    // vector<int> numbers; //{6, 12, 18, 24, 30};
    // // cout<<"The numbers are: ";
    // // for(int x : numbers)
    // //     cout<<x<<" ";
    // // cout<<endl;
    
    // for(int i=0; i<5; i++){
    //     int add;
    //     cin>>add;
    //     numbers.push_back(add);
    // }
    // for(int x : numbers)
    //     cout<<x<<" ";
    // cout<<endl;

    // // int a[3] = {1, 2 ,3};
    // // for(int i=0; i<3; i++)    
    // //     cout<<*(a+i)<<" ";
    // // cout<<endl; 
}