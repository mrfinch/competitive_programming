#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int main(){
    string s1,s2;
    cin >> s1;
    cin >> s2;
    //cout << s1.size() << " " << s2.size() << endl;
    vector< vector<int> > chk(s1.size()+1,vector<int>(s2.size()+1,0));
    int m = INT_MIN;
    if(s1[0]==s2[0]){
        chk[1][1]=1;
        m=1;
    }
    if(s1[s1.size()-1]==s2[s2.size()-1]){
        chk[s1.size()][s2.size()]=1;
        m+=1;
    }
    for(int i=1;i<s1.size()-1;i++){
        for(int j=1;j<s2.size()-1;j++){
            chk[i+1][j+1]=(s1[i]==s2[j])?(1+chk[i][j]):0;
            //cout << chk[i+1][j+1] << endl;
            if(chk[i+1][j+1]>m){
                m=chk[i+1][j+1];
            }
        }
    }
    /*
    if(s2.find(s1[0])!=string::npos && s2.find(s1[s1.size()-1])!=string::npos && m!=s2.size()){
        m+=2;
    }*/
    //int max=chk[s1.size()][s2.size()];
    int out = s2.size()-m;
    cout << out << endl;
}
