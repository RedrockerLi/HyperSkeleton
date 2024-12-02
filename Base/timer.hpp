#ifndef __TIMER_HPP
#define __TIMER_HPP

#include <chrono>
#include <iostream>
#include <string>
#include "dataStructure.hpp"

class Timer {
public:
    Timer(std::string input) : elapsed_time(0), running(false),taskName(input) {}

    void start() {
        if (running) {
            std::cerr << "Timer is already running!" << std::endl;
            return;
        }
        running = true;
        start_time = std::chrono::high_resolution_clock::now();
    }

    void stop() {
        if (!running) {
            std::cerr << "Timer is not running!" << std::endl;
            return;
        }
        auto stop_time = std::chrono::high_resolution_clock::now();
        elapsed_time += std::chrono::duration_cast<std::chrono::microseconds>(stop_time - start_time).count();
        running = false;
    }

    void reset() {
        elapsed_time = 0;
        running = false;
    }

    void print() const {
        std::cout <<taskName << " time: " <<elapsed_time/1000<<"ms"<< elapsed_time%1000<< std::endl;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
    int64_t elapsed_time; // 以微秒为单位记录时间
    bool running;        
    std::string taskName;
};

#endif