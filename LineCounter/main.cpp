#include "FileReader.h"



int main(){

	std::string FilePath = "D:\\my_projects\\c++\\pseudo_generator\\pseudo_generator";
	std::string FilePath1 = "D:\\my_projects\\c++\\pseudo_generator\\pseudo_generator\\main.cpp";
	FileLineReader lineReader;

	int info2 = lineReader.CountLines(FilePath1);
	std::cout << info2 << std::endl;

	int info = lineReader.CountLineInFiles(FilePath);
	std::cout << info;

	return 0;
}
