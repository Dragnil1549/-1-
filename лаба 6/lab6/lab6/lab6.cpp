#include "Funcs.h"
#include <fstream>

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Введите размер таблицы: ";
    int size;
    cin >> size;
    arr* tab = new arr[size];
    int userChoise;
    do
    {
        system("cls");
        cout << "Выберите пункт меню:" << endl;
        cout << "1. Вывод всей таблицы" << endl;
        cout << "2. Добавление элемента" << endl;
        cout << "3. Поиск элемента" << endl;
        cout << "4. Удаление элемента" << endl;
        cout << "0. Выход" << endl;
        cin >> userChoise;
        switch (userChoise)
        {
        case 1:
        {
            output(tab, size);
            break;
        }
        case 2:
        {
            string str;
            int TelNumber;
            cout << "Введите ФИО: ";
            cin.ignore();
            getline(cin, str);
            cout << "Введите номер телефона: ";
            cin >> TelNumber;
            if (0 < TelNumber < INT_MAX)
            {
                input(tab, size, str, TelNumber);
            }
            else cout << "Недоступный номер\n";
            break;
        }
        case 3:
        {
            cout << "Введите номер телефона: ";
            int TelNumber;
            cin >> TelNumber;
            cin.ignore();
            int start = clock();
            search(tab, size, TelNumber);
            int end = clock();
            cout << "Время поиска: " << end - start << " мс" << endl;
            break;
        }
        case 4:
        {
            cout << "Введите номер телефона: ";
            int TelNumber;
            cin >> TelNumber;
            dlt(tab, size, TelNumber);
        }
        default:
            break;
        }
        system("pause");
    } while (userChoise);
}
