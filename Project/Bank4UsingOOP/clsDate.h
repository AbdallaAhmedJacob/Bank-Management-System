#pragma warning (disable : 4996)
#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

class clsDate {

private:

	short _Second;
	short _Minute;
	short _Hour;
	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;

	static void CalculateAdjustedMonthAndYear(short Month, short Year, short& M, short& Y) {
		short a = (14 - Month) / 12;
		Y = Year - a;
		M = Month + (12 * a) - 2;
	}

public:

	clsDate() {
		time_t Time = time(0); // Get time now.
		tm* gmtm = gmtime(&Time); // converting now to tm stract for UTC date/time.

		_Second = gmtm->tm_sec;
		_Minute = gmtm->tm_min;
		_Hour = gmtm->tm_hour;
		_Day = gmtm->tm_mday;
		_Month = gmtm->tm_mon + 1;
		_Year = gmtm->tm_year + 1900;
	}

	clsDate(string Date) {
		SetDate(Date);
	}

	clsDate(short Year, short Month, short Day, short Hour, short Minute, short Second) {
		_Second = Second;
		_Minute = Minute;
		_Hour = Hour;
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDate(short Year, short Month, short Day) {
		_Second = 0;
		_Minute = 0;
		_Hour = 0;
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDate(short OrderOfDay, short Year) {
		*this = ConvertDayOrderToDate(OrderOfDay, Year);
	}

	void SetDate(short Year, short Month, short Day, short Hour, short Minute, short Second) {
		_Second = Second;
		_Minute = Minute;
		_Hour = Hour;
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	void SetDate(short Year, short Month, short Day) {
		_Second = 0;
		_Minute = 0;
		_Hour = 0;
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	void SetDate(string Date) {
		clsDate cDate = ConvertStringToDate(Date);

		_Day = cDate.Day;
		_Month = cDate.Month;
		_Year = cDate.Year;
	}

	string GetDate() {
		return FormatDate(*this, "dd/mm/yyyy");
	}

	__declspec(property(get = GetDate, put = SetDate)) string Date;

	void SetSecond(short Second) {
		_Second = Second;
	}

	short GetSecond() {
		return _Second;
	}

	__declspec(property(get = GetSecond, put = SetSecond)) short Second;

	void SetMinute(short Minute) {
		_Minute = Minute;
	}

	short GetMinute() {
		return _Minute;
	}

	__declspec(property(get = GetMinute, put = SetMinute)) short Minute;

	void SetHour(short Hour) {
		_Hour = Hour;
	}

	short GetHour() {
		return _Hour;
	}

	__declspec(property(get = GetHour, put = SetHour)) short Hour;

	void SetDay(short Day) {
		_Day = Day;
	}

	short GetDay() {
		return _Day;
	}

	__declspec(property(get = GetDay, put = SetDay)) short Day;

	void SetMonth(short Month) {
		_Month = Month;
	}

	short GetMonth() {
		return _Month;
	}

	__declspec(property(get = GetMonth, put = SetMonth)) short Month;

	void SetYear(short Year) {
		_Year = Year;
	}

	short GetYear() {
		return _Year;
	}

	__declspec(property(get = GetYear, put = SetYear)) short Year;

	static void Print(clsDate Date) {
		cout << FormatDate(Date) << endl;
	}

	void Print() {
		Print(*this);
	}

	static clsDate ConvertStringToDate(string stDate) {
		clsDate Date;
		string Tump;
		short pos = 0;

		short i = 0;
		while (stDate[i] != '/') {
			Tump += stDate[i];
			i++;
		}

		pos = (short)stDate.find("/");
		Date.Day = stoi(Tump);
		stDate.erase(0, pos + 1);
		Tump = "";
		i = 0;

		while (stDate[i] != '/') {
			Tump += stDate[i];
			i++;
		}
		pos = (short)stDate.find("/");
		Date.Month = stoi(Tump);
		stDate.erase(0, pos + 1);

		Date.Year = stoi(stDate);

		return Date;
	}

	static string ConvertDateTostring(clsDate Date) {
		return FormatDate(Date);
	}

	string ConvertDateTostring() {
		return FormatDate(*this);
	}

	static string FormatDate(clsDate Date, string Format = "dd/mm/yyyy") {
		string Formated;
		short pos = 0;

		pos = (short)Format.find("dd");
		Format.erase(pos, 2);
		Formated = Format.insert(pos, to_string(Date.Day));

		pos = (short)Format.find("mm");
		Format.erase(pos, 2);
		Formated = Format.insert(pos, to_string(Date.Month));

		pos = (short)Format.find("yyyy");
		Format.erase(pos, 4);
		Formated = Format.insert(pos, to_string(Date.Year));

		return Formated;
	}


	string FormatDate(string Format = "dd/mm/yyyy") {
		return FormatDate(*this, Format);
	}

	static string FormatTime(clsDate Date, string Format = "hh:mm:ss")
	{
		string Formated;
		short pos = 0;

		pos = (short)Format.find("hh");
		Format.erase(pos, 2);
		Formated = Format.insert(pos, to_string(Date.Hour));

		pos = (short)Format.find("mm");
		Format.erase(pos, 2);
		Formated = Format.insert(pos, to_string(Date.Minute));

		pos = (short)Format.find("ss");
		Format.erase(pos, 4);
		Formated = Format.insert(pos, to_string(Date.Second));

		return Formated;
	}

	string FormatTime(string Format = "hh:mm:ss") {
		return FormatDate(*this, Format);
	}

	static string GetDateTime(clsDate Date) {
		return FormatDate(Date) + " - " + FormatTime(Date);
	}

	string GetDateTime() {
		return GetDateTime(*this);
	}

	static bool IsLeapYear(short Year) {
		return (Year % 400 == 0 || (Year % 100 != 0 && Year % 4 == 0));
	}

	bool IsLeapYear() {
		return IsLeapYear(Year);
	}

	static short GetTotalDaysTheYear(short Year) {
		return (IsLeapYear(Year)) ? 366 : 365;
	}

	short GetTotalDaysTheYear() {
		return GetTotalDaysTheYear(Year);
	}

	static short GetTotalHoursTheYear(short Year) {
		return GetTotalDaysTheYear(Year) * 24;
	}

	short GetTotalHoursTheYear() {
		return GetTotalHoursTheYear(Year);
	}

	static int GetTotalMinutesTheYear(short Year) {
		return GetTotalHoursTheYear(Year) * 60;
	}

	int GetTotalMinutesTheYear() {
		return GetTotalMinutesTheYear(Year);
	}

	static int GetTotalSecondsTheYear(short Year) {
		return GetTotalMinutesTheYear(Year) * 60;
	}

	int GetTotalSecondsTheYear() {
		return GetTotalSecondsTheYear(Year);
	}

	static short GetNumberOfDaysInAMonth(short Year, short Month) {
		if (Month < 1 || Month > 12)
			return 0;
		short NumberDaysInMonth[]{ 31,28,31,30,31,31,30,31,30,31,30,31 };
		return (Month == 2) ? (IsLeapYear(Year)) ? 29 : 28 : NumberDaysInMonth[Month - 1];
	}

	short GetNumberOfDaysInAMonth() {
		return GetNumberOfDaysInAMonth(Year, Month);
	}

	static short GetNumberOfHorsInMonth(short Year, short Month) {
		return GetNumberOfDaysInAMonth(Year, Month) * 24;
	}

	short GetNumberOfHorsInMonth() {
		return GetNumberOfHorsInMonth(Year, Month);
	}

	static int GetNumberOfMinutesInMonth(short Year, short Month) {
		return GetNumberOfHorsInMonth(Year, Month) * 60;
	}

	int GetNumberOfMinutesInMonth() {
		return GetNumberOfMinutesInMonth(Year, Month);
	}

	static int GetNumberOfSecondsInMonth(short Year, short Month) {
		return GetNumberOfMinutesInMonth(Year, Month) * 60;
	}

	int GetNumberOfSecondsInMonth() {
		return GetNumberOfSecondsInMonth(Year, Month);
	}

	static bool IsValidDate(short Day, short Month, short Year) {
		return (Day <= GetNumberOfDaysInAMonth(Year, Month));
	}

	static bool IsValidDate(clsDate Date) {
		return IsValidDate(Date.Day, Date.Month, Date.Year);
	}

	bool IsValidDate() {
		return IsValidDate(*this);
	}

	static short GetDayOfWeekIndex(short Day, short Month, short Year) {
		if (!IsValidDate(Day, Month, Year))
			return -2;

		short M = 0, Y = 0;

		CalculateAdjustedMonthAndYear(Month, Year, M, Y);

		return (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;
	}

	static short GetDayOfWeekIndex(clsDate Date) {
		return GetDayOfWeekIndex(Date.Day, Date.Month, Date.Year);
	}

	short GetDayOfWeekIndex() {
		return GetDayOfWeekIndex(*this);
	}

	static string GetDayShortName(short DayIndex) {
		string NameDay[]{ "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return (DayIndex >= 0 && DayIndex <= 6) ? NameDay[DayIndex] : "Invalid";
	}

	string GetDayShortName() {
		return GetDayShortName(GetDayOfWeekIndex());
	}

	static string GetShortMonthName(short Month) {
		string arrShortMonthNames[]{ "Invalid", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		return (Month >= 1 && Month <= 12) ? arrShortMonthNames[Month] : arrShortMonthNames[0];
	}

	string GetShortMonthName() {
		return GetShortMonthName(Month);
	}

	static void PrintMonthCalendar(short Month, short Year) {
		short positionCounter = 0;

		printf("\n______________________%s______________________\n", GetShortMonthName(Month).c_str());

		printf("\nSun    Mon    Tue    Wed    Thu    Fri    Sat\n");

		short firstDayIndex = GetDayOfWeekIndex(1, Month, Year);

		for (short i = 0; i < firstDayIndex; i++) {
			printf("       ");
			positionCounter++;
		}

		short totalDays = GetNumberOfDaysInAMonth(Year, Month);

		for (short i = 1; i <= totalDays; i++) {
			cout << setw(3) << i << "    ";

			if (++positionCounter == 7) {
				positionCounter = 0;
				cout << "\n";
			}
		}
		printf("\n_______________________________________________\n");
	}

	void PrintMonthCalendar() {
		PrintMonthCalendar(Month, Year);
	}

	static void PrintYearCalendar(short Year) {
		printf("\n\n_______________________________________________\n\n");
		printf("\t  CALENDAR FOR THE YEAR %i", Year);
		printf("\n\n_______________________________________________\n\n");

		for (short i = 1; i <= 12; i++)
			PrintMonthCalendar(i, Year);
	}

	void PrintYearCalendar() {
		PrintYearCalendar(Year);
	}

	static short GetDayOrderInYear(short Day, short Month, short Year) {
		unsigned int TotalDays = 0;

		for (short i = 1; i < Month; i++)
			TotalDays += GetNumberOfDaysInAMonth(Year, i);

		return TotalDays + Day;
	}

	static short GetDayOrderInYear(clsDate Date) {
		return GetDayOrderInYear(Date.Day, Date.Month, Date.Year);
	}

	short GetDayOrderInYear() {
		return GetDayOrderInYear(*this);
	}

	static clsDate ConvertDayOrderToDate(short dayOrder, short Year) {
		if (!(IsLeapYear(Year) && (dayOrder >= 1 && dayOrder <= 366) || !IsLeapYear(Year) && (dayOrder >= 1 && dayOrder <= 365))) // Validation.
			return clsDate(0, 0, 0);

		short totalDaysInCurrentMonth = 0;
		short currentMonth = 1;

		for (currentMonth = 1; currentMonth <= 12; currentMonth++) {
			totalDaysInCurrentMonth = GetNumberOfDaysInAMonth(Year, currentMonth);

			if (dayOrder > totalDaysInCurrentMonth) {
				dayOrder -= totalDaysInCurrentMonth;
			}
			else
				break;
		}

		return clsDate(dayOrder, currentMonth, Year);
	}

	clsDate ConvertDayOrderToDate(short dayOrder) {
		return ConvertDayOrderToDate(dayOrder, Year);
	}

	static clsDate GetDateAfterAdding(short AddingDay, clsDate Date) {
		short NumberDaysInMonth = 0;
		short TumpDays = 0;

		while (true)
		{
			NumberDaysInMonth = GetNumberOfDaysInAMonth(Date.Year, Date.Month);
			TumpDays = NumberDaysInMonth - Date.Day;

			if (TumpDays >= AddingDay)
			{
				Date.Day += AddingDay;
				break;
			}
			else
			{
				AddingDay -= TumpDays;
				if (Date.Month < 12)
				{
					Date.Month++;
					Date.Day = 0;
				}
				else
				{
					Date.Month = 1;
					Date.Year++;
				}
			}
		}
		return Date;
	}

	clsDate GetDateAfterAdding(short AddingDay) {
		return GetDateAfterAdding(AddingDay, *this);
	}

	static void AddDate(short AddingDay, clsDate& Date) {
		clsDate cDate = GetDateAfterAdding(AddingDay, Date);

		Date.Day = cDate.Day;
		Date.Month = cDate.Month;
		Date.Year = cDate.Year;
	}

	void AddDate(short AddingDay) {
		AddDate(AddingDay, *this);
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2) {
		return (Date1.Year == Date2.Year) ?
			(Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : (Date1.Month < Date2.Month)
			: (Date1.Year < Date2.Year);
	}

	bool IsDateLessDate2(clsDate Date2) {
		return IsDate1BeforeDate2(Date, Date2);
	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2) {
		return (Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2) {
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
	}

	bool IsDateAfterDate2(clsDate Date2) {
		return IsDate1AfterDate2(*this, Date2);
	}

	bool IsDateEqualDate2(clsDate Date2) {
		return IsDate1EqualDate2(*this, Date2);
	}

	static bool IsLastDayInAMonth(clsDate Date) {
		return (GetNumberOfDaysInAMonth(Date.Year, Date.Month) == Date.Day);
	}

	bool IsLastDayInAMonth() {
		return IsLastDayInAMonth(*this);
	}

	static bool IsLastAMonthInAYear(short Month) {
		return (Month == 12);
	}

	bool IsLastAMonthInAYear() {
		return IsLastAMonthInAYear(Month);
	}

	static clsDate AddOneDay(clsDate Date) {
		(IsLastAMonthInAYear(Date.Month)) ? Date.Year += 1, Date.Month = 1, Date.Day = 1 :
			(IsLastDayInAMonth(Date)) ? Date.Month += 1, Date.Day = 1 : Date.Day += 1;
		return Date;
	}

	void AddOneDay() {
		*this = AddOneDay(*this);
	}

	static void ReversDate(clsDate& Date1, clsDate& Date2) {
		clsDate Tump(Date1);

		Date1 = Date2;
		Date2 = Tump;
	}

	static short GetDefference(clsDate Date1, clsDate Date2, bool TwoWay = false) {

		if (!IsDate1BeforeDate2(Date1, Date2)) {
			if (TwoWay)
				ReversDate(Date1, Date2);
			return NULL;
		}

		short Defference = 0;

		while (Date1.Year != Date2.Year) {
			Defference += (IsLeapYear(Date1.Year++)) ? 366 : 365;
		}

		if (Date1.Year == Date2.Year) {
			if (Date1.Month == Date2.Month)
				Defference = (Date1.Day == Date2.Day) ? Defference : Date2.Day - Date1.Day;
			else {
				short OrderMonth = Date1.Month;
				while (OrderMonth != Date2.Month) {
					Defference += GetNumberOfDaysInAMonth(Date1.Year, OrderMonth++);
				}
				Defference += Date2.Day - Date1.Day;
			}
		}

		ReversDate(Date1, Date2);

		return (TwoWay) ? Defference * -1 : Defference;
	}

	short GetDefference(clsDate Date2, bool TwoWay = true) {
		return GetDefference(*this, Date2, TwoWay);
	}

	static short GetAgeInDays(clsDate Date) {
		return GetDefference(Date, clsDate(), false);
	}

	short GetAgeInDays() {
		return GetAgeInDays(*this);
	}

	static clsDate AddXDays(short Adding, clsDate Date) {
		for (short i = 1; i <= Adding; i++) {
			Date = AddOneDay(Date);
		}
		return Date;
	}

	void AddXDays(short Adding) {

		*this = AddXDays(Adding, *this);
	}

	static clsDate AddOneWeek(clsDate Date) {
		for (int i = 1; i <= 7; i++) {
			Date = AddOneDay(Date);
		}
		return Date;
	}

	void AddOneWeek() {
		*this = AddOneWeek(*this);
	}

	static clsDate AddXWeeks(short Adding, clsDate Date) {
		for (short i = 1; i <= Adding * 7; i++)
		{
			Date = AddOneDay(Date);
		}
		return Date;
	}

	void AddXWeeks(short Adding) {
		*this = AddXWeeks(Adding, *this);
	}

	static clsDate AddOneMonth(clsDate Date) {
		short NumberAddingOfDays = 0;
		if (IsLastAMonthInAYear(Date.Month))
			Date.Year++, Date.Month = 1;
		else
			NumberAddingOfDays = GetNumberOfDaysInAMonth(Date.Year, Date.Month);

		for (int i = 1; i <= NumberAddingOfDays; i++) {
			Date = AddOneDay(Date);
		}
		return Date;
	}

	void AddOneMonth() {
		*this = AddOneMonth(*this);
	}

	static clsDate AddXMonths(short Adding, clsDate Date) {
		for (short i = 1; i <= Adding; i++)
			Date = AddOneMonth(Date);
		return Date;
	}

	void AddXMonths(short Adding) {
		*this = AddXMonths(Adding, *this);
	}

	static clsDate AddOneYear(clsDate Date) {
		Date.Year++;
		return Date;
	}

	void AddOneYear() {
		*this = AddOneYear(*this);
	}

	static clsDate AddXYears(short Adding, clsDate Date) {
		Date.Year += Adding;
		return Date;
	}

	void AddXYears(short Adding) {
		*this = AddXYears(Adding, *this);
	}

	static clsDate AddOneDecaet(clsDate Date) {
		Date.Year += 10;
		return Date;
	}

	void AddOneDecaet() {
		Year += 10;
	}

	static clsDate AddXDecaets(short Adding, clsDate Date) {
		Date.Year += (10 * Adding);
		return Date;
	}

	void AddXDecaets(short Adding) {
		Year += (10 * Adding);
	}

	static clsDate AddCentury(clsDate Date) {
		Date.Year += 100;
		return Date;
	}

	void AddCentury() {
		Year += 100;
	}

	static clsDate AddMillennium(clsDate Date) {
		Date.Year += 1000;
		return Date;
	}

	void AddMillennium() {
		Year += 1000;
	}

	static clsDate DecreaseDateBayOneDay(clsDate Date) {
		(Date.Month == 1) ? Date.Year -= 1, Date.Month = 12, Date.Day = 31 :
			(Date.Day == 1) ? Date.Month -= 1, Date.Day = GetNumberOfDaysInAMonth(Date.Year, Date.Month) : Date.Day -= 1;
		return Date;
	}

	void DecreaseDateBayOneDay() {
		*this = DecreaseDateBayOneDay(*this);
	}

	static clsDate DecreaseDateBayXDays(short Decrease, clsDate Date) {
		for (short i = 1; i <= Decrease; i++)
			Date = DecreaseDateBayOneDay(Date);

		return Date;
	}

	void DecreaseDateBayXDays(short Decrease) {
		*this = DecreaseDateBayXDays(Decrease, *this);
	}

	static clsDate DecreaseDateBayOneWeek(clsDate Date) {
		for (int i = 1; i <= 7; i++)
			Date = DecreaseDateBayOneDay(Date);

		return Date;
	}

	void  DecreaseDateBayOneWeek() {
		*this = DecreaseDateBayOneWeek(*this);
	}

	static clsDate DecreaseDateBayXWeeks(short Decrease, clsDate Date) {
		for (int i = 1; i <= Decrease * 7; i++)
			Date = DecreaseDateBayOneDay(Date);

		return Date;
	}

	void DecreaseDateBayXWeeks(short Decrease) {
		*this = DecreaseDateBayXWeeks(Decrease, *this);
	}

	static clsDate DecreaseDateBayOneMonth(clsDate Date) {
		short NumberDecreasengOfDays = 0;
		if (Date.Month == 1)
			Date.Year--, Date.Month = 12;
		else
			(Date.Day > 28) ? Date.Day = GetNumberOfDaysInAMonth(Date.Year, Date.Month), Date.Month-- : Date.Month--;

		return Date;
	}

	void DecreaseDateBayOneMonth() {
		*this = DecreaseDateBayOneMonth(*this);
	}

	static clsDate DecreaseDateBayXMonths(short Decrease, clsDate Date) {
		for (short i = 1; i <= Decrease; i++)
			Date = DecreaseDateBayOneMonth(Date);

		return Date;
	}

	void DecreaseDateBayXMonths(short Decrease) {
		*this = DecreaseDateBayXMonths(Decrease, *this);
	}

	static clsDate DecreaseDateBayOneYear(clsDate Date) {
		Date.Year--;
		return Date;
	}

	void DecreaseDateBayOneYear() {
		*this = DecreaseDateBayOneYear(*this);
	}

	static clsDate DecreaseDateBayXYears(short Decrease, clsDate Date) {
		Date.Year -= Decrease;
		return Date;
	}

	void DecreaseDateBayXYears(short Decrease) {
		*this = DecreaseDateBayXYears(Decrease, *this);
	}

	static clsDate DecreaseDateBayOneDecaet(clsDate Date) {
		Date.Year -= 10;
		return Date;
	}

	void DecreaseDateBayOneDecaet() {
		*this = DecreaseDateBayOneDecaet(*this);
	}

	static clsDate DecreaseDateBayXDecaets(short Decrease, clsDate Date) {
		Date.Year -= (10 * Decrease);
		return Date;
	}

	void DecreaseDateBayXDecaets(short Decrease) {
		*this = DecreaseDateBayXDecaets(Decrease, *this);
	}

	static clsDate DecreaseDateBayCentury(clsDate Date) {
		Date.Year -= 100;
		return Date;
	}

	void DecreaseDateBayCentury() {
		*this = DecreaseDateBayCentury(*this);
	}

	static clsDate DecreaseDateBayMillennium(clsDate Date) {
		Date.Year -= 1000;
		return Date;
	}

	void DecreaseDateBayMillennium() {
		*this = DecreaseDateBayMillennium(*this);
	}

	static bool IsItEndOfWeek(short IndexDay = -1) {
		return (IndexDay == 6);
	}

	static bool IsItWeekend(clsDate Date) {
		short  IndexDay = GetDayOfWeekIndex(Date);

		return (IndexDay == 5 || IndexDay == 6);
	}

	bool IsItWeekend() {
		return IsItWeekend(*this);
	}

	static bool IsBusinessDay(clsDate Date) {
		return !IsItWeekend(Date);
	}

	bool IsBusinessDay() {
		return IsBusinessDay(*this);
	}

	static short DaysUntilTheEndOfWeek(clsDate Date) {
		return 6 - GetDayOfWeekIndex(Date);
	}

	short DaysUntilTheEndOfWeek() {
		return DaysUntilTheEndOfWeek(*this);
	}

	static short DaysUntilTheEndOfMonth(clsDate Date) {
		return GetNumberOfDaysInAMonth(Date.Year, Date.Month) - Date.Day;
	}

	short DaysUntilTheEndOfMonth() {
		return DaysUntilTheEndOfMonth(*this);
	}

	static short DaysUntilTheEndOfYear(clsDate Date) {
		short Days = DaysUntilTheEndOfMonth(Date);
		++Date.Month;

		while (Date.Month <= 12)
			Days += GetNumberOfDaysInAMonth(Date.Year, Date.Month++);

		return Days;
	}

	short DaysUntilTheEndOfYear() {
		return DaysUntilTheEndOfYear(*this);
	}

	static short ActucalVacationDays(clsDate VacationStarts, clsDate VacationEnds) {
		short VacationDays = 0;
		bool Way = IsDate1BeforeDate2(VacationStarts, VacationEnds);

		if (!Way)
			ReversDate(VacationStarts, VacationEnds);

		while (!IsDate1EqualDate2(VacationStarts, VacationEnds)) {
			if (!IsItWeekend(VacationStarts))
				VacationDays++;

			VacationStarts = AddOneDay(VacationStarts);
		}

		VacationDays = (Way) ? VacationDays : VacationDays * -1, ReversDate(VacationStarts, VacationEnds);

		return VacationDays;
	}

	short ActucalVacationDays(clsDate VacationEnds) {
		return ActucalVacationDays(*this, VacationEnds);
	}

	static clsDate ActucalVacationDays(clsDate VacationStarts, short VacationDays) {
		clsDate VacationEnds = VacationStarts;

		while (VacationDays != 0) {
			if (!IsItWeekend(VacationEnds))
				(VacationDays >= 0) ? VacationDays-- : VacationDays++;

			VacationEnds = AddOneDay(VacationEnds);
		}
		return VacationEnds;
	}

	clsDate ActucalVacationDays(short VacationDays) {
		return ActucalVacationDays(*this, VacationDays);
	}

	enum eDateCompare { Befour = -1, Equal = 0, After = 1 };

	static eDateCompare DateCombarer(clsDate Date1, clsDate Date2) {
		if (IsDate1BeforeDate2(Date1, Date2))
			return eDateCompare::Befour;
		if (IsDate1EqualDate2(Date1, Date2))
			return eDateCompare::Equal;

		return eDateCompare::After;
	}

	eDateCompare DateCombarer(clsDate Date2) {
		return DateCombarer(*this, Date2);
	}
};