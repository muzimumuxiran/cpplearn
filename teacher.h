#pragma once
#include<iostream>

#include"identify.h"
using namespace std;

class teacher :public identify {
public:
	teacher();
	teacher(int id, string name, string passwd);
	virtual void showmeu();
	void showallorder();
	void validorder();
	int id;
};