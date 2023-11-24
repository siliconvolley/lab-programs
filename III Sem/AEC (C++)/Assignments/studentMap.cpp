#include<bits/stdc++.h>
using namespace std;

//To store USN and Marks using Maps & print Top 2 students
int main(){
    map <int, int> student, toppers;
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

    // for(auto it = student.begin(); it != student.end(); it++){
    //     cout<<"USN: "<<(*it).first<<", marks: "<<(*it).second<<endl;
    // }
    cout<<endl;
    
    int top, key;
    for(int i=1; i<=2; i++){
        top = student.begin()->first;
        for(auto it = student.begin(); it != student.end(); it++){
            if((*it).second > top){
                key = (*it).first;
                top = (*it).second;
                toppers.insert({key, top});
            }
        }
        cout<<"Rank "<<i<<" - ";
        cout<<"USN: "<<key<<" & "<<"Marks: "<<top<<endl;
        student.erase(key);
    }
}