#include <iostream>
using namespace std;
#define endl '\n'
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a;i>=b; i--)

int h, n;
int ans;

void f(int node, int layer, int left){
	if(left<1<<layer) f(node*2, layer-1, left);
	else if(left==1<<layer){
		ans=node;
		return;
	}
	else f(node*2+1, layer-1, left-(1<<layer));
	return;
}

main(){
	cin >> h >> n;
	f(1, h, n);
	cout << ans;
}
