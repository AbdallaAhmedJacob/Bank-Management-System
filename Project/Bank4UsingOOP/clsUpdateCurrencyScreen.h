#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

class clsUpdateCurrencyScreen : clsScreen
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

	static void _UpdateCurrencyRate(clsCurrency Currency)
	{
		cout << "\nUpdate Currency Rate:";
		cout << "\n_______________________________\n";
		cout << "Enter New Rate: ";
		Currency.UpdateRate(clsInputValidate::ReadNumber<float>());
		cout << "\nCurrency Rate Updated Successsfully :-)\n";
		_PrintCurrencyCard(Currency);
	}

public:

	static void ShowUpdateCurrencyScreen()
	{
		_DrawScreenHeader("\t Update Currency Screen");
		string CurrencyCode = clsInputValidate::ReadString("\nPlease Enter Currency Code: ");

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		if (Currency.IsEmpty())
			cout << "\nCurrency not found :-(";
		else
		{
			_PrintCurrencyCard(Currency);
			char Answer;
			cout << "\nAre you sure you want to update the rate of this ccurrency? [Y:N]: ";
			cin >> Answer;

			if (Answer == 'Y' || Answer == 'y')
			{
				_UpdateCurrencyRate(Currency);
			}
		}
	}
};
