#include<bits/stdc++.h>
using namespace std;

int main(){
    multiset <int> s;
    s.insert('A');
    s.insert('A');
    s.insert('C');
    s.insert('D');
    s.insert('E');

    for(auto itr : s)
        cout<<itr<<" ";

    for(auto it = s.begin(); it != s.end(); ++it)
        cout<<*it<<" ";
    cout<<endl;
}