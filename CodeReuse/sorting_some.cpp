#include <iostream>
using std::cin;
using std::cout;
using namespace std;

int compareStudentRecord(const void * voidA, const void * voidB) {
	studentRecord * recordA = (studentRecord *) voidA;
	studentRecord * recordB = (studentRecord *) voidB;
	return recordA->grade() - recordB->grade();
}

studentRecord sortArray[arraySize];
int sortArrayCount = 0;
for (int i = 0; i < arraySize; i++) {
	if (sra[i].grade() != -1) {
		sortArray[sortArrayCount] = sra[i];
		sortArrayCount++;
	}
}
qsort(sortArray, sortArrayCount, sizeof(studentRecord), compareStudentRecord);
sortArrayCount = 0;
for (int i = 0; i < arraySize; i++) {
	if (sra[i].grade() != -1) {
		sra[i] = sortArray[sortArrayCount];
		sortArrayCount++;
	}
}

int start = 0;
int end = arraySize - 1;
for(int i = start + 1; i <= end; i++){
	for(int j = i; j > start && sra[j-1].grade() > sra[j].grade(); j--){
		studentRecord temp = sra[j-1];
		sra[j-1] = sra[j];
		sra[j] = temp;
	}
}

for (int i = start + 1; i <= end; i++) {
	if (sra[i].grade() != -1) {
	int rightswap = i;
		for (int leftswap = i - 1;
		leftswap >= start
		&& (sra[leftswap].grade() > sra[rightswap].grade()
		|| sra[leftswap].grade() == -1);
		leftswap--)
		{
			if(sra[leftswap].grade() != -1) {
				studentRecord temp = sra[leftswap];
				sra[leftswap] = sra[rightswap];
				sra[rightswap] = temp;
				rightswap = leftswap;
			}
		}
	}
}