#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct matrix{
    /*matrix(string x,bool y){
        w=x;
        u=y;
    }*/
    char w;
    bool u;
};

int main(){
    int n;
    cin >> n;
    vector< vector<matrix> > inp(n,vector<matrix>(n));
    int i=0;
    int cnt=0;
    while(i<n){
        int j=0;
        while(j<n){
            char temp;
            cin >> temp;
            inp[i][j].w=temp;
            inp[i][j].u=false;
            j++;
            if(temp=='#'){
                cnt++;
            }
        }
        i++;
    }
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << inp[i][j].w;
        }
        cout << endl;
    }*/
    if(cnt%5!=0){
        cout << "NO" << endl;
        return 0;
    }

    for(int i=1;i<inp.size()-1;i++){
        for(int j=1;j<inp.size()-1;j++){
            if(inp[i][j-1].w=='#' && inp[i][j+1].w=='#' && inp[i+1][j].w=='#' && inp[i-1][j].w=='#' && inp[i][j].w=='#' &&
                inp[i][j-1].u==false && inp[i][j+1].u==false && inp[i+1][j].u==false && inp[i-1][j].u==false && inp[i-1][j].u==false){
                inp[i][j-1].u=true;
                inp[i][j+1].u=true;
                inp[i+1][j].u=true;
                inp[i-1][j].u=true;
                inp[i][j].u=true;
            }
        }
    }
    for(int i=0;i<inp.size();i++){
        for(int j=0;j<inp.size();j++){
            if(inp[i][j].w=='#' && inp[i][j].u==false){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
}
