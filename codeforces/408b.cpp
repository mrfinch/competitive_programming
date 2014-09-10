#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string in,out;
	cin >> in;
	cin >> out;
	vector<int> c(27,0);
	char a[] = {' ','a','b','c','d','e','f','g','h','i','j','k',
	'l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	//vector<string> ch(a,a+sizeof(a)/sizeof(int) );
	for(int i=0;i<in.size();i++){
		if(in[i]=='a'){
			c[1]++;
		}
		else if(in[i]=='b'){
			c[2]++;
		}
		else if(in[i]=='c'){
			c[3]++;
		}
		else if(in[i]=='d'){
			c[4]++;
		}
		else if(in[i]=='e'){
			c[5]++;
		}
		else if(in[i]=='f'){
			c[6]++;
		}
		else if(in[i]=='g'){
			c[7]++;
		}
		else if(in[i]=='h'){
			c[8]++;
		}
		else if(in[i]=='i'){
			c[9]++;
		}
		else if(in[i]=='j'){
			c[10]++;
		}
		else if(in[i]=='k'){
			c[11]++;
		}
		else if(in[i]=='l'){
			c[12]++;
		}
		else if(in[i]=='m'){
			c[13]++;
		}
		else if(in[i]=='n'){
			c[14]++;
		}
		else if(in[i]=='o'){
			c[15]++;
		}
		else if(in[i]=='p'){
			c[16]++;
		}
		else if(in[i]=='q'){
			c[17]++;
		}
		else if(in[i]=='r'){
			c[18]++;
		}
		else if(in[i]=='s'){
			c[19]++;
		}
		else if(in[i]=='t'){
			c[20]++;
		}
		else if(in[i]=='u'){
			c[21]++;
		}
		else if(in[i]=='v'){
			c[22]++;
		}
		else if(in[i]=='w'){
			c[23]++;
		}
		else if(in[i]=='x'){
			c[24]++;
		}
		else if(in[i]=='y'){
			c[25]++;
		}
		else if(in[i]=='z'){
			c[26]++;
		}

	}
	int ct = 0;
	for(int i=1;i<27;i++){
		int temp = count(out.begin(),out.end(),a[i]);
		if(temp==0){

		}
		else if(temp > 0){
			if(count(in.begin(),in.end(),a[i])<1){
				cout << -1 << endl;
				return 0;
			}
			ct += min(temp,count(in.begin(),in.end(),a[i]));
		}
	}
	cout << ct << endl;
}
