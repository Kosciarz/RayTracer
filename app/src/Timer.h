#pragma once

#include <iostream>
#include <chrono>
#include <string>

class Timer
{
public:
    using Clock = std::chrono::high_resolution_clock;

public:
    Timer()
    {
        Reset();
    }

    void Reset()
    {
        m_Start = Clock::now();
    }

    double ElapsedSeconds() const
    {
        return std::chrono::duration_cast<std::chrono::seconds>(ElapsedTime()).count();
    }

    long long ElapsedMilliseconds() const
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(ElapsedTime()).count();
    }

    long long ElapsedMicroseconds() const
    {
        return std::chrono::duration_cast<std::chrono::microseconds>(ElapsedTime()).count();
    }

    long long ElapsedNanoseconds() const
    {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(ElapsedTime()).count();
    }

private:
    Clock::duration ElapsedTime() const
    {
        return Clock::now() - m_Start;
    }

private:
    Clock::time_point m_Start;
};


class ScopedTimer
{
public:
    ScopedTimer(const std::string& name)
        : m_Name{name}
    {
    }

    ~ScopedTimer()
    {
        auto time = m_Timer.ElapsedMilliseconds();
        std::cout << "[TIMER] " << m_Name << ": " << time << "ms" << '\n';
    }

private:
    Timer m_Timer;
    std::string m_Name;
};