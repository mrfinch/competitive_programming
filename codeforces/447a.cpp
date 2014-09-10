#include <iostream>
#include <vector>

using namespace std;

int main(){
    int p,n;
    cin >> p >> n;
    vector<int> c(p,0);
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        int x;
        x=t%p;
        if(c[x]<1){
            c[x]++;
        }
        else{
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
