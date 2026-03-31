#include "inheritance.h"

using namespace std;
//parent logic
Parent::Parent() : Parent("unknown", 1, "unknown", "unknown", "unknown") {}

Parent::Parent(std::string name, int age, std::string gender,
	std::string eyeColor, std::string hairColor) {
	this->name = name;
	this->age = age;
	this->gender = gender;
	this->eyeColor = eyeColor;
	this->hairColor = hairColor;
}
Parent::~Parent() {
	cout << "\nParent destructor\n";
}
std::string Parent::getName() {
	return this->name;
}
void Parent::breathe() {
	cout << "\nParent is breathing\n";
}
void Parent::tellSecret() {
	cout << "No secret";
}


//sister logic
Sister::Sister() {
	this->sisterSecret = "unknown";
}
Sister::Sister(string name, int age, string gender, string eyeColor,string hairColor, string sisterSecret)
: Parent(name,age,gender,eyeColor,hairColor){
	this->sisterSecret = sisterSecret;
}
Sister::~Sister() {
	cout << "\nSister destructor\n";
}
void Sister::breathe() {
	cout << "\Sister is breathing\n";
}
void Sister::tellSecret() {
	cout << "Sister's secret is: " << this->sisterSecret<<endl;
}



//brother logic
Brother::Brother() {
	this->brotherSecret = "unknown";


}
Brother::Brother(string name, int age, string gender, string eyeColor, string hairColor, string brotherSecret)
	: Parent(name, age, gender, eyeColor, hairColor) {
	this->brotherSecret = brotherSecret;
}
Brother::~Brother() {
	cout << "\Brother destructor\n";
}
void Brother::breathe() {
	cout << "\Brother is breathing\n";
}
void Brother::tellSecret() {
	cout<<"Brother secret is: "<<this->brotherSecret<<endl;
}


//child logic
Child::Child() {
	this->childSecret = "unknown";
}
Child::Child(string name, int age, string gender, string eyeColor, string hairColor, string childSecret)
	: Parent(name, age, gender, eyeColor, hairColor) {
	this->childSecret = childSecret;
}
Child::~Child() {
	cout << "\nChild destructor\n";
}
void Child::breathe() {
	cout << "\nChild is breathing\n";
}
void Child::tellSecret() {
	cout << "\nChild's secret is: " << childSecret << endl;
}