#include <iostream>
#include <string>
using namespace std;

string f(string in, string pre){
	int l=in.length();
	if(l<=1) return in;
	
	int i=-1;
	while(in[++i]!=pre[0]);
	
	string nextin, ans, nextpre;
	nextin.append(in, 0, i);
	nextpre.append(pre, 1, i);
	ans.append(f(nextin, nextpre));
	
	string innext, prenext;
	innext.append(in, i+1, l-i);
	prenext.append(pre, i+1, l-i);
	ans.append(f(innext, prenext));
	
	ans.append(in, i, 1);
	return ans;
}

main(){
	string in, pre;
	cin >> in >> pre;
	cout << f(in, pre);
}
