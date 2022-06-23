#include "Funcs.h"

int hash_f(string str)
{
    int sum = 0;
    for (int i = 0; i < str.length(); i++) {
        sum += str[i];
    }
    return sum % NUM;
}

void output(arr* tab, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr* ptr = &tab[i];
        cout << "—трока " << i + 1 << ":\n";
        do
        {
            if (ptr->str[0] == '\0')
            {
                cout << "ѕусто \n";
                break;
            }
            else
            {
                cout << "ƒанные: " << ptr->str << " Ќомер телефона: " << ptr->TelNumber << endl;
            }
        } while (ptr = ptr->next);
    }
}
void dlt(arr* tab, int size, int TelNumber)
{
    int k = hash_f(to_string(TelNumber));
    while (k > size - 1) k -= size;
    arr* ptr = &tab[k];
    if (ptr->TelNumber == TelNumber)
    {
        if (ptr->next) //удаление, если есть в €чейке еще один элемент, удал€ет последний
        {
            ptr->next = ptr->next->next;
            ptr->TelNumber = ptr->TelNumber;
            ptr->str = ptr->str;
        }
        else //если нет ссылки на другую €чейку
        {
            ptr->TelNumber = 0;
            ptr->str = '\0';
        }
        return;
    }
    if (ptr->TelNumber)
    {
        arr* ptr_prev = new arr;
        while (ptr->next && ptr->next->TelNumber != TelNumber)
        {
            ptr_prev = ptr;
            ptr = ptr->next;
        }
        if (ptr->TelNumber == TelNumber)
        {
            ptr_prev->next = ptr->next;
            delete ptr;
            return;
        }
        cout << "ќшибка\n";
        exit(1);
    }
    cout << "Ёлемент не найден\n";
    return;
}
void input(arr* tab, int size, string str, int TelNumber)
{
    int k = hash_f(to_string(TelNumber));
    while (k > size - 1) k -= size; //регул€ци€ размера ключа/строки, чтобы он был в пределе строк таблицы
    arr* ptr = &tab[k];
    if (!ptr->TelNumber)
    {
        ptr->next = NULL;
        ptr->str = str;
        ptr->TelNumber = TelNumber;
    }
    else //если ключи схожи, создаетс€ ссылка на другой элемент в той жк €чейке
    {
        while (ptr->next) ptr = ptr->next; //предыдущему элементу присваиваетс€ ссылка на новый элемент
        arr* p = new arr;
        p->next = NULL;
        p->str = str;
        p->TelNumber = TelNumber;
        ptr->next = p;
    }
}
void search(arr* tab, int size, int TelNumber)
{
    int k = hash_f(to_string(TelNumber));
    while (k > size - 1) k -= size;
    arr* ptr = &tab[k];
    if (ptr->TelNumber)
    {
        while (ptr->next && ptr->TelNumber != TelNumber)
        {
            ptr = ptr->next;
        }
        if (ptr->TelNumber == TelNumber)
        {
            cout << " люч: " << ptr->TelNumber << " ƒанные: " << ptr->str << endl;
            return;
        }
        cout << "ќшибка\n";
        exit(1);
    }
    cout << "Ёлемент не найден\n";
    return;
}