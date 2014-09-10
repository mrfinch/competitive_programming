#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
    int n;
    cin >> n;
    //vector<int> a(n);
    int m=0;
    int res=0;
    int t;
    while(m<n){
        //cin >> a[m];
        scanf("%d",&t);
        res=res^t;
        m++;
    }
    /*for(int i=0;i<n;i++){
        res=res^a[i];
    }*/
    //cout << res << endl;
    printf("%d\n",res);
}
