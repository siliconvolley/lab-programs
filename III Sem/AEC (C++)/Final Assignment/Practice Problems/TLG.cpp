#include <bits/stdc++.h>
using namespace std;

int main() {
	    int n;
	    cin>>n;
	    int winner=0;
	    int player1=0,player2=0; 
	    int lead=0;
	    
	    while(n--){
	        int p1,p2;
	        cin>>p1>>p2;
	        player1+=p1; 
	        player2+=p2;
	                        
	        int x=abs(player1-player2);
	                                    
	        if(x>lead){   
	            lead=x;
	            player1>player2?winner=1:winner=2;
	        }
	    }
	    cout<<winner<<" "<<lead<<endl; 
	return 0;
}
