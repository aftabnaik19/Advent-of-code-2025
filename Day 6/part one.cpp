#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n = 4, m = 1000; 
    vector<vector<int>>v(n,vector<int>(m));
    vector<char> ops(m);
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m ; j++){
            cin>>v[i][j];
        }
    }
    char c;
    int finalAns = 0;
    for(int i = 0 ; i < m; i++){
        cin>>c;
        int ans = 1 ;
        for(int j = 0 ; j < n; j++){
            if(c=='*')ans*=v[j][i];
            else ans+=v[j][i];
        }
        finalAns+=ans;
        if(c=='+')finalAns--;
    }
    cout<<finalAns<<endl;
    return 0;
}
