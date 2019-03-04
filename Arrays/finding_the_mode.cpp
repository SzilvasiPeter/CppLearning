#include <iostream>
using std::cin;
using std::cout;

int main(){

	// Histogram
	const int MAX_RESPONSE = 10;
	int histrogram[MAX_RESPONSE];
	for(int i = 0; i < MAX_RESPONSE; i++){
		histrogram[i] = 0;
	}
	for(int i = 0; i < MAX_RESPONSE; i++){
		histrogram[surveyData[i] - 1]++;
	}

	const int ARRAY_SIZE = 12;
	int surveyData[ARRAY_SIZE] = {4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10};

	int mostFrequent = 0;
	for(int i = 1; i < MAX_RESPONSE; i++){
		if(histrogram[i] > histrogram[mostFrequent]) mostFrequent = 1;
	}
	mostFrequent++;
	
	int highestFrequency = ?;
	int currentFrequency = 0;
	for (int i = 0; i < ARRAY_SIZE; i++){
		currentFrequency++;
		//if(surveyData[i] IS LAST OCCURENCE OF A VALUE){
		if(i == ARRAY_SIZE - 1 || surveyData[i] != surveyData[i + 1]){
			if(currentFrequency > highestFrequency){
				highestFrequency = currentFrequency;
				mostFrequent = surveyData[i];
			}
			currentFrequency = 0;
		}
	}

	return 0;
}