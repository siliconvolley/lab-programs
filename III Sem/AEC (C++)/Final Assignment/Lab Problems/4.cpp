#include<bits/stdc++.h>
using namespace std;

bool isVowel(char c){                       //Function to check whether a given character is a Vowel or not
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}

int main(){
    int testcases;
    cout<<"Enter number of Test Cases: ";
    cin>>testcases;                         //Entering the number of test cases
    while(testcases--){
        int count=0;
        string s;                           //Entering the String
        cout<<"Enter the String: ";
        cin>>s;
        for(int i=0; i<s.length(); i++){
            count = 0;
            if(isVowel(s[i])){
                for(int j=i; j<i+3; j++){
                    if(isVowel(s[j]))
                        count++;            //Counting the number of vowels
                }
                if(count > 2){
                    cout<<"Happy"<<endl;    
                    break;
                }
            }                               //If the number of Vowels is greater than 2, Bhuvan is HAPPY or else SAD
        }
        if(count == 0)
            cout<<"Sad"<<endl;
    }
}