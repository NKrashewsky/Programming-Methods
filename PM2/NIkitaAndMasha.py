from abc import ABC, abstractmethod
import random


class BaseSequence(ABC):

    def __init__(self, sequence=None):
        self.sequence = sequence if sequence else []

    @abstractmethod
    def print_sequence(self):
        pass

    @abstractmethod
    def save_to_file(self, filename):
        pass

    @abstractmethod
    def __del__(self):
        pass


class Sequence(BaseSequence):

    # Конструктор
    def __init__(self, sequence=None, size=None, mode=None):

        # Готовая последовательность
        if sequence is not None:
            super().__init__(sequence)

        # Ручной ввод
        elif size == "manual":

            n = int(input("Введите количество элементов: "))

            self.sequence = []

            for i in range(n):
                value = int(input(f"Введите элемент {i + 1}: "))
                self.sequence.append(value)

        # Случайная генерация
        elif size is not None:
            self.sequence = self.generate_sequence(size, mode)

        else:
            self.sequence = []

    # Генерация последовательности
    def generate_sequence(self, size, mode=None):

        seq = [random.randint(-20, 20)]

        for i in range(1, size):

            if mode == "возрастающая":
                seq.append(seq[-1] + random.randint(1, 10))

            elif mode == "убывающая":
                seq.append(seq[-1] - random.randint(1, 10))

            elif mode == "неубывающая":
                seq.append(seq[-1] + random.randint(0, 10))

            elif mode == "невозрастающая":
                seq.append(seq[-1] - random.randint(0, 10))

            else:
                seq.append(random.randint(-20, 20))

        return seq

    # Вывод
    def print_sequence(self):
        print("Последовательность:", self.sequence)

    # Определение типа
    def determine_type(self):

        inc = all(self.sequence[i] < self.sequence[i + 1]
                  for i in range(len(self.sequence) - 1))

        dec = all(self.sequence[i] > self.sequence[i + 1]
                  for i in range(len(self.sequence) - 1))

        non_dec = all(self.sequence[i] <= self.sequence[i + 1]
                      for i in range(len(self.sequence) - 1))

        non_inc = all(self.sequence[i] >= self.sequence[i + 1]
                      for i in range(len(self.sequence) - 1))

        if inc:
            print("Последовательность возрастающая")

        elif dec:
            print("Последовательность убывающая")

        elif non_dec:
            print("Последовательность неубывающая")

        elif non_inc:
            print("Последовательность невозрастающая")

        # Арифметическая прогрессия
        if len(self.sequence) >= 2:

            d = self.sequence[1] - self.sequence[0]

            arithmetic = all(
                self.sequence[i + 1] - self.sequence[i] == d
                for i in range(len(self.sequence) - 1)
            )

            if arithmetic:
                print("Это арифметическая прогрессия")

        # Геометрическая прогрессия
        if len(self.sequence) >= 2 and self.sequence[0] != 0:

            q = self.sequence[1] / self.sequence[0]

            geometric = all(
                self.sequence[i] != 0 and
                self.sequence[i + 1] / self.sequence[i] == q
                for i in range(len(self.sequence) - 1)
            )

            if geometric:
                print("Это геометрическая прогрессия")

    # Запись в файл
    def save_to_file(self, filename):

        with open(filename, "w", encoding="utf-8") as file:
            file.write(" ".join(map(str, self.sequence)))

        print("Данные сохранены в файл")

    # Чтение из файла
    @classmethod
    def load_from_file(cls, filename):

        with open(filename, "r", encoding="utf-8") as file:
            data = list(map(int, file.read().split()))

        return cls(data)

    # Проверка принадлежности
    def contains(self, element):

        if element in self.sequence:
            print("Элемент принадлежит последовательности")

        else:
            print("Элемент не принадлежит последовательности")

    # Сравнение
    def compare(self, other):

        if self.sequence == other.sequence:
            print("Последовательности равны")

        elif len(self.sequence) > len(other.sequence):
            print("Первая последовательность длиннее")

        elif len(self.sequence) < len(other.sequence):
            print("Вторая последовательность длиннее")

        else:
            print("Последовательности имеют одинаковую длину")

    # Максимум и минимум
    def max_min(self):

        print("Максимум:", max(self.sequence))
        print("Минимум:", min(self.sequence))

    # Подпоследовательности
    def subsequences(self):

        positive = [x for x in self.sequence if x > 0]
        negative = [x for x in self.sequence if x < 0]
        zeros = [x for x in self.sequence if x == 0]

        local_max = []
        local_min = []

        for i in range(1, len(self.sequence) - 1):

            if self.sequence[i] > self.sequence[i - 1] and \
               self.sequence[i] > self.sequence[i + 1]:
                local_max.append(self.sequence[i])

            if self.sequence[i] < self.sequence[i - 1] and \
               self.sequence[i] < self.sequence[i + 1]:
                local_min.append(self.sequence[i])

        print("Положительные:", positive)
        print("Отрицательные:", negative)
        print("Нули:", zeros)
        print("Локальные максимумы:", local_max)
        print("Локальные минимумы:", local_min)

    # Наибольшая и наименьшая подпоследовательности
    def subsequence_lengths(self):

        max_seq = []
        min_seq = []

        current = [self.sequence[0]]

        for i in range(1, len(self.sequence)):

            if self.sequence[i] >= self.sequence[i - 1]:
                current.append(self.sequence[i])

            else:

                if len(current) > len(max_seq):
                    max_seq = current

                if not min_seq or len(current) < len(min_seq):
                    min_seq = current

                current = [self.sequence[i]]

        if len(current) > len(max_seq):
            max_seq = current

        if not min_seq or len(current) < len(min_seq):
            min_seq = current

        print("Наибольшая подпоследовательность:", max_seq)
        print("Наименьшая подпоследовательность:", min_seq)

    # Экстраполяция
    def extrapolate(self, n):

        if len(self.sequence) < 2:
            print("Недостаточно элементов")
            return

        d = self.sequence[1] - self.sequence[0]

        arithmetic = all(
            self.sequence[i + 1] - self.sequence[i] == d
            for i in range(len(self.sequence) - 1)
        )

        if arithmetic:

            last = self.sequence[-1]

            for i in range(n):
                last += d
                self.sequence.append(last)

            print("Экстраполяция выполнена")
            return

        if self.sequence[0] != 0:

            q = self.sequence[1] / self.sequence[0]

            geometric = all(
                self.sequence[i] != 0 and
                self.sequence[i + 1] / self.sequence[i] == q
                for i in range(len(self.sequence) - 1)
            )

            if geometric:

                last = self.sequence[-1]

                for i in range(n):
                    last *= q
                    self.sequence.append(int(last))

                print("Экстраполяция выполнена")
                return

        print("Последовательность не является прогрессией")

    # Деструктор
    def __del__(self):
        print("Объект Sequence удалён")




seq1 = Sequence(size="manual")

seq1.print_sequence()

seq1.determine_type()

seq1.max_min()

seq1.subsequences()

seq1.subsequence_lengths()

seq1.contains(5)

seq1.extrapolate(3)

seq1.print_sequence()

seq1.save_to_file("sequence.txt")


# Чтение из файла
seq2 = Sequence.load_from_file("sequence.txt")

seq2.print_sequence()

seq1.compare(seq2)


# Случайная возрастающая последовательность
seq3 = Sequence(size=10, mode="возрастающая")

seq3.print_sequence()

seq3.determine_type()