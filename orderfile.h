#pragma once
#include"identify.h"
#include"globalfile.h"

class orderfile {
public:

	orderfile();
	void updateorder();

	int size;
	map<int, map<string, string>>mo;
};