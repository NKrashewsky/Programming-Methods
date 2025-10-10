#include <iostream>
#include <ctime>
#include <locale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int year, month, day;
    cout << "Введите год: ";
    cin >> year;
    cout << "Введите месяц: ";
    cin >> month;
    cout << "Введите день: ";
    cin >> day;

    int days_in_months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        days_in_months[1] = 29;
    }

    int next_day = day + 1;
    int next_month = month;
    int next_year = year;

    if (next_day > days_in_months[month - 1])
    {
        next_day = 1;
        next_month++;
        if (next_month > 12)
        {
            next_month = 1;
            next_year++;
        }
    }

    int previous_day = day - 1;
    int previous_month = month;
    int previous_year = year;

    if (previous_day < 1)
    {
        previous_month--;
        if (previous_month < 1)
        {
            previous_month = 12;
            previous_year--;
        }
        previous_day = days_in_months[previous_month - 1];
    }

    cout << "Предыдущий день: " << previous_day << "." << previous_month << "." << previous_year << endl;
    cout << "Следующий день: " << next_day << "." << next_month << "." << next_year << endl;

    return 0;
}