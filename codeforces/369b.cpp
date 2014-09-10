#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,k,l,r,sall,sk;
    cin >> n >> k >> l >> r >> sall >> sk;
    vector<int> out(n);
    int rem = sk%k;
    for(int i=0;i<k;i++){
        out[i]=sk/k+(rem>0);
        rem=rem-1;
    }
    int temp = sall-sk;
    rem=0;
    if(n-k!=0){
    rem=(temp)%(n-k);
    }
    int t = n-k;
    for(int i=k;i<n;i++){
        out[i]=temp/t+(rem>0);
        rem=rem-1;
    }
    for(int i=0;i<out.size();i++){
        cout << out[i] << " ";
    }
}
