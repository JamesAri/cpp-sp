#ifndef CPP_SP_ARGUMENT_PARSER_H
#define CPP_SP_ARGUMENT_PARSER_H

#include <tuple>
#include "common/supported-file-types.h"


/**
 * @return input file, output file, width and height wrapped in tuple.
 */
std::tuple<std::string, std::string, float, float, SUPPORTED_FILE_TYPES> parseArguments(char *argv[]);

#endif //CPP_SP_ARGUMENT_PARSER_H
