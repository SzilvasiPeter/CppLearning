#include <iostream>
using namespace std;

int iterativeArraySum(int integers[], int size){
	int sum = 0;
	for(int i = 0; i < size; i++){
		sum += integers[i];
	}

	return sum;
}

int arraySumDelegate(int integers[], int size){
	if(size == 0) return 0;
	int lastNumber = integers[size - 1];
	int allButLastSum = iterativeArraySum(integers, size - 1);

	return lastNumber + allButLastSum;
}

int arraySumRecursive(int integers[], int size){
	if(size == 0) return 0;
	int lastNumber = integers[size - 1];
	int allButLastSum = arraySumRecursive(integers, size - 1);

	return lastNumber + allButLastSum;
}

int zeroCountIterative(int numbers[], int size){
	int sum = 0;
	int count = 0;
	for(int i = 0; i < size; i++){
		if(numbers[i] == 0) count ++;
	}
	return count;
}

int zeroCountRecursive(int numbers[], int size){
	if(size == 0) return 0;
	int count = zeroCountRecursive(numbers, size - 1);
	if(numbers[size - 1] == 0) count ++;
	
	return count;
}

int zeroCountStatic(int numbers[], int size){
	static int count = 0;
	if(size == 0) return 0;
	if(numbers[size - 1] == 0) count ++;
	zeroCountStatic(numbers, size - 1);
}