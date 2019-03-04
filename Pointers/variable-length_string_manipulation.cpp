#include <iostream>
using std::cin;
using std::cout;

typedef char* arrayString;

int length(arrayString s){
	int count = 0;
	while(s[count] != 0){
		count++;
	}
	return count;
}

int howManyReplace(arrayString source, arrayString target, arrayString replace){
	int count = 0;
	int howMany = 0;
	for(int i = 0; i < length(source); i++){
		if(source[i] == target[0]){
			for(int j = 0; j < length(target); j++){
				if(source[i + j] == target[j]){
					count++;
				}
			}
			if(count == length(target)){
				howMany++;
				count = 0;
			}
		}
	}

	return howMany;
}

char characterAt(arrayString s, int position){
	if(position < 0 || position >= length(s)){
		cout << "The position is not valid";
		return '0';
	}
	return s[position];
}

void append(arrayString& s, char c){
	int oldLength = length(s);
	arrayString newS = new char[oldLength + 2];
	for (int i = 0; i < oldLength; i++){
		newS[i] = s[i];
	}
	newS[oldLength] = c;
	newS[oldLength + 1] = 0;
	delete[] s;
	s = newS;
}

void concatenate(arrayString& s1, arrayString s2){
	int s1_OldLength = length(s1);
	int s2_Length = length(s2);
	int s1_NewLength = s1_OldLength + s2_Length;
	arrayString newS = new char[s1_NewLength + 1];
	for(int i = 0; i < s1_OldLength; i++){
		newS[i] = s1[i];
	}
	for(int i = 0; i < s2_Length; i++){
		newS[s1_OldLength + i] = s2[i];
	}

	newS[s1_NewLength] = 0;
	delete[] s1;
	s1 = newS;
}

void replaceString(arrayString& source, arrayString target, arrayString replaceText){
	int sourceLength = length(source);
	int targetLength = length(target);
	int replaceTextLength = length(replaceText);

	int lengthDifference = replaceTextLength - targetLength;
	int howMany = howManyReplace(source, target, replaceText);

	int count = 0;
	int newLength = sourceLength + (howMany * lengthDifference) + 1;
	cout << newLength << "," << targetLength << "," << replaceTextLength << "\n";
	if(newLength != sourceLength){
		arrayString newString = new char[newLength];
		int diff = 0;
		for(int i = 0; i < sourceLength; i++){
		cout << "current01 i: " << i << "\n";
			if(source[i] != target[0]){
				cout << "if1 branch" << "\n";
				newString[i + diff] = source[i];
			}else{
				cout << "else1 branch" << "\n";
				for(int j = 0; j < targetLength; j++){
					if(source[i + j] == target[j]){
						count++;
					}
				}
				if(count != targetLength){
					cout << "if2 branch" << "\n";
					cout << "source[i]: " << source[i] << "\n";
					cout << "newString[i + diff]: " << newString[i + diff] << "\n";
					newString[i + diff] = source[i];
					cout << "newString[i + diff]: " << newString[i + diff] << "\n";
					count = 0;
				}else{
					cout << "else2 branch" << "\n";
					for(int k = 0; k < replaceTextLength; k++){
						newString[i + k] = replaceText[k];
					}
					count = 0;
					i += targetLength - 1;
					diff += lengthDifference;
				}
			}
		cout << "current02 i: " << i << "\n";
		cout << "diff" << diff << "\n\n";
		}
		newString[newLength] = 0;
		delete[] source;
		source = newString;
	}
	
}

void appendTester(){
	arrayString a = new char[5];
	a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
	append(a, '!');
	cout << a << "\n";
	// arrayString b = new char[1];
	// b[0] = 0;
	// append(b, '!');
	// cout << b << "\n";
}

void concatenateTester(){
	arrayString a = new char[5];
	a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
	arrayString b = new char[4];
	b[0] = 'b'; b[1] = 'e'; b[2] = 'd'; b[3] = 0;
	concatenate(a,b);
	cout << a << "\n";
	// arrayString a = new char[5];
	// a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
	// arrayString c = new char[1];
	// c[0] = 0;
	// concatenate(a, c);
	// cout << a << "\n" << c << "\n";
	// cout << (void *) a << "\n" << (void *) c << "\n";
}

void replaceStringTester(){
	arrayString a = new char[9];
	a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 'e'; a[5] = 'e'; a[6] = 's'; a[7] = 'b'; a[8] = 0;
	arrayString b = new char[3];
	b[0] = 'e'; b[1] = 's'; b[2] = 0;
	arrayString c = new char[4];
	c[0] = 'x'; c[1] = 'y'; c[2] = 'z'; c[3] = 0;
	replaceString(a, b, c);
	cout << a << "\n";
}

int main(){

	appendTester();
	concatenateTester();
	replaceStringTester();

	return 0;
}