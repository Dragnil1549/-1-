#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int rec(int kol)
{
    if (kol == 1)
    {
        //return 0;
    }
    if (kol == 2)
    {
        //return 1;
    }
    return rec(kol - 1) + rec(kol - 2);
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите число (меньше 50) \n";
    cin >> n;
    time_t start = time(0);
    int *a = new int[n];
    a[0] = 0;
    a[1] = 1;
    if (n < 2)
    {
        cout << a[n];
        exit;
    }
    for (int i = 2; i < n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    cout << a[n - 1] << "\n";
    cout << (time(NULL) - start) / 60 << "минут" << time(NULL) - start << "сукунд" << (time(NULL) - start) * 60 << "милсек" "\n";
    
    cout << rec(n) << "\n";
    cout << (time(NULL) - start) / 60 << "минут" << time(NULL) - start << "секунд" << (time(NULL) - start) * 60 << "милсек" "\n";
}

