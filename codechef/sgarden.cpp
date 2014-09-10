#include <iostream>
#include <vector>

using namespace std;

int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main(){
    int t;
    cin >> t;
    while(t){
        int n;
        cin >> n;
        vector<int> inp(n+1,0);
        int m=1;
        while(m<n+1){
            cin >> inp[m];
            m++;
        }
        long long out=1;
        long long prev=1;
        long long cnt=1;
        for(int i=1;i<inp.size();i++){
            int x=inp[i];
            cnt=1;
            while(x!=i){
                //cout << "x " << x << endl;
                cnt++;
                x=inp[x];
            }
            prev=out;
            out=gcd(out,cnt);
            out=((prev*cnt)/out)%(1000000000+7);
            //cout << cnt << " " << out << endl;
        }
        //int res=(prev*cnt)/out;
        cout << out << endl;
        t--;
    }
}
