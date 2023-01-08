#ifndef CPP_SP_STRING_UTIL_H
#define CPP_SP_STRING_UTIL_H

#include <string>
#include <vector>

/**
 * Splits string by delimiter and doesn't return empty/whitespace tokens.
 */
std::vector<std::string> split(const std::string &s, const std::string &delimiter);

#endif //CPP_SP_STRING_UTIL_H
