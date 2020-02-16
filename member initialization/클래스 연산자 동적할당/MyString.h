#pragma once
#include <iostream>
using namespace std;


typedef char DataType;

class MyString
{
private:  //size_t가 뭐가 의미가 있을까?
	DataType *strBuf = nullptr;
	int len = 0;
	int capa = 0;

public:
	MyString();
	MyString(DataType str);
	MyString(const DataType *str);
	MyString(const MyString &_other);
	~MyString();

	int Length();
	int Capacity();
	void Out();
	

	MyString& operator= (const MyString &_right);
	MyString& operator= (const DataType *s);

	MyString& operator+=(const MyString &_right);
	MyString& operator+=(const DataType *s);

	MyString operator+ (const MyString &_right);
	MyString operator+ (const DataType *s);

	bool operator == (const MyString &_right);
	bool operator != (const MyString &_right);
	DataType & operator[](int n);

	friend  std::ostream&	operator<< (std::ostream &_cout, MyString &_right);
	friend  std::istream&   operator>> (std::istream &_cin, MyString &_right);
	friend	MyString operator+(const DataType *_left, MyString &_right);  // 이게 맴버 함수가 될 수 없어서 이렇게 햇는데 맞는 걸까? 일단 되긴 된다!

};