#include <iostream>
#include <string>
#include <cctype>
#include <cstdio>
using namespace std;

int main(){
    string inp;
    while(getline(cin,inp)){
        bool c=false;
        bool j=false;
        bool cons=false;
        for(int i=0;i<inp.size();i++){
            if(inp[i]=='_'){
                c=true;
                if(i>0 && inp[i-1]=='_'){
                    cons=true;
                }
            }
            else if(isupper(inp[i])){
                j=true;
            }
        }
        if(isupper(inp[0])){
            cout << "Error!" << endl;
        }
        else if(inp[inp.size()-1]=='_' || inp[0]=='_' || cons==true || isupper(inp[0])){
            cout << "Error!" << endl;
        }
        else if(c && j){
            cout << "Error!" << endl;
        }
        else if(!c && !j){
            cout << inp << endl;
        }
        else if(c){
            string out="";
            bool upp=false;
            for(int i=0;i<inp.size();i++){
                if(inp[i]=='_'){
                    upp=true;
                }
                else{
                    if(upp){
                        out+=toupper(inp[i]);
                    }
                    else{
                        out+=inp[i];
                    }
                    upp=false;
                }
            }
            cout << out << endl;
        }
        else if(j){
            string s;
            for(int i=0;i<inp.size();i++){
                if(isupper(inp[i])){
                    s+="_";
                    s+=tolower(inp[i]);
                }
                else{
                    s+=inp[i];
                }
            }
            cout << s << endl;
        }
    }
}
