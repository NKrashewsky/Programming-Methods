#include <locale>
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int mast, value;
    cout << "Введите масть: ";
    cin >> mast;
    cout << "Введите достоинство: ";
    cin >> value;

    switch (value)
    {
    case 6:
        cout << "шестерка ";
        break;
    case 7:
        cout << "семерка ";
        break;
    case 8:
        cout << "восьмерка ";
        break;
    case 9:
        cout << "девятка ";
        break;
    case 10:
        cout << "десятка ";
        break;
    case 11:
        cout << "валет ";
        break;
    case 12:
        cout << "дама ";
        break;
    case 13:
        cout << "король ";
        break;
    case 14:
        cout << "туз ";
        break;
    default:
        cout << "такого достоинства не существует :(" << "\n";
        break;
    }

    switch (mast)
    {
    case 1:
        cout << "пик" << "\n";
        break;
    case 2:
        cout << "трефы" << "\n";
        break;
    case 3:
        cout << "бубен" << "\n";
        break;
    case 4:
        cout << "червы" << "\n";
        break;
    default:
        cout << "такой масти не существует :(";
        break;
    }

}

