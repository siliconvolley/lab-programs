#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, k; 
	    cin>>n>>k;
	    int player_heights[n];
	    for(int i=0; i<n; i++){
	        cin>>player_heights[i];
	    }
	    int count=0;
	    for(int i=0; i<n; i++){
	        if(player_heights[i]>k)
	            count++;
	    }
	    cout<<count<<endl;
	}
	return 0;
}
