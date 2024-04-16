#include <iostream>
#include <vector>
#define int long long
#define endl '\n'
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a;i>=b; i--)
using namespace std;
int n;
vector<int> pre;
vector<int> post;
int f(int a, int b, int size){
	if(size==0) return 2;
	if(pre[a]!=post[b+size-1]) return 0;
	bool chk=false;
	int p;
	if(size==1){
		return pre[a]==post[b];
	}
	if(size==2){
		if(pre[a]!=post[b+1]) return 0;
		if(pre[a+1]!=post[b]) return 0;
		return 2;
	}
	fori(i, b, b+size-1){
		if(pre[a+1]==post[i]){
			chk=true;
			p=i;
			break;
		}
	}
	if(!chk) return 0;
	int c=f(a+1, b, p-b+1);
	if(!c) return 0;
	int d=f(a+p-b+2, p+1, size-p+b-2);
	if(!d) return 0;
	return c*d;
}
signed main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	fori(i, 0, n){
		int k;
		cin >> k;
		pre.push_back(k);
	}
	fori(i, 0, n){
		int k;
		cin >> k;
		post.push_back(k);
	}
	cout << f(0, 0, n);
}
