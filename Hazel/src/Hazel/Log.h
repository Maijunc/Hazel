#ifndef SANDBOX_LOG_H
#define SANDBOX_LOG_H

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Hazel {
    class Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;}
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger;}
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core log macros
#define HZ_CORE_TRACE(...)    ::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)     ::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)     ::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)    ::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...)    ::Hazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// params:
// 括号里是...的，被称为可变参数宏，也称为变参宏，允许在宏中使用不定数量的参数
// VA_ARGS 是预处理器宏的一个特殊标识符，它表示可变参数列表。

// Client log marcos
#define HZ_TRACE(...)	 ::Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)     ::Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)     ::Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...)    ::Hazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_FATAL(...)    ::Hazel::Log::GetClientLogger()->fatal(__VA_ARGS__)

#endif //SANDBOX_LOG_H
