#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "clsPerson.h" 
#include "clsString.h"
#include "Global.h"


using namespace std;

class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNew = 2 };
    enMode _Mode;

    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkedForDelete = false;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector <string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));
    }

    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {
        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;
    }

    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if (C._MarkedForDelete == false)
                {
                    DataLine = _ConverClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();
        }

    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    float _CheckAmaont(float Amaont)
    {
        return (Amaont < 1) ? 0 : Amaont;
    }

    string _PrepareTransferLogRecord(float Amaont, clsBankClient DestinationClient, string Seperator = "#//#")
    {
        string TransferLogRecord = "";
        TransferLogRecord += clsDate::GetDateTime(clsDate()) + Seperator;
        TransferLogRecord += AccountNumber + Seperator;
        TransferLogRecord += DestinationClient.AccountNumber + Seperator;
        TransferLogRecord += to_string(Amaont) + Seperator;
        TransferLogRecord += to_string(AccountBalance) + Seperator;
        TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
        TransferLogRecord += CurrentUser.UserName;

        return TransferLogRecord;
    }


    void _TransferLogRegister(float Amaont, clsBankClient DestinationClient)
    {
        fstream File;

        File.open("TransferLogRegister.txt", ios::out | ios::app);

        if (File.is_open())
            File << _PrepareTransferLogRecord(Amaont, DestinationClient, "#//#") << endl;

        File.close();
    }

public:

    clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;

        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    string GetAccountNumber() {
        return _AccountNumber;
    }

    void SetAccountNumber(string AccountNumber) {
        _AccountNumber = AccountNumber;
    }

    __declspec(property(get = GetAccountNumber, put = SetAccountNumber)) string AccountNumber;

    string GetPinCode() {
        return _PinCode;
    }

    void SetPinCode(string PinCode) {
        _PinCode = PinCode;
    }

    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    float GetAccountBalance() {
        return _AccountBalance;
    }

    void SetAccountBalance(float AccountBalance) {
        _AccountBalance = AccountBalance;
    }

    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    static clsBankClient Find(string AccountNumber)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
            }
            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    bool Delete()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber == _AccountNumber)
            {
                C._MarkedForDelete = true;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

        *this = _GetEmptyClientObject();

        return true;

    }

    enum enSaveResults { svFailedEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
            return enSaveResults::svFailedEmptyObject;
        case enMode::UpdateMode:
            _Update();
            return enSaveResults::svSucceeded;
        case enMode::AddNew:
        {
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();
                this->_Mode = enMode::UpdateMode;
                return  enSaveResults::svSucceeded;
            }
        }

        }

        
    }

    static bool IsClientExist(string AccountNumber)
    {
        return (!clsBankClient::Find(AccountNumber).IsEmpty());
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNew, "", "", "", "", AccountNumber, "", 0);
    }

    static vector<clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    bool Deposit(float Amount)
    {
        if (_CheckAmaont(Amount))
        {
            _AccountBalance += Amount;
            return Save();
        }
        else
            return false;
    }

    bool Withdraw(float Amount)
    {
        if (_CheckAmaont(Amount))
        {
            _AccountBalance -= Amount;
            return Save();
        }
        else
            return false;
    }

    bool Transfer(float Amount, clsBankClient& DestinationClient)
    {
        if (Amount > AccountBalance)
            return false;

        if (this->Withdraw(Amount))
            if (DestinationClient.Deposit(Amount))
            {
                return true;
                this->_TransferLogRegister(Amount, DestinationClient);
            }
            else
                this->Deposit(Amount);

        return false;
    }

    static double GetTotalBalances()
    {
        vector <clsBankClient> vClients = _LoadClientsDataFromFile();
        double TotalBalances = 0;

        for (clsBankClient& C : vClients)
            TotalBalances += C.AccountBalance;
        
        return TotalBalances;
    }

    

    
};