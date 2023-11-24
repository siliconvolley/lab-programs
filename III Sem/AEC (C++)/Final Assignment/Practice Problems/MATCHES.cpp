#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int a, b, sum, rem, totalSticks=0;
	    cin>>a>>b;
	    sum=a+b;
	    while(sum>0){
	        rem=sum%10;
	        sum=sum/10;
	        switch(rem){
	            case 0: totalSticks+=6;
	                    break;
	            case 1: totalSticks+=2;
	                    break;
	            case 2: totalSticks+=5;
	                    break;
	            case 3: totalSticks+=5;
	                    break;
	            case 4: totalSticks+=4;
	                    break;
	            case 5: totalSticks+=5;
	                    break;
	            case 6: totalSticks+=6;
	                    break;
	            case 7: totalSticks+=3;
	                    break;
	            case 8: totalSticks+=7;
	                    break;
	            case 9: totalSticks+=6;
	                    break;
	            default: break;
	        }
	    }
	    cout<<totalSticks<<endl;
	}
	return 0;
}
