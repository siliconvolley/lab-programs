#include<bits/stdc++.h>
using namespace std;

list <int> numbers, temp;

void findNextElement(int , int );

//Display the list
void displaySet(){
    for(int i : numbers){
        cout<<i<<" ";
    }
    cout<<endl;
}

//Find a given number in the list
void findElement(int n){
    int x, pos;
    cout<<"Enter Number to be Searched and a Position: ";
    cin>>x>>pos;
    int j = 0;
    for(int i : numbers){
        if(i == pos){
            if(i == x){
                cout<<"Element "<<x<<" Found at Position "<<j+1<<endl;
                return;
            }
            else{
                cout<<"Element "<<x<<" Not Found at Position "<<j+1<<endl;
                findNextElement(x, pos);
                return;
            }
        }
    }
}

//To find the next greater element of a given number
void findNextElement(int element, int position){
    int i = 0;
    for(int x : temp){
        if(element < x){
            i = x;
            break;
        }
    }
    int j = 0;
    for(int x : numbers){
        if(x == i){
            cout<<"The greatest number just after "<<element<<" in the list is "<<x<<" found at position "<<j+1<<endl;
            return;
        }
        else
            j++;
    }

}
int main(){
    int size;
    cout<<"Enter the number of elements: ";
    cin>>size;
    cout<<"Enter the numbers: "<<endl;
    for(int i=0; i<size; i++){
        int element;
        cin>>element;
        numbers.push_back(element);
    }
    cout<<endl;
    displaySet();

    //Sorting the set in ascending order
    cout<<"Set after sorting: ";
    temp = numbers;
    temp.sort();
    for(int i : temp){
        cout<<i<<" ";
    }
    cout<<endl;

    findElement(size);

}