#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    string s, t;
	    cin>>s;
	    cin>>t;
	    for(int i=0; i<5; i++){
	        if(s[i] == t[i])
	            t[i] = 'G';
	        else
	            t[i] = 'B';
	    }
	    cout<<t<<endl;
}
	return 0;
}
