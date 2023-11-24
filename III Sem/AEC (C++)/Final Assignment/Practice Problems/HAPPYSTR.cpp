#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int t,c=0;  cin>>t;
	while(t--){
	    string s;   cin>>s;
	    int l = s.length();
	    
	    for(int i=0; i<l; i++){
	        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
	            c++;
	            if(c==3){
	                cout<<"Happy\n";
	                break;
	            }
	        }     
	        else c=0;
	    }
	    if(c!=3) cout<<"Sad\n";
	    
	}
	return 0;
	
}
