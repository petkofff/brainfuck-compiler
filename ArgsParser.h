#pragma once

#include <cstring>

class ArgsParser {
   public:
    ArgsParser(int argc, char** argv)
        : argc(argc),
          argv(argv),
          input(nullptr),
          output(nullptr),
          help(false) {}

    ArgsParser() = delete;
    ArgsParser(const ArgsParser&) = default;
    ~ArgsParser() = default;

    bool parse();

    const char* inputStr() const { return input; }

    const char* outputStr() const { return output; }

    bool helpFlag() const { return help; }

   private:
    int argc;
    char** argv;

    char* input;
    char* output;
    bool help;
};
