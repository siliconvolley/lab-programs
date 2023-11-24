#include <iostream>
using namespace std;

int main() 
{
    int t,a,b,i,count=0;
    cin>>t;
    while(t--)
    {
        count=0;
        cin>>a>>b;
        for(i=a;i<=b;i++)
        {
            if(i%10==2||i%10==3||i%10==9)
            {
                count++;
            }
        }
        cout<<count<<endl;
    }
}
