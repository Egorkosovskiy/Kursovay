#include <iostream>

#include <string>

#include "fstream"

#include <Windows.h>

#include"material_tech2.h"

using namespace std;

material_tech2::material_tech2() :material()

{

	length = 0;

}

material_tech2::material_tech2(const material_tech2& temp) :material(temp)

{

	length = temp.length;

}

void material_tech2::print_information()

{

	material::print_information();

	cout << "Длина продукции в м: " << length << endl;

}

double material_tech2::get_length()const

{

	return length;

}

void material_tech2::set_length(double length)

{

	this->length = length;

}

material_tech2& material_tech2::operator=(const material_tech2& comp)

{

	material::operator=(comp);

	length = comp.length;

	return *this;

}

void material_tech2::write_file(string word)

{

	material::write_file(word);

	ofstream file(word, ios::app);

	file << "Длина продукции в м: ";

	file << length << endl;

	file.close();

}

void material_tech2::read_file(ifstream& file)

{

	material::read_file(file);

	file >> length;

}

void material_tech2::zapis()

{

	material::zapis();

	cout << "Длина продукции в м: ";

	cin >> length;

}