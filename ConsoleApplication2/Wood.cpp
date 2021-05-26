#include <iostream>

#include <string>

#include "fstream"

#include <Windows.h>

#include"Wood.h"

using namespace std;

Wood::Wood() :material_tech2()

{

	count = 0;

}

Wood::Wood(const Wood& temp) :material_tech2(temp)

{

	count = temp.count;

}

void Wood::print_information()

{

	material_tech2::print_information();

	cout << "Толщина в мм " << count << endl;

}

int Wood::get_count()const

{

	return count;

}

void Wood::set_count(int depth)

{

	this->count = depth;

}

Wood& Wood::operator=(const Wood& comp)

{

	material_tech2::operator=(comp);

	count = comp.count;

	return *this;

}

void Wood::write_file(string word)

{

	Wood::write_file(word);

	ofstream file(word, ios::app);

	file << "Толщина в мм ";

	file << count << endl;

	file.close();

}

void Wood::read_file(ifstream& file)

{

	material_tech2::read_file(file);

	file >> count;

}

void Wood::zapis()

{

	material_tech2::zapis();

	cout << "Толщина в мм ";

	cin >> count;

}