#ifndef __FPS__
#define __FPS__

#include <SFML/System.hpp>
#include <cstdint>

class Fps
{
public:
    Fps() : _frame(0),
            _fps(0) {}

    const uint64_t get_fps(void) const
    {
        return _fps;
    }

    void update(void)
    {
        if (_clock.getElapsedTime().asSeconds() >= 1.f)
        {
            _fps = _frame;
            _frame = 0;
            _clock.restart();
        }

        ++_frame;
    }

private:
    uint64_t _frame;
    uint64_t _fps;
    sf::Clock _clock;
};

#endif