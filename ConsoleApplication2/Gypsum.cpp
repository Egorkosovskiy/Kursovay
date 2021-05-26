#include <iostream>

#include <string>

#include "fstream"

#include <Windows.h>

#include"Gypsum.h"

using namespace std;

Gypsum::Gypsum() : material_tech()

{

	material = "";

}

Gypsum::Gypsum(const Gypsum& temp) :material_tech(temp)

{

	material = temp.material;

}

void Gypsum::print_information()

{

	material_tech::print_information();

	cout << "Введите марку прочности продукта(100,200,300,400,500) " << material << endl;

}

string Gypsum::get_material()const

{

	return material;

}

void Gypsum::set_material(string material)

{

	this->material = material;

}

Gypsum& Gypsum::operator=(const Gypsum& comp)

{

	material_tech::operator=(comp);

	material = comp.material;

	return *this;

}

void Gypsum::write_file(string word)

{

	material_tech::write_file(word);

	ofstream file(word, ios::app);

	file << "Введите марку прочности продукта(100,200,300,400,500) ";

	file << material << endl;

	file.close();

}

void Gypsum::read_file(ifstream& file)

{

	material_tech::read_file(file);

	getline(file, material);

}

void Gypsum::zapis()

{

	material_tech::zapis();

	cout << "Введите марку прочности продукта(100,200,300,400,500) ";

	cin >> material;

}