#include "util/commands-parser.h"
#include "components/Line.h"
#include "components/Rectangle.h"
#include "components/Circle.h"

#include <iostream>
#include <fstream>
#include <string>

enum EOperations {
    LINE,
    CIRCLE,
    RECT,
    ROTATE,
    SCALE,
    TRANSLATE,
    UNKNOWN,
};

constexpr EOperations getOperationCode(std::string const &string) {
    if (string == "line") return EOperations::LINE;
    if (string == "circle") return EOperations::CIRCLE;
    if (string == "rect") return EOperations::RECT;
    if (string == "rotate") return EOperations::ROTATE;
    if (string == "scale") return EOperations::SCALE;
    if (string == "translate") return EOperations::TRANSLATE;
    return EOperations::UNKNOWN;
}

bool applyCanvasCommand(std::string &command, std::shared_ptr<Canvas> &canvas) {
    // TODO: if input command in trimmed, we can check stringstrem for eof, which
    //      should return 1 if there are no more elements, i.e. line 10 15 20 25 30
    //      would not be a valid command.
    std::stringstream ss(command);
    std::string operation;
    ss >> operation;
    auto operationCode = getOperationCode(operation);
    float x1, x2, y1, y2, r, w, h, f, a;
    switch (operationCode) {
            /**
             * line <x1> <y1> <x2> <y2>
             */
        case LINE:
            if (!(ss >> x1 >> y1 >> x2 >> y2)) return false;
            canvas->add(std::make_unique<Line>(x1, y1, x2, y2));
            break;
            /**
             * circle <x> <y> <r>
             */
        case CIRCLE:
            if (!(ss >> x1 >> y1 >> r)) return false;
            canvas->add(std::make_unique<Circle>(x1, y1, r));
            break;
            /**
             * rect <x> <y> <w> <h>
             */
        case RECT:
            if (!(ss >> x1 >> y1 >> w >> h)) return false;
            canvas->add(std::make_unique<Rectangle>(x1, y1, w, h));
            break;
            /**
            * rotate <x> <y> <a>
            */
        case ROTATE:
            if (!(ss >> x1 >> y1 >> a)) return false;
            canvas->rotate({x1, y1}, a);
            break;
            /**
            * scale <x> <y> <f>
            */
        case SCALE:
            if (!(ss >> x1 >> y1 >> f)) return false;
            if(f == 0.f) throw std::runtime_error(INVALID_SCALE_MOD_ERROR);
            canvas->scale({x1, y1}, f);
            break;
            /**
            * translate <x> <y>
            */
        case TRANSLATE:
            if (!(ss >> x1 >> y1)) return false;
            canvas->translate({x1, y1});
            break;
        case UNKNOWN:
            return false;
    }
    return true;
}

void parseCommands(std::filesystem::path &fileName, std::shared_ptr<Canvas> &canvas) {
    std::ifstream input(fileName);

    if (!input.is_open()) {
        throw std::runtime_error(FILE_OPEN_ERROR);
    }

    auto validLinesCounter = 0;

    for (std::string line; getline(input, line);) {
        auto pos = line.find(COMMENT_TAG);
        if (pos != std::string::npos)
            line = line.substr(0, pos);

        // Also checks empty lines
        if (std::all_of(line.begin(), line.end(), isspace)) {
            continue;
        }

        // Missing line trimming here.
        // Since I'm using Apple Clang C++20 library features
        // I cannot use ranges or some features from std::functional which
        // were removed in C++20. Also, I would probably use boost for trimming,
        // but that's overkill in this case. Since I don't want to implement some
        // nonsensical implementation for trimming string, I will skip this part.
        // This leads to unwanted behaviour where for example:
        // line 10 15 20 25 30 will be parsed as valid command line 10 15 20 25.

        try {
            auto success = applyCanvasCommand(line, canvas);
            if (!success) throw std::runtime_error("");
            validLinesCounter++;
        } catch (std::exception &e) {
            std::stringstream ss;
            ss << CORRUPTED_COMMAND_FILE_ERROR << "\n"
            << line << " is not a valid command\n"
            << e.what();
            throw std::runtime_error(ss.str());
        }
    }
    std::cout << "OK\n" << validLinesCounter << std::endl;
}

