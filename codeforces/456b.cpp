#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <utility>

using namespace std;

bool func(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}
int main(){
    int n;
    cin >> n;
    vector< pair<int,int> > a(n);
    int m=0;
    while(m<n){
        cin >> a[m].first >> a[m].second;
        m++;
    }
    sort(a.begin(),a.end(),func);
    int q=a[0].second;
    bool x=false;
    for(int i=1;i<n;i++){
        if(a[i].first!=a[i-1].first && a[i].second<q){
            x=true;
            break;
        }
        else{
            if(a[i].second>q){
                q=a[i].second;
            }
        }
    }
    if(x==true){
        cout << "Happy Alex"  << endl;
    }
    else{
        cout << "Poor Alex" << endl;
    }
}
