# Clock Contract example

[The conformance program](../tests/conformance.cpp) pairs a simulated implementation with assertions at the Contract boundary. The fake overrides query and set for the default peripheral domain. The program uses `ClockSource&` for reads and `ClockControl&` for a change on the same object. A rejected CPU query preserves the initial output, a 17 Hz request is declined, and an accepted 1 MHz request is visible through the source view.

## Implementation excerpt

This class is taken from the program. The linked source contains the test cases and any additional fixtures.

```cpp
#include <clock/clock_source.hpp>
#include <clock/clock_control.hpp>


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
```

## Build and run

From this repository root, with assertions enabled, compile the full program. A passing run exits with status 0 and prints no output. Use `conformance.exe` on Windows.

```sh
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude tests/conformance.cpp -o conformance
./conformance
```

To verify enforcement of the abstract interface, compile the two negative sources separately. The first should diagnose an abstract type and the second an incompatible override.

```sh
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -fsyntax-only tests/missing_override.cpp
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -fsyntax-only tests/wrong_override.cpp
```
