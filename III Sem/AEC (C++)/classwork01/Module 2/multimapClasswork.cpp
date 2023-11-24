#include<bits/stdc++.h>
using namespace std;

//To store USN and 3 Internal Marks using Multimap
int main(){
    multimap <int, int> student;
    int size;
    cout<<"Enter Number of Students: ";
    cin>>size;
    cout<<endl;

    for(int i=0; i<size; i++){
        int USN, marks1, marks2, marks3;
        cout<<"Enter USN and 3 Internals Marks of student "<<i+1<<": ";
        cin>>USN>>marks1>>marks2>>marks3;
        student.insert({USN, marks1});
        student.insert({USN, marks2});
        student.insert({USN, marks3});
    }
    int i = 1;
    for(auto it = student.begin(); it != student.end(); it++){
        cout<<"USN: "<<(*it).first<<", Marks "<<i<<": "<<(*it).second<<endl;
        i++;
    }

    //Toppers

    int sum = 0;
    for(auto it = student.begin(); it != student.end(); it++){
        sum += (*it)
    }
}