#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    while(true){
        int n1,n2;
        cin >> n1;
        if(n1==0){
            break;
        }
        vector<int> a(n1);
        int m=0;
        map<int,int> m1;
        while(m<n1){
            cin >> a[m];
            m1[a[m]]++;
            m++;
        }
        cin >> n2;
        vector<int> b(n2);
        //map<int,int> m2;
        m=0;
        while(m<n2){
            cin >> b[m];
            m1[b[m]]++;
            m++;
        }
        vector<int> d1;
        int s=0;
        bool add=false;
        for(int i=0;i<a.size();i++){
            if(m1[a[i]]==2){
                s+=a[i];
                d1.push_back(s);
                s=0;
                add=false;
            }
            else{
                s+=a[i];
                add=true;
            }
        }
        if(add){
            d1.push_back(s);
        }
        s=0;
        vector<int> d2;
        add=false;
        for(int i=0;i<b.size();i++){
            if(m1[b[i]]==2){
                s+=b[i];
                d2.push_back(s);
                s=0;
                add=false;
            }
            else{
                s+=b[i];
                add=true;
            }
        }
        if(add){
            d2.push_back(s);
        }
        int x=min(d2.size(),d1.size());
        long long res=0;
        for(int i=0;i<x;i++){
            if(d1[i]>d2[i]){
                res+=d1[i];
            }
            else{
                res+=d2[i];
            }
        }
        if(d2.size()>d1.size()){
            if(d2[d2.size()-1]>0)
                res+=d2[d2.size()-1];
        }
        if(d1.size()>d2.size()){
            if(d1[d1.size()-1]>0)
                res+=d1[d1.size()-1];
        }
        cout << res << endl;
    }

}
