#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int x1, x2, y1, y2;
	    cin>>x1>>y1>>x2>>y2;
	    if(x1 == x2 || y1 == y2)
	        cout<<"YES"<<endl;
	    else
	        cout<<"NO"<<endl;
	}
	return 0;
}
