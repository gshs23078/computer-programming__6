#include <iostream>
#include <vector>
#define endl "\n"
#define int long long
using namespace std;
vector<bool> Right;
void f(int h, int n){
	if(!h) return;
	int k=1;
	if(k<<h >n){
		Right.push_back(0);
		f(h-1, n);
	}
	else if(k<<h ==n) return;
	else{
		Right.push_back(1);
		f(h-1, n-(k<<h));
	}
	return;
}
signed main(){
	int h, n, ans=1;
	cin >> h >> n;
	f(h, n);
	int l=Right.size();
	for(int i=0; i<l; i++)
		ans=ans*2+Right[i];
	cout << ans;
}
