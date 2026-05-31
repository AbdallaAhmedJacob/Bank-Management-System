#pragma once
#include "clsScreen.h"

class clsLoginRegisterListScreen : protected clsScreen
{
    static void _PrintRecordLine(clsUser::stLoginRegisterRecord Record)
    {
        cout << setw(8) << left << "" << "| " << setw(35) << left << Record.DateTime;
        cout << "| " << setw(20) << left << Record.UserName;
        cout << "| " << setw(20) << left << Record.Password;
        cout << "| " << setw(10) << left << Record.Permissions;
    }

public:


    static void ShowLoginRecordsList()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
            return;

        vector <clsUser::stLoginRegisterRecord> vLoginRegister = clsUser::GetLoginRegister();
        string Title = "\t  Login Register List Screen";
        string SubTitle = "\t    (" + to_string(vLoginRegister.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Date/Time";
        cout << "| " << left << setw(30) << "User Name";
        cout << "| " << left << setw(30) << "Password";
        cout << "| " << left << setw(30) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLoginRegister.size() == 0)
            cout << "\t\t\t\tNo Login Records Available In the System!";
        else
            for (clsUser::stLoginRegisterRecord Record : vLoginRegister)
            {
                _PrintRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

