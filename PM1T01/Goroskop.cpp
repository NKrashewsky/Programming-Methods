#include <iostream>
#include <string>
#include <locale>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int day, month, years, gg, st, i, j, k;
    string lasts;
    vector<string> year = {
        "крысы", "быка", "тигра",
        "кролика/кота","дракона", "змеи",
        "лошади", "козы", "обезьяны",
        "петуха", "собаки", "свиньи"
    };
    vector<string> mw = { "Женская(Инь)", "Мужская(Ян)" };
    vector<string> s = { "земля", "вода", "дерево", "огонь", "земля" };

    cout << "Введите день своего рождения: ";
    cin >> day;
    if (day > 31)
        while (day > 31)
        {
            cout << "Вы неправильно ввели день рождения, введите его ещё раз: ";
            cin >> day;
        }
    cout << "Введите месяц своего рождения: ";
    cin >> month;
    if (month > 12 || month == 0)
        while (month > 12 || month == 0)
        {
            cout << "Вы неправильно ввели месяц, введите ещё раз: ";
            cin >> month;
        }
    if ((month == 4 || month == 6 || month == 9 || month == 11 || month == 8) && day == 31)
        while (day >= 31)
        {
            cout << "Вы неправильно ввели день, в вашем месяце 30 дней! Введите ещё раз: ";
            cin >> day;
        }
    if (month == 2 && day > 29)
        while (day > 29)
        {
            cout << "Вы неправильно ввели день, в вашем месяце 28/29 дней!!! Введите ещё раз: ";
            cin >> day;
        }
    cout << "Введите год своего рождения: ";
    cin >> years;
    if ((years % 4 != 0) && (month == 2))
        while (day > 28)
        {
            cout << "Ваш год не високосный, в вашем месяце 28 дней, введите день ещё раз: ";
            cin >> day;
        }

    gg = years % 12;
    st = years % 10;

    k = st / 2;

    if ((gg - 4) >= 0 && (gg - 4) <= 7) {
        i = gg - 4;
    }

    if (gg >= 0 && gg <= 3) {
        i = gg + 8;
    }


    if (i % 2 == 0)
        j = 1;
    else
        j = 0;

    lasts = year[i][year[i].length() - 1];

    if (lasts == "ы" || lasts == "и")
    {
        s[0] = "металлической";
        s[1] = "водяной";
        s[2] = "деревянной";
        s[3] = "огненной";
        s[4] = "земляной";
    }
    else
    {
        s[0] = "металлического";
        s[1] = "водяного";
        s[2] = "деревянного";
        s[3] = "огненного";
        s[4] = "земляного";
    }

    cout << "Вы родились в год " << s[k] << " " << year[i] << endl;
    cout << "Тип вашей энергии : " << mw[j];
}