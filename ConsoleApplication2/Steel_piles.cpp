#include <iostream>

#include <string>

#include "fstream"

#include <Windows.h>

#include"Steel_piles.h"

using namespace std;

Steel_piles::Steel_piles() :material_tech2()

{

	kickbacks = "";

}

Steel_piles::Steel_piles(const Steel_piles& temp) :material_tech2(temp)

{

	kickbacks = temp.kickbacks;

}

void Steel_piles::print_information()

{

	material_tech2::print_information();

	cout << "тип материалла: " << kickbacks << endl;

}

string Steel_piles::get_kickbacks()const

{

	return kickbacks;

}

void Steel_piles::set_kickbacks(string kickbacks)

{

	this->kickbacks = kickbacks;

}

Steel_piles& Steel_piles::operator=(const Steel_piles& comp)

{

	material_tech2::operator=(comp);

	kickbacks = comp.kickbacks;

	return *this;

}

void Steel_piles::write_file(string word)

{

	material_tech2::write_file(word);

	ofstream file(word, ios::app);

	file << "тип материалла: ";

	file << kickbacks << endl;

	file.close();

}

void Steel_piles::read_file(ifstream& file)

{

	material_tech2::read_file(file);

	getline(file, kickbacks);

}

void Steel_piles::zapis()

{

	material_tech2::zapis();

	cout << "тип материалла: ";

	cin >> kickbacks;

}