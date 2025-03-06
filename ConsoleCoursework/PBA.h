#ifndef PBA_H
#define PBA_H

#include <string>
using namespace std;

// Структура для персонального банковского аккаунта
struct PBA {
    string name;         // Фамилия Имя Отчество
    string telephone;    // Номер телефона +7(***)***-**-**
    string data;         // Дата заключения кредита
    string address;      // Домашний адрес
    string card;         // Номер карты
    string account;      // Номер банковского счета
    PBA* next = NULL;    // Указатель на следующий элемент
};

#endif // PBA_H
