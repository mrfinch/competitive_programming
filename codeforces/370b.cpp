#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int> a,vector<int> b){
    /*cout << a.size() << "   " << b.size() << endl;
    cout << "//// \n";
    for(int i=0;i<a.size();i++){
        cout << a[i] << endl;
    }
    for(int i=0;i<b.size();i++){
        cout << b[i] << endl;
    }
    cout << "\\\\ \n";*/
    bool chk=true;
    for(int i=0;i<b.size();i++){
        for(int j=0;j<a.size();j++){
            //cout << a[j] << " " << b[i] << endl;

            if(b[i]==a[j]){
                chk=false;
                break;
            }
            //not subset
        }
        if(chk){
                //cout << "dsrdt" << endl;
                return false;
                }
                chk=true;
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    int i=0;
    vector< vector<int> > inp(n);
    while(i<n){
        int k;
        cin >> k;
        int j=0;
        while(j<k){
            int t;
            cin >> t;
            inp[i].push_back(t);
            j++;
        }
        i++;
    }
    /*
    for(int i=0;i<inp.size();i++){
        for(int j=0;j<inp[i].size();j++){
            cout << inp[i][j] << " ";
        }
        cout << endl;
    }
    */
    vector<int> out(n,false);
    for(int i=0;i<inp.size();i++){
        for(int j=0;j<inp.size();j++){
            if(i==j){
                continue;
            }
            else{
                bool subset = check(inp[i],inp[j]);
                if(subset){
                    out[i]=true;
                    //cout << i << endl;
                }
            }
        }
    }
    for(int i=0;i<out.size();i++){
        if(out[i]){
            cout << "NO"  << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
}
