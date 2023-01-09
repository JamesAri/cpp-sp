#ifndef CPP_SP_ARGUMENT_PARSER_H
#define CPP_SP_ARGUMENT_PARSER_H

#include <tuple>
#include <filesystem>
#include "supported-file-types.h"

/**
 * @return input file, output file, width and height wrapped in tuple.
 */
std::tuple<std::filesystem::path, std::filesystem::path, float, float, ESupportedFileTypes>
        parseArguments(char *argv[]);

#endif //CPP_SP_ARGUMENT_PARSER_H
