#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue <int> q;
    if(q.empty())
        cout<<"Queue is empty"<<endl;
    else
        cout<<"Queue is empty"<<endl;
    int n, ele;
    cout<<"Enter number of Elements to be inserted: ";
    cin>>n;
    cout<<"Enter Elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>ele;
        q.push(ele);
    }
    cout<<endl<<"The Queue now contains: "<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}