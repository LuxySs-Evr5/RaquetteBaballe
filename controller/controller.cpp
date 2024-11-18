#include "controller.hpp"

#include <chrono>
#include <iostream>
#include <thread>

constexpr unsigned SLEEP_TIME = 1;

void Controller::run() {
    using clock = std::chrono::high_resolution_clock;
    using time_point = std::chrono::time_point<clock>;
    using duration = std::chrono::duration<double>;

    time_point t_last_update = clock::now();

    for (int i = 0; i < 10; i++) {
        time_point t_now = clock::now();

        duration delta_time = t_now - t_last_update;

        t_last_update = t_now;

        model_.update(delta_time.count());
        std::cout << "delta time= " << delta_time.count() << std::endl;

        std::this_thread::sleep_for(std::chrono::duration<float>(SLEEP_TIME));
    }
}
