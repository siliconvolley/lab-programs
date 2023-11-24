#include <iostream>
#include <string>
using namespace std;

void solution()
{
    int N, count;
    string name;
    
	cin >> N >> name;
	count = 0;
	for(int i = 0; i < N; i++)
	{
	    if(name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u')
	    {
	        count = 0;
	        continue;
	    }
	    else
	    {
	        count++;
	        if(count == 4)
	        break;
	    }
	}
	if(count < 4)
	{
	    cout << "YES" << endl;
	}
	else
	{
	    cout << "NO" << endl;
	}
}


int main() {
	// your code goes here
	int T;
	cin >> T;
	while(T--)
	{
        solution();
	}
	return 0;
}
