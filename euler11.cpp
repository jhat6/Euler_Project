#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
	int mat[20][20];
	int prod;
	int maxprod;

	ifstream fin; // open stream
	// open the parameters file and read data
	fin.open("EP11_dat.txt");
	
	for (int i = 0; i < 20; i++){
		for (int j = 0; j < 20; j++){
			fin >> mat[i][j];
		}
	}

    cout << resetiosflags(ios::fixed)
    << setiosflags(ios::scientific)
    << "ios::scientific ON" << endl;
	prod = 0;
	for (int i = 0; i < 20; i++){
		for (int j = 0; j < 20; j++){
			// up
			if (i > 2){
			    prod = mat[i][j]*mat[i-1][j]*mat[i-2][j]*mat[i-3][j];
				if (prod > maxprod) {maxprod = prod;}
				// NE
				if (j  < 17){
					prod = mat[i][j]*mat[i-1][j+1]*mat[i-2][j+2]*mat[i-3][j+3];				
					if (prod > maxprod) {maxprod = prod;}
				}
				
				// NW
				if (j > 2 ){
					prod = mat[i][j]*mat[i-1][j-1]*mat[i-2][j-2]*mat[i-3][j-3];				
					if (prod > maxprod) {maxprod = prod;}
				}
			}

			// down
			if (i < 17){ 
			    prod = mat[i][j]*mat[i+1][j]*mat[i+2][j]*mat[i+3][j];
				if (prod > maxprod) {maxprod = prod;}
				// SE
				if (j < 17){
			    prod = mat[i][j]*mat[i+1][j+1]*mat[i+2][j+2]*mat[i+3][j+3];
				if (prod > maxprod) {maxprod = prod;}
				}

				// SW
				if (j > 2){
			    prod = mat[i][j]*mat[i+1][j-1]*mat[i+2][j-2]*mat[i+3][j-3];
				if (prod > maxprod) {maxprod = prod;}
				}
			}

			// left
			if (j > 2){
			    prod = mat[i][j]*mat[i][j-1]*mat[i][j-2]*mat[i][j-3];
				if (prod > maxprod) {maxprod = prod;}
			}

			//right
			if (j < 17){
			    prod = mat[i][j]*mat[i][j+1]*mat[i][j+2]*mat[i][j+3];			    
				if (prod > maxprod) {maxprod = prod;}
			}			
		}		
	}

	/*for (int i = 0; i < 20; i++){
		for (int j = 0; j < 20; j++){
			cout << mat[i][j];
			cout << endl;
		}
		cout << endl;
	}*/
	cout << "max product = "<< maxprod << endl;
	return 0;
	
}