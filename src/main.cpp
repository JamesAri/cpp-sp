#include "editor/Exporter.h"
#include "components/Line.h"
#include "components/Rectangle.h"
#include "components/Circle.h"
#include "util/string-util.h"
#include "util/argument-parser.h"
#include "common/constants.h"

using namespace std::string_literals;

// Apple Clang nema support pro:
//      std::execution, std::ranges, std::format, ...
// jinak bych je v praci velmi rad pouzil
// https://en.cppreference.com/w/cpp/compiler_support/20

//        std::shared_ptr<IDrawable> line = std::make_shared<Line>(50.f, 50.f, 100.f, 50.f);
//        canvas.add(line);
int main(int argc, char *argv[]) {
    if (argc != EXPECTED_ARGC) {
        perror("Invalid arguments.\nUsage: drawing.exe <input_file> <output_file> <size>");
        exit(EXIT_FAILURE);
    }

    try {
        auto [inputFile, outputFile, width, height, type] = parseArguments(argv);
        auto canvas = Canvas(width, height);
        auto exporter = Exporter(canvas, outputFile);

        switch (type) {
            case SUPPORTED_FILE_TYPES::SVG:
                exporter.exportToSvg();
                break;
            case SUPPORTED_FILE_TYPES::PGM:
                exporter.exportToPgm();
                break;
        }

    } catch (std::runtime_error &re) {
        perror(re.what());
        exit(EXIT_FAILURE);
    }
}

