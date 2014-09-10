#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <iomanip>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t){
        int n;
        cin >> n;
        double res=0.0;
        for(int i=1;i<=n;i++){
            res+=(1/(i*1.0));
        }
        res=res*n;
        //cout << setprecision(2);
        //cout << res << endl;
        printf("%.2f\n",res);
        t--;
    }
}
