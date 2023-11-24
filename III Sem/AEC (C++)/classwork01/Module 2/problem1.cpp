#include<iostream>
#include<algorithm>
#include<list>
using namespace std;

int main(){
    list<int> numbers;
    int size;
    cout<<"Enter number of elements: ";
    cin>>size;
    cout<<"Enter "<<size<<" elements: ";
    for(int i=0; i<size; i++){
        int element;
        cin>>element;
        numbers.push_back(element);
    }

    for(int x : numbers){
        if(x % 2 == 1){
            cout<<x<<" ";
            //numbers.remove(x);
        }
    }
    cout<<endl;
    for(int x : numbers)
        cout<<x<<" ";
    cout<<endl;
}