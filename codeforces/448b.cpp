#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string s1,s2;
    cin >> s1;
    cin >> s2;
    if(s2.size()>s1.size()){
        cout << "need tree" << endl;
        return 0;
    }

    if(s1.find(s2)!=string::npos){
        cout << "automaton" << endl;
    }
    else{
        bool autom=true;
        int x=0;
        for(int i=0;i<s2.size();i++){
            int p;
            if((p=s1.find(s2[i],x))!=string::npos){
                x=p+1;
            }
            else{
                autom=false;
                break;
            }
        }
        if(autom){
            cout << "automaton" << endl;
            return 0;
        }
        vector<int> c1(26,0);
        vector<int> c2(26,0);
        for(int i=0;i<s1.size();i++){
            c1[s1[i]-'a']++;
        }
        for(int i=0;i<s2.size();i++){
            c2[s2[i]-'a']++;
        }
        bool array=true;
        for(int i=0;i<26;i++){
            if(c1[i]!=c2[i]){
                array=false;
                break;
            }
        }
        if(array){
            cout << "array" << endl;
            return 0;
        }
        bool both=true;
        for(int i=0;i<26;i++){
            if(c2[i]>c1[i]){
                both=false;
                break;
            }
        }
        if(both){
            cout << "both" << endl;
            return 0;
        }
        else{
            cout << "need tree" << endl;
        }
    }
}
