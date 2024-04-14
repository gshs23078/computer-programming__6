#include <iostream>
#define int long long
#define endl "\n"
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a;i>=b; i--)
#define mod 9901
using namespace std;
int mem[201][101];
bool chk[201][201];
int f(int n, int k){
	if(chk[n][k]) return mem[n][k];
	chk[n][k]=true;
	int p=1;
	if(k*2-1>n) return mem[n][k]=0;
	if(k<60 && n>((p<<k)-1)) return mem[n][k]=0;
	if(n%2==0) return mem[n][k]=0;
	if(n==0 && k==0) return mem[n][k]=1;
	if(n==1 && k==1) return mem[n][k]=1;
	int ans=0;
	fori(i, 1, n) fori(j, 1, k-1){
		ans+=f(i, j)*f(n-i-1, k-1);
		ans%=mod;
	}
	ans<<=1;
	ans%=mod;
	fori(i, 1, n){
		ans+=f(i, k-1)*f(n-i-1, k-1);
		ans%=mod;
	}
	return mem[n][k]=ans;
}
signed main(){
	int n, k;
	cin >> n >> k;
	fori(i, 0, 201) fori(j, 0, 201)
		chk[i][j]=false;
	cout << f(n, k);
}
