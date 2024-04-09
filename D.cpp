#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
vector<char> op;
vector<int> num;
stack<int> st;
int l=0, k=1;
int ans;
bool isnum(char x){
	return (x>='0' && x<='9');
}
bool isop(char x){
	return (x=='+' || x=='-' || x=='*' || x=='/');
}
void in(int n){
	if(n>=l) return;
	if(n<k) cout << "(";
	in(2*n+1);
	if(n<k) cout << op[n];
	else cout << num[n-k];
	in(2*n+2);
	if(n<k) cout << ")";
}
void post(int n){
	if(n>=l) return;
	post(2*n+1);
	post(2*n+2);
	if(n<k){
		cout << op[n] << " ";
			int p=st.top();
			st.pop();
			int q=st.top();
			st.pop();
		if(op[n]=='+'){
			st.push(p+q);
		}
		else if(op[n]=='-'){
			st.push(q-p);
		}
		else if(op[n]=='*'){
			st.push(p*q);
		}
		else if(op[n]=='/'){
			st.push(q/p);
		}
	}
	else{
		cout << num[n-k] << " ";
		st.push(num[n-k]);
	}
}
signed main(){
	char x[300]={};
	fgets(x, 300, stdin);
	int i=0;
	while(x[i]){
		if(isop(x[i])){
			op.push_back(x[i]);
		}
		else if(isnum(x[i])){
			int p=0;
			while(isnum(x[i])){
				p*=10;
				p+=x[i]-'0';
				i++;
			}
			i--;
			num.push_back(p);
		}
		i++;
	}
	l=op.size()+num.size();
	k=op.size();
	in(0);
	cout << endl;
	post(0);
	cout << endl;
	cout << st.top();
}
