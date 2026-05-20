#pragma once
#include "clsScreen.h"
#include "clsUser.h"

class clsTransferLogListScreen : protected clsScreen
{
    static void _PrintRecordLine(clsUser::stTransferLogRegisterRecord Record)
    {
        cout << setw(8) << left << "" << "| " << setw(30) << left << Record.DateTime;
        cout << "| " << setw(10) << left << Record.SourceAccount;
        cout << "| " << setw(10) << left << Record.DestinationAccount;
        cout << "| " << setw(10) << left << Record.Amount;
        cout << "| " << setw(10) << left << Record.SourceBalance;
        cout << "| " << setw(10) << left << Record.DestinationBalance;
        cout << "| " << setw(10) << left << Record.User;
    }

public:

    static void ShowTransferLogRecordsList()
    {
        vector <clsUser::stTransferLogRegisterRecord> vTransferLogRegister = clsUser::GetTransferLogRegister();
        string Title = "\t  Login Register List Screen";
        string SubTitle = "\t    (" + to_string(vTransferLogRegister.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "____________________________________________\n" << endl;

        cout << setw(8) << left << "";
        cout << "| " << left << setw(30) << "Date/Time";
        cout << "| " << setw(10) << left << "s.Aco";
        cout << "| " << setw(10) << left << "d.Aco";
        cout << "| " << setw(10) << left << "Amount";
        cout << "| " << setw(10) << left << "s.Balance ";
        cout << "| " << setw(10) << left << "d.Balance ";
        cout << "| " << setw(10) << left << "User";
        cout << setw(8) << left << "" << "\n\t__________________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogRegister.size() == 0)
            cout << "\t\t\t\tNo Login Records Available In the System!";
        else
            for (clsUser::stTransferLogRegisterRecord Record : vTransferLogRegister)
            {
                _PrintRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "____________________________________________\n" << endl;

    }
};