#pragma once
#include <iostream>

#include <string>

#include "fstream"

#include <Windows.h>

#include"Gypsum.h"

using namespace std;

class glass :public Gypsum

{

public:

	glass();

	glass(const glass& holod);

	void print_information()override;

	string get_material()const;

	void set_material(string material);

	glass& operator=(const glass& comp);

	void write_file(string word)override;

	void read_file(ifstream& file)override;

	void zapis()override;

protected:

	string material;

};