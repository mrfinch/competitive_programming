#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>&,int);

void build_heap(vector<int>& inp){
    for(int i=(inp.size()-2)/2;i>=0;i--){
        heapify(inp,i);
    }
}

void heapify(vector<int>& inp,int i){
    int l=2*i+1;
    int r=2*i+2;
    int ind=-1;
    int temp=i;
    if(l<inp.size()){
        if(inp[l]<inp[temp]){
            ind=l;
            temp=l;
        }
    }
    if(r<inp.size()){
        if(inp[r]<inp[temp]){
            ind=r;
            temp=r;
        }
    }
    if(ind!=-1){
        int t=inp[ind];
        inp[ind]=inp[i];
        inp[i]=t;
        heapify(inp,ind);
    }
}

void heap_sort(vector<int>& inp){
    if(inp.size()>0){
        cout << inp[0] << endl;
        int t=inp[0];
        inp[0]=inp[inp.size()-1];
        inp[inp.size()-1]=inp[0];
        inp.pop_back();
        heapify(inp,0);
        heap_sort(inp);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> inp(n);
    int m=0;
    while(m<n){
        cin >> inp[m];
        m++;
    }
    build_heap(inp);
    /*for(int i=0;i<inp.size();i++){
        cout << inp[i] << endl;
    }*/
    heap_sort(inp);
}
