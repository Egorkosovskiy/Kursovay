#include <iostream>

#include <string>

#include "fstream"

#include <Windows.h>

#include"material_tech.h"

using namespace std;

material_tech::material_tech() : material()

{

	height = 0;

}

material_tech::material_tech(const material_tech& temp) : material(temp)

{

	height = temp.height;

}

void material_tech::print_information()

{

	material::print_information();

	cout << "Категория Материалла (1-5) " << height << endl;

}

int material_tech::get_height()const

{

	return height;

}

void material_tech::set_height(int height)

{

	this->height = height;

}

material_tech& material_tech::operator=(const material_tech& comp)

{

	material::operator=(comp);

	height = comp.height;

	return *this;

}

void material_tech::write_file(string word)

{

	material::write_file(word);

	ofstream file(word, ios::app);

	file << "Категория Материалла (1-5) ";

	file << height << endl;

	file.close();

}

void material_tech::read_file(ifstream& file)

{

	material::read_file(file);

	file >> height;

}

void material_tech::zapis()

{

	material::zapis();

	cout << "Категория Материалла (1-5) ";

	cin >> height;

}