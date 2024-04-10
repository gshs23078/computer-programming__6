#include <iostream>
#define endl "\n"
#define int long long
using namespace std;
int ans[21]={0};
int f(int n){
	if(ans[n]) return ans[n];
	if(n<2) return ans[n]=1;
	int sum=0;
	for(int i=0; i<n; i++)
		sum+=f(i)*f(n-i-1);
	return ans[n]=sum;
}
signed main(){
	int n;
	cin >> n;
	cout << f(n);
}
