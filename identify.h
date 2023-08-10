#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<vector>
#include<deque>
#include<map>
#include<numeric>
#include<functional>

using namespace std;

class identify {
public:

	virtual void showmeu() = 0;

	string name;
	string passwd;
};