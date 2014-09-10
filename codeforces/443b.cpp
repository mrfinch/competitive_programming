#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    string t=s;
    for(int i=0;i<k;i++){
        t+="/";
    }
    int mm=0;
    for(int i=0;i<t.size();i++){
        for(int j=1;j<t.size();j++){
            int cnt=0;
            if(t.size()-j<0){
                break;
            }
            int nn=2*j;
            for(int k=0;k<t.size()-j;k++){
                if(t[k]==t[k+j] || t[k+j]=='/'){
                    cnt+=2;
                    if(cnt>nn){
                        cnt=nn;
                    }
                    if(cnt>mm)
                        mm=cnt;
                }
                else{
                    cnt=0;
                }
            }
        }
    }
    cout << mm << endl;
}
