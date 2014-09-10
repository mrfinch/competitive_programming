#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a,s,d;
    int q,w,e;
    int n;
    cin >> a >> s >> d;
    cin >> q >> w >> e;
    cin >> n;
    int s1=a+s+d;
    int s2=q+w+e;
    int q1=ceil(s1/(5.0));
    int q2=ceil(s2/(10.0));
    if(q1+q2<=n){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
