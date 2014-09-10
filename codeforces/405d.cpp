#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int i=0;
    vector<int> chk(1e6+1,0);
    vector<int> inp;
    //cout << 10e6 << endl;
    int s=1e6;
    int cnt=0;
    vector<int> out;

    while(i<n){
        int t;
        scanf("%d",&t);
        if(chk[s-t+1]==0){
            chk[s-t+1]=2;
            chk[t]=2;
            out.push_back(s-t+1);
            cnt++;
        }
        else{
            chk[t]=1;
            inp.push_back(t);
        }
        i++;
    }
    int m=inp.size();
    for(int i=0;i<m;i++){
        if(chk[inp[i]]==2){
            continue;
        }
        else{
            chk[s-inp[i]+1]=2;
            int m=chk.size();
            for(int i=1;i<m;i++){
                if(chk[i]==false && chk[s-i+1]==false){
                    out.push_back(i);
                    out.push_back(s-i+1);
                    chk[i]=2;
                    chk[s-i+1]=2;
                    cnt+=2;
                    break;
                }
            }
        }
    }
    printf("%d\n",cnt);
    int h=out.size();
    for(int i=0;i<h;i++){
        printf("%d ",out[i]);
    }
    printf("\n");
}
