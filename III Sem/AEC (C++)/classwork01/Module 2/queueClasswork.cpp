#include<bits/stdc++.h>
using namespace std;

//store 5 ice creams in queue
int main(){
    queue <string> iceCream;
    int n;
    cout<<"Enter 5 Ice-Creams: "<<endl;
    for(int i=0; i<5; i++){
        string iceCreams;
        cin>>iceCreams;
        iceCream.push(iceCreams);
    }
    cout<<"Ice-Creams in the Stack: "<<endl;
    while(!iceCream.empty()){
        cout<<iceCream.front()<<" ";
        iceCream.pop();
    }
}