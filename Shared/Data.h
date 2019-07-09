#include <stdint.h>

constexpr uint32_t LOOP_TIME_MS = 10;
constexpr uint32_t UPDATE_TIME_MS = 100;

struct SharedData_t
{
    double angle;
    struct
    {
        double p;
        double i;
        double d;
    } output;
    uint32_t idleLoopTimer;
    uint32_t controlLoopTimer;
    uint32_t presence;
};
