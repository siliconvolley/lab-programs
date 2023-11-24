#include<bits/stdc++.h>
#include<stack>
using namespace std;

int main(){
    stack <string> icecream;
    icecream.push("Vanilla");
    icecream.push("Chocolate");

    cout<<"Stack is: ";
    while(!icecream.empty()){
        cout<<icecream.top()<<", ";
        icecream.pop();
    }
}