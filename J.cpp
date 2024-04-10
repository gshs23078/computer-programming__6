#include <iostream>
#include <vector>
using namespace std;
#define int long long
#define endl "\n"
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a; i>=b; i--)
signed main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int p, ns, t;
	vector<int> ans;
	cin >> p >> ns >> t;
	int par[p+1]={0};
	while(ns--){
		int k, x, y;
		cin >> k >> x >> y;
		par[x]=k;par[y]=k;
	}
	while(par[t]){
		ans.push_back(t);
		t=par[t];
	}
	ans.push_back(1);
	int l=ans.size();
	cout << l << endl;
	ford(i, l-1, 0) cout << ans[i] << endl;
}
