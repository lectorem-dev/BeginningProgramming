#include <iostream>
#include <windows.h>  // Для использования SetConsoleOutputCP
#include <cwchar>  // Для использования L""
#include "BankAccountList.h"
#include "BankAccountManager.h"

using namespace std;

int main() {
    // Изменяем кодировку консоли на CP1251 для корректного отображения русских символов
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    SetConsoleTitleW(L"Менеджер банковских счетов");

    BankAccountList list;

    // Чтение данных из файла
    list.readDataFromFile("accounts.csv");  // Замените на реальный путь

    BankAccountManager manager(list);  // Передаем объект списка в менеджер

    bool running = true;  // Флаг работы программы
    while (running) {
        running = manager.showMenu();  // Даем возможность выйти из цикла
    }

    // Перед завершением программы сохраняем изменения
    list.saveToFile("accounts.csv");

    return 0;
}
