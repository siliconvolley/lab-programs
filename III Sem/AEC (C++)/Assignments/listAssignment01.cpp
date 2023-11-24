#include<bits/stdc++.h>
using namespace std;

list <int> numbers;

//To display the contents of the list
void displayList(){
    for(int i : numbers)
        cout<<i<<" ";
    cout<<endl;
}

//To check odd or even
bool odd(int value){
    if(value == 1 || value%2 == 1)
        return true;
    return false;
}

//Deleting ODD Numbers
void deleteOdd(){
    numbers.remove_if(odd);    
    cout<<"After deleting Odd Numbers: ";
    displayList();
}

//Adding the squares of the existing numbers
void addSquares(){
    int sumSq = 0;
    for(int x : numbers)
        sumSq+=(x*x);

    cout<<endl<<"Sum of the squares of the remaining numbers = "<<sumSq<<endl;
}

//Sum of the elements of the list
void listSum(){
    int sum = 0;
    for(int x : numbers)
        sum+=x;
    cout<<endl<<"Sum of the numbers in the list = "<<sum<<endl;
}
int main(){
    int size;
    cout<<"Enter number of  elements: ";
    cin>>size;
    cout<<"Enter the numbers: "<<endl;
    for(int i=0; i<size; i++){
        int ele;
        cin>>ele;
        numbers.push_back(ele);
    }

    deleteOdd();
    addSquares();
    listSum();
}