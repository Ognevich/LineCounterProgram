#include "FileReader.h"

FileLineReader::FileLineReader()
{
}

int FileLineReader::CountLines(std::string& filePath)
{

	int lineCounter = 0;

	std::ifstream file(filePath);
	std::string line;


	if (file.is_open()) {
		while (std::getline(file, line)) {
			if (line != "" && line != "\t") {
				lineCounter++;
			}
		}
	}
	else {
		std::cout << "FileNotFoud";
	}

	return lineCounter;

}

std::vector<std::string> FileLineReader::GetFilesPath(const std::string& filePath)
{
	std::vector<std::string> files;

	for (auto& entry : std::filesystem::directory_iterator(filePath)) {
		if (entry.is_regular_file()) {
			std::string ext = entry.path().extension().string();
			if (ext == ".cpp" || ext == ".h") {
				files.push_back(entry.path().string());
			}
		}
		else if (entry.is_directory()){

			std::vector<std::string> subFiles = GetFilesPath(entry.path().string());
			files.insert(files.end(), subFiles.begin(), subFiles.end());
		}
	}


	return files;
}

int FileLineReader::CountLineInFiles(const std::string& filePath)
{
	int lineCounter = 0;

	std::vector<std::string> files = GetFilesPath(filePath);

	for (std::string file : files) {
		int currentLines = CountLines(file);
		lineCounter = lineCounter + currentLines;
	}

	return lineCounter;

}