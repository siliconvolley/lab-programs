#include<bits/stdc++.h>
using namespace std;

//Store 5 fruits in a Stack
int main(){
    stack <string> fruits;
    cout<<"Enter 5 Fruits: "<<endl;
    for(int i=0; i<5; i++){
        string f;
        cin>>f;
        fruits.push(f);
    }

    cout<<endl<<"5 Fruits in the Stack are: "<<endl;
    while(!fruits.empty()){
        cout<<fruits.top()<<endl;
        fruits.pop();
    }
}