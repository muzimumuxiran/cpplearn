#include"student.h"
#include"globalfile.h"

student::student() {

}

student::student(int id, string name, string passwd) {
	this->id = id;
	this->name = name;
	this->passwd = passwd;

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	computerroom rom;
	while (ifs >> rom.id && ifs >> rom.maxnum) {
		vr.push_back(rom);
	}
}

void student::showmeu() {
	cout << "��ӭѧ��" << this->name << "ʹ��" << endl;
	cout << "1 ����ԤԼ" << endl;
	cout << "2 �鿴����ԤԼ" << endl;
	cout << "3 �鿴����ԤԼ" << endl;
	cout << "4 ȡ��ԤԼ" << endl;
	cout << "0 ע����¼" << endl;
	cout << "��ѡ�����" << endl;
}

void student::applyorder() {
	cout << "��������ʱ������һ������,�����������ʱ�䣨1-5����" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;
	while (true) {
		cin >> date;
		if (date >= 1 && date <= 5) {
			break;
		}
		cout << "����ʱ���������������룺" << endl;
	}

	cout << "������ԤԼʱ��1������ 2������" << endl;
	while (true) {
		cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		cout << "��������ȷ��ʱ�䣺" << endl;
	}

	cout << "��ѡ�����1��2��3" << endl;
	cout << "�����ֱ�Ϊ" << vr[0].maxnum << "," << vr[1].maxnum << "," << vr[2].maxnum << endl;
	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "��������ȷ�Ļ�����" << endl;
	}

	cout << "ԤԼ�ɹ�������У�" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuid:" << this->id << " ";
	ofs << "stuname:" << this->name << " ";
	ofs << "roomid:" << room << " ";
	ofs << "status:" << 1 << " ";

	ofs.close();

	system("pause");
	system("cls");
}

void student::showmyorder() {
	orderfile of;
	if (of.size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.size; i++) {
		if (this->id == atoi(of.mo[i]["stuid"].c_str())) {
			cout << "ԤԼ���ڣ�" << of.mo[i]["date"];
			cout << "ʱ��Σ�" << (of.mo[i]["interval"] == "1" ? "����" : "����");
			cout << "������ţ�" << of.mo[i]["roomid"];
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
	}
	system("pause");
	system("cls");
}

void student::showallorder() {
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

void student::cancelorder() {
	orderfile of;
	if (of.size == 0) {
		cout << "��ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;
	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.size; i++) {
		if (this->id == atoi(of.mo[i]["stuid"].c_str())) {
			if (of.mo[i]["status"] == "1" || of.mo[i]["status"] == "2") {
				v.push_back(i);
				cout << index++ << "��";
				cout << "ԤԼ���ڣ�" << of.mo[i]["date"];
				cout << "ʱ��Σ�" << (of.mo[i]["interval"] == "1" ? "����" : "����");
				cout << "������ţ�" << of.mo[i]["roomid"];
				string status = "״̬��";
				if (of.mo[i]["status"] == "1") {
					status += "�����";
				}
				else if (of.mo[i]["status"] == "2") {
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}
		}
	}
	cout << "������ȡ���ļ�¼��0�����أ�" << endl;
	int select = 0;

	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				of.mo[v[select - 1]]["status"] = "0";
				of.updateorder();
				cout << "ȡ���ɹ�" << endl;
				break;
			}
		}
		cout << "�����������������룺" << endl;
	}
	system("pause");
	system("cls");
}