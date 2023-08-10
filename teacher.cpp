#include"teacher.h"
#include"orderfile.h"

teacher::teacher() {

}

teacher::teacher(int id, string name, string passwd) {
	this->id = id;
	this->name = name;
	this->passwd = passwd;
}

void teacher::showmeu() {
	cout << "��ӭ��ʦ��" << this->name << endl;
	cout << "1 �鿴����ԤԼ" << endl;
	cout << "2 ���ԤԼ" << endl;
	cout << "0 ע����¼" << endl;
	cout << "��ѡ�����" << endl;
}

void teacher::showallorder() {
	orderfile of;
	if (of.size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.size; i++) {
		cout << "ԤԼ���ڣ�" << of.mo[i]["date"];
		cout << "ʱ��Σ�" << (of.mo[i]["interval"] == "1" ? "����" : "����");
		cout << "������ţ�" << of.mo[i]["roomid"];
		cout << "ѧ�ţ�" << of.mo[i]["stuid"];
		cout << "������" << of.mo[i]["stuname"];
		string status = "״̬��";
		if (of.mo[i]["status"] == "1") {
			status += "�����";
		}
		else if (of.mo[i]["status"] == "2") {
			status += "ԤԼ�ɹ�";
		}
		else if (of.mo[i]["status"] == "-1") {
			status += "ԤԼʧ�ܣ����δͨ��";
		}
		else {
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;

	}
	system("pause");
	system("cls");
}

void teacher::validorder() {
	orderfile of;
	if (of.size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	vector<int>v;
	int index = 0;
	cout << "����˵ļ�¼���£�" << endl;

	for (int i = 0; i < of.size; i++) {
		if (of.mo[i]["status"] == "1") {
			v.push_back(i);
			cout << ++index << "��";
			cout << "ԤԼ���ڣ�" << of.mo[i]["date"];
			cout << " ʱ��Σ�" << (of.mo[i]["interval"] == "1" ? "����" : "����");
			cout << " ������ţ�" << of.mo[i]["roomid"];
			cout << " ѧ�ţ�" << of.mo[i]["stuid"];
			cout << " ������" << of.mo[i]["stuname"];
			cout << " ״̬�������" << endl;
		}
	}

	cout << "��������˵�ԤԼ��¼:0������" << endl;
	int select = 0;
	int ret = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				cout << "��������˽��1��ͨ�� 2����ͨ��" << endl;
				cin >> ret;
				if (ret == 1) {
					of.mo[v[select - 1]]["status"] = "2";
				}
				else {
					of.mo[v[select - 1]]["status"] = "-1";
				}
				of.updateorder();
				cout << "�����ϣ�" << endl;
				break;
			}
			cout << "�����������������룺" << endl;
		}
	}
	system("pause");
	system("cls");
}