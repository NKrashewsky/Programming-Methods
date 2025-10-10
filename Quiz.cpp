#include <iostream>
#include <string>
#include <ctime>
#include <locale>


const int q = 10;

using namespace std;
void cls() {
#ifdef WINDOWS
    system("cls");
#endif
#ifdef LINUX
    system("clear");
#endif
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    bool repeatDialog = true;
    unsigned int res;
    float score = 0;

    cls();
    cout << "Предлагаем пройти вам квиз" << endl;
    
    string questions[] = {
        "Дата основания мехмата?",
        "Мехмат - это факультет чего?",
        "Кто сейчас декан?",
        "Кто такая Нина?",
        "Что будет написано у кмов?",
        "Когда капуста?",
        "Какая кричалка у мехмата?",
        "Присутствовали ли бы вы на паре Щегловой в 19:10?",
        "Понимаете ли вы, что говорит Малевич?",
        "Второй закон системного анализа?"
    };
    string answers[] = {
    "1958", "1984", "1972",
    "Денег", "Любви", "Славы",
    "Базылев", "Курсов", "Босяков",
    "Ведущий специалист по отчислениям", "Заместитель декана", "Доцент кафедры алгебры",
    "Смерть в нищете", "Математик.Системный аналитик", "Математик.Преподаватель",
    "5", "4", "Ее отменили",
    "Шах и мат - это мехмат", "Мехмат - это сила", "Мехмат спереди, остальные сзади(Ауф)",
    "Да", "Выбрал быть счастливым", "Не знаю",
    "Я киборг и я понимаю", "Нет", "Я не понимаю где я",
    "1-3-7", "Инь-янь", "Здесь и сейчас"
    };
    float scores[] = { // max 11.5
                        // min 3.25
        1, 0, 0,
        0.5, 1, 0.5,
        0.5, 0.75, 1,
        1, 0, 0,
        0.25, 1, 0.5,
        0, 1, 0,
        1, 0.5, 0.75,
        1, 1, 1,
        1.5, 0.5, 1,
        0, 2, 0
    };
    int variant = 0;
    string awards[] = {
        "Абитуриент",
        "Первокурсник",
        "Знаток мехмата",
        "Легенда мехмата"
    };
    while (repeatDialog) {
        //cls();
        for (int i = 0; i < q; i++) {
            cout << questions[i] << endl;
            cout << 1 << "." << answers[3*i] << endl;
            cout << 2 << "." << answers[3*i + 1] << endl;
            cout << 3 << "." << answers[3*i + 2] << endl;
            cout << "Введите вариант ответа: " << endl;
            cin >> variant;
            switch (variant) {
            case 1:
            case 2:
            case 3:
                score += scores[3 * i + variant - 1];
                break;
            default:
                cout << "Неправильный вариант ответа.Выберите 1, 2, 3" << endl;
                cin >> variant;
            }
            
        }
        repeatDialog = false;
        
        switch (int (score)) {
        case 3:
        case 4:
            cout << awards[0];
            break;
        case 5:
        case 6:
        case 7:
            cout << awards[1];
            break;
        case 8:
        case 9:
        case 10:
            cout << awards[2];
            break;
        default:
            cout << awards[3];
        }
    }

    return 0;
}

