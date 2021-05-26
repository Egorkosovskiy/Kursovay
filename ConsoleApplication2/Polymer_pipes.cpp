#include <iostream>

#include <string>

#include "fstream"

#include <Windows.h>

#include"Polymer_pipes.h"

using namespace std;

Polymer_pipes::Polymer_pipes() :material_tech2()

{

	kam = 0;

}

Polymer_pipes::Polymer_pipes(const Polymer_pipes& temp) :material_tech2(temp)

{

	kam = temp.kam;

}

void Polymer_pipes::print_information()

{

	material_tech2::print_information();

	cout << "диаметр трубы в мм " << kam << endl;

}

int Polymer_pipes::get_kam()const

{

	return kam;

}

void Polymer_pipes::set_kam(int kam)

{

	this->kam = kam;

}

Polymer_pipes& Polymer_pipes::operator=(const Polymer_pipes& comp)

{

	material_tech2::operator=(comp);

	kam = comp.kam;

	return *this;

}

void Polymer_pipes::write_file(string word)

{

	material_tech2::write_file(word);

	ofstream file(word, ios::app);

	file << "диаметр трубы в мм ";

	file << kam << endl;

	file.close();

}

void Polymer_pipes::read_file(ifstream& file)

{

	material_tech2::read_file(file);

	file >> kam;

}

void Polymer_pipes::zapis()

{

	material_tech2::zapis();

	cout << "диаметр трубы в мм ";

	cin >> kam;
}