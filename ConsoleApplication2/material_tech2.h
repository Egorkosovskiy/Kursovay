#pragma once
#include <iostream>

#include <string>

#include "fstream"

#include <Windows.h>

#include"material.h"

using namespace std;

class material_tech2 :public material

{

public:

	material_tech2();
	material_tech2(const material_tech2& holod);
	void print_information()override;
	double get_length()const;
	void set_length(double v);
	material_tech2& operator=(const material_tech2& comp);
	void write_file(string word)override;
	void read_file(ifstream& file)override;
	void zapis()override;

protected:

	double length;

};