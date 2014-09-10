#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;
    vector<int> inp(n);
    int i=0;
    while(i<n){
        fin >> inp[i];
        i++;
    }
    sort(inp.begin(),inp.end());
    int mi = 1e5;
    for(int i=0;i<inp.size();i++){
        int p=0;
        for(int j=i+1,k=inp.size()-1;j<=k;){
            int mid=(j+k)/2;
            if(inp[mid]<=2*inp[i]){
                if(mid>p){
                    p=mid;
                }
                j=mid+1;
            }
            else{
                k=mid-1;
            }
            //cout << i << j << mid << endl;
        }
        if(inp.size()-(p-i+1)<mi){
            mi=inp.size()-(p-i+1);
        }
    }
    fout << mi << endl;
}
