#include "util/argument-parser.h"
#include "util/string-util.h"
#include "common/constants.h"

#include <tuple>
#include <string>
#include <filesystem>


std::tuple<std::string, std::string, float, float, SUPPORTED_FILE_TYPES> parseArguments(char *argv[]) {
    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    auto sizes = split(argv[3], ARG_CANVAS_SIZE_DELIMITER);
    SUPPORTED_FILE_TYPES type;

    if (sizes.size() != 2) {
        throw std::invalid_argument(INVALID_CANVAS_SIZE_SYNTAX_ERROR);
    }

    auto stringWidth = sizes[0], stringHeight = sizes[1];
    float width, height;
    size_t idx1, idx2;

    try {
        width = std::stof(stringWidth, &idx1);
        height = std::stof(stringHeight, &idx2);
    } catch (const std::invalid_argument& ia) {
        throw std::invalid_argument(INVALID_CANVAS_SIZE_SYNTAX_ERROR);
    }

    if (idx1 != stringWidth.size() || idx2 != stringHeight.size()) {
        throw std::invalid_argument(INVALID_CANVAS_SIZE_SYNTAX_ERROR);
    }

    auto extension = std::filesystem::path(outputFile).extension();

    if (extension.compare(PGM_EXTENSION)) type = SUPPORTED_FILE_TYPES::PGM;
    else if (extension.compare(SVG_EXTENSION)) type = SUPPORTED_FILE_TYPES::SVG;

    return std::make_tuple(inputFile, outputFile, width, height, type);
}