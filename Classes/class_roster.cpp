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
	if(newGrade >= -1)
		_studentID = newID;
}

int studentRecord::name(){
	return _name;
}

void studentRecord::setName(int newName){
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

