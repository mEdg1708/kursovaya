#include "kursovaya.h"

void c_settings::set_people()
{
	int people;

	cout << "Введите кол-во человек от 1 до 6: ", cin >> people;

	if (people >= 1 && people <= 6)
		this->search_options.people = people;
	else
	{
		cout << "Диапозон[1; 6]" << endl;
		cout << "Введите кол-во человек: ", cin >> people;
	}
}

void c_settings::set_price()
{
	float min_price, max_price;

	cout << "Введите мин. цену от 1 до 150: ", cin >> min_price;

	if (min_price >= 1.0f && min_price <= 150.0f)
		this->search_options.min_price = min_price;
	else
	{
		cout << "Диапозон[1; 150]" << endl;
		cout << "Введите мин. цену: ", cin >> min_price;
	}

	cout << "Введите макс. цену от 1 до 150: ", cin >> max_price;

	if (max_price >= 1.0f && max_price <= 150.0f)
		this->search_options.max_price = max_price;
	else
	{
		cout << "Диапозон[1; 150]" << endl;
		this->search_options.max_price = max_price;
	}
}

void c_settings::set_days()
{
	int days;

	cout << "Введите кол-во дней: ", cin >> days;

	if (days >= 1)
		user.days = days;
	else
	{
		cout << "Кол-во должно быть больше 1" << endl;
		cout << "Введите кол-во дней: ", cin >> days;
	}
}

float c_settings::current_price(float price)
{
	return (user.get_sale() != 0) ? (price - (user.get_sale() * (price / 100))) * this->search_options.people : (price * this->search_options.people);
}

void c_settings::show_full_country_list()
{
	const char* all_offers[10] =
	{
		"Turkey", "Egypt", "Greece", "Cyprus",
		"Cuba", "Dominican", "France", "Israel",
		"Germany", "Czech"
	};

	system("cls");

	for (auto i = 0; i < ARRAYSIZE(all_offers); i++)
		cout << all_offers[i] << endl;

	cout << endl;
	cout << "Выберите страну: ", cin >> user.country;
	cout << endl;

	if (utils.crc32(user.country.c_str()) == utils.crc32("Turkey"))
	{
		this->set_people();
		this->set_days();

		cout << "Цена чтобы поехать в " << all_offers[0] << ": " << current_price(user.get_price(user.price[0], user.days)) << "$" << endl;
	}
	else if (utils.crc32(user.country.c_str()) == utils.crc32("Egypt"))
	{
		this->set_people();
		this->set_days();

		cout << "Цена чтобы поехать в " << all_offers[1] << ": " << current_price(user.get_price(user.price[1], user.days)) << "$" << endl;
	}
	else if (utils.crc32(user.country.c_str()) == utils.crc32("Greece"))
	{
		this->set_people();
		this->set_days();

		cout << "Цена чтобы поехать в " << all_offers[2] << ": " << current_price(user.get_price(user.price[2], user.days)) << "$" << endl;
	}
	else if (utils.crc32(user.country.c_str()) == utils.crc32("Cyprus"))
	{
		this->set_people();
		this->set_days();

		cout << "Цена чтобы поехать в " << all_offers[3] << ": " << current_price(user.get_price(user.price[3], user.days)) << "$" << endl;
	}
	else if (utils.crc32(user.country.c_str()) == utils.crc32("Cuba"))
	{
		this->set_people();
		this->set_days();

		cout << "Цена чтобы поехать в " << all_offers[4] << ": " << current_price(user.get_price(user.price[4], user.days)) << "$" << endl;
	}
	else if (utils.crc32(user.country.c_str()) == utils.crc32("Dominican"))
	{
		this->set_people();
		this->set_days();

		cout << "Цена чтобы поехать в " << all_offers[5] << ": " << current_price(user.get_price(user.price[5], user.days)) << "$" << endl;
	}
	else if (utils.crc32(user.country.c_str()) == utils.crc32("France"))
	{
		this->set_people();
		this->set_days();

		cout << "Цена чтобы поехать в " << all_offers[6] << ": " << current_price(user.get_price(user.price[6], user.days)) << "$" << endl;
	}
	else if (utils.crc32(user.country.c_str()) == utils.crc32("Israel"))
	{
		this->set_people();
		this->set_days();

		cout << "Цена чтобы поехать в " << all_offers[7] << ": " << current_price(user.get_price(user.price[7], user.days)) << "$" << endl;
	}
	else if (utils.crc32(user.country.c_str()) == utils.crc32("Germany"))
	{
		this->set_people();
		this->set_days();

		cout << "Цена чтобы поехать в " << all_offers[8] << ": " << current_price(user.get_price(user.price[8], user.days)) << "$" << endl;
	}
	else if (user.country.c_str() == "Czech")
	{
		this->set_people();
		this->set_days();

		cout << "Цена чтобы поехать в " << all_offers[9] << ": " << current_price(user.get_price(user.price[9], user.days)) << "$" << endl;
	}
	else
	{
		system("cls");
		return;
	}

	cout << endl;
	cout << "Введите buy, чтобы купить: ", cin >> user.buy;

	if (utils.crc32(user.buy.c_str()) == utils.crc32("buy"))
	{
		user.sale += 5;
		system("cls");
		return;
	}
	else
	{
		system("cls");
		return;
	}
}

