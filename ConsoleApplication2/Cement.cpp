#include <iostream>

#include <string>

#include "fstream"

#include <Windows.h>

#include"Cement.h"

using namespace std;

Cement::Cement() : material_tech()

{

	height = 0;

}

Cement::Cement(const Cement& chair) :material_tech(chair)

{

	height = chair.height;

}

void Cement::print_information()

{

	material_tech::print_information();

	cout << "Введите марку прочности продукта(100,200,300,400,500) : " << height << endl;

}

int Cement::get_kam()const

{

	return height;

}

void Cement::set_kam(int kam)

{

	this->height = kam;

}

Cement& Cement::operator=(const Cement& comp)

{

	material_tech::operator=(comp);

	height = comp.height;

	return *this;

}

void Cement::write_file(string word)

{

	material_tech::write_file(word);

	ofstream file(word, ios::app);

	file << "Введите марку прочности продукта(100,200,300,400,500)";

	file << height << endl;

	file.close();

}

void Cement::read_file(ifstream& file)

{

	material_tech::read_file(file);

	file >> height;

}

void Cement::zapis()

{

	material_tech::zapis();

	cout << "Введите марку прочности продукта(100,200,300,400,500) ";

	cin >> height;

}