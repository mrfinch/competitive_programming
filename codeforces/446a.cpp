#include <iostream>
#include <vector>
//not complete
using namespace std;

struct node{
    node(int x,int y,int z){
        l_u=x;l_wu=y;u_num=z;
    }
    int l_u,l_wu,u_num;
};

int main(){
    int n;
    cin >> n;
    vector<int> inp(n);
    int m=0;
    while(m<n){
        cin >> inp[m];
        m++;
    }
    vector<node> dp(n,node(1,1,-1));
    dp[0].l_u=1;
    dp[0].l_wu=1;
    for(int i=1;i<inp.size();i++){
        for(int j=0;j<i;j++){
            if(inp[i]>inp[j] || inp[i]>dp[j].u_num){
                dp[i].l_wu=max(dp[j].l_wu+1,dp[i].l_wu);
                dp[i].l_wu=max(dp[j].l_u+1,dp[i].l_wu);
                dp[i].l_u=max(dp[j].l_u+1,dp[i].l_u);
                if(dp[j].u_num!=-1){
                    dp[i].u_num=max(inp[i],dp[j].u_num);
                }
            }
            /*
            if(inp[i]>dp[j].u_num && dp[j].u_num!=-1){
                dp[i].l_u=max(dp[j].l_u+1,dp[i].l_u);
                if(dp[j].u_num!=-1){
                    dp[i].u_num=max(inp[i],dp[j].u_num);
                }
            }*/
            if(inp[i]<=inp[j] && dp[j].u_num==-1){
                dp[i].l_u=max(dp[j].l_u+1,dp[i].l_u);
                //dp[i].l_wu=max(dp[i].l_wu,dp[j].l_u);
                dp[i].u_num=inp[j]+1;
            }
            if(inp[i]<=inp[j] && dp[j].u_num!=-1){
                dp[i].l_u=max(dp[i].l_u,dp[j].l_u);
                //dp[i].l_wu=max(dp[i].l_wu,dp[j].l_u);
            }
        }
    }
    int max=0;
    for(int i=0;i<inp.size();i++){
        cout << dp[i].l_u << " " << dp[i].l_wu << " " << dp[i].u_num << endl;
        if(dp[i].l_u>max){
            max=dp[i].l_u;
        }
        if(dp[i].l_wu>max){
            max=dp[i].l_wu;
        }
    }
    cout << max << endl;
}
