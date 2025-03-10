#pragma once

#include <string>
#include <chrono>
#include <iostream>

#define PROFILE_CONCAT_INTERNAL(X, Y) X ## Y
#define PROFILE_CONCAT(X, Y) PROFILE_CONCAT_INTERNAL(X, Y)
#define UNIQUE_VAR_NAME_PROFILE PROFILE_CONCAT(profileGuard, __LINE__)
#define LOG_DURATION(x) LogDuration UNIQUE_VAR_NAME_PROFILE(x)

class LogDuration {
public:
    using CLock = std::chrono::steady_clock;

    LogDuration(const std::string &id) : id_(id) {}

    ~LogDuration() {
        using namespace std::chrono;
        using namespace std::literals;

        const auto end_time = CLock::now();
        const auto dur = end_time - start_time_;
        std::cerr << id_ << ": " << duration_cast<std::chrono::milliseconds>(dur).count() << " ms"s << std::endl;
    }

private:
    std::string id_;
    const CLock::time_point start_time_ = CLock::now();
};
