#include <iostream>
using namespace std;

class AutoMobile{
public:
	AutoMobile();
	AutoMobile(string newName, string newModelName, int newModelYear);
	
	string getName(){
		return _name;
	}
	void setName(string newName){
		_name = newName;
	}
	string getModelName(){
		return _modelName;
	}
	void setModelName(string newModelName){
		_modelName = newModelName;
	}
	int getModelYear(){
		return _modelYear;
	}
	void setModelYear(int newYear){
		_modelYear = newYear;
	}

	void toString(){
		cout << _modelYear << " " << _modelName << " " << _name << "\n";
	}

private:
	string _name;
	string _modelName;
	int _modelYear;
	int CarAge();
};

AutoMobile::AutoMobile(){
	setName("");
	setModelName("");
	setModelYear(0);
}

AutoMobile::AutoMobile(string name, string modelName, int modelYear){
	setName(name);
	setModelName(modelName);
	setModelYear(modelYear);
}

int main(){

	AutoMobile autoMobile("Bug", "Wolsvagen", 1998);
	autoMobile.toString();	

	return 0;
}