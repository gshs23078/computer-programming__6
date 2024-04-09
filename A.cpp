#include <bits/stdc++.h>
#define int long long
using namespace std;
string str;
int l;
void f(int n){
	if(n>=l) return;
	cout << str[n] << " ";
	f(n*2+1);
	f(n*2+2);
}
signed main(){
	int n;
	cin >> n;
	cin >> str;
	l=str.length();
	f(0);
}
