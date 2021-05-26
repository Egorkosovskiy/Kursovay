#pragma once
#include <iostream>

#include <string>

#include "fstream"

#include <Windows.h>

#include"material_tech.h"

using namespace std;

class Cement : public material_tech

{

public:

	Cement();

	Cement(const Cement& holod);

	void print_information()override;

	int get_kam()const;

	void set_kam(int kam);

	Cement& operator=(const Cement& comp);

	void write_file(string word)override;

	void read_file(ifstream& file)override;

	void zapis()override;

protected:

	int height;

};