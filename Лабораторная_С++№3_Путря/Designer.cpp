#include "Designer.h"



Designer::Designer() : Employee() {
	cout << "�������� " << name_ << " " << surname_ << " ������� � ����" << endl << endl;
}

Designer::Designer(const string& name, const string& surname, char gender, short year_birth, short year_start, const string& phone) : Employee(name, surname, gender, year_birth, year_start, phone) {
	cout << "�������� " << name_ << " " << surname_ << " ������� � ����" << endl << endl;
}

Designer::~Designer() {
	cout << "�������� " << name_ << " " << surname_ << " ������ � ������!" << endl << endl;
}

ostream& Designer::operator<<(ostream& out) {

	out << "��� ��������� " << name_ << endl;
	out << "������� ��������� " << surname_ << endl;
	out << "��� ��������� " << gender_ << endl;
	out << "��� �������� ��������� " << year_birth_ << endl;
	out << "��� ������ ������� ��������� " << year_start_ << endl;
	out << "������� ��������� " << phone_ << endl<<endl;
	
	return out;
}

void Designer::serialize()const {
	const string path = name_ + ".txt";
	ofstream fout(path);
	if (fout.is_open()) {
		fout << "��� ��������� " << name_ << endl;
		fout << "������� ��������� " << surname_ << endl;
		fout << "��� ��������� " << gender_ << endl;
		fout << "��� �������� ��������� " << year_birth_ << endl;
		fout << "��� ������ ������� ��������� " << year_start_ << endl;
		fout << "������� ��������� " << phone_ << endl << endl;
	}
	fout.close();
}

void Designer::PrintStatistics() {
	*this << cout;
}

void Designer::Imitation() {
	cout << "--------------------------------START Imitation--------------------------" << endl;
	for (size_t i = 0; i < 3; i++) {
		cout << "������� �" << i + 1 << endl;
		//srand(time(i));

		int votes = rand() % 30;
		if (votes >= 10) {
			rating_ += rand() % 10 + 1;
		}
		cout << "�������������: " << votes << " �� ��������� " << name_ << endl;
		cout << "������� �������: " << rating_ << " ��������� " << name_ << " " << surname_ << endl << endl;
		cout << "--------------------------------Imitation-------------------------------------" << endl;
	}
	cout << "--------------------------------END Imitation-----------------------------" << endl;
}

void Designer::Process(const string& photo_path) {
	cout << "Image "<<photo_path<<" was produced by " << name_<<endl;
	int t = rand() % 10 + 1;
	rating_ += t;
	cout << "������� ���������� �� " << t << ". ������� �������: " << rating_<<endl<<endl;
}
