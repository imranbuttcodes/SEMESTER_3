#pragma once
class Person
{
private:
	char* Name;
	char* countryName;
	int age;
public:
	Person();
	Person(char* Name, int age, char* countryName);
	Person(const Person& other);
	void setName(char* Name);
	void setCountry(char* countryName);
	void setAge(int age);
	int getAge() const;
	char* getName() const;
	char* getCountry() const;
	void compareAge(Person& other);
	void display();
	int strLen(char* arr);
	~Person();
};


