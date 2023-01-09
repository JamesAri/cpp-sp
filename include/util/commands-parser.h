#ifndef CPP_SP_COMMANDS_PARSER_H
#define CPP_SP_COMMANDS_PARSER_H

#include <filesystem>
#include "editor/Canvas.h"

/**
 * Reads commands from fileName and applies those commands.
 * @param fileName filename with commands.
 * @param canvas canvas container for loaded primitives and actions.
 */
void parseCommands(std::filesystem::path &fileName, std::shared_ptr<Canvas> &canvas);


#endif //CPP_SP_COMMANDS_PARSER_H
