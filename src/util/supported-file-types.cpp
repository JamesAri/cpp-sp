#include "util/supported-file-types.h"

bool isValidType(ESupportedFileTypes type) {
    switch (type) {
        case ESupportedFileTypes::SVG:
        case ESupportedFileTypes::PGM:
            return true;
        default:
            return false;
    }
}
