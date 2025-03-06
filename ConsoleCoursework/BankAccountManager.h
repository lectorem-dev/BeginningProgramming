#ifndef BANK_ACCOUNT_MANAGER_H
#define BANK_ACCOUNT_MANAGER_H

#include "BankAccountList.h" // Для работы с классом BankAccountList
#include <iostream>
#include <conio.h>
#include <windows.h> // Для работы с консольными аттрибутами
#include <vector>

class BankAccountManager {
private:
    int selectedOption = 0; // Текущий выбранный пункт меню
    vector<string> menuOptions = {
        "Показать базу данных",
        "Удалить элемент из базы данных",
        "Добавить элемент в базу данных",
        "Воспользоваться поисковиком",
        "Открыть HTML справку",
        "Сохранить данные в файл",
        "Завершить работу программы"
    };

public:
    BankAccountList& list; // Ссылка на список аккаунтов

    // Конструктор, принимающий ссылку на BankAccountList
    BankAccountManager(BankAccountList& accountList) : list(accountList) {}

    bool showMenu();
    void listAccounts(BankAccountList& list);
    void deleteItem();
    void addItem(BankAccountList& list);
    void searchItem(BankAccountList& list);
    void openHTMLHelp();
};

#endif
