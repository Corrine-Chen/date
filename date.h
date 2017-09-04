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

        // 求当前日期day天后的日期
	Date operator+(int days);

        // 求当前日期day天前的日期
	Date operator-(int days);

        // 求两个日期之间差看多少天 
	int operator-(const Date& d);


	// 前置++
	Date& operator++();

	// 后置++
	Date operator++(int);
	
	// 前置--
	Date& operator--();

	// 后置--
	Date operator--(int);

        ~Date();

private:
	int _year;
	int _month;
	int _day;
};
