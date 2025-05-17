#include "global_variables.hpp"

#include <filesystem>

// ### Different paths ###
std::string getPathToFont() {
    std::string systemPath = "/usr/share/raquette-baballe/ressources/fonts/CaskaydiaCoveNerdFontMono-Regular.ttf";
    std::string localPath = "ressources/fonts/CaskaydiaCoveNerdFontMono-Regular.ttf";

    return std::filesystem::exists(systemPath) ? systemPath : localPath;
}

std::string getPathToMusic() {
    std::string systemPath = "/usr/share/raquette-baballe/ressources/music/music.wav";
    std::string localPath = "ressources/music/music.wav";

    return std::filesystem::exists(systemPath) ? systemPath : localPath;
}

std::string getPathToHeartImage() {
    std::string systemPath = "/usr/share/raquette-baballe/ressources/images/heart.png";
    std::string localPath = "ressources/images/heart.png";

    return std::filesystem::exists(systemPath) ? systemPath : localPath;
}

std::string getPathToLevels() {
    std::string systemPath = "/usr/share/raquette-baballe/ressources/levels/";
    std::string localPath = "ressources/levels/";

    return std::filesystem::exists(systemPath) ? systemPath : localPath;
}