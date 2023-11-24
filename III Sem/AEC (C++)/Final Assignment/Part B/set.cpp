#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set <string> brands;
    brands.insert("Asus");
    brands.insert({"Dell, HP, Alienware"});
    
    cout<<"Laptop Brands are: ";

    for(const auto &i : brands){
        cout<<i<<", ";
    }
}