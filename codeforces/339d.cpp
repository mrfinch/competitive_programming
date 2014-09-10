#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int main(){
    int n,m;
    cin >> n >> m;
    vector< vector<int> > inp(n+1,vector<int>());
    int num=1<<n;
    int i=0;
    while(i<num){
        int t;
        cin >> t;
        inp[0].push_back(t);
        i++;
    }
    int y=inp[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<y;j+=2){
            if(i%2==0){
                inp[i+1].push_back(inp[i][j]|inp[i][j+1]);
            }
            else{
                inp[i+1].push_back(inp[i][j]^inp[i][j+1]);
            }
        }
        y/=2;
    }
    /*for(int i=0;i<n+1;i++){
        for(int j=0;j<inp[i].size();j++){
            cout << inp[i][j] << " ";
        }
        cout << endl;
    }*/
    int k=0;
    while(k<m){
        int p,b;
        cin >> p >> b;
        inp[0][p-1]=b;
        int t=p-1;
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(t%2==0){
                    inp[i+1][t/2]=inp[i][t]|inp[i][t+1];
                    //cout << inp[i+1][t/2] << "fdg" << endl;
                }
                else{
                    inp[i+1][t/2]=inp[i][t]|inp[i][t-1];
                    //cout << inp[i+1][t/2] << "fd" << endl;
                }
            }
            else{
                if(t%2==0){
                    inp[i+1][t/2]=inp[i][t]^inp[i][t+1];
                    //cout << inp[i+1][t/2] << "f" << endl;
                }
                else{
                    inp[i+1][t/2]=inp[i][t]^inp[i][t-1];
                    //cout << inp[i+1][t/2] << "g" << endl;
                }
            }
            t/=2;
        }
        cout << inp[n][0] << endl;
        k++;
    }
}
