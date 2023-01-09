#include "editor/Exporter.h"
#include "util/argument-parser.h"
#include "util/commands-parser.h"
#include "common/constants.h"

#include <iostream>


int main(int argc, char *argv[]) {
    if (argc != EXPECTED_ARGC) {
        std::cerr << INVALID_ARGUMENTS_ERROR << std::endl;
        exit(EXIT_FAILURE);
    }

    try {
        auto [inputFile, outputFile, width, height, type] = parseArguments(argv);

        if (!isValidType(type))
            throw std::runtime_error(INVALID_FILE_TYPE_ERROR);

        auto canvas = std::make_shared<Canvas>(width, height);
        parseCommands(inputFile, canvas);
        auto exporter = Exporter(canvas, outputFile);

        switch (type) {
            case ESupportedFileTypes::SVG:
                exporter.exportToSvg();
                break;
            case ESupportedFileTypes::PGM:
                exporter.exportToPgm();
                break;
        }

    } catch (std::runtime_error &re) {
        std::cerr << re.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

