#ifndef CPP_SP_EXPORTER_H
#define CPP_SP_EXPORTER_H

#include "Canvas.h"

class Exporter {
private:
    Canvas mCanvas;
    std::string mFileName;
public:
    explicit Exporter(Canvas &canvas, std::string &&fileName);

    void exportToSvg();
    void exportToPgm();
};


#endif //CPP_SP_EXPORTER_H
