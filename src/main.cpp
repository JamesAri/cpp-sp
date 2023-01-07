#include "Exporter.h"
#include "Line.h"

using namespace std::string_literals;

/**
 * Splits string by delimiter and doesn't return empty/whitespace tokens.
 */
std::vector<std::string> split(const std::string &s, const std::string &delimiter) {
    size_t posStart = 0, posEnd, delimLen = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((posEnd = s.find(delimiter, posStart)) != std::string::npos) {
        token = s.substr(posStart, posEnd - posStart);
        posStart = posEnd + delimLen;
        if(!token.empty()) res.push_back(token);
    }
    token = s.substr(posStart);
    if(!token.empty()) res.push_back(token);
    return res;
}

int main(int argc, char *argv[]) {
    // arg parsing todo
    auto inputFile  = argv[1];
    auto outputFile = argv[2];
    auto rawSize = argv[3];


    auto size = split(rawSize, "x");
    auto width = std::stof(size[0]);
    auto height = std::stof(size[1]);
    auto canvas = Canvas(width, height);
    std::shared_ptr<IDrawable> line = std::make_shared<Line>(10.f, 10.f, 30.f, 30.f);
    canvas.add(line);
    auto exporter = Exporter(canvas, "my_test.svg"s);
    exporter.exportToSvg();
}

