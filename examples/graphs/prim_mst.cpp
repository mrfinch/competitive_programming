#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findMin(vector<int> key,vector<bool> vis){
    int ind=0;
    int min=INT_MAX;
    for(int i=0;i<key.size();i++){
        if(key[i]<min && vis[i]==false){
            min=key[i];
            ind=i;
        }
    }
    return ind;
}

void prim_mst(vector< vector<int> > inp,int n){
    vector<bool> vis(n,false);
    vector<int> key(n,INT_MAX);
    vector<int> parent(n,-1);
    //vis[0]=true;
    key[0]=0;
    for(int i=1;i<n;i++){
        int min_ind = findMin(key,vis);
        //cout << min_ind << "vf" << endl;
        vis[min_ind]=true;
        for(int i=0;i<inp[min_ind].size();i++){

            if(vis[i]==false && inp[min_ind][i]<key[i] && inp[min_ind][i]>0){
            	//cout << i << " " << min_ind <<endl;
                parent[i]=min_ind;
                key[i]=inp[min_ind][i];
            }
        }
    }
    for(int i=1;i<n;i++){
    	//cout << parent[i] << endl;
        cout << parent[i] << "-" << i << " wt:" << inp[parent[i]][i] << endl;
    }
}

int main(){
    int n;
    cin >> n;
    vector< vector<int> > inp(n,vector<int>(n,0));
    int i=0;
    while(i<n){
        int j=0;
        while(j<n){
            cin >> inp[i][j];
            j++;
        }
        i++;
    }
    prim_mst(inp,inp.size());
}
