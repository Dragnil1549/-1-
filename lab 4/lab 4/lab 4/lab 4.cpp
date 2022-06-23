#include <iostream>
#include <random>
#include <set>
int main()
{
    setlocale(LC_ALL, "RUS");
    //task_1
    std::cout << "Введите число товаров (до 1000) ";
    int kol = 0;
    std::cin >> kol;
    double *a=new double[kol];
    for (int i = 0; i < kol; i++)
    {
        a[i] = rand() % 300 / 3.1;
    }

    std::cout << "\n";
    int buf = 0;
    for (int i = 0; i < kol; i++)
    {
        for (int i = 1; i < (kol - 1); i++)
        {
            if (a[i] < a[i - 1])
            {
                buf = a[i - 1];
                a[i - 1] = a[i];
                a[i] = buf;
            }
            if (a[i] > a[i + 1])
            {
                buf = a[i + 1];
                a[i + 1] = a[i];
                a[i] = buf;
            }
        }
    }
    for (int i = 0; i < kol; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
    double k = 0;
    k = kol / 2;
    k = round(k);
    k = (int)k + 1;
    double *expens = new double [(int)k];
    for (int i = 0; i < sizeof(expens) / 8; i++)
    {
        expens[i] = 0;
    }
    int j = 0;
    for (int i = kol / 2; i < kol; i++)
    {

        expens[j] = a[i];
        j++;
    }
    for (int i = 0; i < kol / 2 + 1; i++)
    {
        if (expens[i] != 0)
            std::cout << expens[i] << "\n";
        if (a[i] != expens[i])
        {
            std::cout << a[i] << " Но бесплатно" << "\n";
        }

    }
    int sum = 0;
    std::cout << "\n";
    for (int i = 0; i < kol / 2 + 1; i++)
    {
        sum += expens[i];
    }
    std::cout << "Сумма равна: " << sum << "\n";
    //task_2
    srand(time(0));
    std::cout << "Введите кол-во участников \n";
    unsigned int amount = 0;
    std::cin >> amount;
    unsigned int *res = new unsigned int[amount];
    for (int i = 0; i < amount; i++)
    {
        res[i] = rand() % 10 + 1;
        std::cout << res[i] << " ";
    }
    std::cout << "\n";
    for (int i = 0; i < amount; i++)
    {
        for (int i = 1; i < (amount - 1); i++)
        {
            if (res[i] < res[i - 1])
            {
                buf = res[i - 1];
                res[i - 1] = res[i];
                res[i] = buf;
            }
            if (res[i] > res[i + 1])
            {
                buf = res[i + 1];
                res[i + 1] = res[i];
                res[i] = buf;
            }
        }
    }

    int big[3];
    int i = 1;
    for (int j = 0; j <= 3; j++)
    {
        big[j] = res[amount - i];
        while (big[j] == res[amount - i])
        {
            i++;
        }
        if (j == 2)
        {
            break;
        }
        j++;
        big[j] = res[amount - i];
        i++;
    }
    for (int i = 0; i < 3; i++)
    {
        std::cout << big[i] << " ";
    }
    std::cout << "\n";
    int prizers = 0;
    for (int i = 0; i < amount; i++)
    {
        if ((res[i] == big[0]) || (res[i] == big[1]) || (res[i] == big[2]))
        {
            prizers++;
        }
    }
    std::cout << "Количество призеров равно: " << prizers << "\n";
}
