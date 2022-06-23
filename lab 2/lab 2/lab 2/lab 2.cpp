#include <iostream>
#include <cmath>
int main()
{
    setlocale(LC_ALL,"Russian");
    std::cout << "Введите предел значения \n";
    int max;
    std::cin >> max;
    short ans = 0;
    int res = 0;
    int min = 1;
    int counter = 0;
    while (ans != 1)
    {
        counter++;
        res = (min + max) / 2;
        std::cout << "Ваше число равно " << res << "\n";
        std::cout << "1)Да \n";
        std::cout << "2)Много \n";
        std::cout << "3)Мало \n";
        std::cin >> ans;
        if (ans == 2)
        {
            max = res;
        }
        else
        {
            min = res;
        }
    }
    std::cout << "Для нахождения числа понадобилось " << counter << " попыток \n";
}
