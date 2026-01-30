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
			cout << "Ñòóäåíò ïåðåâåäåí íà " << course_ << " êóðñ." << endl;
			return true;
		}
		else {
			cout << "Ñòóäåíò ó÷èòñÿ íà ïîñëåäíåì êóðñå." << endl;
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
		cout << "=== Èíôîðìàöèÿ î ñòóäåíòå ===" << endl;
		cout << "Èìÿ: " << fName_ << endl;
		cout << "Ôàìèëèÿ: " << lName_ << endl;
		cout << "Íàïðàâëåíèå: " << spec_ << endl;
		cout << "Êóðñ: " << course_ << endl;
		cout << "Ãðóïïà: " << group_ << endl;
		cout << "Âàðèàíò: " << var_ << endl;
		cout << "=============================" << endl;
	}

	Student() : fName_(""), lName_(""), spec_(""), course_(1), group_(1), var_(1) {
		cout << "Êîíñòðóêòîð ïî óìîë÷àíèþ âûçâàí" << endl;
	}

	Student(const string& fName, const string& lName, const string& spec, int course, const int& group, int variant)
		: fName_(fName), lName_(lName), spec_(spec), course_(course), group_(group), var_(variant) {

		if (course_ < 1) course_ = 1;
		if (course_ > 6) course_ = 6;
		if (var_ < 1) var_ = 1;

		cout << "Êîíñòðóêòîð ïîëíîãî çàïîëíåíèÿ âûçâàí" << endl;
	}

	Student(const Student& other)
		: fName_(other.fName_), lName_(other.lName_), spec_(other.spec_), course_(other.course_), group_(other.group_), var_(other.var_) {
		cout << "Êîíñòðóêòîð êîïèðîâàíèÿ âûçâàí" << endl;
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

	cout << "Ñîçäàíèå ñòóäåíòà ÷åðåç êîíñòðóêòîð ïî óìîë÷àíèþ" << endl;
	Student student1;
	student1.infa();

	cout << "\nÑîçäàíèå ñòóäåíòà ÷åðåç êîíñòðóêòîð ïîëíîãî çàïîëíåíèÿ" << endl;
	Student student2("Äæîííè", "Êåéäæ", "Ìàòîáèê", 2, 2, 5);
	student2.infa();

	cout << "\nÑîçäàíèå ñòóäåíòà ÷åðåç êîíñòðóêòîð êîïèðîâàíèÿ" << endl;
	Student student3 = student2;
	student3.infa();

	cout << "\nÒåñò ñåòòåðîâ" << endl;
	student1.set_course(3);
	student1.set_var(10);
	cout << "Óñòàíîâëåí êóðñ: " << student1.get_course() << endl;
	cout << "Óñòàíîâëåí âàðèàíò: " << student1.get_var() << endl;

	cout << "\nÒåñò ïåðåâîäà íà ñëåäóþùèé êóðñ" << endl;
	student2.perevod();
	student2.infa();

	// Ïåðåâîä ñòóäåíòà, êîòîðûé íà ïîñëåäíåì êóðñå
	Student student4("Êåíøè", "Òàêàõàøè", "Èïøå÷êà", 6, 1, 3);
	student4.perevod();
}
