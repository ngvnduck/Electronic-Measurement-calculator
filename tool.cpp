#include <bits/stdc++.h>

using namespace std;
class PhepDo {
public:
	double giatri;
	double ss;
	double ssbp;
	bool ccc;
	// Cac ham
	void set(double r) {
		giatri=r;
		ss=0;
		ssbp=0;
		ccc=true;
	}
};
void show(const PhepDo &m) {
	cout << setfill(' ');
	cout << setw(20) << left << m.giatri;
	cout << setw(20) << left << m.ss;
	cout << setw(20) << left << m.ssbp << endl;
}
void showList(const vector<PhepDo> &list) {
	if(list.size()==0) {
		cout << "Empty list!" << endl;
		return;
	}
	cout << setfill('-') << setw(62) << "-" << endl;
	cout << setfill(' ');
	cout << setw(2) << left << "" << "| ";
	cout <<"\033[31m"<< setw(20) << left << "Ket qua do";
	cout <<"\033[32m"<< setw(20) << left << "Sai so";
	cout <<"\033[33m"<< setw(20) << left << "Sai so binh phuong" << endl << "\033[0m";
	cout << setfill('-') << setw(62) << "-" << endl;
	for (int i = 0; i < list.size(); i++) {
		cout << setfill(' ') << setw(2)<< left << i+1 <<"| ";
    	show(list[i]);
    	cout << setfill('-') << setw(62) << "-" << endl;
    }
}
double phepdotrungbinh(vector<PhepDo> &list) {
	double ans=0;
	for (int i=0; i<list.size();i++) {
		ans += list[i].giatri;
	}
	ans = ans/list.size();
	return ans;
}
void tinhss(vector<PhepDo> &list) {
	double mean=phepdotrungbinh(list);
	for (int i=0; i<list.size();i++) {
		list[i].ss=abs(mean - list[i].giatri);
		list[i].ssbp = pow(list[i].ss,2);
	}
}
double saisotrungbinh(vector<PhepDo> &list) {
	double ans=0;
	for (int i=0; i<list.size();i++) {
		ans += list[i].ss;
	}
	int n=list.size();
	return ans/sqrt(n*(n-1));
}
double saisoTBbinhphuong(vector<PhepDo> &list) {
	double ans=0;
	for (int i=0; i<list.size();i++) {
		ans += list[i].ssbp;
	}
	int n=list.size();
	return sqrt(ans/(n-1));
}
void check(vector<PhepDo> &list) {
	while(1) {
		tinhss(list);
		showList(list);
		bool error=false;
		double k=saisotrungbinh(list);
		cout << "Trung binh phep do: " << phepdotrungbinh(list) << endl << "Sai so trung binh: " << saisotrungbinh(list) << endl;
		for (int i=0; i<list.size();i++) {
			if(list[i].ss>(6*k)) {
				cout << "\033[33mPhep do so " << i+1 << " bi sai\033[0m" << endl;
				list[i].ccc=false;
				error = true;
			}
		}
		for (int i=0; i<list.size();i++) {
			if(list[i].ccc == false) {
				list.erase(list.begin()+i);
				i--;
			}
		}
		if (error == false) {
			cout << "\033[32mCac phep do deu dung.\033[0m" << endl;
			cout << "Sai so trung binh binh phuong: " << saisoTBbinhphuong(list) << endl;
			cout << "Sai so trung binh binh phuong cua cac aTB: " << saisoTBbinhphuong(list)/sqrt(list.size()) << endl;
			cout << "\033[32m" << "Ket qua phep do: X = " << phepdotrungbinh(list) << " +- " << 3*saisoTBbinhphuong(list)/sqrt(list.size()) << "\033[0m" << endl;
			return;
		}
	}
}
int main() {
	// cout << fixed;
	vector<PhepDo> list;
	PhepDo x;
	cout << "Nhap so phep do: ";
	int m; cin >> m;
	cout << "Nhap gia tri cac phep do: ";
	for (int i=0; i<m;i++) {
		double n; cin >> n; x.set(n);
		list.push_back(x);
	}
	check(list);
	return 0;
}
