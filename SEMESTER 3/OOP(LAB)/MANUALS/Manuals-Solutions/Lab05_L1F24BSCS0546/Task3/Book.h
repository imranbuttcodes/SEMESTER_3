#pragma once
class Book
{
private:
	const char* title;
	char* auther;
	float price;
public:
	Book();
	Book(const char* title, char* auther, float price);
	Book(Book& other,bool isDeep);
	void setTitle(const char* title);
	void setAuther(char* auther);
	void setPrice(float price);
	const char* getTitle()const;
	char* getAuther() const;
	float getPrice()const;
    void display() const;
    void applyDiscount(double percentage);
    ~Book();
    float average(Book *arr,int size);
    int strLen(char* arr);
    char* copyData(char* arr);
};

