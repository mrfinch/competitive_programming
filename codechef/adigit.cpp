#include <iostream>
#include <vector>
#include <string>
using namespace std;
//not complete
int main(){
    int n,m;
    cin >> n >> m;
    vector< vector<int> > inp(10,vector<int>(m+1,0));
    string s;
    cin >> s;
    for(int i=0;i<inp.size();i++){
        for(int j=1;j<=s.size();j++){
            inp[i][j]=inp[i][j-1];
            if(s[j-1]-'0'==i){
                inp[i][j]++;
            }
        }
    }
    int k=0;
    while(k<m){
        int ind;
        cin >> ind;
        int val=s[ind+1]-'0';
        int b1=0;
        for(int i=0;i<val-1;i++){
            cout << inp[i][ind-1] << endl;
            b1+=(inp[i][ind-1]*(val-i));
        }
        int b2=0;
        for(int i=val+1;i<9;i++){
            cout << inp[i][ind-1] << endl;
            b2+=(inp[i][ind-1]*(val-i));
        }
        k++;
        cout << (b1-b2) << endl;
    }
}
