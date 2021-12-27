#include "Photographer.h"



Photographer::Photographer() : Employee(),count_photo_(0) {
	cout << "�������� " << name_ << " " << surname_ << " ������� � ����" << endl << endl;
}

Photographer::Photographer(const string& name, const string& surname, char gender, short year_birth, short year_start, const string& phone,int count_photo) : Employee(name, surname, gender, year_birth, year_start, phone),count_photo_(count_photo) {
	cout << "�������� " << name_ << " " << surname_ << " ������� � ����" << endl << endl;
}

Photographer::~Photographer() {
	cout << "�������� " << name_ << " " << surname_ << " ������ � ������!" << endl << endl;
}



ostream& Photographer::operator<<(ostream& out) {

	out << "��� ��������� " << name_ << endl;
	out << "������� ��������� " << surname_ << endl;
	out << "��� ��������� " << gender_ << endl;
	out << "��� �������� ��������� " << year_birth_ << endl;
	out << "��� ������ ������� ��������� " << year_start_ << endl;
	out << "������� ��������� " << phone_ << endl;
	out << "���������� ���� � ��������� " << count_photo_ << endl<<endl;

	return out;
}

void Photographer::serialize()const {
	const string path = name_ + ".txt";
	ofstream fout(path);
	if (fout.is_open()) {
		fout << "��� ��������� " << name_ << endl;
		fout << "������� ��������� " << surname_ << endl;
		fout << "��� ��������� " << gender_ << endl;
		fout << "��� �������� ��������� " << year_birth_ << endl;
		fout << "��� ������ ������� ��������� " << year_start_ << endl;
		fout << "������� ��������� " << phone_ << endl;
		fout << "���������� ���� � ��������� " << count_photo_ << endl << endl;
	}
	fout.close();
}

void Photographer::setCountPhoto(const int count_photo) {
	count_photo_ = count_photo;
}
int Photographer::getCountPhoto()const {
	return count_photo_;
}

void Photographer::PrintStatistics() {
	*this << cout;
}

void Photographer::Imitation() {
	cout << "--------------------------------START Imitation---------------------------------" << endl;
	for (size_t i = 0; i < 3; i++) {
		cout << "����������� �" << i + 1 << endl;
		//srand(time(i));

		int votes = rand() % 30;
		if (votes >= 10) {
			rating_ += rand() % 10 + 1;
		}
		cout << "�������������: " << votes << " �� ��������� " << name_ << endl;
		cout << "������� �������: " << rating_ << " ��������� " << name_ << " " << surname_ << endl << endl;
		cout << "--------------------------------Imitation-------------------------------------" << endl;
	}
	cout << "--------------------------------END Imitation----------------------------------" << endl;
}

void Photographer::Process(const string& photo_path) {
	cout << "Photo "<< photo_path <<" was processed by " << name_;
	count_photo_++;
	cout << " ���������� ���� � ���������� " << count_photo_ << endl << endl;
}
