#include "BankAccountList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio> // ��� ������������� printf

using namespace std;

// �����������
BankAccountList::BankAccountList() : head(NULL) {}

// ���������� ��� ������������ ������
BankAccountList::~BankAccountList() {
    PBA* current = head;
    while (current != NULL) {
        PBA* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// ������� ��� ���������� ������ ��������
void BankAccountList::addAccount(PBA newAccount) {
    PBA* newNode = new PBA;
    *newNode = newAccount;
    newNode->next = head;
    head = newNode;
}

// ����� ��� ���������� ������ �������� � ������
void BankAccountList::addAccount(const string& name, const string& telephone, const string& data, const string& address, const string& card, const string& account) {
    PBA* newAccount = new PBA{ name, telephone, data, address, card, account, NULL };
    if (head == NULL) {
        head = newAccount;
    }
    else {
        PBA* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newAccount;
    }
}

// ����� ��� �������� �������� �� ������ � ������
void BankAccountList::deleteAccountByIndex(int index) {
    if (head == nullptr) {
        cout << "\n������ ����.\n";
        return;
    }

    PBA* current = head;
    PBA* previous = nullptr;
    int currentIndex = 1;  // ������ �������� �������� (������� � 1)

    // ���� ������� � ������ ��������
    while (current != nullptr && currentIndex < index) {
        previous = current;
        current = current->next;
        currentIndex++;
    }

    // ���� ������� � ����� �������� �� ������
    if (current == nullptr) {
        cout << "\n������� � ����� ������� �� ������.\n";
        return;
    }

    // ���� ������� - ��� ������ ������� � ������
    if (previous == nullptr) {
        head = current->next;  // �������� ������ �� ��������� �������
    }
    else {
        previous->next = current->next;  // ��������� ��������� �� ��������� �������
    }

    delete current;  // ����������� ������
    cout << "\n������� " << index << " ������.\n";
}

// ������� ��� ������ ��������
void BankAccountList::searchAccount(string query) {
    PBA* current = head;
    bool found = false;
    int index = 1; // ������� ��� ������ ������ ������

    printf("%-5s", "�");
    printf("%-20s", "�.�.�");
    printf("%-20s", "�������");
    printf("%-14s", "����");
    printf("%-20s", "�������� �����");
    printf("%-17s", "����� �����");
    printf("%-17s", "���������� ����\n");
    printf("--------------------------------------------------------------------------------------------------------------\n");

    while (current != NULL) {
        if (current->name.find(query) != string::npos ||
            current->telephone.find(query) != string::npos ||
            current->account.find(query) != string::npos) {

            printf("%-5d", index);
            printf("%-20s", current->name.c_str());
            printf("%-20s", current->telephone.c_str());
            printf("%-14s", current->data.c_str());
            printf("%-20s", current->address.c_str());
            printf("%-17s", current->card.c_str());
            printf("%-17s", current->account.c_str());
            cout << "\n";

            found = true;
            index++; // ����������� ������� ������ ������
        }
        current = current->next;
    }

    if (!found) {
        cout << "��� ���������� � ��������.\n";
    }
}

// ����� ��� ������ ������ �� �����
void BankAccountList::printList() {
    PBA* current = head;
    int index = 1; // ����� ������

    // ��������� �������
    printf("%-5s", "�");
    printf("%-20s", "�.�.�");
    printf("%-20s", "�������");
    printf("%-14s", "����");
    printf("%-20s", "�������� �����");
    printf("%-17s", "����� �����");
    printf("%-17s", "���������� ����\n");

    // �������������� �����
    printf("--------------------------------------------------------------------------------------------------------------\n");
    // ����� ������
    while (current != NULL) {
        printf("%-5d", index);  // ����� ������
        printf("%-20s", current->name.c_str());
        printf("%-20s", current->telephone.c_str());
        printf("%-14s", current->data.c_str());
        printf("%-20s", current->address.c_str());
        printf("%-17s", current->card.c_str());
        printf("%-17s", current->account.c_str());
        printf("\n");

        current = current->next;
        index++;
    }
    // �������������� �����
    printf(" --------------------------------------------------------------------------------------------------------------\n");
}

// ����� ��� ���������� ������ �� �����
void BankAccountList::readDataFromFile(const string& filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, telephone, data, address, card, account;
        getline(ss, name, ',');
        getline(ss, telephone, ',');
        getline(ss, data, ',');
        getline(ss, address, ',');
        getline(ss, card, ',');
        getline(ss, account, ',');
        addAccount(name, telephone, data, address, card, account);
    }
}

// ����� ��� ������ ������ � ����
void BankAccountList::saveToFile(const string& filename) {
    // ��������� ���� ��� ������
    ofstream outFile(filename);

    if (!outFile.is_open()) {
        cout << "\n�� ������� ������� ���� ��� ������.\n";
        return;
    }

    PBA* current = head;

    // �������� �� ������ � ���������� ������ � ����
    while (current != nullptr) {
        outFile << current->name << ","
            << current->telephone << ","
            << current->data << ","
            << current->address << ","
            << current->card << ","
            << current->account << "\n";
        current = current->next;
    }

    outFile.close();  // ��������� ����
    cout << "\n������ ������� ��������� � ����.\n";
}
