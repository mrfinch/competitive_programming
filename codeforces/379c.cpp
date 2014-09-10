/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    ll m=0;
    vector<ll> inp(n);
    ll maxm=0;
    while(m<n){
        cin >> inp[m];
        if(inp[m]>maxm){
            maxm=inp[m];
        }
        m++;
    }
    vector<bool> chk(maxm+n,false);
    //sort(inp.begin(),inp.end());
    //ll curr=inp[0];
    /*for(ll i=0;i<inp.size();i++){
        if(inp[i]<=curr){
            inp[i]++;
            curr++;
        }
    }*/
  /*  for(ll i=0;i<inp.size();i++){
        for(ll j=inp[i];j<chk.size();j++){
            if(chk[j]==false){
                chk[j]=true;
                inp[i]=j;
                break;
            }
        }
    }
    for(int i=0;i<inp.size();i++){
        cout << inp[i] << " ";
    }
}*/
#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,c,r[300100];
pair<int,int> a[300100];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i].first);
    a[i].second=i;
  }
  sort(a,a+n);
  for (i=c=0; i<n; i++, c++) r[a[i].second]=c=max(c,a[i].first);
  for (i=0; i<n; i++) printf("%d%c",r[i],i==n-1?'\n':' ');
  return 0;
}
