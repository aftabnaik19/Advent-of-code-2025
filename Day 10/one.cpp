/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
vector<vector<int>> buttons;
vector<ull> buttons2;
vector<int> req;
#define INF 1e9
void processInput(string &s) {
	int n = s.size();
	int i = 0 ;
	for( i = 1; i < n ; i++) {
		if(s[i]==']')break;
	}
	string state = s.substr(1,i-1);
	req.resize(state.size());
	for(i = 0 ; i < state.size(); i++) {
		req[i]=(state[i]=='#');
	}
// 	for(auto x: req)cout<<x;
// 	cout<<endl;
	while(s.back()!='{')s.pop_back();
	s.pop_back();
	s.pop_back();
	string buts = s.substr(i+3);
// 	cout<<buts<<endl;

	vector<int> temp;
	while(!buts.empty()) {
		char c = buts.back();
		buts.pop_back();
		if(c==')')temp.clear();
		else if(c=='(')buttons.push_back(temp);
		else if(c==' ' || c==',')continue;
		else temp.push_back(c-'0');
	}
	// for(auto v: buttons){
	//     for(auto x: v)cout<<x<<" ";
	//     cout<<endl;
	// }
}

int solve() {
	int ans = 0 ;
	string s;
	for(auto x: req)s+=to_string(x);
	reverse(s.begin(),s.end());
	bitset<10> finalState(s);
// 	cout<<finalState<<endl;
	vector<int> dist(1<<10,INF);
	int dest = finalState.to_ullong();
	queue<int> q;
	vector<char> vis(1<<10);
	q.push(0);
	dist[0]=0;
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		if(vis[node])continue;
		vis[node]=true;
		if(node==dest)return dist[dest];
		for(auto v: buttons) {
			ull num = node ;
			for(auto x: v) {
				num^=(1LL<<x);
			}
			if(dist[num]>dist[node]+1) {
				dist[num]=dist[node]+1;
				q.push(num);
			}
		}

	}
	cout<<dist[dest]<<endl;
	return dist[dest];
}

signed main()
{
	string s;
	int ans = 0 ;
	while(getline(cin,s)) {
		req.clear();
		buttons.clear();
		processInput(s);
		ans+=solve();
	}
	cout<<ans<<endl;
	return 0;
}
