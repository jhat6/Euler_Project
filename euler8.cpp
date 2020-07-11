#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){
    string num;  
    char cdat[1];
    int dat[1000];   
    ifstream fin;
    fin.open("number.txt");
    int cnt = 0;
    int prod;
    int max5 = 0;
    for (int i = 0; i < 20; i++){
	getline(fin, num);
	for (int j = 0; j < 50; j++){
            cdat[0] = num[j];             
            dat[cnt] = atoi(cdat);
            if (cnt > 3){
                prod = dat[cnt]*dat[cnt-1]*dat[cnt-2]*dat[cnt-3]*dat[cnt-4];             
                if (prod > max5){max5 = prod;}
                cout << max5 << endl;
            }
         cnt += 1;
	}
        cout << endl;	
   } 
   fin.close();
   return 0;
}