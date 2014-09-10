#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string s1,s2;
    cin >> s1;
    cin >> s2;
    vector<int> cnts2(26,0);
    for(int i=0;i<s2.size();i++){
        cnts2[s2[i]-'a']++;
    }
    if(s2.size()>s1.size()){
        cout << 0 << endl;
        return 0;
    }
    int cnt=0;
    //cout << "fes";
    bool v=false;
    for(int i=0;i<s1.size();i++){
        if(s1[i]!='?'){
            v=true;
            break;
        }
    }
    if(!v){
        cout << s1.size()-s2.size()+1 << endl;
        return 0;
    }
    v=false;
    for(int i=0;i<s1.size()-1;i++){
        if(s1[i]!=s1[i+1]){
            v=true;
            break;
        }
    }
    bool p =false;
    if(v==false){
        for(int i=0;i<s2.size();i++){
            if(s2[i]!=s1[0] && s1[0]!='?'){
                p=true;
                break;
            }
        }
        if(p==false){
            cout << s1.size()-s2.size()+1 << endl;
            return 0;
        }
    }
    vector<int> cnts1(26,0);
    for(int i=0;i<=s1.size()-s2.size();i++){
        for(int j=i;j<(i+s2.size()) && j<s1.size();j++){
            //cout << "sf" << i+s2.size() << " " << j << s1[j] << endl;
            if(s1[j]=='?')
                continue;
            cnts1[s1[j]-'a']++;
        }
        //int c1=0;
        bool x=false;
        for(int i=0;i<26;i++){
            //cout << cnts1[i] << cnts2[i] << endl;
            if(cnts1[i]>cnts2[i]){
                x=true;
                break;
            }
        }
        if(!x)
            cnt++;
        //fill(cnts1.begin(),cnts2.end(),0);
        //cout << i << " " << cnt << endl;

        for(int i=0;i<cnts1.size();i++){
            cnts1[i]=0;
        }
    }
    cout << cnt << endl;
}

