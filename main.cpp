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
			cout << "�鿴����ԤԼ" << endl;
			tea->showallorder();
			break;
		case 2:
			cout << "���ԤԼ" << endl;
			tea->validorder();
			break;
		case 0:
			delete acher;
			cout << "ע���ɹ�!" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "����������������룡" << endl;
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
			cout << "����ԤԼ" << endl;
			stu->applyorder();
			break;
		case 2:
			cout << "�鿴����ԤԼ" << endl;
			stu->showmyorder();
			break;
		case 3:
			cout << "�鿴����ԤԼ" << endl;
			stu->showallorder();
			break;
		case 4:
			cout << "ȡ��ԤԼ" << endl;
			stu->cancelorder();
			break;
		case 0:
			delete tudent;
			cout << "ע���ɹ�!" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "����������������룡" << endl;
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
			cout << "����˺�" << endl;
			m->addperson();
			break;
		case 2:
			cout << "�鿴�˺�" << endl;
			m->showperson();
			break;
		case 3:
			cout << "�鿴����" << endl;
			m->showcomputer();
			break;
		case 4:
			cout << "���ԤԼ" << endl;
			m->clearfile();
			break;
		case 0:
			delete anager;
			cout << "ע���ɹ�!" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "����������������룡" << endl;
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
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	int id;
	string name;
	string pwd;

	if (type == 1) {
		cout << "���������ѧ��:" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "���������ְ����:" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "�������룺" << endl;
	cin >> pwd;

	if (type == 1) {
		int fid;
		string fname;
		string fpwd;

		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (fid == id && fname == name && fpwd == pwd) {
				cout << "ѧ����¼��֤ͨ����" << endl;
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
				cout << "��ʦ��¼��֤ͨ����" << endl;
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
				cout << "����Ա��¼��֤ͨ����" << endl;
				system("pause");
				system("cls");
				person = new manager(name, pwd);
				managermeu(person);
				return;
			}
		}
	}
	cout << "��¼��֤ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;

}

int main() {

	int choice = 0;
	
	while (true) {
		cout << "��ӭ��������ԤԼϵͳ" << endl;
		cout << "1 ѧ��" << endl;
		cout << "2 ��ʦ" << endl;
		cout << "3 ����Ա" << endl;
		cout << "0 �˳�" << endl;
		cout << "�������������" << endl;
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
			cout << "��ӭ�ٴ�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}