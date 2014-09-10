#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(){
    while(true){
        string a;
        getline(cin,a);
        if(a[0]=='*'){
            break;
        }
        bool emty=true;;
        for(int i=0;i<a.size();i++){
            if(a[i]!=' '){
                emty=false;
                break;
            }
        }
        if(emty)
            continue;
        char c;
        int i;
        for(i=0;i<a.size();i++){
            if(a[i]==' '){
                continue;
            }
            else{
                c=tolower(a[i]);
                break;
            }
        }
        bool t=true;
        bool chk=false;
        for(;i<a.size();i++){
            if(a[i]==' '){
                chk=true;
            }
            else if(a[i]!=' ' && chk==true){
                if(tolower(a[i])!=c){
                    t=false;
                    break;
                }
                else{
                    chk=false;
                }
            }
        }
        if(t)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
}
