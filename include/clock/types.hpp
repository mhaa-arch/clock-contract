#ifndef MHAA_CLOCK_TYPES_HPP
#define MHAA_CLOCK_TYPES_HPP

#include <stdint.h>

namespace mhaa
{
    namespace clock
    {
        enum class Domain
        {
            Cpu,
            Peripheral,
            LowSpeed
        };

        enum class DomainId : uint16_t
        {
        };

        struct ClockDomain
        {
            constexpr ClockDomain(Domain kind, DomainId id = DomainId{}) : kind(kind), id(id) {}

            Domain kind;
            DomainId id;
        };
    }
}

#endif
