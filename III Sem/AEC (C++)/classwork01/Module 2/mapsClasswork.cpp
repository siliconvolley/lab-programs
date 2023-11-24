#include<bits/stdc++.h>
using namespace std;

//To store USN and Marks using Maps
int main(){
    map <int, int> student;
    int size;
    cout<<"Enter Number of Students: ";
    cin>>size;
    cout<<endl;

    for(int i=0; i<size; i++){
        int USN, marks;
        cout<<"Enter USN and marks of student "<<i+1<<": ";
        cin>>USN>>marks;
        student.insert({USN, marks});
    }

    for(auto it = student.begin(); it != student.end(); it++){
        cout<<"USN: "<<(*it).first<<", marks: "<<(*it).second<<endl;
    }
}