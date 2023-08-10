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
	cout << "欢迎学生" << this->name << "使用" << endl;
	cout << "1 申请预约" << endl;
	cout << "2 查看自身预约" << endl;
	cout << "3 查看所有预约" << endl;
	cout << "4 取消预约" << endl;
	cout << "0 注销登录" << endl;
	cout << "请选择操作" << endl;
}

void student::applyorder() {
	cout << "机房开放时间是周一到周五,请输入申请的时间（1-5）：" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;
	while (true) {
		cin >> date;
		if (date >= 1 && date <= 5) {
			break;
		}
		cout << "输入时间有误，请重新输入：" << endl;
	}

	cout << "请输入预约时间1、上午 2、下午" << endl;
	while (true) {
		cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		cout << "请输入正确的时间：" << endl;
	}

	cout << "请选择机房1，2，3" << endl;
	cout << "容量分别为" << vr[0].maxnum << "," << vr[1].maxnum << "," << vr[2].maxnum << endl;
	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "请输入正确的机房：" << endl;
	}

	cout << "预约成功，审核中！" << endl;

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
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.size; i++) {
		if (this->id == atoi(of.mo[i]["stuid"].c_str())) {
			cout << "预约日期：" << of.mo[i]["date"];
			cout << "时间段：" << (of.mo[i]["interval"] == "1" ? "上午" : "下午");
			cout << "机房编号：" << of.mo[i]["roomid"];
			string status = "状态：";
			if (of.mo[i]["status"] == "1") {
				status += "审核中";
			}
			else if (of.mo[i]["status"] == "2") {
				status += "预约成功";
			}
			else if (of.mo[i]["status"] == "-1") {
				status += "预约失败，审核未通过";
			}
			else {
				status += "预约已取消";
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
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.size; i++) {
		cout << "预约日期：" << of.mo[i]["date"];
		cout << "时间段：" << (of.mo[i]["interval"] == "1" ? "上午" : "下午");
		cout << "机房编号：" << of.mo[i]["roomid"];
		cout << "学号：" << of.mo[i]["stuid"];
		cout << "姓名：" << of.mo[i]["stuname"];
		string status = "状态：";
		if (of.mo[i]["status"] == "1") {
			status += "审核中";
		}
		else if (of.mo[i]["status"] == "2") {
			status += "预约成功";
		}
		else if (of.mo[i]["status"] == "-1") {
			status += "预约失败，审核未通过";
		}
		else {
			status += "预约已取消";
		}
		cout << status << endl;
			
	}
	system("pause");
	system("cls");
}

void student::cancelorder() {
	orderfile of;
	if (of.size == 0) {
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;
	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.size; i++) {
		if (this->id == atoi(of.mo[i]["stuid"].c_str())) {
			if (of.mo[i]["status"] == "1" || of.mo[i]["status"] == "2") {
				v.push_back(i);
				cout << index++ << "、";
				cout << "预约日期：" << of.mo[i]["date"];
				cout << "时间段：" << (of.mo[i]["interval"] == "1" ? "上午" : "下午");
				cout << "机房编号：" << of.mo[i]["roomid"];
				string status = "状态：";
				if (of.mo[i]["status"] == "1") {
					status += "审核中";
				}
				else if (of.mo[i]["status"] == "2") {
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}
	cout << "请输入取消的记录，0代表返回：" << endl;
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
				cout << "取消成功" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入：" << endl;
	}
	system("pause");
	system("cls");
}