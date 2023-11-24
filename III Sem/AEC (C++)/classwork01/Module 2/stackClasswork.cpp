#include<bits/stdc++.h>
using namespace std;

//Stack to store fruits stack
int main(){
    stack <string> fruits;
    int n;
    cout<<"Enter number of fruits: ";
    cin>>n;
    cout<<"Enter "<<n<<" fruit(s): "<<endl;
    for(int i=0; i<n; i++){
        string fruit;
        cin>>fruit;
        fruits.push(fruit);
    }
    cout<<"Fruits in the Stack: "<<endl;
    while(!fruits.empty()){
        cout<<fruits.top()<<" ";
        fruits.pop();
    }
}