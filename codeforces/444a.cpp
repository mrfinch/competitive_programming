#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
#include <stdio.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> cost(n+1);
    int a=1;
    while(a<n+1){
        cin >> cost[a];
        a++;
    }
    a=0;
    vector< pair<int,int> > inp[n+1];
    while(a<m){
        int t1,t2,c;
        cin >> t1 >> t2 >> c;
        inp[t1].push_back(make_pair(t2,c));
        a++;
    }
    double max=0.0;
    for(int i=1;i<n+1;i++){
        for(int j=0;j<inp[i].size();j++){
            double t=(cost[i]+cost[inp[i][j].first])/(inp[i][j].second*1.0);
            if(t>max){
                max=t;
            }
        }
    }
    //cout << setprecision(16);
    //cout << max << endl;
    printf("%.15f\n",max);
}
