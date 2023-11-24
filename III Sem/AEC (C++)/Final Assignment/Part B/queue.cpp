#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main(){
    queue <string> city;
    city.push("Delhi");
    city.push("Bengaluru");
    city.push("Bhopal");

    cout<<"Queue: ";
    while(!city.empty()){
        cout<<city.front()<<", ";
        city.pop();
    }
}