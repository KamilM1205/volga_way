#pragma once

#include <cstdio>
#include <vector>
#include <fstream>

namespace Loader {
    namespace errors
    {
        const int OK = 0x000;
        const int FILE_EXISTS_ERROR = 0x001;
        const int FILE_OPEN_ERROR = 0x002;
        const int FILE_STRUCT_ERROR = 0x003;
    } // namespace errors
    

    // Структура координат 3-х мерной точки
    struct Point
    {
        float x, y, z;
    };

    struct Horizon 
    {
        float x1, z1, x2, z2;
    };
    
    /* VWF - VolgaWayFile
    *  Это структура файла *.vwf
    *  Хранит в себе данные скважины
    */
    typedef struct VWF {
        int point_count; // Количество точек скважины
        int plan; // Количество точек плана
        int horizons; // Количество точек горизонта
        float deviation; // Погрешность
        std::vector<Point> traectory; // Точки траектории скважины
        std::vector<Point>  ptraectory; // Точки плана
        std::vector<Horizon> hpoints; // Точки горизонта

        u_short error; // Код ошибки при загрузке/парсинге файла
    };

    // Загружает файл и парсит его в структуру VWF
    VWF load_file(const char file_path[]);
};