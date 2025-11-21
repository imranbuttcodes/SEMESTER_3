#pragma once

class Person{
private:
char* Name;
int age;
public:
static int persontCount;
Person();
Person(const char* Name,int age);
void set_Name(const char* Name);
void set_age(int age);
const char* get_name() const ;
int get_age() const;
~Person();
void dispaly() const;

};