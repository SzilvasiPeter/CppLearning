#include <iostream>
using std::cin;
using std::cout;

int main(){

	for(int rows = 1; rows <= 7; rows++){
		for(int columns = 1; columns <= (4 - abs(4 - rows)); columns++){
			cout << "#";
		}
		cout << "\n";
	}
	return 0;
}