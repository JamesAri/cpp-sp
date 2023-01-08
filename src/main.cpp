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
        if (!token.empty()) res.push_back(token);
    }
    token = s.substr(posStart);
    if (!token.empty()) res.push_back(token);
    return res;
}

int main(int argc, char *argv[]) {
    auto inputFile = argv[1];
    auto outputFile = argv[2];
    auto rawSize = argv[3];

    auto size = split(rawSize, "x");
    auto width = std::stof(size[0]);
    auto height = std::stof(size[1]);
    auto canvas = Canvas(width, height);

    std::shared_ptr<IDrawable> line = std::make_shared<Line>(50.f, 50.f, 100.f, 50.f);
    canvas.add(line);
    canvas.rotate({75.0f, 50.0f}, 45);
    canvas.translate({20.0f, 20.0f});
    canvas.scale({0.0f, 0.0f}, 2.f);
    std::shared_ptr<IDrawable> line2 = std::make_shared<Line>(20.f, 20.f, 100.f, 80.f);
    canvas.add(line2);
    canvas.scale({0.0f, 0.0f}, .25);
    std::shared_ptr<IDrawable> line3 = std::make_shared<Line>(5.f, 20.f, 25.f, 5.f);
    canvas.add(line3);
    canvas.rotate({80.0f, 80.0f}, 180.f);
    canvas.rotate({80.0f, 80.0f}, 90.f);
    canvas.rotate({80.0f, 80.0f}, -180.f);

    auto exporter = Exporter(canvas, "my_test.svg"s);
    exporter.exportToSvg();
}

