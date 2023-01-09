#ifndef CPP_SP_EXPORTER_H
#define CPP_SP_EXPORTER_H

#include "Canvas.h"
#include <filesystem>

class Exporter {
private:
    std::shared_ptr<Canvas> mCanvas;
    std::filesystem::path mFileName;
public:
    Exporter(std::shared_ptr<Canvas> &canvas, std::filesystem::path &fileName);

    void exportToSvg();
    void exportToPgm();
};


#endif //CPP_SP_EXPORTER_H
