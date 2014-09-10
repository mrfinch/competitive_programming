#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct semi{
    semi(int a,bool b){
        used = b;
        num = a;
    }
    bool used;
    int num;
};
bool func(semi a,semi b){
    return a.num<b.num;
}
int main(){
    int n;
    cin >> n;
    vector<semi>a (n,semi(0,false));
    vector<semi>b (n,semi(0,false));
    int i=0;
    while(i<n){
        int t1,t2;
        cin >> t1 >> t2;
        a[i].num=t1;
        b[i].num=t2;
        i++;
    }
    for(int i=0;i<n/2;i++){
        a[i].used=true;
        b[i].used=true;
    }
    int ii=0;int jj=0;
    for(int i=0;i<n;i++){
        if(a[ii].num<b[jj].num){
            a[ii].used=true;
            ii++;
        }
        else{
            b[jj].used=true;
            jj++;
        }
    }
    vector<semi>c;
    /*c.reserve(a.size()+b.size());
    c.insert(c.end(),a.begin(),a.end());
    c.insert(c.end(),b.begin(),b.end());
    //merge(a.begin(),a.begin()+a.size(),b.begin(),b.begin()+b.size(),c.begin());
    sort(c.begin(),c.end(),func);*/
    i=0;
    int j=0;
    /*while(i<a.size() && j<b.size()){
        if(a[i].num<b[j].num){
            c.push_back(semi(a[i].num,false));
            i++;
        }
        else{
            c.push_back(semi(b[j].num,false));
            j++;
        }
    }
    while(i<a.size()){
        c.push_back(semi(a[i].num,false));
        i++;
    }
    while(j<b.size()){
        c.push_back(semi(a[i].num,false));
        j++;
    }*/
    int k=0;
    /*while(n-2*k>=0){
        int temp=n-2*k;
        for(int i=2*k-1;i<temp;i++){
            c[i].used=true;
        }
        for(int i=0;i<k;i++){
            a[i].used=true;
            b[i].used=true;
        }
        k++;
    }*/
    /*for(int i=0;i<n;i++){
        c[i].used=true;
    }
    for(int i=0;i<n/2;i++){
        a[i].used=true;
        b[i].used=true;
    }*/
    //vector<int>::iterator it;
    /*for(int j=0;j<c.size()/2;j++){
        for(int i=0;i<a.size();i++){
            if(a[i].num==c[j].num && c[j].used==true){
                a[i].used=true;
            }
        }
        for(int i=0;i<b.size();i++){
            if(b[i].num==c[j].num && c[j].used==true){
                b[i].used=true;
            }
        }
    }*/
    string s1="";
    string s2="";
    for(int i=0;i<a.size();i++){
        if(a[i].used==true){
            s1+="1";
        }
        else{
            s1+="0";
        }
    }
    for(int i=0;i<b.size();i++){
        if(b[i].used==true){
            s2+="1";
        }
        else{
            s2+="0";
        }
    }
    cout << s1 << endl;
    cout << s2 << endl;
}
