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
	cout << "欢迎教师：" << this->name << endl;
	cout << "1 查看所有预约" << endl;
	cout << "2 审核预约" << endl;
	cout << "0 注销登录" << endl;
	cout << "请选择操作" << endl;
}

void teacher::showallorder() {
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

void teacher::validorder() {
	orderfile of;
	if (of.size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	vector<int>v;
	int index = 0;
	cout << "待审核的记录如下：" << endl;

	for (int i = 0; i < of.size; i++) {
		if (of.mo[i]["status"] == "1") {
			v.push_back(i);
			cout << ++index << "、";
			cout << "预约日期：" << of.mo[i]["date"];
			cout << " 时间段：" << (of.mo[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房编号：" << of.mo[i]["roomid"];
			cout << " 学号：" << of.mo[i]["stuid"];
			cout << " 姓名：" << of.mo[i]["stuname"];
			cout << " 状态：审核中" << endl;
		}
	}

	cout << "请输入审核的预约记录:0代表返回" << endl;
	int select = 0;
	int ret = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				cout << "请输入审核结果1、通过 2、不通过" << endl;
				cin >> ret;
				if (ret == 1) {
					of.mo[v[select - 1]]["status"] = "2";
				}
				else {
					of.mo[v[select - 1]]["status"] = "-1";
				}
				of.updateorder();
				cout << "审核完毕！" << endl;
				break;
			}
			cout << "输入有误，请重新输入：" << endl;
		}
	}
	system("pause");
	system("cls");
}