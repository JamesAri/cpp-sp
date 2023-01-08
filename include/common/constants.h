#ifndef CPP_SP_CONSTANTS_H
#define CPP_SP_CONSTANTS_H

// Arguments
constexpr int EXPECTED_ARGC = 4;
const std::string ARG_CANVAS_SIZE_DELIMITER{"x"};

// SVG
const std::string SVG_EXTENSION{"svg"};
const std::string XMLNS{"http://www.w3.org/2000/svg"};
const std::string SVG_VERSION{"1.1"};
const std::string SVG_DEFAULT_BACKGROUND_COLOR{"white"};
const std::string SVG_DEFAULT_BRUSH_STYLE{" style=\"stroke:rgb(0,0,0);stroke-width:2\" "};


// PGM
const std::string PGM_EXTENSION{"pgm"};
const std::string PGM_VERSION{"P2"};
constexpr char PGM_BLACK_VALUE = '0';
constexpr char PGM_WHITE_VALUE = '1';
constexpr int PGM_MAX_LINE_WIDTH = 70;

// Error messages
const std::string FILE_OPEN_ERROR{"an error occurred, couldn't open file"};
const std::string INVALID_CANVAS_SIZE_SYNTAX_ERROR{"canvas size parameter is invalid"};


#endif //CPP_SP_CONSTANTS_H
