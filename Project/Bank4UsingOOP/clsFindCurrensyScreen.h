#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFindCurrensyScreen : clsScreen
{
	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\n\nCurrency Card:\n";
		cout << "\n_______________________________\n";
		cout << "\nCountry   : " << Currency.Country();
		cout << "\nCode      : " << Currency.CurrencyCode();
		cout << "\nName      : " << Currency.CurrencyName();
		cout << "\nRate (1$) : " << Currency.Rate();
		cout << "\n_______________________________\n";
	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t Find Currency Screen");

		cout << "\nFind By: [1] Code or [2] Country : ";
		short Choise = clsInputValidate::ReadNumberBetween<short>(1, 2);
		cin.ignore(1, '\n');
		string FindBy;
		clsCurrency Currency = clsCurrency::FindByCode("");

		if (Choise == 1)
		{
			FindBy = clsInputValidate::ReadString("\nPlease Enteer Currency Code: ");
			Currency = clsCurrency::FindByCode(FindBy);
		}
		if (Choise == 2)
		{
			FindBy = clsInputValidate::ReadString("\nPlease Enteer Currency Country: ");
			Currency = clsCurrency::FindByCountry(FindBy);
		}

		if (!clsCurrency::IsCurrencyExist(Currency.CurrencyCode()))
			cout << "\nCurrency not found :-(";
		else
			_PrintCurrencyCard(Currency);
	}
};

