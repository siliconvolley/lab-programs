#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
	   int n,s=0,r,num;
	   cin>>n;
	   num = n;
	   while(n > 0) {
	       r = n%10;
	       s = (s*10) + r;
	       n = n/10;
	   }
	   if(num == s) {
	       cout<<"wins"<<endl;
	   }else {
	       cout<<"loses"<<endl;
	   }
	}
	return 0;
}
