#include <iostream>
#include <string>
#include <queue>
#include <stack>
#define int long long
#define endl "\n"
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a;i>=b; i--)
using namespace std;
string solve(string a, string b){
	int l=a.length();
	if(l==1) return a.substr(0, 1);
	int k;
	for(k=0; k<l; k++){
		if(a[k]==b[0]) break;
	}
	if(k==0){
		string p=a.substr(0, 1);
		string q=solve(a.substr(k+1), b.substr(k+1));
		q.append(p);
		return q;
	}
	string p=solve(a.substr(0, k), b.substr(1, k));
	if(k==l-1){
		p.append(1, b[0]);
		return p;
	}
	string q=solve(a.substr(k+1), b.substr(k+1));
	p.append(q);
	p.append(1, b[0]);
	return p;
}
signed main(){
	string stra, strb;
	cin >> stra >> strb;
	cout << solve(stra, strb);
}