void c_settings::criteria()
{
	system("cls");

	this->set_price();

	const char* all_offers[10] =
	{
		"Turkey", "Egypt", "Greece", "Cyprus",
		"Cuba", "Dominican", "France", "Israel",
		"Germany", "Czech"
	};

	cout << endl;
	cout << "Вам доступны: ";
	cout << endl;

	for (auto i = 0; i < ARRAYSIZE(all_offers); i++)
	{
		if (user.price[i] < this->search_options.min_price || user.price[i] > this->search_options.max_price)
			continue;

		cout << all_offers[i] << endl;
	}

	cout << endl;
	cout << "Выберите страну: ", cin >> user.country;
	cout << endl;

	if (utils.crc32(user.country.c_str()) == utils.crc32("Turkey"))
	{
		this->set_people();
		this->set_days();

		cout << "Цена чтобы поехать в " << all_offers[0] << ": " << current_price(user.get_price(user.price[0], user.days)) << "$" << endl;
	}
	else if (utils.crc32(user.country.c_str()) == utils.crc32("Egypt"))
	{
		this->set_people();
		this->set_days();

		cout << "Цена чтобы поехать в " << all_offers[1] << ": " << current_price(user.get_price(user.price[1], user.days)) << "$" << endl;
	}
	else if (utils.crc32(user.country.c_str()) == utils.crc32("Greece"))
	{
		this->set_people();
		this->set_days();

		cout << "Цена чтобы поехать в " << all_offers[2] << ": " << current_price(user.get_price(user.price[2], user.days)) << "$" << endl;
	}
	else if (utils.crc32(user.country.c_str()) == utils.crc32("Cyprus"))
	{
		this->set_people();
		this->set_days();

		cout << "Цена чтобы поехать в " << all_offers[3] << ": " << current_price(user.get_price(user.price[3], user.days)) << "$" << endl;
	}
	else if (utils.crc32(user.country.c_str()) == utils.crc32("Cuba"))
	{
		this->set_people();
		this->set_days();

		cout << "Цена чтобы поехать в " << all_offers[4] << ": " << current_price(user.get_price(user.price[4], user.days)) << "$" << endl;
	}
	else if (utils.crc32(user.country.c_str()) == utils.crc32("Dominican"))
	{
		this->set_people();
		this->set_days();

		cout << "Цена чтобы поехать в " << all_offers[5] << ": " << current_price(user.get_price(user.price[5], user.days)) << "$" << endl;
	}
	else if (utils.crc32(user.country.c_str()) == utils.crc32("France"))
	{
		this->set_people();
		this->set_days();

		cout << "Цена чтобы поехать в " << all_offers[6] << ": " << current_price(user.get_price(user.price[6], user.days)) << "$" << endl;
	}
	else if (utils.crc32(user.country.c_str()) == utils.crc32("Israel"))
	{
		this->set_people();
		this->set_days();

		cout << "Цена чтобы поехать в " << all_offers[7] << ": " << current_price(user.get_price(user.price[7], user.days)) << "$" << endl;
	}
	else if (utils.crc32(user.country.c_str()) == utils.crc32("Germany"))
	{
		this->set_people();
		this->set_days();

		cout << "Цена чтобы поехать в " << all_offers[8] << ": " << current_price(user.get_price(user.price[8], user.days)) << "$" << endl;
	}
	else if (utils.crc32(user.country.c_str()) == utils.crc32("Czech"))
	{
		this->set_people();
		this->set_days();

		cout << "Цена чтобы поехать в " << all_offers[9] << ": " << current_price(user.get_price(user.price[9], user.days)) << "$" << endl;
	}
	else
	{
		system("cls");
		return;
	}

	cout << endl;
	cout << "Введите buy, чтобы купить: ", cin >> user.buy;

	if (utils.crc32(user.buy.c_str()) == utils.crc32("buy"))
	{
		user.sale += 5;
		system("cls");
		return;
	}
	else
	{
		system("cls");
		return;
	}
}

float c_user::get_sale()
{
	return std::clamp(this->sale, 0.0f, 20.0f);
}

float c_user::get_price(float price, int days)
{
	return days * price;
}
