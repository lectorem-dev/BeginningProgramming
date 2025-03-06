#ifndef BANK_ACCOUNT_LIST_H
#define BANK_ACCOUNT_LIST_H

#include "PBA.h"  // Подключаем структуру PBA
#include <string>

class BankAccountList {
private:
    PBA* head;  // Указатель на начало списка

public:
    // Конструктор
    BankAccountList();

    // Деструктор для освобождения памяти
    ~BankAccountList();

    // Метод для добавления нового элемента в список
    void addAccount(const string& name, const string& telephone, const string& data, const string& address, const string& card, const string& account);
    void addAccount(PBA newAccount);

    void deleteAccountByIndex(int index);

    void searchAccount(string query);

    // Метод для вывода списка на экран
    void printList();

    // Метод для считывания данных из файла
    void readDataFromFile(const string& filename);

    // Метод для записи данных в файл
    void saveToFile(const string& filename);
};

#endif // BANK_ACCOUNT_LIST_H
