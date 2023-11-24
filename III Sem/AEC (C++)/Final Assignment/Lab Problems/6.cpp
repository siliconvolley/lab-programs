#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcases;
	cin>>testcases;							//Entering the number of test cases
	while(testcases--){
        int x, y, z, sum, div;
	    cin>>x>>y>>z;						//Entering the total levels, minutes to complete & break-time

	    if(x <= 3)
	        sum = x*y;
        else{
			if((x%3) == 0)
				sum = (x*y) + ( ( (x/3) - 1 ) * z );		//If number of levels are divisible by 3, then the last break-time is not taken by Chetan
			else
				sum = (x*y) + ( (x/3) * z );				//Else calculate the total time taken
	    }
        cout<<sum<<endl;
	}
}