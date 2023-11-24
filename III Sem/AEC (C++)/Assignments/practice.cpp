#include<iostream>
#include<set>
using namespace std;

int main(){
    set <int> SET = {1, 2, 3, 5, 8, 1};
    for(const auto &e : SET)
        cout<<e<<" ";
    cout<<endl;
    return 0;
}