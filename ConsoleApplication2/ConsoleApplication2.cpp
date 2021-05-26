// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>

#include <string>

#include "fstream"

#include <Windows.h>

#include "material.h"


#include "material_tech.h"

#include "Cement.h"

#include "Gypsum.h"

#include "glass.h"

#include "Wood.h"

#include "Bitumen.h"



#include "Steel_piles.h"

#include "material_tech2.h"

#include "Polymer_pipes.h"

#include "Imaterial.h"

#include "Vector.h"

#include "Exception.h"

using namespace std;

template<class T>

bool sort_price(const T& stat1, const T& stat2) {

	if (stat1->get_price() < stat2->get_price()) return true;

	return false;

}

template<class T>

bool FindByName(string value, const T& stat) {

	if (value == stat->get_name()) return true;

	return false;

}

int main()

{

	SetConsoleCP(1251);

	SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "Russian");

	int choose, temp = 1, count, i = 0, num_error = 1;

	cout << "Введите размер корзины: ";

	cin >> count;

	Vector<material*>vector(count);

	cout << "Выберите, каким образом Вы хотите добавить материал в корзину:" << endl;

	cout << "1 - ввод с клавиатуры" << endl;

	cout << "2 - ввод из файла" << endl;

	cout << "0 - выход из программы" << endl;

	cin >> choose;

	switch (choose)

	{

	case 0:

		return 0;

	case 1:

		while (i < count)

		{

			cout << "Выберите, что хотите  заказать? :" << endl;

			cout << "1 - Цемент/песок" << endl;

			cout << "2 - Гипс/бетон" << endl;

			cout << "3 - стекольныая продукция" << endl;

			cout << "4 - Доски" << endl;

			cout << "5 - Полимерные трубы-" << endl;

			cout << "6 - Стальные сваи" << endl;

	

			int object;

			cin >> object;

			switch (object)

			{

			case 1:

				vector.Plus(new Cement(), i);

				vector(i)->zapis();

				break;

			case 2:

				vector.Plus(new Gypsum(), i);

				vector(i)->zapis();

				break;

			case 3:

				vector.Plus(new glass(), i);

				vector(i)->zapis();

				break;

			case 4:

				vector.Plus(new Wood(), i);

				vector(i)->zapis();

				break;

		

			

			case 5:

				vector.Plus(new Polymer_pipes(), i);

				vector(i)->zapis();

				break;

			case 6:

				vector.Plus(new Steel_piles(), i);

				vector(i)->zapis();

				break;

			}

			i++;

		}

		break;

	case 2:

		string put;

		cout << "Введите путь до файла: ";

		cin >> put;

		while (i < count)

		{

			cout << "Выберите класс файла:" << endl;

			cout << "1 - Цемент/песок" << endl;

			cout << "2 - Гипс/бетон" << endl;

			cout << "3 - стекольныая продукция" << endl;

			cout << "4 - Доски" << endl;

			cout << "5 - Полимерные трубы-" << endl;

			cout << "6 - Стальные сваи" << endl;

			int object;

			cin >> object;

			try {

				switch (object)

				{

				case 1:

				{

					vector.Plus(new Cement(), i);

					ifstream is(put.c_str());

					if (!is) throw Exception("Не удаётся открыть файл");

					else

					{

						vector(i)->read_file(is);

						is.close();

					}

					break;

				}

				case 2:

				{

					vector.Plus(new Gypsum(), i);

					ifstream is(put.c_str());

					if (!is) throw Exception("Не удаётся открыть файл");

					else

					{

						vector(i)->read_file(is);

						is.close();

					}

					break;

				}

				case 3:

				{

					vector.Plus(new glass(), i);

					ifstream is(put.c_str());

					if (!is) throw Exception("Не удаётся открыть файл");

					else

					{

						vector(i)->read_file(is);

						is.close();

					}

					break;

				}

				case 4:

				{

					vector.Plus(new Wood(), i);

					ifstream is(put.c_str());

					if (!is) throw Exception("Не удаётся открыть файл");

					else

					{

						vector(i)->read_file(is);

						is.close();

					}

					break;

				}

				

				

				case 5:

				{

					vector.Plus(new Polymer_pipes(), i);

					ifstream is(put.c_str());

					if (!is) throw Exception("Не удаётся открыть файл");

					else

					{

						vector(i)->read_file(is);

						is.close();

					}

					break;

				}

				case 6:

				{

					vector.Plus(new Steel_piles(), i);

					ifstream is(put.c_str());

					if (!is) throw Exception("Не удаётся открыть файл");

					else

					{

						vector(i)->read_file(is);

						is.close();

					}

					break;

				}

				}

			}

			catch (Exception& beda_file)

			{

				cout << "Ошибка " << num_error << endl;

				cout << beda_file.get_error() << endl;

				num_error++;

			}

			i++;

		}

		break;

	}

	while (temp != 0)

	{

		cout << "Выберите действие:" << endl;

		cout << "1 - очистка объектов" << endl;

		cout << "2 - отсортировать по цене" << endl;

		cout << "3 - вывод всей информации об объекте" << endl;

		cout << "4 - поиск объекта" << endl;

		cout << "5 - запись в файл" << endl;

		cout << "0 - выход" << endl;

		cin >> choose;

		string number;

		try {

			switch (choose)

			{

			case 0:

				temp = 0;

				break;

			case 1:

				vector.clear();

				cout << "Очищено" << endl;

				break;

			case 2:

				vector.sort(sort_price);

				break;

			case 3:

				cout << "Всего элементов: " << vector.length() << endl;

				vector.print();

				break;

			case 4:

			{

				cout << "Введите название объекта: " << endl;

				cin >> number;

				material** temp = vector.Search(number, FindByName);

				if (temp == nullptr) cout << "Вашего элемента не существует..." << endl;

				else (*temp)->print_information();

				break;

			}

			case 5:

				if (vector.i == 0)throw Exception("Элементов нет");

				int num;

				string put;

				cout << "Введите номер, записываемого объекта: ";

				cin >> num;

				cout << "Укажите путь для сохранения файла: ";

				cin >> put;

				vector(num - 1)->write_file(put);

				break;

			}

		}

		catch (Exception& beda)

		{

			cout << "Ошибка " << num_error << endl;

			cout << beda.get_error() << endl;

			num_error++;

		}

	}

	system("pause");

	return 0;

}