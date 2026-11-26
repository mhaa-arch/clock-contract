#include <clock/clock_source.hpp>
#include <clock/clock_control.hpp>

#include <cassert>

using namespace mhaa::clock;

class Fake final : public ClockControl
{
public:
    bool frequency_hz(ClockDomain domain, uint32_t &rate) const override
    {
        if ((domain.kind != Domain::Peripheral || domain.id != DomainId{}))
        {
            return false;
        }
        rate = frequency_;
        return true;
    }

    bool set_frequency_hz(ClockDomain domain, uint32_t rate) override
    {
        if ((domain.kind != Domain::Peripheral || domain.id != DomainId{}) || rate != 1000000)
        {
            return false;
        }
        frequency_ = rate;
        return true;
    }

private:
    uint32_t frequency_ = 32768;
};

int main()
{
    Fake fake;
    ClockSource &source = fake;
    ClockControl &control = fake;
    uint32_t frequency = 7;
    assert(!source.frequency_hz(Domain::Cpu, frequency) && frequency == 7);
    assert(source.frequency_hz(Domain::Peripheral, frequency) && frequency == 32768);
    assert(!control.set_frequency_hz(Domain::Peripheral, 17));
    assert(control.set_frequency_hz(Domain::Peripheral, 1000000));
    assert(source.frequency_hz(Domain::Peripheral, frequency) && frequency == 1000000);
}
