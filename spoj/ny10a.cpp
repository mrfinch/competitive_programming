#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> out(8,0);
        //cout << s.size() << endl;
        for(int i=0;i<=s.size()-3;i++){
        	//cout << s.substr(i,3) << endl;
            string x=s.substr(i,3);
            if(x.find("TTT")!=string::npos){
                out[0]++;
            }
            if(x.find("TTH")!=string::npos){
                out[1]++;
            }
            if(x.find("THT")!=string::npos){
                out[2]++;
            }
            if(x.find("THH")!=string::npos){
                out[3]++;
            }
            if(x.find("HTT")!=string::npos){
                out[4]++;
            }
            if(x.find("HTH")!=string::npos){
                out[5]++;
            }
            if(x.find("HHT")!=string::npos){
                out[6]++;
            }
            if(x.find("HHH")!=string::npos){
                out[7]++;
            }
        }
        cout << n << " ";
        for(int i=0;i<out.size();i++){
            cout << out[i] << " ";
        }
        cout << endl;
        t--;
    }
}

