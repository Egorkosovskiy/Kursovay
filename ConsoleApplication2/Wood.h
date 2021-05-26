#pragma once
#include <iostream>

#include <string>

#include "fstream"

#include <Windows.h>

#include"material_tech2.h"

using namespace std;

class Wood :public material_tech2

{

public:

	Wood();

	Wood(const Wood& holod);

	void print_information()override;

	int get_count()const;

	void set_count(int count);

	Wood& operator=(const Wood& comp);

	void write_file(string word)override;

	void read_file(ifstream& file)override;

	void zapis()override;

protected:

	int count;

};