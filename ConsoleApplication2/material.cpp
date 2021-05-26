#include <iostream>

#include <string>

#include "fstream"

#include <Windows.h>

#include "material.h"

using namespace std;

material::material()

{

	name = "";

	brand = "";

	color = "";

	price = 0;

}

material::material(const material& temp)

{

	name = temp.name;

	brand = temp.brand;


	price = temp.price;

}

void material::print_information()

{

	cout << "Название: " << name << endl;

	cout << "Производитель: " << brand << endl;

	cout << "Колличество (шт/кг): " << color << endl;

	cout << "Цена: " << price << endl;

}

double material::get_price() const

{

	return price;

}

string material::get_name() const

{

	return name;

}

string material::get_brand() const

{

	return brand;

}

void material::set_price(double price)

{

	this->price = price;

}

void material::set_name(string name)

{

	this->name = name;

}

void material::set_brand(string brand)

{

	this->brand = brand;

}
string material::get_color()const

{

	return color;

}

void material::set_color(string color)

{

	this->color = color;

}





material& material::operator=(const material& comp)

{

	price = comp.price;

	name = comp.name;

	brand = comp.brand;

	color = comp.color;


	return *this;

}

void material::write_file(string word)

{

	ofstream file(word, ios::app);

	file << "Название: ";

	file << name << endl;

	file << "Производитель: ";

	file << brand << endl;

	file << "Цена: ";

	file << price << endl;

	file << "Колличество (шт/кг)  ";

	file << color << endl;

	file.close();

}

void material::read_file(ifstream& file)

{

	getline(file, name);

	getline(file, brand);


	file >> price;

}

void material::zapis()

{

	cout << "Название  ";

	cin >> name;

	cout << "Производитель: ";

	cin >> brand;

	cout << "Цена: ";

	cin >> price;

	cout << "Колличество (шт/кг): ";

	cin >> color;


	

}