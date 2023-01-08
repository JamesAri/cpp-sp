#include "editor/Exporter.h"
#include <fstream>
#include <sstream>

/**
 * Creates PGM P2 version raster.
 * Created pixels will have the lowest value, i.e. black color.
 *
 * https://netpbm.sourceforge.net/doc/pgm.html
 *
 * @param pixels sorted unique integers representing pixels in bitmap.
 * @return raster string stream.
 */
std::stringstream createRaster(std::vector<int> pixels, int canvasSize) {
    std::stringstream ss;
    auto targetPixel = pixels.back();
    pixels.pop_back();
    for (int i = 0; i < canvasSize; i++) {
        if (!(i % PGM_MAX_LINE_WIDTH)) {
            ss << "\n";
        }

        if (i == targetPixel) {
            if (!pixels.empty()) {
                targetPixel = pixels.back();
                pixels.pop_back();
            }
            ss << PGM_BLACK_VALUE << " ";
            continue;
        }

        ss << PGM_WHITE_VALUE << " ";
    }
    return ss;
}

std::vector<int> createUniqueSortedPixels(const std::vector<Point> &points, float canvasWidth) {
    std::vector<int> pixels(points.size());

    // std::execution::par_unseq - not supported by Apple Clang
    std::transform(points.cbegin(), points.cend(),
                   std::back_inserter(pixels),
                   [canvasWidth](const Point &p) {
                       return static_cast<int>(p.getY() * canvasWidth + p.getX());
                   });
    std::sort(pixels.rbegin(), pixels.rend()); // could use Radix sort
    pixels.erase(unique(pixels.begin(), pixels.end()), pixels.end());
    return pixels;
}

Exporter::Exporter(Canvas &canvas, std::string &fileName) : mCanvas(canvas), mFileName(fileName) {}

void Exporter::exportToPgm() {
    std::ofstream output(mFileName, std::ios_base::trunc);

    if (!output.is_open()) {
        throw std::runtime_error(FILE_OPEN_ERROR);
    }

    output << PGM_VERSION << "\n"
           << mCanvas.getWidth() << " " << mCanvas.getHeight() << "\n"
           << PGM_WHITE_VALUE;

    auto points = mCanvas.asPgm();

    if (points.empty()) {
        output << std::endl;
        return;
    }

    auto pixels = createUniqueSortedPixels(points, mCanvas.getWidth());
    auto canvasSize = static_cast<int>(mCanvas.getWidth() * mCanvas.getHeight());
    auto raster = createRaster(pixels, canvasSize);
    output << raster.rdbuf();
}



void Exporter::exportToSvg() {
    std::ofstream output(mFileName, std::ios_base::trunc);

    if (!output.is_open()) {
        throw std::runtime_error(FILE_OPEN_ERROR);
    }

    output << "<svg version=\"" << SVG_VERSION << "\"\n"
           << "     width=\"" << mCanvas.getWidth() << "\"\n"
           << "     height=\"" << mCanvas.getHeight() << "\"\n"
           << "     style=\"background-color:" << SVG_DEFAULT_BACKGROUND_COLOR << "\"\n"
           << "     xmlns=\"" << XMLNS << "\">\n"
           << mCanvas.asSvg().str()
           << "</svg>\n";
}