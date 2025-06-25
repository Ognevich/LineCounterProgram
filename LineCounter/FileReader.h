#ifndef FILE_READER_H
#define FILE_READER_H
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>

class FileLineReader{
public:
	FileLineReader();

	int CountLines(std::string& filePath);
	std::vector<std::string> GetFilesPath(const std::string& filePath);
	int CountLineInFiles(const std::string& filePath);

private:
};

#endif
