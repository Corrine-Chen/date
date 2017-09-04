#pragma once
#include<iostream>
using namespace std;

#define  months  13
#define  years    2

extern char dateTable[years][months] ;


class Date
{
public:
        Date(int year = 2017, int month = 1 , int day = 1);
        Date(const Date& d);
        Date& operator=(const Date& d);
	bool operator<(const Date& d);
	bool operator>(const Date& d);
	bool operator<=(const Date& d);
	bool operator>=(const Date& d);
	bool operator!=(const Date& d);
	bool operator==(const Date& d);

        // ��ǰ����day��������
	Date operator+(int days);

        // ��ǰ����day��ǰ������
	Date operator-(int days);

        // ����������֮�������� 
	int operator-(const Date& d);


	// ǰ��++
	Date& operator++();

	// ����++
	Date operator++(int);
	
	// ǰ��--
	Date& operator--();

	// ����--
	Date operator--(int);

        ~Date();

private:
	int _year;
	int _month;
	int _day;
};
