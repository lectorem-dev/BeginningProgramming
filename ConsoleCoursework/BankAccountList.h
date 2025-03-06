#ifndef BANK_ACCOUNT_LIST_H
#define BANK_ACCOUNT_LIST_H

#include "PBA.h"  // ���������� ��������� PBA
#include <string>

class BankAccountList {
private:
    PBA* head;  // ��������� �� ������ ������

public:
    // �����������
    BankAccountList();

    // ���������� ��� ������������ ������
    ~BankAccountList();

    // ����� ��� ���������� ������ �������� � ������
    void addAccount(const string& name, const string& telephone, const string& data, const string& address, const string& card, const string& account);
    void addAccount(PBA newAccount);

    void deleteAccountByIndex(int index);

    void searchAccount(string query);

    // ����� ��� ������ ������ �� �����
    void printList();

    // ����� ��� ���������� ������ �� �����
    void readDataFromFile(const string& filename);

    // ����� ��� ������ ������ � ����
    void saveToFile(const string& filename);
};

#endif // BANK_ACCOUNT_LIST_H
