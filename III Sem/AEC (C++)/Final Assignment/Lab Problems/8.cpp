#include<bits/stdc++.h>
using namespace std;

int main(){
	int x,y,s,t,res=0,loss=0;
	cout<<"Enter the Position of the frog (x, y), Side-length of the square & Time: ";
	cin>>x>>y>>s>>t;
	int remaining;
	remaining = t - (x+y);
	if(remaining <= (2*s)+1){			//To check if the remaining steps are within the square or not
		int j=0;
		if(remaining > s)
			j = remaining - s;			//If the remaining steps is greater than the diagonal of the square then assign the number of steps to be taken after the diagonal

		for(int k=0; k<=remaining+1; k++)
			res += k;					//Loop to add the number of points before the diagonal with the remaining steps

		for(int k=1; k<=j; k++)
			loss += (k * 2);			//If the steps go beyond the diagonal, add the number of lost point with increment of lost points of 2 with each step

		res = res - loss;
		cout<<res<<endl;
	}
	else
	cout<<((s+1)*(s+1))<<endl;			//If remaining steps go outside the square then print maximum number of points present in the square
}
