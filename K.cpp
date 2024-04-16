#include <iostream>
using namespace std;
#define int long long
#define endl '\n'
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a;i>=b; i--)
char ans[60][60];
bool link[27][27], done[27]={0};
int h=0, w=0;
int maxh=1, maxw=0;
void solve(int x){
	done[x]=true;
	ans[h][w++]='-';
	ans[h][w++]=x+'a';
	if(maxw<w) maxw=w;
	bool first=false;
	int parent=h;
	fori(i, 0, 26){
		if(done[i]) continue;
		if(!link[x][i]) continue;
		if(!first){
			first=true;
			solve(i);
		}
		else{
			fori(j, parent+1, h+1)
				ans[j][w-1]='|';
			ans[++h][w-1]='+';
			if(maxh<=h) maxh=h+1;
			solve(i);
		}
	}
	w-=2;
}
signed main(){
	fori(i, 0, 60) fori(j, 0, 60) ans[i][j]='.';
	int n;
	cin >> n;
	fori(i, 0, 27) fori(j, 0, 27) link[i][j]=false;
	fori(i, 0, n-1){
		char p, q;
		cin >> p >> q;
		p-='a', q-='a';
		link[p][q]=link[q][p]=true;
	}
	solve(0);
	fori(i, 0, maxh){
		fori(j, 0, maxw)
			cout << ans[i][j];
		cout << endl;
	}
}
