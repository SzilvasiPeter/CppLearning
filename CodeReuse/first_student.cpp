#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class studentRecord{
public:
	studentRecord();
	studentRecord(int newGrade, int newID, string newName);
	int grade();
	void setGrade(int newGrade);
	int studentID();
	void setStudentID(int newID);
	string name();
	void setName(string newName);
	string letterGrade();

private:
	int _grade;
	int _studentID;
	string _name;
	bool isValidGrade(int grade);
};

int studentRecord::grade(){
	return _grade;
}

bool studentRecord::isValidGrade(int grade){
	if((grade >= 0) && (grade <= 100))
		return true;
	else
		return false;
}

void studentRecord::setGrade(int newGrade){
	if(isValidGrade(newGrade))
		_grade = newGrade;
}

int studentRecord::studentID(){
	return _studentID;
}

void studentRecord::setStudentID(int newID){
	if(newID >= -1){
		_studentID = newID;
	}
}

string studentRecord::name(){
	return _name;
}

void studentRecord::setName(string newName){
	_name = newName;
}

studentRecord::studentRecord(int newGrade, int newID, string newName){
	setGrade(newGrade);
	setStudentID(newID);
	setName(newName);
}

studentRecord::studentRecord(){
	setGrade(0);
	setStudentID(-1);
	setName("");
}

string studentRecord::letterGrade(){
	if(!isValidGrade(_grade)) return "ERROR";
	const int NUMBER_CATEGORIES = 11;
	const string GRADE_LETTER[] = {"F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A"};
	const int LOWEST_GRADE_SCORE[] = {0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93};
	int category = 0;
	while(category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade)
		category++;
	return GRADE_LETTER[category - 1];
}

typedef bool (*firstStudentPolicy)(studentRecord r1, studentRecord r2);

bool higherGrade(studentRecord r1, studentRecord r2){
	return r1.grade() > r2.grade();
}

bool lowerStudentNumber(studentRecord r1, studentRecord r2){
	return r1.studentID() < r2.studentID();
}

bool nameComesFirst(studentRecord r2, studentRecord r2){
	return strcmp(r1.name().c_str(), r2.name().c_str()) < 0;
}

class studentCollection {
private:
struct studentNode {
	studentRecord studentData;
	studentNode * next;
};
public:
	studentCollection();
	~studentCollection();
	studentCollection(const studentCollection &original);
	studentCollection& operator=(const studentCollection& rhs);
	void addRecord(studentRecord newStudent);
	studentRecord recordWithNumber(int idNum);
	void removeRecord(int idNum);
	void setFirstStudentPolicy(firstStudentPolicy f)
	studentRecord firstStudent();
	friend class scIterator;
private:
	firstStudentPolicy _currentPolicy;
	typedef studentNode * studentList;
	studentList _listHead;
	void deleteList(studentList &listPtr);
	studentList copiedList(const studentList original);
};


studentCollection::studentCollection(){
	_listHead = NULL;
	_currentPolicy = NULL;
}

void studentCollection::addRecord(studentRecord newStudent) {
	studentNode * newNode = new studentNode;
	newNode->studentData = newStudent;
	newNode->next = _listHead;
	_listHead = newNode;
}

studentRecord studentCollection::recordWithNumber(int idNum){
	studentNode* loopPtr = _listHead;
	while(loopPtr != NULL && loopPtr->studentData.studentID() != idNum){
		loopPtr = loopPtr->next;
	}
	if(loopPtr == NULL){
		studentRecord dummyRecord(-1, -1, "");
	}else{
		return loopPtr->studentData;		
	}
}

void studentCollection::removeRecord(int idNum){
	studentNode* loopPtr = _listHead;
	studentNode* trailing = NULL;
	while(loopPtr != NULL && loopPtr->studentData.studentID() != idNum){
		trailing = loopPtr;
		loopPtr = loopPtr->next;
	}
	if(loopPtr == NULL) return;
	if(trailing == NULL){
		_listHead = _listHead->next;
	}else{
		trailing->next = loopPtr->next;
	}
	delete loopPtr;
}

void studentCollection::deleteList(studentList &listPtr){
	while(listPtr != NULL){
		studentNode* temp = listPtr;
		listPtr = listPtr->next;
		delete temp;
	}
}

studentCollection::~studentCollection(){
	deleteList(_listHead);
}

studentCollection::studentList studentCollection::copiedList(const studentList original){
	if(original == NULL){
		return NULL;
	}
	studentList newList = new studentNode;
	newList->studentData = original->studentData;
	studentNode* oldLoopPtr = original->next;
	studentNode* newLoopPtr = newList;
	while(oldLoopPtr != NULL){
		newLoopPtr->next = new studentNode;
		newLoopPtr = newLoopPtr->next;
		newLoopPtr->studentData = oldLoopPtr->studentData;
		oldLoopPtr = oldLoopPtr->next;
	}
	newLoopPtr->next = NULL;
	return newList;
}

studentCollection& studentCollection::operator=(const studentCollection &rhs){
	if(this != &rhs){
		deleteList(_listHead);
		_listHead = copiedList(rhs._listHead);
	}
	return *this;
}

studentCollection::studentCollection(const studentCollection &original){
	_listHead = copiedList(original._listHead);
}

void studentCollection::setFirstStudentPolicy(firstStudentPolicy f){
	_currentPolicy = f;
}

studentRecord studentCollection::firstStudent(){
	if(_listHead == NULL || _currentPolicy == NULL){
		studentRecord dummyRecord(-1, -1, "");
		return dummyRecord;
	}
	studentNode* loopPtr = _listHead;
	studentRecord first = loopPtr->studentData;
	loopPtr = loopPtr->next;
	while(loopPtr != NULL){
		if(_currentPolicy(loopPtr->studentData, first)){
			first = loopPtr->studentData;
		}
		loopPtr = loopPtr->next;
	}

	return first;
}

class scIterator{
public:
	scIterator();
	scIterator(studentCollection::studentNode* initial);
	void advance();
	bool pastEnd();
	studentRecord student();
private:
	studentCollection::studentNode* current;
}

scIterator::scIterator(){
	current == NULL;
}

scIterator::scIterator(studentCollection::studentNode* initial){
	current = initial;
}

scIterator studentCollection::firstItemIterator(){
	return scIterator(_listHead);
}

void scIterator::advance(){
	if(current != NULL)
		current = current->next;
}

bool scIterator::pastEnd(){
	return current == NULL;
}

studentRecord scIterator::student(){
	if(current == NULL){
		studentRecord dummyRecord(-1, -1, "");
		return dummyRecord;
	}else{
		return current->studentData;
	}
}

int main(){

	scIterator iter;
	int gradeTotal = 0;
	int numRecords = 0;
	iter = sc.firstItemIterator();
	while(!iter.pastEnd()){
		numRecords++;
		gradeTotal += iter.student().grade();
		iter.advance();
	}
	double avarage = (double) gradeTotal / numRecords;

	return 0;
}