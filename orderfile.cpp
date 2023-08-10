#include"orderfile.h"

orderfile::orderfile() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;
	string interval;
	string stuid;
	string stuname;
	string roomid;
	string status;

	this->size = 0;

	while (ifs >> date && ifs >> interval && ifs >> stuid && ifs >> stuname && ifs >> roomid && ifs >> status) {
		string key;
		string value;
		map<string, string>m;

		int pos = date.find(":");
		if (pos != -1) {
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = interval.find(":");
		if (pos != -1) {
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = stuid.find(":");
		if (pos != -1) {
			key = stuid.substr(0, pos);
			value = stuid.substr(pos + 1, stuid.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = stuname.find(":");
		if (pos != -1) {
			key = stuname.substr(0, pos);
			value = stuname.substr(pos + 1, stuname.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = roomid.find(":");
		if (pos != -1) {
			key = roomid.substr(0, pos);
			value = roomid.substr(pos + 1, roomid.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = status.find(":");
		if (pos != -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		
		this->mo.insert(make_pair(this->size, m));
		this->size++;
	}
	ifs.close();

	/*for (map<int, map<string, string>>::iterator it = mo.begin(); it != mo.end(); it++) {
		cout << "key:" << it->first << "value:" << endl;
		for (map<string, string>::iterator mit = (*it).second.begin(); mit != (*it).second.end(); mit++) {
			cout << "key:" << mit->first << "value:" << mit->second;
		}
		cout << endl;
	}*/
}

void orderfile::updateorder() {
	if (this->size == 0) {
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->size; i++) {
		ofs << "date:" << this->mo[i]["date"] << " ";
		ofs << "interval:" << this->mo[i]["interval"] << " ";
		ofs << "stuid:" << this->mo[i]["stuid"] << " ";
		ofs << "stuname:" << this->mo[i]["stuname"] << " ";
		ofs << "roomid:" << this->mo[i]["roomid"] << " ";
		ofs << "status:" << this->mo[i]["status"] << endl;
	}

	ofs.close();
}