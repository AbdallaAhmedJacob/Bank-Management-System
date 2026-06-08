#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrensyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCallculatorScreen.h"

using namespace std;

class clsCurrencyExchangScreen : clsScreen
{
    enum _enCurrencyExchingOptions {
        eListCurrency = 1, eFindCurrency = 2, eUpdateCurrency = 3,
        CurrencyCallculator = 4, MainMenue = 5
    };

    static short _ReadCurrencyExchingOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 5, "Enter Number between 1 to 5: ");
        cin.ignore(1, '\n');

        return Choice;
    }

    static void GoBacktoShowCurrencyExchingScreen()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Currency Exching Menue...\n";

        system("pause>0");
        ShowCurrencyExchingScreen();
    }

    static void _ListCurrenciesScreen()
    {
        //cout << "\nList Currencies Scrren wil be here...\n";
        clsCurrenciesListScreen::ShowListCurrenciesScreen();
    }

    static void _FindCurrensyScreen()
    {
        //cout << "\nFind Currensy Scrren wil be here...\n";
        clsFindCurrensyScreen::ShowFindCurrencyScreen();
    }

    static void _UpdateRateScreen()
    {
        //cout << "\nUpdate Rate Scrren wil be here...\n";
        clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
    }

    static void _CurrencyCallculatorScreen()
    {
        //cout << "\nCurrency Callculator Scrren wil be here...\n";
        clsCurrencyCallculatorScreen::ShowCurrencyCallculatorScreen();
    }

    static  void _GoBackToCurrencyExchingMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Currency Exching Main Menue...\n";

        system("pause>0");
        ShowCurrencyExchingScreen();
    }

    static void _PerfromCurrencyExchingOption(_enCurrencyExchingOptions CurrencyExchingOption)
    {
        switch (CurrencyExchingOption)
        {

        case _enCurrencyExchingOptions::eListCurrency:
            system("cls");
            _ListCurrenciesScreen();
            GoBacktoShowCurrencyExchingScreen();
            break;
        case _enCurrencyExchingOptions::eFindCurrency:
            system("cls");
            _FindCurrensyScreen();
            GoBacktoShowCurrencyExchingScreen();
            break;
        case _enCurrencyExchingOptions::eUpdateCurrency:
            system("cls");
            _UpdateRateScreen();
            GoBacktoShowCurrencyExchingScreen();
            break;
        case _enCurrencyExchingOptions::CurrencyCallculator:
            system("cls");
            _CurrencyCallculatorScreen();
            GoBacktoShowCurrencyExchingScreen();
            break;
        case _enCurrencyExchingOptions::MainMenue:
            // The main funcation to handl this case.
            break;
        }
    }

public:

    static void ShowCurrencyExchingScreen()
    {
        system("cls");
        clsScreen::_DrawScreenHeader("Crrency Exching Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tCrrency Exching Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currensy.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Callculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromCurrencyExchingOption((_enCurrencyExchingOptions)_ReadCurrencyExchingOption());
    }
};

