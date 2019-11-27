#include "ArgsParser.h"

#include <cstring>

bool ArgsParser::parse() {
    if (argc >= 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))) {
        help = true;
        return true;
    }

    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-i") || !strcmp(argv[i], "--input")) {
            if (++i >= argc) {
                return false;
            }

            input = argv[i];
        } else if (!strcmp(argv[i], "-o") || !strcmp(argv[i], "--output")) {
            if (++i >= argc) {
                return false;
            }

            output = argv[i];
        } else {
            return false;
        }
    }

    return true;
}
