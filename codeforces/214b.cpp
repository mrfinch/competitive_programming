#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool myfunc(int a,int b){
    return a>b;
}

int main(){
    int n;
    cin >> n;
    vector<int> inp(n);
    int i=0;
    while(i<n){
        cin >> inp[i];
        i++;
    }
    sort(inp.begin(),inp.end(),myfunc);
    if(inp[inp.size()-1]!=0){
        cout << -1 << endl;
        return 0;
    }
    bool done=false;
    while(!done){
        int sum=0;
        if(inp.size()==0){
            break;
        }
        for(int i=0;i<inp.size();i++){
            sum+=inp[i];
        }
        int x = sum%3;
        if(x==0){
            done=true;
        }
        else if(x==1){
            done=true;
            for(int i=inp.size()-1;i>=0;i--){
                if(inp[i]%3==1){
                    inp.erase(inp.begin()+i);
                    done=false;
                    break;
                }
            }
            if(done){
                int c=0;int i1=-1;int i2=-1;
                for(int i=inp.size()-1;i>=0;i--){
                    if(inp[i]%3==2){
                        if(i1==-1){
                            i1=i;
                            c++;
                        }
                        else if(i2==-1){
                            i2=i;
                            c++;
                        }
                        if(c==2){
                            done=false;
                            break;
                        }
                    }
                }
                if(!done){
                    inp.erase(inp.begin()+i1);
                    inp.erase(inp.begin()+i2);
                }
            }
        }
        else if(x==2){
            done=true;
            for(int i=inp.size()-1;i>=0;i--){
                if(inp[i]%3==2){
                    inp.erase(inp.begin()+i);
                    done=false;
                    break;
                }
            }
            if(done){
                int c=0;int i1=-1;int i2=-1;
                for(int i=inp.size()-1;i>=0;i--){
                    if(inp[i]%3==1){
                        if(i1==-1){
                            i1=i;
                            c++;
                        }
                        else if(i2==-1){
                            i2=i;
                            c++;
                        }
                        if(c==2){
                            done=false;
                            break;
                        }
                    }
                }
                if(!done){
                    inp.erase(inp.begin()+i1);
                    inp.erase(inp.begin()+i2);
                }
            }
        }

    }
    string s;
    bool allzero=true;
    for(int i=0;i<inp.size();i++){
        if(inp[i]!=0){
            allzero=false;
        }
        s+=inp[i]+'0';
    }
    if(allzero)
        cout << 0 << endl;
    else
        cout << s <<endl;
}
