/*

uppercase mode: modulo 27
lowercase mode: modulo 27
punctuation mode: modulo 9

*/

#include <iostream>
using std::cin;
using std::cout;

int main(){

	char outputCharacter;
	enum modeType {UPPERCASE, LOWERCASE, PUNCTUATION};
	modeType mode = UPPERCASE;
	const char punctuation[8] = {'!', '?', ',', '.', ' ', ';', '"', '\''};
	char digitChar;

	do{
		digitChar = cin.get();
		int number = (digitChar - '0');
		digitChar = cin.get();
		while((digitChar != 10) && (digitChar != ',')){
			number = number * 10 + (digitChar - '0');
			digitChar = cin.get();
		}
		switch(mode){
			case UPPERCASE:
				number = number % 27;
				outputCharacter = number + 'A' - 1;
				if(number == 0){
					mode = LOWERCASE;
					continue;
				}
				break;
			case LOWERCASE:
				number = number % 27;
				outputCharacter = number + 'a' - 1;
				if (number == 0){
					mode = PUNCTUATION;
					continue;
				}
				break;
			case PUNCTUATION:
				number = number % 9;
				outputCharacter = punctuation[number - 1];
				if(number == 0){
					mode = UPPERCASE;
					continue;
				}
				break;
		}
		cout << outputCharacter;
	} while(digitChar != 10);
	cout << "\n";

	return 0;
}