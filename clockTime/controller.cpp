#include "controller.hpp"

#include <chrono>
#include <iostream>
#include <thread>

constexpr std::chrono::duration<double> SLEEP_TIME(1.0f);

void Controller::run() {
    using clock = std::chrono::high_resolution_clock;
    using time_point = std::chrono::time_point<clock>;
    using duration = std::chrono::duration<double>;

    time_point t_last_update =
        clock::now() - std::chrono::duration_cast<clock::duration>(SLEEP_TIME);

    while (true) {
        time_point t_now = clock::now();

        duration delta_time = t_now - t_last_update;

        t_last_update = t_now;

        model_.update(delta_time.count());

        std::this_thread::sleep_for(std::chrono::duration<double>(SLEEP_TIME));
    }
}
