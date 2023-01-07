#include "Exporter.h"
#include <fstream>
#include <sstream>

std::string backgroundElement() {
    std::stringstream ss;
    ss << R"(<rect width="100%" height="100%")"
       << " stroke=\"" << BACKGROUND_DEFAULT_COLOR << "\""
       << " fill=\"" << BACKGROUND_DEFAULT_COLOR << "\"/>";
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
           << "     xmlns=\"" << XMLNS << "\">\n"
           << "     " << backgroundElement() << "\n"
           << "     " << mCanvas.asSvg().str() << "\n"
           << "</svg>\n";
}