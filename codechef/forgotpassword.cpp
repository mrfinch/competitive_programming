#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t>0){
        int n;
        cin >> n;
        vector<char> c(n);
        vector<char> p(n);
        int m=0;
        while(m<n){
            cin >> c[m] >> p[m];
            m++;
        }
        string inp;
        cin >> inp;
        vector<bool> used(inp.size(),false);
        for(int i=0;i<c.size();i++){
            for(int j=0;j<inp.size();j++){
                if(c[i]==inp[j] && used[j]==false){
                    inp[j]=p[i];
                    used[j]=true;

                }
            }
        }
        //cout << inp << endl;
        if(inp.find(".")!=string::npos){
            int t=inp.size();
            for(int i=inp.size()-1;i>=0;i--){
                if(inp[i]=='0'){
                    t--;
                }
                else{
                    break;
                }
            }
            inp=inp.substr(0,t);
        }
        int q=0;
        for(int i=0;i<inp.size();i++){
            if(inp[i]=='0'){
                q++;
            }
            else{
                break;
            }
        }
        inp=inp.substr(q);
        if(inp[inp.size()-1]=='.'){
            inp=inp.substr(0,inp.size()-1);
        }
        if(inp.size()!=0){
        cout << inp << endl;
        }
        else{
        	cout << 0 << endl;
        }
        t--;
    }
}
