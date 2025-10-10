#include <iostream>
#include <locale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, k, p;

	cin >> n;

	k = n % 10;
	p = (n % 100) / 10;
	if (n == 0)
		cout << "Мы не собрали грибов в лесу";
	else
	{
		if ((k == 1 && p == 0) || (k == 1 && p != 1))
			cout << "Мы собрали " << n << " гриб";

		if ((k >= 2 && k <= 4 && p == 0) || (k >= 2 && k <= 4 && p != 1))
			cout << "Мы собрали " << n << " гриба";

		if ((p == 0 && k >= 5) || (p == 1) || (p > 1 && k >= 5))
			cout << "Мы собрали " << n << " грибов";
	}
}
