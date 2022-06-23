
#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool Check(string&);

int main()
{
    setlocale(LC_ALL, "RU");

    string str;
    cout << "Введите строку \n";
    getline(cin, str);

    if (Check(str))
    {
        cout << "Верно";
    }
    else
    {
        cout << "Неверно";
    }

    return 0;
}

bool Check(string& str)
{
    stack<char> stack1;
    stack<char> stack2;

    for (char i : str)
    {
        if (i == '(' || i == ')' || i == '{' || i == '}' || i == '[' || i == ']')
        {
            if (stack1.size() && ((stack1.top() == '(' && i == ')') || (stack1.top() == '{' && i == '}') || (stack1.top() == '[' && i == ']')))
            {
                stack1.pop();
            }
            else stack1.push(i);
        }
    }

    if (stack1.size() % 2) return false;

    int Size = stack1.size() / 2;

    for (int i = 0; i < Size; i++)
    {
        stack2.push(stack1.top());
        stack1.pop();
    }

    char first, second;
    while (Size)
    {
        first = stack1.top();
        second = stack2.top();

        if (!((first == '(' && second == ')') || (first == '{' && second == '}') || (first == '[' && second == ']'))) return false;

        stack1.pop();
        stack2.pop();

        Size--;
    }

    return true;
}
