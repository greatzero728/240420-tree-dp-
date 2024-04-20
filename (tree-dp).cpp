#include<bits/stdc++.h>

using namespace std;
using INT = long long;

const int NN = 101010, mod = 1e9 + 7;

int f[NN] = {1}, inv[NN];

int power(int a, int b) {
	int ans = 1;
	for(; b; b >>= 1, a = (INT)a * a % mod) {
		if(b & 1) ans = (INT)ans * a % mod;
	}
	return ans;
}

int C(int n, int k) {
	if(k < 0 || k > n) return 0;
	return (INT)f[n] * inv[k] % mod * inv[n - k] % mod;
}

vector<int> adj[NN];

int a[NN], b[NN], M;

void dfs(int u, int f = 0) {
	int mul = 1, num = 0;
	for(int v : adj[u]) if(v ^ f) {
		dfs(v, u), num++;
		mul = (INT)mul * a[v] % mod;
	}
	a[u] = (INT)C(M - 2, num) * mul % mod * ::f[num] % mod;
	b[u] = (INT)C(M - 1, num) * mul % mod * ::f[num] % mod;
}

int getTotalWays(int m, int g_nodes, vector<int> g_from, vector<int> g_to) {
	for(int i = 1; i < NN; i++) {
		f[i] = (INT)f[i - 1] * i % mod;
	}
	inv[NN - 1] = power(f[NN - 1], mod - 2);
	for(int i = NN - 2; i >= 0; i--) {
		inv[i] = (INT)inv[i + 1] * (i + 1) % mod;
	}
	
	int n = g_nodes; M = m;
	for(int i = n - 1; i--; ) {
		int u = g_from[i], v = g_to[i];
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	
	return (INT)m * b[1] % mod;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test\\in.txt", "r", stdin);
	freopen("test\\out.txt", "w", stdout);
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
