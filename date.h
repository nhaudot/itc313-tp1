#ifndef DATE_H
#define DATE_H

#include <string>


namespace date
{
	class Date
	{
	public:
		Date(int year=2020, int month=1, int day=1);
		int getDay() const;
		int getMonth() const;
		int getYear() const;
		void setDay(int day);
		void nextDay();
		void setMonth(int month);
		void setYear(int year);
		bool checkDate(int month, int day) const;
		std::string toString() const;
		bool operator>(const date::Date& compareDate) const;
		bool operator==(const date::Date& compareDate) const;
		int operator-(const date::Date& date2) const; // Retourne différence date1/date2 positive, négative ou nulle en jours
		~Date();
	private:
		int _day;
		int _month;
		int _year;
	};
}


#endif