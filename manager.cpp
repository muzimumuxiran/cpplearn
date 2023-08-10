#include"manager.h"
#include"globalfile.h"

manager::manager() {

}

manager::manager(string name, string passwd) {
	this->name = name;
	this->passwd = passwd;
	this->initvector();

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	computerroom com;
	while (ifs >> com.id && ifs >> com.maxnum) {
		vc.push_back(com);
	}
	ifs.close();
	cout << "����������" << vc.size() << endl;
}

void manager::showmeu() {
	cout << "��ӭ����Ա" << this->name << "��¼��" << endl;
	cout << "����Ա�˵�" << endl;
	cout << "1 ����˺�" << endl;
	cout << "2 �鿴�˺�" << endl;
	cout << "3 �鿴����" << endl;
	cout << "4 ���ԤԼ" << endl;
	cout << "0 ע����¼" << endl;
	cout << "��ѡ�����" << endl;
}

void manager::addperson() {
	cout << "����������˺ŵ����ͣ�" << endl;
	cout << "1 ���ѧ��" << endl;
	cout << "2 �����ʦ" << endl;

	string filename;
	string tip;

	string errortip;
	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1) {
		filename = STUDENT_FILE;
		tip = "������ѧ��";
		errortip = "ѧ���ظ�������������";
	}
	else if (select == 2) {
		filename = TEACHER_FILE;
		tip = "������ְ�����";
		errortip = "ְ�����ظ�������������";
	}
	else {
		cout << "�������" << endl;
		return;
	}

	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;

	while (true) {
		cin >> id;
		bool ret = checkrepeat(id, select);
		if (ret) {
			cout << errortip << endl;
		}
		else {
			break;
		}
	}

	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << "" << endl;
	cout << "��ӳɹ���";

	system("pause");
	system("cls");

	ofs.close();

	this->initvector();
}
void printstudent(student &s) {
	cout << "ѧ�ţ�" << s.id << " ������" << s.name << endl;
}
void printteacher(teacher &t) {
	cout << "ְ���ţ�" << t.id << " ������" << t.name << endl;
}
void manager::showperson() {
	cout << "��ѡ��鿴�����ݣ�" << endl;
	cout << "1 ѧ��" << endl;
	cout << "2 ��ʦ" << endl;

	int select = 0;
	cin >> select;
	if (select == 1) {
		cout << "ѧ����Ϣ���£�" << endl;
		for_each(vs.begin(), vs.end(), printstudent);
	}
	else {
		cout << "��ʦ��Ϣ���£�" << endl;
		for_each(vt.begin(), vt.end(), printteacher);
	}
	system("pause");
	system("cls");
}

void manager::showcomputer() {
	cout << "��������Ϣ����:" << endl;
	for (vector<computerroom>::iterator it = vc.begin(); it != vc.end(); it++) {
		cout << "�����ı�ţ�" << it->id << " ���������������" << it->maxnum << endl;
	}
	system("pause");
	system("cls");
}

void manager::clearfile() {
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

void manager::initvector() {
	vs.clear();
	vt.clear();

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}
	student s;
	while (ifs >> s.id && ifs >> s.name && ifs >> s.passwd) {
		vs.push_back(s);
	}
	cout << "��ǰѧ������Ϊ:" << vs.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}
	teacher t;
	while (ifs >> t.id && ifs >> t.name && ifs >> t.passwd) {
		vt.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ:" << vt.size() << endl;
	ifs.close();
}

bool manager::checkrepeat(int id, int type) {
	if (type == 1) {
		for (vector<student>::iterator it = vs.begin(); it != vs.end(); it++) {
			if (it->id == id) {
				return true;
			}
		}
	}
	else {
		for (vector<teacher>::iterator it = vt.begin(); it != vt.end(); it++) {
			if (it->id == id) {
				return true;
			}
		}
	}
	return false;
}