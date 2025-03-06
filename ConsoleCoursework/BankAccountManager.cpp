#include "BankAccountManager.h"

using namespace std;

// Функция для очистки экрана
void ClearConsole() {
    system("cls");
}

// Функция для отображения меню
bool BankAccountManager::showMenu() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int key = 0;

    while (true) {
        system("cls"); // Очистка экрана перед перерисовкой

        SetConsoleTextAttribute(h, 6);
        cout << "Выберите действие:\n\n";

        // Отображаем все пункты меню
        for (size_t i = 0; i < menuOptions.size(); i++) {
            if (i == selectedOption) {
                SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); // Белый фон
                cout << " " << menuOptions[i] << " \n";
                SetConsoleTextAttribute(h, 6);  // Вернуть стандартный цвет
            }
            else {
                cout << " " << menuOptions[i] << " \n";
            }
        }

        key = _getch(); // Ожидание нажатия клавиши

        if (key == 224) { // Код для стрелок
            key = _getch(); // Читаем вторую часть кода клавиши

            if (key == 72) { // Стрелка вверх
                selectedOption = (selectedOption - 1 + menuOptions.size()) % menuOptions.size();
            }
            else if (key == 80) { // Стрелка вниз
                selectedOption = (selectedOption + 1) % menuOptions.size();
            }
        }
        else if (key == 13) { // Enter
            break;
        }
    }

    system("cls"); // Очистка экрана перед выполнением действия

    switch (selectedOption) {
    case 0:
        listAccounts(list);  // Вывод базы данных
        break;
    case 1:
        deleteItem();  // Удаление элемента
        break;
    case 2:
        addItem(list);  // Добавление элемента
        break;
    case 3:
        searchItem(list);  // Поиск
        break;
    case 4:
        openHTMLHelp();  // Открытие HTML-справки
        break;
    case 5:
        list.saveToFile("accounts.csv");  // Сохранение данных
        break;
    case 6:
        list.saveToFile("accounts.csv");  // Автосохранение перед выходом
        return false; // Завершаем программу
    default:
        cout << "Ошибка! Неверный выбор.\n";
        break;
    }

    system("pause");
    return true; // Продолжаем работу
}


// Функция для отображения всех аккаунтов
void BankAccountManager::listAccounts(BankAccountList& list) {
    list.printList();  // Выводим список аккаунтов
}

// Функция для удаления аккаунта
void BankAccountManager::deleteItem() {
    int indexToDelete;
    cout << "\nВведите номер элемента для удаления: ";
    cin >> indexToDelete;

    list.deleteAccountByIndex(indexToDelete);  // Удаляем аккаунт по индексу
}


// Функция для добавления нового аккаунта
void BankAccountManager::addItem(BankAccountList& list) {
    PBA newAccount;

    cout << "Введите Ф.И.О: ";
    cin.ignore();
    getline(cin, newAccount.name);

    cout << "Введите номер телефона: ";
    cin >> newAccount.telephone;

    cout << "Введите дату заключения кредита: ";
    cin >> newAccount.data;

    cout << "Введите домашний адрес: ";
    cin.ignore();
    getline(cin, newAccount.address);

    cout << "Введите номер карты: ";
    cin >> newAccount.card;

    cout << "Введите номер банковского счета: ";
    cin >> newAccount.account;

    list.addAccount(newAccount);  // Добавляем новый аккаунт в базу данных
    cout << "\nАккаунт успешно добавлен.";
}

// Функция для поиска аккаунта
void BankAccountManager::searchItem(BankAccountList& list) {
    string searchQuery;

    cout << "Введите данные для поиска (Ф.И.О., телефон, номер счета): ";
    cin.ignore();
    getline(cin, searchQuery);

    list.searchAccount(searchQuery);  // Поиск по базе данных
}

// Функция для открытия HTML справки
void BankAccountManager::openHTMLHelp() {
    system("start help.html");  // Открытие HTML файла с помощью браузера
}
