#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int a[5], b[5], count1 = 0, count2 = 0;
	    for(int i=0; i<5; i++){
	        cin>>a[i];
	        cin>>b[i];
	        if(a[i] == 1)
	            count1++;
	        if(b[i] == 1)
	            count2++;
	    }
	    
	    if(count1 > count2)
	        cout<<1<<endl;
	    else if(count1 < count2)
	        cout<<2<<endl;
	    else
	        cout<<0<<endl;
	}
	return 0;
}
