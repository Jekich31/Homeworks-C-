#pragma once
#include <iostream>
#include <string>
class Parent {
protected:
	std::string name;
	std::string gender;
	std::string eyeColor;
	std::string hairColor;
	int age;

public:
	Parent();
	Parent(std::string name, int age, std::string gender,
		std::string eyeColor, std::string hairColor);
	~Parent();
	std::string getName();
	//void quarrel();
	//void think();
	virtual void breathe();
	virtual void tellSecret();
};
class Sister : public virtual Parent {
private:
	std::string sisterSecret;
public:
	Sister();
	Sister(std::string name, int age, std::string gender, std::string eyeColor, std::string hairColor,std::string sisterSecret);
	~Sister();
	void breathe() override;
	 void tellSecret() override;
};
class Brother : public virtual Parent {
private:
	std::string brotherSecret;
public:
	Brother();
	Brother(std::string name, int age, std::string gender, std::string eyeColor, std::string hairColor, std::string brotherSecret);
	~Brother();
	void breathe() override;
	 void tellSecret() override;
};
class Child : public Brother, public Sister {
private:
	std::string childSecret;
public:
	Child();
	Child(std::string name, int age, std::string gender, std::string eyeColor, std::string hairColor, std::string childSecret);
	~Child();
	void breathe() override;
	 void tellSecret() override;
};