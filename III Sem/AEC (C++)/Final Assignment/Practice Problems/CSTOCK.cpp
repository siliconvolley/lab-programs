#include <iostream>
using namespace std;

int main() {
	int t, a, b;
	float s, c;
	cin>>t;
	while(t--){
	    cin>>s>>a>>b>>c;
	    s += (s*(c/100.0));
	    if(s>=a && s<=b)
	        cout<<"yes"<<endl;
	    else
	        cout<<"no"<<endl;
	}
}