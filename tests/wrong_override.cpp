#include <clock/clock_source.hpp>

using namespace mhaa::clock;

class WrongOverride final : public ClockSource
{
public:
    bool frequency_hz(ClockDomain domain, uint32_t &frequency_hz) override;
};
