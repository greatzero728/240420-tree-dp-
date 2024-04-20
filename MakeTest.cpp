#define rnd (((((INT)rand() << 15) | rand()) << 15) | rand())
#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int main() {
	freopen("test\\in.txt", "w", stdout);
	
	srand(time(0));
	
	int m = rnd % 10 + 1;
	int n = rnd % 10 + 1;
//	m = 4, n = 3;
	cout<<m<<endl;
	cout<<n<<' '<<n - 1<<endl;
	for(int i = 1; i < n; i++) {
		int u = rnd % i;
		cout<<u + 1<<' '<<i + 1<<endl;
	}
	return 0;
}
