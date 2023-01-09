#include "util/argument-parser.h"
#include "util/string-util.h"
#include "common/constants.h"

#include <tuple>
#include <string>


std::tuple<std::filesystem::path, std::filesystem::path, float, float, ESupportedFileTypes>
        parseArguments(char *argv[]) {
    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    auto sizes = split(argv[3], ARG_CANVAS_SIZE_DELIMITER);
    ESupportedFileTypes type;

    if (sizes.size() != 2) {
        throw std::runtime_error(INVALID_CANVAS_SIZE_SYNTAX_ERROR);
    }

    auto stringWidth = sizes[0], stringHeight = sizes[1];
    float width, height;
    size_t idx1, idx2;

    try {
        width = std::stof(stringWidth, &idx1);
        height = std::stof(stringHeight, &idx2);
    } catch (const std::runtime_error& ia) {
        throw std::runtime_error(INVALID_CANVAS_SIZE_SYNTAX_ERROR);
    }

    if (idx1 != stringWidth.size() || idx2 != stringHeight.size()) {
        throw std::runtime_error(INVALID_CANVAS_SIZE_SYNTAX_ERROR);
    }

    auto extension = std::filesystem::path(outputFile).extension();

    if (!extension.compare(PGM_EXTENSION)) type = ESupportedFileTypes::PGM;
    else if (!extension.compare(SVG_EXTENSION)) type = ESupportedFileTypes::SVG;

    return std::make_tuple(inputFile, outputFile, width, height, type);
}