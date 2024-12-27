#ifndef LOG_HPP
#define LOG_HPP

#include <fstream>
#include <memory>
#include <unordered_map>

class Log {
  public:
    enum class LogType {
        BallPos,
        Bidirectional,
        BounceType,
        BrickDestroyed,
        ChangeBetweenLastUpdate,
        ClosestPoint,
        CollidingObject,
        CollisionButSameDirection,
        DirVec,
        Error,
        PenetrationRate,
        Unidirectional,
    };

  private:
    static std::unique_ptr<Log> singleton;

    size_t linesOutput = 0;
    std::ofstream logfile;

    // Map to toggle log types
    std::unordered_map<LogType, bool> logTypeEnabled;

    Log();

    /**
     * @brief Convert LogType to string for output
     */
    std::string logTypeToString(LogType type) const;

  public:
    Log(Log &&) = delete;
    Log &operator=(Log &&) = delete;
    Log(const Log &) = delete;
    Log &operator=(const Log &) = delete;

    /**
     * @brief Get the Log Singleton.
     */
    static Log &get();

    /**
     * @brief Enable/Disable the given log Type.
     *
     * @param type The LogType to enable/disable.
     * @param enable True to enable, false to disable.
     */
    void toggleLogType(LogType type, bool enabled);

    /**
     * @brief Add a new message to the logs in the given log type.
     *
     * @param type The log type.
     * @param message The message.
     */
    void addMessage(LogType type, const std::string &message);

    /**
     * @brief Returns the number of lines that have been output.
     */
    size_t getLinesOutput() const;
};

#endif
