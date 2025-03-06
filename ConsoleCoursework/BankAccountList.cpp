#include "BankAccountList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio> // Для использования printf

using namespace std;

// Конструктор
BankAccountList::BankAccountList() : head(NULL) {}

// Деструктор для освобождения памяти
BankAccountList::~BankAccountList() {
    PBA* current = head;
    while (current != NULL) {
        PBA* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// Функция для добавления нового аккаунта
void BankAccountList::addAccount(PBA newAccount) {
    PBA* newNode = new PBA;
    *newNode = newAccount;
    newNode->next = head;
    head = newNode;
}

// Метод для добавления нового элемента в список
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

// Метод для удаления аккаунта по номеру в списке
void BankAccountList::deleteAccountByIndex(int index) {
    if (head == nullptr) {
        cout << "\nСписок пуст.\n";
        return;
    }

    PBA* current = head;
    PBA* previous = nullptr;
    int currentIndex = 1;  // Индекс текущего элемента (считаем с 1)

    // Ищем элемент с нужным индексом
    while (current != nullptr && currentIndex < index) {
        previous = current;
        current = current->next;
        currentIndex++;
    }

    // Если элемент с таким индексом не найден
    if (current == nullptr) {
        cout << "\nЭлемент с таким номером не найден.\n";
        return;
    }

    // Если элемент - это первый элемент в списке
    if (previous == nullptr) {
        head = current->next;  // Сдвигаем голову на следующий элемент
    }
    else {
        previous->next = current->next;  // Обновляем указатель на следующий элемент
    }

    delete current;  // Освобождаем память
    cout << "\nЭлемент " << index << " удален.\n";
}

// Функция для поиска аккаунта
void BankAccountList::searchAccount(string query) {
    PBA* current = head;
    bool found = false;
    int index = 1; // Счетчик для вывода номера строки

    printf("%-5s", "№");
    printf("%-20s", "Ф.И.О");
    printf("%-20s", "Телефон");
    printf("%-14s", "Дата");
    printf("%-20s", "Домашний адрес");
    printf("%-17s", "Номер карты");
    printf("%-17s", "Банковский счет\n");
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
            index++; // Увеличиваем счетчик номера строки
        }
        current = current->next;
    }

    if (!found) {
        cout << "Нет совпадений с запросом.\n";
    }
}

// Метод для вывода списка на экран
void BankAccountList::printList() {
    PBA* current = head;
    int index = 1; // Номер строки

    // Заголовок таблицы
    printf("%-5s", "№");
    printf("%-20s", "Ф.И.О");
    printf("%-20s", "Телефон");
    printf("%-14s", "Дата");
    printf("%-20s", "Домашний адрес");
    printf("%-17s", "Номер карты");
    printf("%-17s", "Банковский счет\n");

    // Разделительная линия
    printf("--------------------------------------------------------------------------------------------------------------\n");
    // Вывод данных
    while (current != NULL) {
        printf("%-5d", index);  // Номер строки
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
    // Разделительная линия
    printf(" --------------------------------------------------------------------------------------------------------------\n");
}

// Метод для считывания данных из файла
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

// Метод для записи данных в файл
void BankAccountList::saveToFile(const string& filename) {
    // Открываем файл для записи
    ofstream outFile(filename);

    if (!outFile.is_open()) {
        cout << "\nНе удалось открыть файл для записи.\n";
        return;
    }

    PBA* current = head;

    // Проходим по списку и записываем данные в файл
    while (current != nullptr) {
        outFile << current->name << ","
            << current->telephone << ","
            << current->data << ","
            << current->address << ","
            << current->card << ","
            << current->account << "\n";
        current = current->next;
    }

    outFile.close();  // Закрываем файл
    cout << "\nДанные успешно сохранены в файл.\n";
}
