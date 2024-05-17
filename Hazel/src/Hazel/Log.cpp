#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Hazel {
    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    void Log::Init()
    {
        ////设置记录消息的样式	颜色 时间 Logger名 实际的消息
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_CoreLogger = spdlog::stdout_color_mt("Hazel");
        // I guess trace is highest level
        s_CoreLogger->set_level(spdlog::level::trace);
        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace);
    }
}