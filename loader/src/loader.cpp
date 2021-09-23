#include "loader/loader.h"

std::vector<std::string> get_elems(std::string* line, std::string prefix) {
    std::vector<std::string> elems;
    size_t pos = 0;
    while ((pos = (*line).find(prefix)) != std::string::npos)
    {
        elems.push_back((*line).substr(0, pos));
        (*line).erase(0, pos + 1);
    }
    elems.push_back(*line);
    return elems;
}

Loader::VWF parse(std::vector<std::string> lines) {
    Loader::VWF vwf;

    std::vector<std::string> elems = get_elems(&lines.at(0), " ");
    
    vwf.point_count = std::stoi(elems.at(0));
    vwf.plan = std::stoi(elems.at(1));
    vwf.horizons = std::stoi(elems.at(2));
    vwf.deviation = std::stof(lines.at(1));

    for (int i = 0; i < vwf.point_count; i++)
    {
        std::vector<std::string> coords = get_elems(&lines.at(2 + i), " ");
        vwf.traectory.push_back(Loader::Point{
            std::stof(coords.at(0)), // x
            std::stof(coords.at(1)), // y
            std::stof(coords.at(2)) // z
        });
    }
    
    for (int i = 0; i < vwf.plan; i++)
    {
        std::vector<std::string> coords = get_elems(&lines.at(2 + vwf.point_count + i), " ");
        vwf.ptraectory.push_back(Loader::Point{
            std::stof(coords.at(0)), // x
            std::stof(coords.at(1)), // y
            std::stof(coords.at(2)) // z
        });
    }

    for (int i = 0; i < vwf.horizons; i++)
    {
        std::vector<std::string> coords = get_elems(&lines.at(2 + vwf.point_count + vwf.plan + i), " ");
        vwf.hpoints.push_back(Loader::Horizon{
            std::stof(coords.at(0)), // x1
            std::stof(coords.at(1)), // z1
            std::stof(coords.at(2)), // x2
            std::stof(coords.at(3)) // z2
        });
    }

    return vwf;
}

Loader::VWF Loader::load_file(const char file_name[]) {
    std::ifstream file(file_name, std::ios_base::in);
    std::string str;
    std::vector<std::string> file_str;

    if (!file.is_open())
    {
            printf("Couldn't open file.");
    }

    if (!file.good()) {
            printf("File is not exists.");
    }

    while (std::getline(file, str)) {
        file_str.push_back(str);
    }

    file.close();
    return parse(file_str);
}