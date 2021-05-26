#pragma once


#include <iostream>

#include <string>

#include "fstream"

#include <Windows.h>

#include"material.h"

using namespace std;

class material_tech :public material

{

public:

	material_tech();

	material_tech(const material_tech& holod);

	void print_information()override;

	int get_height()const;

	void set_height(int height);

	material_tech& operator=(const material_tech& comp);

	void write_file(string word)override;

	void read_file(ifstream& file)override;

	void zapis()override;

protected:

	int height;

};