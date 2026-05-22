# Создать массив экземпляров структуры, которая хранит данные о клиентах прокатного ателье:
# Фамилия И.О. клиента, название костюма, инвентарный номер,
# цена проката за день, срок возврата костюма, был ли возвращен в срок.
# После этого сформировать "черный список" из ФИО тех, кто не вернул костюм вовремя.


from dataclasses import dataclass


@dataclass
class Client:
    fio: str
    costume: str
    inventory_number: int
    rent_price_per_day: float
    return_days: int
    returned_on_time: bool


# Массив клиентов
clients = []

# Количество клиентов
n = int(input("Введите количество клиентов: "))

# Ввод данных
for i in range(n):

    print(f"\nКлиент {i + 1}")

    fio = input("ФИО: ")
    costume = input("Название костюма: ")
    inventory_number = int(input("Инвентарный номер: "))
    rent_price_per_day = float(input("Цена проката за день: "))
    return_days = int(input("Срок возврата (в днях): "))

    answer = input("Возвращен в срок? (да/нет): ").lower()

    returned_on_time = answer == "да"

    client = Client(
        fio,
        costume,
        inventory_number,
        rent_price_per_day,
        return_days,
        returned_on_time
    )

    clients.append(client)



print("\nСписок клиентов:\n")

for client in clients:

    print("ФИО:", client.fio)
    print("Костюм:", client.costume)
    print("Инвентарный номер:", client.inventory_number)
    print("Цена за день:", client.rent_price_per_day)
    print("Срок возврата:", client.return_days)
    print("Возвращен вовремя:", "Да" if client.returned_on_time else "Нет")
    print()


# Формирование черного списка
black_list = []

for client in clients:

    if not client.returned_on_time:
        black_list.append(client.fio)


# Вывод черного списка
print("Черный список:\n")

if len(black_list) == 0:
    print("Нарушителей нет")

else:
    for person in black_list:
        print(person)