#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcases;
	cout<<"Enter number of Test Cases: ";
	cin>>testcases;							//Entering the number of Test Cases
	while(testcases--){
        int x, y, ans;
		cout<<"Enter two Integers: ";
	    cin>>x>>y;							//Entering the stairs to be reached & the stairs he can climb per move
	    ans = x/y;
	    ans += (x%y);
	    cout<<ans<<endl;
	}
}