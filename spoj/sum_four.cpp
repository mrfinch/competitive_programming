#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    vector<int> d(n);
    int m=0;
    while(m<n){
        scanf("%d %d %d %d",&a[m],&b[m],&c[m],&d[m]);
        m++;
    }
    vector<int> d1(n*n);
    vector<int> d2(n*n);
    m=0;
    //map<int,int> m1;
    //map<int,int> m2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            d1[m]=a[i]+b[j];
            d2[m]=c[i]+d[j];
            //m1[d1[m]]++;
            //m2[d2[m]]++;
            //cout << m1[d1[m]] << endl;
            m++;
        }
    }
    //sort(d1.begin(),d1.end());
    //sort(d2.)
    int res=0;
    /*for(int i=0;i<d1.size();i++){
    	if(m2[-1*d1[i]]>0){
            res+=m2[-1*d1[i]];
        }
    }
    for(int i=0;i<d2.size();i++){
        if(m1[-1*d2[i]]==true){
            res++;
        }
    }*/
    sort(d2.begin(),d2.end());
    pair<vector<int>::iterator,vector<int>::iterator> bd;
    for(int i=0;i<d1.size();i++){
        bd=equal_range(d2.begin(),d2.end(),-1*d1[i]);
        res+=(bd.second-bd.first);
    }
    cout << res << endl;
}
