#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <cstdio>
class XXX;
using namespace std;
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
    list<string> lString;
    string fName, line, templateClass, pathExe, pathTemplate;

	pathExe = argv[0];
	int indexXXX = pathExe.find("\\");
	while (indexXXX != string::npos)
	{
		pathTemplate += pathExe.substr(0, indexXXX + 1);
		pathExe.replace(0, indexXXX + 1, "");
		indexXXX = pathExe.find("\\");
	}
	cout << pathTemplate << endl;
	if (argc > 1) {
		templateClass = argv[1];
	}
	else {
		cin >> templateClass;
		//templateClass = "templateClass";
	}
	ifstream in(pathTemplate + "templateClass.txt"); // открываем файл для чтения
	if (in.is_open())
	{
		while (getline(in, line))
		{
			int indexXXX = line.find("XXX");
			while(indexXXX != string::npos)
			{
				line.replace(indexXXX, 3, "");
				line.insert(indexXXX, templateClass);
				indexXXX = line.find("XXX");
			}
			cout << line << endl;
			lString.push_back(line);
		}
		ofstream outcpp(pathTemplate + templateClass + ".cpp"); //output file
		ofstream outhdr(pathTemplate + templateClass + ".hpp"); //output file
		if (outcpp.is_open() && outhdr.is_open()) {
			list<string>::iterator iter = lString.begin();
			for (bool isHpp = true; iter != lString.end(); iter++) {
				line = iter->c_str();
				if (isHpp) {
					outhdr << line << std::endl;
				}
				else {
					outcpp << line << std::endl;
				}
				if (iter->find("};") != string::npos)
					isHpp = !isHpp;
			}
			outcpp.close();
			outhdr.close();
		}
		else {
			if (!outcpp.is_open()) {
				cout << "Файл не открыт для записи" << pathTemplate + templateClass + ".cpp" << endl;
				fName = templateClass + ".cpp";
				remove(fName.c_str());
			}
			else {
				outcpp.close();
			}
			if (!outhdr.is_open()) {
				cout << "Файл не открыт для записи" << pathTemplate + templateClass + ".hpp" << endl;
				fName = templateClass + ".hpp";
				remove(fName.c_str());
			}
			else {
				outhdr.close();
			}
		}
	}
	else {
		cout << "Файл не открыт в каталоге " << pathTemplate<< "templateClass.txt" <<endl;		
	}
	in.close();     // закрываем файл
	system("pause");
	return 0;
}
class XXX {
private:
//fields, methods
	static void _swap(XXX& first, XXX& second);
	void swap(XXX& other);
public:
	XXX();
	XXX(const XXX& other);
	XXX(XXX&& other);
	XXX& operator=(const XXX& other);
	XXX& operator=(XXX&& other);
	~XXX();
};
void XXX::_swap(XXX& first, XXX& second) {
	using std::swap;
	if (&first != &second) {
		//swap(first.XField, second.XField);//where XField is some class field
	}
}
void XXX::swap(XXX& other) {
	_swap(*this, other);
}
XXX::XXX(const XXX& other) {
	//this->XField = other.XField;//where XField is some class field
}
XXX::XXX(XXX&& other) {
	*this = std::move(other);
}
XXX& XXX::operator=(const XXX& other) {
	XXX temp(other);
	this->swap(temp);
	return *this;
}
XXX& XXX::operator=(XXX&& other) {
	this->swap(other);
	return *this;
}
XXX::~XXX() {}