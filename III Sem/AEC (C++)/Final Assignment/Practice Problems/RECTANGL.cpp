#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, a, b, c, d;
	cin >> t;
	while (t--) {
	    cin >> a >> b >> c >> d;
	    cout << ((a^b^c^d) == 0 ? "YES" : "NO") << '\n';
	}
	return 0;
}
