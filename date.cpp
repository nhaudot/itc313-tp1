#include <iostream>
#include "date.h"


namespace date
{
	Date::Date(int year, int month, int day)
	{
		bool status = checkDate(month, day);
		assert(status == true && "Date is not valid");
		_year = year;
		_month	= month;
		_day = day;
	}

	int Date::getDay() const
	{
		return _day;
	}

	int Date::getMonth() const
	{
		return _month;
	}

	int Date::getYear() const
	{
		return _year;
	}

	void Date::setDay(int day)
	{
		bool status = checkDate(_month, day);
		assert(status == true && "Day is not valid");
		_day = day;
	}

	void Date::nextDay()
	{
		// Changement de mois/année
		if (getMonth() == 12 && getDay() == 31)
		{
			setYear(getYear() + 1);
			setMonth(1);
			setDay(1);
		}
		else if (getDay() == 31)
		{
			if (getMonth() == 1 || getMonth() == 3 || getMonth() == 5 || getMonth() == 7 || getMonth() == 8 || getMonth() == 10 || getMonth() == 12)
			{
				setMonth(getMonth() + 1);
				setDay(1);
			}
		}
		else if (getDay() == 30)
		{
			if (getMonth() == 2 || getMonth() == 4 || getMonth() == 6 || getMonth() == 9 || getMonth() == 11)
			{
				setMonth(getMonth() + 1);
				setDay(1);
			} else
			{
				setDay(getDay() + 1);
			}
		}
		else if (getDay() == 28 && getMonth() == 2)
		{
				setMonth(getMonth() + 1);
				setDay(1);
		}
		else
		{
			setDay(getDay() + 1);
		}
	}

	void Date::setMonth(int month)
	{
		assert((month >= 1) && (month <= 12));
		_month = month;
	}
	void Date::setYear(int year)
	{
		_year = year;
	}

	std::string Date::toString() const
	{
		std::string monthsList[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

		std::string str = std::to_string(getYear()) + "/" + monthsList[getMonth() - 1] + "/" + std::to_string(getDay());

		return str;
	}

	bool Date::checkDate(int month, int day) const
	{
		// On estime la date comme valide avant qu'elle passe par les conditions
		bool status = true;

		// Mois qui finissent par 31, vérifie si la date est bien entre 1 et 31
		if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day > 31 || day < 1))
		{
			status = false;
		}
		// Mois qui finissent par 30, vérifie si la date est bien entre le 1 et le 30
		else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30 || day < 1))
		{
			status = false;
		}
		// Mois de Février, vérifie si la date est bien entre le 1 et le 28
		else if ((month == 2) && (day > 28 || day < 1))
		{
			status = false;
		}

		// Vérifie que le mois est valide
		if ((month > 12) || (month < 1))
		{
			status = false;
		}

		return status;
	}

	bool Date::operator>(const date::Date& compareDate) const
	{
		bool status = true;

		int val1 = (getYear() * 10000) + (getMonth() * 100) + getDay();
		int val2 = (compareDate.getYear() * 10000) + (compareDate.getMonth() * 100) + compareDate.getDay();

		if (val1 < val2)
		{
			status = false;
		}

		return status;
	}

	bool Date::operator==(const date::Date& compareDate) const
    {
        bool status = true;

        if (getYear() != compareDate.getYear())
        {
            status = false;
        }
        else
        {
            if (getMonth() != compareDate.getMonth())
            {
                status = false;
            }
            else
            {
                if (getDay() != compareDate.getDay())
                {
                    status = false;
                }
            }
        }

        return status;
    }

	int Date::operator-(const date::Date& date2) const
	{
		bool null = false;     // Drapeau pour vérifier si la différence est nulle
		int length = 0;        // Taille entre les 2 dates
		bool negative = false; // Drapeau pour savoir si la différence est négative ou positive


		Date higherDate;
		Date lowerDate;

		// Tests pour déterminer si length = 0 ou length > 0 ou length < 0
		if (*this == date2)
		{
			null = true;
		}
		else if (*this > date2)
		{
			lowerDate = date2;
			higherDate = *this;
		}
		else
		{
			lowerDate = *this;
			higherDate = date2;
			negative = true;
		}

		// Comptage de la différence en  valeur absolue
		while (higherDate > lowerDate && null == false)
		{
			length++;
			lowerDate.nextDay();

 		}
		// Changement du signe de length si besoin
 		if (negative == true) 
 		{
 			length = -length;
 		}

 		return length;
	}

	Date::~Date()
	{
		//std::cout << "# Destructor called (date)" << std::endl;
	}
}