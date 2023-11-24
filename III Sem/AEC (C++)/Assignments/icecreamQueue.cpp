#include<bits/stdc++.h>
using namespace std;

//Store 5 Ice-Cream in a Queue
int main(){
    queue <string> iceCream;
    cout<<"Enter 5 Ice-Creams: "<<endl;
    for(int i=0; i<5; i++){
        string s;
        cin>>s;
        iceCream.push(s);
    }

    cout<<endl<<"5 Ice-Creams in the Stack are: "<<endl;
    while(!iceCream.empty()){
        cout<<iceCream.front()<<endl;
        iceCream.pop();
    }
}