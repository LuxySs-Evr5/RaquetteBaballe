#include "log.hpp"

#include <iostream>

std::unique_ptr<Log> Log::singleton;

Log::Log() : logfile("log.txt") {
    if (!logfile.is_open()) {
        std::cerr << "Error opening log file!" << std::endl;
    }
    logTypeEnabled = {
        {LogType::BallPos, true},
        {LogType::Bidirectional, true},
        {LogType::BounceType, true},
        {LogType::BrickDestroyed, true},
        {LogType::ChangeBetweenLastUpdate, true},
        {LogType::ClosestPoint, true},
        {LogType::CollidingObject, true},
        {LogType::CollisionButSameDirection, true},
        {LogType::DirVec, true},
        {LogType::Error, true},
        {LogType::PenetrationRate, true},
        {LogType::Unidirectional, true},
    };
}

std::string Log::logTypeToString(LogType type) const {
    switch (type) {
    case LogType::BallPos:
        return "BallPos";
    case LogType::Bidirectional:
        return "Bidirectional";
    case LogType::BounceType:
        return "BounceType";
    case LogType::BrickDestroyed:
        return "BrickDestroyed";
    case LogType::ChangeBetweenLastUpdate:
        return "ChangeBetweenLastUpdate";
    case LogType::ClosestPoint:
        return "ClosestPoint";
    case LogType::CollidingObject:
        return "CollidingObject";
    case LogType::CollisionButSameDirection:
        return "CollisionButSameDirection";
    case LogType::DirVec:
        return "Dirvec";
    case LogType::Error:
        return " Error";
    case LogType::PenetrationRate:
        return "PenetrationRate";
    case LogType::Unidirectional:
        return "Unidirectional";
    default:
        return "Unknown";
    }
}

Log &Log::get() {
    if (!singleton) {
        singleton = std::unique_ptr<Log>(new Log());
    }
    return *singleton;
}

void Log::toggleLogType(LogType type, bool enabled) {
    logTypeEnabled.at(type) = enabled;
}

void Log::addMessage(LogType type, const std::string &message) {
    if (logTypeEnabled.at(type)) {
        logfile << "[" << logTypeToString(type) << "] " << message << std::endl;
        ++linesOutput;
    }
}

size_t Log::getLinesOutput() const { return linesOutput; }
