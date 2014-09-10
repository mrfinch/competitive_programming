#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> inp(n,0);
    int m=0;
    while(m<n){
        cin >> inp[m];
        m++;
    }
    string out = "";
    bool loop=false;
    int i=0;
    while(!loop){
        if(i==0){
            for(i=0;i<inp.size();i++){
                if(inp[i]>0){
                    inp[i]--;
                    out+="P";
                }
                if(i!=inp.size()-1){
                    out+="R";
                }
                else{
                    out+="L";
                }
            }
        }
        if(i==1){
            for(i=1;i<inp.size();i++){
                if(inp[i]>0){
                    inp[i]--;
                    out+="P";
                }
                if(i!=inp.size()-1){
                    out+="R";
                }
                else{
                    out+="L";
                }
            }
        }
        if(i==inp.size()){
            for(i=inp.size()-2;i>=0;i--){
                if(inp[i]>0){
                    inp[i]--;
                    out+="P";
                }
                if(i==0){
                    out+="R";
                }
                else{
                    out+="L";
                }
            }
        }
        loop=true;
        for(i=0;i<inp.size();i++){
            if(inp[i]>0){
                loop=false;
                break;
            }
        }
        i=1;
        //cout << out << endl;
    }

    //cout << out << endl;
    out = out.substr(0,out.find_last_of("P")+1);
    cout << out << endl;
}
