#include "iostream"
#include <random>
#include <ctime>
#include <cmath>
int comp(const int* i, const int* j)
{
    return *i - *j;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    std::cout << "Введите кол-во чисел \n";
    int n;
    std::cin >> n;
    int *a =new int[n], *b=new int[n], *c=new int[n], *d=new int[n], *e=new int[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = -20 + rand() % 100;
        std::cout << a[i] << " ";
        b[i] = c[i] = d[i] = e[i] = a[i];
    }
    int buf = 0;
    std::cout << "\n \n";
    std::cout << "\n \n";
    std::cout << "\n \n";
    
    clock_t start = clock();
    for (int i = 0; i < n; i++)
    {
        for (int i = 1; i < (n - 1); i++)
        {
            if (b[i] < b[i - 1])
            {
                buf = b[i - 1];
                b[i - 1] = b[i];
                b[i] = buf;
            }
            if (b[i] > b[i + 1])
            {
                buf = b[i + 1];
                b[i + 1] = b[i];
                b[i] = buf;

            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << b[i] << " ";
    }
    std::cout << "\n";
    clock_t end = clock();
    std::cout << "Времени затрачено " << (end - start) << "\n \n";
    
    start = clock();
    int q = 0, count = 0;
    q = n;
    q = q / 2;
    while (q > 0)
    {
        for (int i = 0; i < n - q; i++)
        {
            int j = i;
            while (j >= 0 && c[j] > c[j + q])
            {
                count = c[j];
                c[j] = c[j + q];
                c[j + q] = count;
                j--;
            }
        }
        q = q / 2;
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << c[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Времени затрачено " << (clock() - start) << "\n \n";
    std::cout << "\n \n";
    
    start = clock();
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 && d[j - 1] > d[j]; j--)
        {
            std::swap(d[j - 1], d[j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << d[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Времени затрачено " << (clock() - start) << "\n \n";
    std::cout << "\n \n";
    
    start = clock();
    std::qsort(e, 10, sizeof(int), (int(*) (const void*, const void*)) comp);
    for (int i = 0; i < n; i++)
    {
        std::cout << e[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Времени затрачено " << (clock() - start) << "\n \n";
    std::cout << "\n \n";
}