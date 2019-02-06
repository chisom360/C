#include <iostream>
#include <thread>
#include <chrono>

class Timer
{

    //Note: 1 second = 1000 Millisecond
    //flag to check if Timer is active
    bool active = false;

  public:
    void setTimeout(auto function, int delay);
    void setInterval(auto function, int interval);
    void stop();
};

void Timer::setTimeout(auto function, int delay)
{
    this->active = false;
    //instantiate a thread object, by using its constructor that accepts a function
    std::thread t([=]() {
        if (this->active)
            return;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        if (this->active)
            return;
        function();
    });
    t.detach();
}
//setInterval allows to run the code of the same function repeatedly, at a given interval.
void Timer::setInterval(auto function, int interval)
{
    this->active = false;
    std::thread t([=]() {
        while (true)
        {
            if (this->active)
                return;
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));
            if (this->active)
                return;
            function();
        }
    });
    t.detach();
}

void Timer::stop()
{
    this->active = true;
}