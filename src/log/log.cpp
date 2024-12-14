#include "log.hpp"

#include <iostream>

std::unique_ptr<Log> Log::singleton;

Log::Log() : logfile("log.txt") {
    if (!logfile.is_open()) {
        std::cerr << "Error opening log file!" << std::endl;
    }
    logTypeEnabled[LogType::BallPos] = true;
    logTypeEnabled[LogType::BounceType] = true;
    logTypeEnabled[LogType::BrickDestroyed] = true;
    logTypeEnabled[LogType::ClosestPoint] = true;
    logTypeEnabled[LogType::CollidingObject] = true;
    logTypeEnabled[LogType::Unidirectional] = true;
    logTypeEnabled[LogType::Bidirectional] = true;
    logTypeEnabled[LogType::PenetrationRate] = true;
    logTypeEnabled[LogType::CollisionButSameDirection] = true;
    logTypeEnabled[LogType::Error] = true;
}

std::string Log::logTypeToString(LogType type) const {
    switch (type) {
    case LogType::BallPos:
        return "BallPos: ";
    case LogType::BounceType:
        return "BounceType: ";
    case LogType::BrickDestroyed:
        return "BrickDestroyed: ";
    case LogType::ClosestPoint:
        return "ClosestPoint: ";
    case LogType::CollidingObject:
        return "CollidingObject: ";
    case LogType::Unidirectional:
        return "Unidirectional: ";
    case LogType::Bidirectional:
        return "Bidirectional: ";
    case LogType::PenetrationRate:
        return "PenetrationRate: ";
    case LogType::CollisionButSameDirection:
        return "CollisionButSameDirection: ";
    case LogType::Error:
        return " Error: ";
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
    logTypeEnabled[type] = enabled;
}

void Log::addMessage(LogType type, const std::string &message) {
    if (logTypeEnabled[type]) {
        logfile << "[" << logTypeToString(type) << "] " << message << std::endl;
        ++linesOutput;
    }
}

size_t Log::getLinesOutput() const { return linesOutput; }
