#include "util/string-util.h"

std::vector<std::string> split(const std::string &s, const std::string &delimiter) {
    size_t posStart = 0, posEnd, delimLen = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((posEnd = s.find(delimiter, posStart)) != std::string::npos) {
        token = s.substr(posStart, posEnd - posStart);
        posStart = posEnd + delimLen;
        if (!token.empty()) res.push_back(token);
    }
    token = s.substr(posStart);
    if (!token.empty()) res.push_back(token);
    return res;
}