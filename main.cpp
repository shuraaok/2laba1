#include <iostream>
using namespace std;

class Student {
public:

	~Student() {
		cerr << "dtor" << endl;
	}

	bool set_course(int course) {
		if (course > 0 and course <= 4) {
			course_ = course;
			return true;
		}
		return false;
	}
	bool set_var(int var) {
		if (var > 0) {
			var_ = var;
			return true;
		}
		return false;
	}

	bool perevod() {
		if (course_ < 4) {
			course_++;
			cout << "Студент переведен на " << course_ << " курс." << endl;
			return true;
		}
		else {
			cout << "Студент учится на последнем курсе." << endl;
			return false;
		}
	};

	string get_fName() const { return fName_; }
	string get_lName() const { return lName_; }
	string get_spec() const { return spec_; }
	int get_course() const { return course_; }
	int get_group() const { return group_; }
	int get_var() const { return var_; }

	void infa() const {
		cout << "=== Информация о студенте ===" << endl;
		cout << "Имя: " << fName_ << endl;
		cout << "Фамилия: " << lName_ << endl;
		cout << "Направление: " << spec_ << endl;
		cout << "Курс: " << course_ << endl;
		cout << "Группа: " << group_ << endl;
		cout << "Вариант: " << var_ << endl;
		cout << "=============================" << endl;
	}

	Student() : fName_(""), lName_(""), spec_(""), course_(1), group_(1), var_(1) {
		cout << "Конструктор по умолчанию вызван" << endl;
	}

	Student(const string& fName, const string& lName, const string& spec, int course, const int& group, int variant)
		: fName_(fName), lName_(lName), spec_(spec), course_(course), group_(group), var_(variant) {

		if (course_ < 1) course_ = 1;
		if (course_ > 6) course_ = 6;
		if (var_ < 1) var_ = 1;

		cout << "Конструктор полного заполнения вызван" << endl;
	}

	Student(const Student& other)
		: fName_(other.fName_), lName_(other.lName_), spec_(other.spec_), course_(other.course_), group_(other.group_), var_(other.var_) {
		cout << "Конструктор копирования вызван" << endl;
	}

private:
	string fName_;
	string lName_;
	string spec_;
	int course_;
	int group_;
protected:
	int var_;
};
int main() {
	setlocale(LC_ALL, "Russian");

	cout << "Создание студента через конструктор по умолчанию" << endl;
	Student student1;
	student1.infa();

	cout << "\nСоздание студента через конструктор полного заполнения" << endl;
	Student student2("Джонни", "Кейдж", "Матобик", 2, 2, 5);
	student2.infa();

	cout << "\nСоздание студента через конструктор копирования" << endl;
	Student student3 = student2;
	student3.infa();

	cout << "\nТест сеттеров" << endl;
	student1.set_course(3);
	student1.set_var(10);
	cout << "Установлен курс: " << student1.get_course() << endl;
	cout << "Установлен вариант: " << student1.get_var() << endl;

	cout << "\nТест перевода на следующий курс" << endl;
	student2.perevod();
	student2.infa();

	//Перевод студента, который на последнем курсе
	Student student4("Кенши", "Такахаши", "Ипшечка", 6, 1, 3);
	student4.perevod();
}
