#include <iostream>
#include <map>

using namespace std;

int main(){
    int t;
    cin >> t;
    map<int,int> frnds;
    map<int,int> m_frnds;
    while(t){
        int id,n;
        cin >> id >> n;
        if(m_frnds.find(id)!=m_frnds.end()){
            m_frnds.erase(id);
        }
        frnds[id]=1;
        int m=0;
        while(m<n){
            int x;
            cin >> x;
            if(m_frnds.find(x)==m_frnds.end() && frnds.find(x)==frnds.end()){
                m_frnds[x]=1;
            }
            m++;
        }
        t--;
    }
    cout <<  m_frnds.size() << endl;
}
