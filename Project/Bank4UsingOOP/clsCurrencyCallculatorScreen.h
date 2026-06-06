#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrencyCallculatorScreen : clsScreen
{
	static void _PrintCurrencyCard(clsCurrency Currency, string Message = "")
	{
		cout << Message;
		cout << "\n_______________________________\n";
		cout << "\nCountry   : " << Currency.Country();
		cout << "\nCode      : " << Currency.CurrencyCode();
		cout << "\nName      : " << Currency.CurrencyName();
		cout << "\nRate (1$) : " << Currency.Rate();
		cout << "\n_______________________________\n";
	}

	static void _PrintCalculationResult(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
	{
		_PrintCurrencyCard(CurrencyFrom, "\nConveret from:");
		float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);

		cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode() << " = " 
			<< AmountInUSD << " USD" << endl;

		if (CurrencyTo.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting to\n";

		_PrintCurrencyCard(CurrencyTo, "\nConveret to:");

		float AmountInCurrency2 = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);

		cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode() << " = "
			<< AmountInCurrency2 << " " << CurrencyTo.CurrencyCode() << endl;

	}


public:

	static void ShowCurrencyCallculatorScreen()
	{

		char Contenue = 'y';

		while (Contenue == 'Y' || Contenue == 'y')
		{
			system("cls");
			_DrawScreenHeader("\t Currency Callculator Screen");

			clsCurrency CurrencyFrom = clsCurrency::FindByCode(clsInputValidate::ReadString("\nPlease Enter Currency 1 Code"));
			clsCurrency CurrencyTo = clsCurrency::FindByCode(clsInputValidate::ReadString("\nPlease Enter Currency 2 Code"));
			cout << "\nEnter Amount Namber: ";
			float Amount = clsInputValidate::ReadNumber<float>();
			_PrintCalculationResult(Amount, CurrencyFrom, CurrencyTo);

			cout << "\nDo you want to perform another calculation? [Y:N] ";
			cin >> Contenue;

		}

	}
};