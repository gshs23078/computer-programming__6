#include <bits/stdc++.h>
#define int long long
using namespace std;
string str;
int l;
void f(int n){
	if(n>=l) return;
	f(n*2+1);
	f(n*2+2);
	cout << str[n] << " ";
}
signed main(){
	int n;
	cin >> n;
	cin >> str;
	l=str.length();
	f(0);
}
