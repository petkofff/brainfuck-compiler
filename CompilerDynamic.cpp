#include "CompilerDynamic.h"

#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

bool CompilerDynamic::generateCPP() {
    ifstream inp(inputFile);

    if (!inp) {
        cout << "Cannot open input file \"" << inputFile << "\"" << endl;
        return false;
    }

    CPPName = outputFile;
    CPPName += ".cpp";
    ofstream out(CPPName);

    if (!out) {
        cout << "Failed to initialize output stream to \"" << outputFile << "\""
             << endl;
        return false;
    }

    out << DEVectorSource << endl << endl << DynamicStripSource << endl;

    out << "int main() { DynamicStrip s; s.right(); s.left(); ";

    int brackets = 0;

    while (inp) {
        char c = 0;
        inp >> c;

        if (c == '>') {
            out << "s.right(); ";
        } else if (c == '<') {
            out << "s.left(); ";
        } else if (c == '+') {
            out << "++s; ";
        } else if (c == '-') {
            out << "--s; ";
        } else if (c == '.') {
            out << "s.put(); ";
        } else if (c == ',') {
            out << "s.read(); ";
        } else if (c == '[') {
            brackets++;
            out << "while(*s){ ";
        } else if (c == ']') {
            if (brackets < 0) {
                cout << "Unmatched bracket ']'" << endl;
                inp.close();
                out.close();
                return false;
            }

            out << "} ";
        }
    }

    out << "return 0; }" << endl;

    inp.close();
    out.close();

    return true;
}

void CompilerDynamic::generateBinary() {
    string command = "g++ --std=c++14 ";
    command += CPPName;
    command += " -o ";
    command += outputFile;
    system(command.c_str());
}
