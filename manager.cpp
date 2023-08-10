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
	cout << "机房的数量" << vc.size() << endl;
}

void manager::showmeu() {
	cout << "欢迎管理员" << this->name << "登录！" << endl;
	cout << "管理员菜单" << endl;
	cout << "1 添加账号" << endl;
	cout << "2 查看账号" << endl;
	cout << "3 查看机房" << endl;
	cout << "4 清空预约" << endl;
	cout << "0 注销登录" << endl;
	cout << "请选择操作" << endl;
}

void manager::addperson() {
	cout << "请输入添加账号的类型：" << endl;
	cout << "1 添加学生" << endl;
	cout << "2 添加老师" << endl;

	string filename;
	string tip;

	string errortip;
	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1) {
		filename = STUDENT_FILE;
		tip = "请输入学号";
		errortip = "学号重复，请重新输入";
	}
	else if (select == 2) {
		filename = TEACHER_FILE;
		tip = "请输入职工编号";
		errortip = "职工编重复，请重新输入";
	}
	else {
		cout << "输入错误！" << endl;
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

	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << "" << endl;
	cout << "添加成功！";

	system("pause");
	system("cls");

	ofs.close();

	this->initvector();
}
void printstudent(student &s) {
	cout << "学号：" << s.id << " 姓名：" << s.name << endl;
}
void printteacher(teacher &t) {
	cout << "职工号：" << t.id << " 姓名：" << t.name << endl;
}
void manager::showperson() {
	cout << "请选择查看的内容：" << endl;
	cout << "1 学生" << endl;
	cout << "2 老师" << endl;

	int select = 0;
	cin >> select;
	if (select == 1) {
		cout << "学生信息如下：" << endl;
		for_each(vs.begin(), vs.end(), printstudent);
	}
	else {
		cout << "老师信息如下：" << endl;
		for_each(vt.begin(), vt.end(), printteacher);
	}
	system("pause");
	system("cls");
}

void manager::showcomputer() {
	cout << "机房的信息如下:" << endl;
	for (vector<computerroom>::iterator it = vc.begin(); it != vc.end(); it++) {
		cout << "机房的编号：" << it->id << " 机房的最大容量：" << it->maxnum << endl;
	}
	system("pause");
	system("cls");
}

void manager::clearfile() {
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

void manager::initvector() {
	vs.clear();
	vt.clear();

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败！" << endl;
		return;
	}
	student s;
	while (ifs >> s.id && ifs >> s.name && ifs >> s.passwd) {
		vs.push_back(s);
	}
	cout << "当前学生数量为:" << vs.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败！" << endl;
		return;
	}
	teacher t;
	while (ifs >> t.id && ifs >> t.name && ifs >> t.passwd) {
		vt.push_back(t);
	}
	cout << "当前老师数量为:" << vt.size() << endl;
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