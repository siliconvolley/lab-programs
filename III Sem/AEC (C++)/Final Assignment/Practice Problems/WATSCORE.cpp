#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,int> m;
    int n, x, y, sum=0, t;
    cin>>t;
    while(t--)
    { 
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>x>>y;
            if(x<=8)
                m[x]=max(m[x],y);
        }
    map<int, int>::iterator it;

    for(it=m.begin();it!=m.end();it++)
        sum=sum+(*it).second ;

    cout<<sum<<endl;
    sum=0;
    m.clear();
    }
}