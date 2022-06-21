#pragma once

#include <string>
#include <iostream>
#include <windows.h>
#include <algorithm>

using namespace std;

class c_settings
{
public:
	// Set param
	void set_people();
	void set_price();
	void set_days();

	void show_full_country_list();
	void criteria();
private:
	float current_price(float price);

	struct
	{
		int people = 1;

		float min_price = 1.0f; // мин. цена задается в $ 
		float max_price = 1000.0f; // макс. цена задается в $ 
	}
	search_options;
};

inline c_settings settings;

class c_user
{
public:
	string buy = "";
	string country = "";
	int days = 1;

	float sale = 0;
	float price[10];

	float get_sale();
	float get_price(float price, int days);
};

inline c_user user;

class c_utils
{
public:
	constexpr uint32_t crc32(const char* str)
	{
		uint32_t crc = ~0;

		while (*str)
		{
			crc ^= *str++;

			for (uint8_t i = 0; i < 8; i++)
				crc = ((crc & 1) ? (crc >> 1) ^ 0xEDB88320 : (crc >> 1));
		}

		return crc;
	}

	int random_int(int min, int max)
	{
		return min + rand() % (max - min);
	}
};

inline c_utils utils;