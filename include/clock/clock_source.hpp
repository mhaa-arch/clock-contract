#ifndef MHAA_CLOCK_CLOCK_SOURCE_HPP
#define MHAA_CLOCK_CLOCK_SOURCE_HPP

#include <stdint.h>
#include <clock/types.hpp>

namespace mhaa
{
    namespace clock
    {
        /** @brief Queries the current nominal frequency of a logical clock domain. */
        class ClockSource
        {
        public:
            virtual ~ClockSource() = default;

            /** @brief Reads hertz, including zero for a supported stopped clock. */
            virtual bool frequency_hz(ClockDomain domain, uint32_t &frequency_hz) const = 0;
        };
    }
}

#endif
