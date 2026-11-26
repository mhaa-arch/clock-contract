#ifndef MHAA_CLOCK_CLOCK_CONTROL_HPP
#define MHAA_CLOCK_CLOCK_CONTROL_HPP

#include <stdint.h>
#include <clock/clock_source.hpp>
#include <clock/types.hpp>

namespace mhaa
{
    namespace clock
    {
        /** @brief Requests rates on domains with independently exposed clock control. */
        class ClockControl : public ClockSource
        {
        public:
            /** @brief Requests a nonzero nominal rate. False means the request was rejected. */
            virtual bool set_frequency_hz(ClockDomain domain, uint32_t frequency_hz) = 0;
        };
    }
}

#endif
