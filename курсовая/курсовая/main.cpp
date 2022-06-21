#include "kursovaya.h"

void menu()
{
	cout << "   1. Показать полный список стран" << endl;
	cout << "   2. Задать критерии" << endl;
	cout << "   3. Закрыть" << endl;
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	static int select;

	for (auto i = 0; i < 10; i++)
		user.price[i] = float(utils.random_int(50, 150));

	do
	{
		cout << "Ваша скидка: " << user.get_sale() << "%";
		cout << endl;

		menu();

		cout << "Выберите действие: ", cin >> select;

		switch (select)
		{
		case 1:
			settings.show_full_country_list();
			break;
		case 2:
			settings.criteria();
			break;
		}

		if (select != 3)
			system("pause");
	}
	while (select != 3);

	return 0;
}

