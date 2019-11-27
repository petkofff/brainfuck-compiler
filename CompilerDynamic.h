#pragma once

#include <string>

using std::string;

class CompilerDynamic {
   public:
    CompilerDynamic(const char* inputFile, const char* outputFile,
                    const char* DEVectorSource, const char* DynamicStripSource)
        : inputFile(inputFile),
          outputFile(outputFile),
          DEVectorSource(DEVectorSource),
          DynamicStripSource(DynamicStripSource) {}

    CompilerDynamic() = delete;
    CompilerDynamic(const CompilerDynamic&) = default;
    ~CompilerDynamic() = default;

    bool generateCPP();
    void generateBinary();

   private:
    const char* inputFile;
    const char* outputFile;
    const char* DEVectorSource;
    const char* DynamicStripSource;
    string CPPName;
};
