#include <iostream>
#include <fstream>
#include <string>

const std::string	ft_replace(const std::string src, std::string target, std::string replacement) {
	
	std::string	sourceString = src;
	std::string infront;
	std::string behind;

	size_t targetPosition = sourceString.find(target);
	while (targetPosition != std::string::npos) {
		infront = sourceString.substr(0, targetPosition);
		behind = sourceString.substr(targetPosition + target.length());
		sourceString = infront.append(replacement).append(behind);
		targetPosition = sourceString.find(target);
	}
	return (sourceString);
}

void	replaceInFile(std::string filename, std::string targetString, std::string replacementString) {
	std::ifstream inputFile(filename.c_str());
	if (!inputFile) {
		throw std::runtime_error("Couldn't open input file");
	}
	std::string fileContent((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
	inputFile.close();

	const std::string fileContentReplaced = ft_replace(fileContent, targetString, replacementString);
	
	std::ofstream outputFile(filename.append(".replace").c_str());
	if (!outputFile) {
		throw std::runtime_error("Couldn't open output file");
	}
	outputFile << fileContentReplaced;
	outputFile.close();
	return ;
}

int	main(int argc, const char **argv) {
	if (argc != 4) {
		std::cerr <<  "Usage: replace <filename> <targetString> <replacementString>" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string targetString = argv[2];
	std::string replacementString = argv[3];

	try {
        replaceInFile(filename, targetString, replacementString);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }
	return (0);
}