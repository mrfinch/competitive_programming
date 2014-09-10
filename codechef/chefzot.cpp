#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int> inp(n,0);
    int i=0;
    while(i<n){
        cin >> inp[i];
        i++;
    }
    int nz=0;
    int maxm=0;
    for(int i=0;i<inp.size();i++){
        if(inp[i]!=0){
            nz++;
        }
        else{
            nz=0;
        }
        if(nz>maxm){
            maxm=nz;
        }
    }
    cout << maxm << endl;
}
