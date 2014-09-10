#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t){
        int n;
        cin >> n;
        vector<int> inp(n+1,0);
        vector<bool> chk(100001,false);
        int m=1;
        int c=0;
        while(m<=n){
            cin >> inp[m];
            if(chk[inp[m]]==false){
                c++;
                chk[inp[m]]=true;
            }
            m++;
        }
        //sort(inp.begin()+1,inp.end());
        /*int j=inp[1];
        int cnt=0;
        for(int i=1;i<inp.size();i++){
            if(inp[i]==j){
                cnt++;
                j++;
            }
        }*/
        cout << c << endl;
        t--;
    }
}
