#include "BankAccountManager.h"

using namespace std;

// ������� ��� ������� ������
void ClearConsole() {
    system("cls");
}

// ������� ��� ����������� ����
bool BankAccountManager::showMenu() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int key = 0;

    while (true) {
        system("cls"); // ������� ������ ����� ������������

        SetConsoleTextAttribute(h, 6);
        cout << "�������� ��������:\n\n";

        // ���������� ��� ������ ����
        for (size_t i = 0; i < menuOptions.size(); i++) {
            if (i == selectedOption) {
                SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); // ����� ���
                cout << " " << menuOptions[i] << " \n";
                SetConsoleTextAttribute(h, 6);  // ������� ����������� ����
            }
            else {
                cout << " " << menuOptions[i] << " \n";
            }
        }

        key = _getch(); // �������� ������� �������

        if (key == 224) { // ��� ��� �������
            key = _getch(); // ������ ������ ����� ���� �������

            if (key == 72) { // ������� �����
                selectedOption = (selectedOption - 1 + menuOptions.size()) % menuOptions.size();
            }
            else if (key == 80) { // ������� ����
                selectedOption = (selectedOption + 1) % menuOptions.size();
            }
        }
        else if (key == 13) { // Enter
            break;
        }
    }

    system("cls"); // ������� ������ ����� ����������� ��������

    switch (selectedOption) {
    case 0:
        listAccounts(list);  // ����� ���� ������
        break;
    case 1:
        deleteItem();  // �������� ��������
        break;
    case 2:
        addItem(list);  // ���������� ��������
        break;
    case 3:
        searchItem(list);  // �����
        break;
    case 4:
        openHTMLHelp();  // �������� HTML-�������
        break;
    case 5:
        list.saveToFile("accounts.csv");  // ���������� ������
        break;
    case 6:
        list.saveToFile("accounts.csv");  // �������������� ����� �������
        return false; // ��������� ���������
    default:
        cout << "������! �������� �����.\n";
        break;
    }

    system("pause");
    return true; // ���������� ������
}


// ������� ��� ����������� ���� ���������
void BankAccountManager::listAccounts(BankAccountList& list) {
    list.printList();  // ������� ������ ���������
}

// ������� ��� �������� ��������
void BankAccountManager::deleteItem() {
    int indexToDelete;
    cout << "\n������� ����� �������� ��� ��������: ";
    cin >> indexToDelete;

    list.deleteAccountByIndex(indexToDelete);  // ������� ������� �� �������
}


// ������� ��� ���������� ������ ��������
void BankAccountManager::addItem(BankAccountList& list) {
    PBA newAccount;

    cout << "������� �.�.�: ";
    cin.ignore();
    getline(cin, newAccount.name);

    cout << "������� ����� ��������: ";
    cin >> newAccount.telephone;

    cout << "������� ���� ���������� �������: ";
    cin >> newAccount.data;

    cout << "������� �������� �����: ";
    cin.ignore();
    getline(cin, newAccount.address);

    cout << "������� ����� �����: ";
    cin >> newAccount.card;

    cout << "������� ����� ����������� �����: ";
    cin >> newAccount.account;

    list.addAccount(newAccount);  // ��������� ����� ������� � ���� ������
    cout << "\n������� ������� ��������.";
}

// ������� ��� ������ ��������
void BankAccountManager::searchItem(BankAccountList& list) {
    string searchQuery;

    cout << "������� ������ ��� ������ (�.�.�., �������, ����� �����): ";
    cin.ignore();
    getline(cin, searchQuery);

    list.searchAccount(searchQuery);  // ����� �� ���� ������
}

// ������� ��� �������� HTML �������
void BankAccountManager::openHTMLHelp() {
    system("start help.html");  // �������� HTML ����� � ������� ��������
}
