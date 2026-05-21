#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferScreen : protected clsScreen
{

private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber;
        cout << "\nBalance     : " << std::fixed << Client.AccountBalance;
        cout << "\n___________________\n";
    }

    static string _ReadAccountNumber(string Message)
    {
        string AccountNumber = "";
        cout << Message;
        cin >> AccountNumber;

        return AccountNumber;
    }

public:

    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t   Transfer Screen");


        // Read data Transfer From.
        string AccountNumberTransferFrom = _ReadAccountNumber("\nPlease enter AccountNumber to transfer from: ");

        while (!clsBankClient::IsClientExist(AccountNumberTransferFrom))
        {
            cout << "\nClient with [" << AccountNumberTransferFrom << "] does not exist.\n";
            AccountNumberTransferFrom = _ReadAccountNumber("\nPlease enter AccountNumber to transfer from: ");
        }

        clsBankClient SorceClient = clsBankClient::Find(AccountNumberTransferFrom);
        _PrintClient(SorceClient);

        // Read data Transfer To.
        string AccountNumberTransferTo = _ReadAccountNumber("\nPlease enter AccountNumber to transfer to: ");

        while (!clsBankClient::IsClientExist(AccountNumberTransferTo))
        {
            cout << "\nClient with [" << AccountNumberTransferTo << "] does not exist.\n";
            AccountNumberTransferTo = _ReadAccountNumber("\nPlease enter AccountNumber to transfer to: ");
        }

        clsBankClient DestinationClient = clsBankClient::Find(AccountNumberTransferTo);
        _PrintClient(DestinationClient);


        // Read Amount.
        float Amount = 0;

        cout << "\nPlease enter Transfer amount: ";
        while (Amount = clsInputValidate::ReadNumber<float>())
        {
            if (SorceClient.AccountBalance >= Amount)
                break;

            cout << "\nPlease enter amoun fewer of [ " << SorceClient.AccountBalance << " ]: ";
        }
        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (SorceClient.Transfer(Amount, DestinationClient))
            {
                cout << "\nAmount Transfer Successfully.\n";

                _PrintClient(SorceClient);
                _PrintClient(DestinationClient);
            }
            else
            {
                cout << "\nAmount Transfer Faile.\n";

                _PrintClient(SorceClient);
                _PrintClient(DestinationClient);
            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
    }
};

