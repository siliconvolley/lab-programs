#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    vector<int> numbers{10, 20, 30, 40, 50};
    cout<<"The Initial Vector is: ";
    for(const int &i : numbers){
        cout<<i<<" ";
    }

    numbers.push_back(60);
    numbers.push_back(70);

    cout<<endl<<"Updated Vector is: ";

    for(const int &i : numbers){
        cout<<i<<" ";
    }
}