#pragma once
#include <iostream>

#include <string>

#include "fstream"

#include <Windows.h>

#include"material_tech.h"

using namespace std;

class Gypsum : public material_tech

{

public:

	Gypsum();

	Gypsum(const Gypsum& holod);

	void print_information()override;

	string get_material()const;

	void set_material(string material);

	Gypsum& operator=(const Gypsum& comp);

	void write_file(string word)override;

	void read_file(ifstream& file)override;

	void zapis()override;

protected:

	string material;

};