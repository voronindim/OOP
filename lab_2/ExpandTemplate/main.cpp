#include "ExpandTemplate.h"

bool CopyFileWithReplace(const string& inputFileName, const string& outputFileName, const Replacement& params)
{
	ifstream inputFile;
	inputFile.open(inputFileName);
	if (!inputFile.is_open())
	{
		cout << "Input файл не открыт" << endl;
		return false;
	}
	ofstream outputFile;
	outputFile.open(outputFileName);
	if (!outputFile.is_open())
	{
		cout << "Output файл не открыт" << endl;
		return false;
	}
	string tpl;
	while (getline(inputFile, tpl))
	{
		outputFile << ExpandTemplate(tpl, params) << endl;
	}
	return true;
}

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "Параметры командной строки: expand_template.exe <input-file> <output-file> [<param> <value> [<param> <value> …]]" << endl;
		return 1;
	}
	string inputFileName = argv[1];
	string outputFileName = argv[2];

	Replacement params;
	argc = (argc % 2 == 0) ? argc - 1 : argc;
	for (int i = 3; i < argc; i += 2)
	{
		params[argv[i]] = argv[i + 1];
	}

	if (!CopyFileWithReplace(inputFileName, outputFileName, params))
	{
		return 1;
	}

	return 0;
}
