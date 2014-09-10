#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> inp(n+1,0);
    int i=1;
    while(i<n+1){
        cin >> inp[i];
        i++;
    }
    vector<int> s_inp(n+1);
    copy(inp.begin(),inp.end(),s_inp.begin());
    sort(s_inp.begin(),s_inp.end());
    vector<long long> sum_inp(n+1,0);
    vector<long long> sum_s_inp(n+1,0);
    /*for(int i=1;i<n+1;i++){
        for(int j=1;j<=i;j++){
            sum_inp[i]+=inp[j];
            sum_s_inp[i]+=s_inp[j];
        }
    }*/
    for(int i=1;i<n+1;i++){
        sum_inp[i]=sum_inp[i-1]+inp[i];
        sum_s_inp[i]=sum_s_inp[i-1]+s_inp[i];
    }
    int m;
    cin >> m;
    i=0;
    while(i<m){
        int type,l,r;
        cin >> type >> l >> r;
        if(type==1){
            long long out = sum_inp[r]-sum_inp[l-1];
            cout << out << endl;
        }
        else{
            long long out = sum_s_inp[r]-sum_s_inp[l-1];
            cout << out << endl;
        }
        i++;
    }
}
