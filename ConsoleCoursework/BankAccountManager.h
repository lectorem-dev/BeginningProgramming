#ifndef BANK_ACCOUNT_MANAGER_H
#define BANK_ACCOUNT_MANAGER_H

#include "BankAccountList.h" // ��� ������ � ������� BankAccountList
#include <iostream>
#include <conio.h>
#include <windows.h> // ��� ������ � ����������� �����������
#include <vector>

class BankAccountManager {
private:
    int selectedOption = 0; // ������� ��������� ����� ����
    vector<string> menuOptions = {
        "�������� ���� ������",
        "������� ������� �� ���� ������",
        "�������� ������� � ���� ������",
        "��������������� �����������",
        "������� HTML �������",
        "��������� ������ � ����",
        "��������� ������ ���������"
    };

public:
    BankAccountList& list; // ������ �� ������ ���������

    // �����������, ����������� ������ �� BankAccountList
    BankAccountManager(BankAccountList& accountList) : list(accountList) {}

    bool showMenu();
    void listAccounts(BankAccountList& list);
    void deleteItem();
    void addItem(BankAccountList& list);
    void searchItem(BankAccountList& list);
    void openHTMLHelp();
};

#endif
