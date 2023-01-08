#include "Exporter.h"
#include <fstream>
#include <sstream>

std::string backgroundElement() {
    std::stringstream ss;
    ss << R"(<rect width="100%" height="100%")"
       << " stroke=\"" << DEFAULT_BACKGROUND_COLOR << "\""
       << " fill=\"" << DEFAULT_BACKGROUND_COLOR << "\"/>\n";
    return ss.str();
}


Exporter::Exporter(Canvas &canvas, std::string &&fileName) : mCanvas(canvas), mFileName(fileName) {}

void Exporter::exportToPgm() {

}

void Exporter::exportToSvg() {
    std::ofstream output(mFileName, std::ios_base::trunc);

    if (!output.is_open()) {
        throw std::runtime_error(FILE_OPEN_ERROR);
    }

    output << "<svg version=\"" << SVG_VERSION << "\"\n"
           << "     width=\"" << mCanvas.getWidth() << "\"\n"
           << "     height=\"" << mCanvas.getHeight() << "\"\n"
           << "     style=\"background-color:" << DEFAULT_BACKGROUND_COLOR << "\"\n"
           << "     xmlns=\"" << XMLNS << "\">\n"
           << mCanvas.asSvg().str()
           << "</svg>\n";
}