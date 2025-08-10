#include "FileReader.h"



int main(){

	std::string FilePath = "D:\\my_projects\\C\\CTetrisGame";
	FileLineReader lineReader;

	int info = lineReader.CountLineInFiles(FilePath);
	std::cout << info;

	return 0;
}
