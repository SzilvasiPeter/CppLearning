#include <iostream>
using std::cin;
using std::cout;

int main(){

	for(int rows = 1; rows <= 5; rows++){
		for(int columns = 6 - rows; columns >= 1; columns--){
			cout << "#";
		}
		cout << "\n";
	}
	
	return 0;
}