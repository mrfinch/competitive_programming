#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    long long n,a,b;
    cin >> n >> a >> b;
    int i=0;
    vector<long long> ax(n,0);
    while(i<n){
        cin >> ax[i];
        i++;
    }
    vector<long long> bx(n,0);
    for(int i=0;i<bx.size();i++){
        bx[i] = ax[i]%b;
    }
    for(int i=0;i<bx.size();i++){
        cout << bx[i] << " ";
    }
    cout << endl;
}
