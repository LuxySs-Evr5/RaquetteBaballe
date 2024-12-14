#ifndef LOG_HPP
#define LOG_HPP

#include <fstream>
#include <memory>
#include <unordered_map>

class Log {
  public:
    enum class LogType {
        BallPos,
        BounceType,
        BrickDestroyed,
        ClosestPoint,
        CollidingObject,
        Unidirectional,
        Bidirectional,
        PenetrationRate,
        CollisionButSameDirection,
        Error
    };

  private:
    static std::unique_ptr<Log> singleton;

    size_t linesOutput = 0;
    std::ofstream logfile;

    // Map to toggle log types
    std::unordered_map<LogType, bool> logTypeEnabled;

    Log();

    // Convert LogType to string for output
    std::string logTypeToString(LogType type) const;

  public:
    Log(const Log &) = delete;
    Log &operator=(const Log &) = delete;

    static Log &get();

    void toggleLogType(LogType type, bool enabled);

    void addMessage(LogType type, const std::string &message);

    size_t getLinesOutput() const;
};

#endif
