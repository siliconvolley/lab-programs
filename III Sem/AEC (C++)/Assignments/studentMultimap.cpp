#include<bits/stdc++.h>
using namespace std;

//To store USN and 3 internals marks (3 students), compare average, print top 2
int main(){
    multimap <int, int> student, top2;
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            cout<<"Enter USN of Student "<<i<<" & Internal Marks "<<j<<": ";
            int usn, marks; 
            cin>>usn>>marks;
            student.insert({usn, marks});
        }
        cout<<endl;
    }

    //int count=0;
    // for(auto it=student.begin(); it!=student.end(); it++, count++){
    //     if(count == 3){
    //         cout<<endl;
    //         count=0;
    //     }
    //     cout<<(*it).first<<" "<<(*it).second<<endl;
    // }
    // cout<<endl;
    int sum = 0, count = 1, top, average;
    for(int i=0; i<2; i++){
        for(auto it=student.begin(); it!=student.end(); it++, count++){
            sum+=(*it).second;
            if(count == 3){
                top = (*it).first;
                average = sum/3;
                top2.insert({top, average});
                sum = 0;
                continue;
            }
        }
        student.erase(top);
    }
    for(auto it=top2.begin(); it!=top2.end(); it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
}