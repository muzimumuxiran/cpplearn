#pragma once
#include<iostream>

#include"identify.h"
#include"computerroom.h"
#include"orderfile.h"
using namespace std;

class student:public identify {
public:
	student();
	student(int id, string name, string passwd);
	virtual void showmeu();
	void applyorder();
	void showmyorder();
	void showallorder();
	void cancelorder();
	int id;
	vector<computerroom>vr;
};

