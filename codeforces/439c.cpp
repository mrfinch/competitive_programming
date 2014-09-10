#include <iostream>
#include <vector>
//Not complete-WA
using namespace std;
typedef long long ll;
int main(){
    int n,k,p;
    cin >> n >> k >> p;
    vector<ll> inp(n);
    vector<ll> even;
    vector<ll> odd;
    int m=0;
    ll sum=0;
    while(m<n){
        cin >> inp[m];
        sum+=inp[m];
        if(inp[m]%2==0){
            even.push_back(inp[m]);
        }
        else{
            odd.push_back(inp[m]);
        }
        m++;
    }
    int numodd = k-p;
    if(odd.size()<numodd){
        cout << "NO" << endl;
        return 0;
    }
    if(even.size()+odd.size()-numodd<p){
        cout << "NO" << endl;
        return 0;
    }
    /*
    if(sum%2!=numodd%2){
        cout << "NO" << endl;
        return 0;
    }
    int oddused = (max(p-even.size(),even.size()-p))*2;
    int oddleft = odd.size()-oddused;
    if(oddleft<numodd){
        cout << "NO" << endl;
        return 0;
    }*/

    int ii=0;
    int jj=0;
    int i=0;
    int num=0;
    while(i<p){
        if(ii<even.size()){
            //cout << 1 << " " << even[ii] << endl;
            ii++;
            i++;
            num++;
        }
        else{
            //cout << 2 << " " << odd[jj] << " " << odd[jj+1] << endl;
            jj+=2;
            i++;
            num++;
        }
    }
    i=0;
    int temp = jj;
    while(i<numodd-1){
        //cout << 1 << " " << odd[jj] << endl;
        jj++;
        i++;
        num++;
    }
    int remelem = (even.size()-ii)+(odd.size()-jj);
    i=0;
    if(remelem<=0 && num!=k){
        cout << "NO" << endl;
        return 0;
    }
    if((odd.size()-jj)%2==0 && (odd.size()-jj)!=0){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for(int i=0;i<ii;i++){
        cout << 1 << " " << even[i] << endl;
    }
    for(int i=0;i<temp;i+=2){
        cout << 2 << " " << odd[i] << " " << odd[i+1] << endl;
    }
    for(int i=temp;i<jj;i++){
        cout << 1 << " " << odd[i] << endl;
    }
    if(remelem>0){
	    cout << remelem << " ";
	    for(int j=ii;j<even.size();j++){
	        cout << even[j] << " ";
	    }
	    for(int j=jj;j<odd.size();j++){
	        cout << odd[j] << " ";
	    }
	    cout << endl;
    }
}
