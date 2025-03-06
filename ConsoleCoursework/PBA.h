#ifndef PBA_H
#define PBA_H

#include <string>
using namespace std;

// ��������� ��� ������������� ����������� ��������
struct PBA {
    string name;         // ������� ��� ��������
    string telephone;    // ����� �������� +7(***)***-**-**
    string data;         // ���� ���������� �������
    string address;      // �������� �����
    string card;         // ����� �����
    string account;      // ����� ����������� �����
    PBA* next = NULL;    // ��������� �� ��������� �������
};

#endif // PBA_H
