#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"

class clsCurrenciesListScreen : clsScreen
{	
	static void _PrintHeader()
	{
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(40) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

	static void _PrintCurrencyRecord(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << left << setw(30) << Currency.Country();
		cout << "| " << left << setw(8) << Currency.CurrencyCode();
		cout << "| " << left << setw(40) << Currency.CurrencyName();
		cout << "| " << left << setw(10) << Currency.Rate();
	}	
	
public:

	static void ShowListCurrenciesScreen()
	{
		vector <clsCurrency> vCurrency = clsCurrency::GetCurrenciesList();

		_DrawScreenHeader("\t Currencies List Screen", "\t    (" + to_string(vCurrency.size()) + ") Currncy.");
		_PrintHeader();

		if (vCurrency.size() == 0)
			cout << "\t\t\t\tNo Currencies Available In the System!";
		else
			for (clsCurrency C : vCurrency)
			{
				_PrintCurrencyRecord(C);
				cout << endl;
			}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};