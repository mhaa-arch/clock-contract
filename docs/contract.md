# Clock contract

## Identify and read a domain

[ClockSource](../include/clock/clock_source.hpp) queries a `ClockDomain`. A domain combines a category and a `DomainId` from the composition's logical map. Passing a category by itself selects its default instance, ID zero. A successful query stores nominal hertz, including zero when the clock is stopped. A failed query preserves the output.

## Offer rate control selectively

[ClockControl](../include/clock/clock_control.hpp) extends the readable source so both calls address the same resource. It accepts supported, exact positive nominal rates. A rejected request retains the previous configuration. Describe transition requirements and any effect on derived rates in the Adapter documentation.

## Implementation boundary

The Adapter owns resource state. The caller must keep the implementation alive during each call and arrange access from other execution contexts. Document the contexts and concurrency guarantees of the actual implementation. Shared public types are in [`clock/types.hpp`](../include/clock/types.hpp).
