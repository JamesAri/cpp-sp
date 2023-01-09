#ifndef CPP_SP_CONSTANTS_H
#define CPP_SP_CONSTANTS_H


// Arguments
constexpr int EXPECTED_ARGC = 4;
const std::string ARG_CANVAS_SIZE_DELIMITER{"x"};

// Command file
constexpr char COMMENT_TAG = '#';

// SVG
const std::string SVG_EXTENSION{".svg"};
const std::string XMLNS{"http://www.w3.org/2000/svg"};
const std::string SVG_VERSION{"1.1"};
const std::string SVG_DEFAULT_BACKGROUND_COLOR{"white"};
const std::string SVG_DEFAULT_BRUSH_STYLE{" style=\"stroke:rgb(0,0,0);stroke-width:2\" "};


// PGM
const std::string PGM_EXTENSION{".pgm"};
const std::string PGM_VERSION{"P2"};
constexpr char PGM_BLACK_VALUE = '0';
constexpr char PGM_WHITE_VALUE = '1';
constexpr int PGM_MAX_LINE_WIDTH = 70;

// Error messages
const std::string FILE_OPEN_ERROR{"an error occurred, couldn't open file"};
const std::string INVALID_CANVAS_SIZE_SYNTAX_ERROR{"canvas size parameter is invalid"};
const std::string INVALID_ARGUMENTS_ERROR{"invalid arguments.\nusage: drawing.exe <input_file> <output_file> <size>"};
const std::string INVALID_FILE_TYPE_ERROR{"invalid file type, application supports svg and pgm outputs only"};
const std::string CORRUPTED_COMMAND_FILE_ERROR{"invalid input file"};
const std::string INVALID_LINE_POINTS_ERROR{"line primitive error, the extreme points must not merge"};
const std::string INVALID_CIRCLE_RADIUS_ERROR{"circle error, radius must be positive and non-zero"};
const std::string INVALID_RECT_SIZE_ERROR{"rectangle error, width and height must be positive and non-zero"};
const std::string INVALID_SCALE_MOD_ERROR{"scale error, modifier must be non-zero"};


#endif //CPP_SP_CONSTANTS_H
