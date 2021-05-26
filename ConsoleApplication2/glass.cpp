#include <iostream>

#include <string>

#include "fstream"

#include <Windows.h>

#include"glass.h"

using namespace std;

glass::glass() :Gypsum()

{

	material = "";

}

glass::glass(const glass& temp) :Gypsum(temp)

{

	material = temp.material;

}

void glass::print_information()

{

	Gypsum::print_information();

	cout << "Цвет: " << material << endl;

}

string glass::get_material()const

{

	return material;

}

void glass::set_material(string material)

{

	this->material = material;

}

glass& glass::operator=(const glass& comp)

{

	Gypsum::operator=(comp);

	material = comp.material;

	return *this;

}

void glass::write_file(string word)

{

	Gypsum::write_file(word);

	ofstream file(word, ios::app);

	file << "Цвет: ";

	file << material << endl;

	file.close();

}

void glass::read_file(ifstream& file)

{

	Gypsum::read_file(file);

	getline(file, material);

}

void glass::zapis()

{

	Gypsum::zapis();

	cout << "Цвет: ";

	cin >> material;

}