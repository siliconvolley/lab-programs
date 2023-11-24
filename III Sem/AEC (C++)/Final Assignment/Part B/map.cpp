#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map <string, string> unordered_map;
    unordered_map["3rd Year"] = "AIML";
    unordered_map.insert({{"4th Year", "CS"}, {"3rd Year", "CS"}});

    cout<<"KEY - VALUE"<<endl;

    for(const auto &key_value: unordered_map){
        string key = key_value.first;
        string value = key_value.second;

        cout<<key<<" - "<<value<<endl;
    }
}