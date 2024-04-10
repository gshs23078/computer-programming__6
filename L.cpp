#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define int long long
#define endl "\n"
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a; i>=b; i--)
bool ok(int x, int y, int n){
	if(x<0 || x>=n) return false;
	if(y<0 || y>=n) return false;
	return true;
}
signed main(){
	int n;
	cin >> n;
	bool map[n][n];
	fori(i, 0, n){
		string str;
		cin >> str;
		fori(j, 0, n)
			map[i][j]=(str[j]-'0');
	}
	int dx[]={-1, 1, 0, 0};
	int dy[]={0, 0, -1, 1};
	vector<int> ans;
	int num=0;
	while(1){
		int chk=1;
		int x, y=-1;
		fori(i, 0, n){
			fori(j, 0, n){
				if(map[i][j]){
					y=j;
					break;
				}
			}
			if(y>=0){
				x=i;
				break;
			}
		}
		if(y<0) break;
		num++;
		queue<int> qu;
		qu.push(x*n+y);
		map[x][y]=0;
		while(qu.size()){
			x=qu.front()/n;
			y=qu.front()%n;
			qu.pop();
			fori(k, 0, 4){
				if(!ok(x+dx[k], y+dy[k], n))
					continue;
				if(!map[x+dx[k]][y+dy[k]])
					continue;
				qu.push((x+dx[k])*n+(y+dy[k]));
				map[x+dx[k]][y+dy[k]]=0;
				chk++;
			}
		}
		ans.push_back(chk);
	}
	sort(ans.begin(), ans.end());
	cout << num << endl;
	fori(i, 0, num) cout << ans[i] << endl;
}
