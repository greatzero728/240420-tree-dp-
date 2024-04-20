#include<bits/stdc++.h>

using namespace std;
using INT = long long;

const int NN = 101010, mod = 1e9 + 7;

vector<int> adj[NN], vec;
int f[NN];

bool ok(int n) {
	for(int u = 1; u <= n; u++) {
		vec.clear(); vec.push_back(f[u]);
		for(int v: adj[u]) vec.push_back(f[v]);
		sort(vec.begin(), vec.end());
		for(int i = 1; i < vec.size(); i++) if(vec[i - 1] == vec[i]) {
			return false;
		}
	}
	return true;
}

int getTotalWays(int m, int g_nodes, vector<int> g_from, vector<int> g_to) {
	int n = g_nodes;
	for(int i = n - 1; i--; ) {
		int u = g_from[i], v = g_to[i];
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int mul = 1, ans = 0;
	for(int i = n; i--; ) mul = mul * m;
	for(int c = mul; c--; ) {
		for(int i = 1, C = c; i <= n; i++) f[i] = C % m + 1, C /= m;
		if(ok(n)) {
			ans++;
//			for(int i = 1; i <= n; i++) cout<<f[i]<<' '; puts("");
		}
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test\\in.txt", "r", stdin);
	freopen("test\\test.txt", "w", stdout);
#else
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
#endif
	
	int m; scanf("%d", &m);
	int n; scanf("%d %*d", &n);
	vector<int> U(n - 1), V(n - 1);
	for(int i = 0; i + 1 < n; i++) scanf("%d %d", &U[i], &V[i]);
	cout<<getTotalWays(m, n, U, V)<<endl;
	return 0;
}