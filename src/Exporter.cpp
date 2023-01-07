#include "Exporter.h"
#include <fstream>
#include <sstream>

Exporter::Exporter(Canvas &canvas, std::string &fileName) : mCanvas(canvas), mFileName(fileName) {}

void Exporter::exportToPgm() {

}

void Exporter::exportToSvg() {
    std::ofstream output(mFileName, std::ios_base::trunc);

    if (!output.is_open()) {
        throw std::runtime_error(FILE_OPEN_ERROR);
    }

    std::stringstream ss;
    ss << "<svg version=\"" << SVG_VERSION <<"\"\n"
       << "     width=\"" << mCanvas.getWidth() << "\"\n"
       << "     height=\"" << mCanvas.getHeight() << "\"\n"
       << "     xmlns=\"" << XMLNS << "\">\n"
       << "         " << mCanvas.asSvg()
       << "</svg>\n";

    output << ss.rdbuf();
}

/*
 *


    <g transform="
			  rotate(45 50 50)
			  translate(70, 0)
			  translate(0, 0)
			  scale(.5)
			  translate(70, 0)
   ">
        <rect width="50%" height="50%" fill="blue" />
        <circle cx="150" cy="100" r="80" fill="green" />
    </g>



 */