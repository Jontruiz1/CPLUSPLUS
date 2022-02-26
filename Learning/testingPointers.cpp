#include <iostream>
#include <vector>

using std::cout;
using std::endl;

class Person{
	
	public:
		Person(int ag, std::string fname, std::string lname) : age(ag), f_name(fname), l_name(lname){};
		int getAge(){return age;}
		std::string getFName(){return f_name;}
		std::string getLName(){return l_name;}
	private:
		int age;
		std::string f_name;
		std::string l_name;
};

int main() {
	
	Person test1(15, "John", "Jeffrey");
	
	cout << test1.getAge() << " " << test1.getFName() << " " << test1.getLName();

	Person* test2 = new Person(15, "John", "Jeffrey");
	test2->getAge();
	delete test2;


}

