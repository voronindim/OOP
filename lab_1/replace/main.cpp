#include <iostream>
#include <fstream>

using namespace std;
string ReplaceString(string str, string const& lineBefore, string const& lineAfter)
{
    if(!lineBefore.empty())
    {
        size_t value = 0;
        value = str.find(lineBefore, value);
        while(value != string::npos)
        {
            str.erase(value, lineBefore.length());
            str.insert(value, lineAfter);
            value = value + lineAfter.length();
            value = str.find(lineBefore, value);
        }
    }
    return str;
}

void ReadFile(ifstream &fileInput,ofstream &fileOutput, string const& lineBefore, string lineAfter)
{
    string str;
    while (getline(fileInput, str))
    {
        fileOutput << ReplaceString(str, lineBefore, lineAfter);
        if (!fileInput.eof())
        {
            fileOutput << '\n';
        }
    }
}

int main(int argc, char * argv[])
{
    if (argc != 5)
    {
        std::cout << "Invalid argument count\n"
                  << "Usage: replace.exe <inputFile> <outputFile> <searchString> <replacementString>\n";
        return 1;
    }
    ifstream fileInput;
    ofstream fileOutput;
    fileInput.open(argv[1]);
    fileOutput.open(argv[2]);
    string lineBefore = argv[3];
    string lineAfter = argv[4];

    if (!fileInput.is_open())
    {
        cout << "Файл input невозможно открыть\n";
        return 1;
    }

    if (!fileOutput.is_open())
    {
        cout << "Файл output невозможно открыть\n";
        return 1;
    }

    ReadFile(fileInput, fileOutput, lineBefore, lineAfter);

    if (!fileOutput.flush())
    {
        cout << "Fallid to write data to output file\n";
        return 1;
    }
    if (fileInput.bad())
    {
        cout << "Fallid to read data from input file\n";
        return 1;
    }
    return 0;
}
