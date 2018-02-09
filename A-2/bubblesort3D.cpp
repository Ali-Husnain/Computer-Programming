#include <iostream>
using namespace std;

int sorting(int array[2][2][5]){
	int temp;
	for (int i = 0 ; i < 2 ; i++ ){
		for (int j = 0 ; j < 2; j++ ){
			for (int k = 0 ; k < 5 ; k++ ){
				for (int a = 0 ; a < 2 ; a++ ){
					for (int b = 0 ; b < 2 ; b++ ){
						for (int c = 0 ; c < 5 ; c++ ){
							if (array[i][j][k] < array[a][b][c]){
								temp = array[i][j][k];
								array[i][j][k] = array[a][b][c];
								array[a][b][c] = temp;
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0 ; i < 2 ; i++ ){
		for (int j = 0 ; j < 2 ; j++ ){
			for (int k = 0 ; k < 5 ; k++ ){
				cout << array[i][j][k] << endl;
			}
		}
	}
	return 0;
}


int main(){
	int array1[2][2][5] = {{{45,23,67,1,-12},{34,43,234,567,576}},{{345,345,76,87,2},{456,789,890,32,4}}};
	sorting(array1);
}