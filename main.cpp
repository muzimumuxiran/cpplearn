#include <iostream>

#include"identify.h"
#include"globalfile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

using namespace std;

void teachermeu(identify*& acher) {
	while (true) {
		acher->showmeu();
		teacher* tea = (teacher*)acher;

		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "查看所有预约" << endl;
			tea->showallorder();
			break;
		case 2:
			cout << "审核预约" << endl;
			tea->validorder();
			break;
		case 0:
			delete acher;
			cout << "注销成功!" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "输入错误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	vector<vector<int>>a;
	vector<int>a1 = { 1,2,3 };
	a.push_back(a1);
	for (vector<vector<int>>::iterator it = a.begin(); it != a.end(); it++) {
		for (int n = 0; n < it->size(); n++) {
			cout << *it[n] << endl;
		}
	}
}

void studentmeu(identify*& tudent) {
	while (true) {
		tudent->showmeu();
		student* stu = (student*)tudent;

		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "申请预约" << endl;
			stu->applyorder();
			break;
		case 2:
			cout << "查看自身预约" << endl;
			stu->showmyorder();
			break;
		case 3:
			cout << "查看所有预约" << endl;
			stu->showallorder();
			break;
		case 4:
			cout << "取消预约" << endl;
			stu->cancelorder();
			break;
		case 0:
			delete tudent;
			cout << "注销成功!" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "输入错误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void managermeu(identify* &anager) {
	while (true) {
		anager->showmeu();

		manager* m = (manager*)anager;

		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "添加账号" << endl;
			m->addperson();
			break;
		case 2:
			cout << "查看账号" << endl;
			m->showperson();
			break;
		case 3:
			cout << "查看机房" << endl;
			m->showcomputer();
			break;
		case 4:
			cout << "清空预约" << endl;
			m->clearfile();
			break;
		case 0:
			delete anager;
			cout << "注销成功!" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "输入错误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
}

void loginin(string filename, int type) {
	identify* person = NULL;
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	int id;
	string name;
	string pwd;

	if (type == 1) {
		cout << "请输入你的学号:" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入你的职工号:" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "输入密码：" << endl;
	cin >> pwd;

	if (type == 1) {
		int fid;
		string fname;
		string fpwd;

		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (fid == id && fname == name && fpwd == pwd) {
				cout << "学生登录验证通过！" << endl;
				system("pause");
				system("cls");
				person = new student(id, name, pwd);
				studentmeu(person);
				return;
			}
		}
	}
	else if (type == 2) {
		int fid;
		string fname;
		string fpwd;

		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (fid == id && fname == name && fpwd == pwd) {
				cout << "老师登录验证通过！" << endl;
				system("pause");
				system("cls");
				person = new teacher(id, name, pwd);
				teachermeu(person);
				return;
			}
		}
	}
	else if (type == 3) {
		string fname;
		string fpwd;

		while (ifs >> fname && ifs >> fpwd) {
			if (fname == name && fpwd == pwd) {
				cout << "管理员登录验证通过！" << endl;
				system("pause");
				system("cls");
				person = new manager(name, pwd);
				managermeu(person);
				return;
			}
		}
	}
	cout << "登录验证失败！" << endl;
	system("pause");
	system("cls");
	return;

}

int main() {

	int choice = 0;
	
	while (true) {
		cout << "欢迎来到机房预约系统" << endl;
		cout << "1 学生" << endl;
		cout << "2 老师" << endl;
		cout << "3 管理员" << endl;
		cout << "0 退出" << endl;
		cout << "请输入您的身份" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			loginin(STUDENT_FILE, 1);
			break;
		case 2:
			loginin(TEACHER_FILE, 2);
			break;
		case 3:
			loginin(ADMIF_FILE, 3);
			break;
		case 0:
			cout << "欢迎再次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误请重新选择" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}