#include <clock/clock_source.hpp>

using namespace mhaa::clock;

class Incomplete final : public ClockSource
{
public:
};

int main()
{
    Incomplete implementation;
    (void)implementation;
}
