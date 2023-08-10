#pragma once
#include<iostream>

#include"identify.h"
#include"student.h"
#include"teacher.h"
#include"computerroom.h"
using namespace std;

class manager :public identify {
public:
	manager();
	manager(string name,string passwd);
	virtual void showmeu();
	void addperson();
	void showperson();
	void showcomputer();
	void clearfile();
	void initvector();
	bool checkrepeat(int id, int type);
	vector<student>vs;
	vector<teacher>vt;
	vector<computerroom>vc;
};