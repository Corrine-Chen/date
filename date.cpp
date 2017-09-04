#include"date.h"

char dateTable[years][months] = {
	{0,31,28,31,30,31,30,31,31,30,31,30,31},  //平年
	{0,31,29,31,30,31,30,31,31,30,31,30,31}   //闰年
};

static bool IsLeapYear(int year)
{
	if(year%4==0&&year%100!=0||year%400==0)
	{
		return true;
	}
	return false;
}

Date::Date(int year , int month  , int day )
	:_year(year)
	,_month(month)
	,_day(day)
{}
Date::Date(const Date& d)
{
	this->_year=d._year;
	this->_month=d._month;
	this->_day=d._day;
}
Date& Date::operator=(const Date& d)
{
	if(this==&d)
		return *this;
	else
	{
		this->_year=d._year;
		this->_month=d._month;
		this->_day=d._day;
		return *this;
	}

}
bool Date:: operator<(const Date& d)
{
	if(this->_year < d._year)
	{
		return true;
	}
	else if(this->_year==d._year)
	{
		if(this->_month<d._month)
		{
			return true;
		}
		else if(this->_month==d._month)
		{
			if(this->_day<d._day)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
bool Date:: operator>(const Date& d)
{
	if(this->_year > d._year)
	{
		return true;
	}
	else if(this->_year==d._year)
	{
		if(this->_month>d._month)
		{
			return true;
		}
		else if(this->_month==d._month)
		{
			if(this->_day>d._day)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Date:: operator>=(const Date& d)
{
	if(this->_year>d._year)
	{
		return true;
	}
	else if(this->_year==d._year)
	{
		if(this->_month>d._month)
		{
			return true;
		}
		else if(this->_month==d._month)
		{
			if(this->_day>=d._day)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
bool Date:: operator<=(const Date& d)
{
	if(this->_year<d._year)
	{
		return true;
	}
	else if(this->_year==d._year)
	{
		if(this->_month<d._month)
		{
			return true;
		}
		else if(this->_month==d._month)
		{
			if(this->_day<=d._day)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
bool Date::operator!=(const Date& d)
{
	return (this->_year!=d._year||this->_month!=d._month||this->_day!=d._day);
}
bool Date::operator==(const Date& d)
{
	return (this->_year==d._year&&this->_month==d._month&&this->_day==d._day);
}
Date Date:: operator+(int days)
{
	int temp=IsLeapYear(_year);
	int allday=days+_day;
	while(allday>dateTable[temp][_month])
	{
		allday-=dateTable[temp][_month];
		_month++;
		if(_month>12)
		{
			_month=1;
			_year++;
			temp=IsLeapYear(_year);
		}
	}
	_day=allday;
	return *this;
}
Date Date::operator-(int days)
{
	int temp=IsLeapYear(_year);
	if(days<_day)
	{
		_day-=days;
	}
	else if(days==_day)
	{
		_month--;
		if(_month<1)
		{
			_month=12;
			_year--;
			temp=IsLeapYear(_year);
		}
		_day=dateTable[temp][months];
	}
	else 
	{
		int allday=days-_day;
		while(allday>=dateTable[temp][_month-1])
		{
			allday-=dateTable[temp][_month-1];
			_month--;
			if(_month<1)
			{
				_month=12;
				_year--;
				temp=IsLeapYear(_year);
			}
		}
		_day=dateTable[temp][_month-1]-allday;
	}
	return *this;
}
 
int Date::operator-(const Date& d)
{
	/*int sum =0;  
    for(int y=1;y<_year;++y)  
    {  
        sum += 365+IsLeapYear(y);  
    }  
    for(int m=1;m<_month;++m)  
        sum += dateTable[_year][_month];  
    sum += _day;  
*/
	return 0;
}

Date& Date::operator++()//前置++
{
	int temp=IsLeapYear(_year);
	if(_day==dateTable[temp][_month])
	{
		if(_month==12)
		{
			_year++;
			_month=1;
			_day=1;
		}
		else
		{
			_month++;
			_day=1;
		}
	}
	else
	{
		_day++;
	}
	return *this;
}
Date Date::operator++(int)
{
	Date Temp(*this);
	--(*this);//调用前置++
	return Temp;
}
Date& Date::operator--()
{
	int temp=IsLeapYear(_year);
	if(_day==1)
	{
		if(_month==1)
		{
			_month=12;
			_year--;
			_day=dateTable[temp][_month];
		}
		else
		{
			_month--;
			_day=dateTable[temp][_month];
		}
	}
	else
	{
		_day--;
	}
	return *this;
}

Date Date::operator--(int)//a--
{
	Date Temp(*this);
	--(*this);//调用前置--
	return Temp;
}

Date:: ~Date()
{}


void Funtest()
{
	Date d1(2017,5,20);
	Date d2(2016,2,10);
	Date d3(2017,3,20);
	Date d4(d3);
	Date d5(2017,5,31);
	Date d6(2017,1,01);
	Date d7;
	if(d1<d2)
	{
		cout<<"d1<d2"<<endl;
	}
	else
	{
		cout<<"d1>d2"<<endl;
	
	}
	if(d1>d3)
	{
		cout<<"d1>d3"<<endl;
	}
	else
	{
		cout<<"d1<d3"<<endl;
	}
	if(d1==d2)
	{
		cout<<"d1==d2"<<endl;
	}
	else
	{
		cout<<"d1!=d2"<<endl;
	}
	d5++;
	++d4;
	d6--;
	--d1;
	d7=d7+10;
}


int main()
{
	Funtest();
	system("pause");
	return 0;
}



