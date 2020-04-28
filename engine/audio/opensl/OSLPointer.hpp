// Copyright 2015-2020 Elviss Strazdins. All rights reserved.

#ifndef OUZEL_AUDIO_OSLPOINTER_HPP
#define OUZEL_AUDIO_OSLPOINTER_HPP

#include "../../core/Setup.h"

#if OUZEL_COMPILE_OPENSL

#include <SLES/OpenSLES.h>

namespace ouzel
{
    namespace audio
    {
        namespace opensl
        {
            template <class T>
            class Pointer final
            {
            public:
                Pointer() noexcept = default;

                Pointer(T a) noexcept : p(a) {}
                Pointer& operator=(T a) noexcept
                {
                    if (p) (*p)->Destroy(p);
                    p = a;
                    return *this;
                }

                Pointer(const Pointer& other) = delete;
                Pointer& operator=(const Pointer& other) = delete;

                Pointer(Pointer&& other) noexcept : p(other.p)
                {
                    other.p = nullptr;
                }

                Pointer& operator=(Pointer&& other) noexcept
                {
                    if (this == &other) return *this;
                    if (p) (*p)->Destroy(p);
                    p = other.p;
                    other.p = nullptr;
                    return *this;
                }

                ~Pointer()
                {
                    if (p) (*p)->Destroy(p);
                }

                T operator->() const noexcept
                {
                    return *p;
                }

                T get() const noexcept
                {
                    return p;
                }

                explicit operator bool() const noexcept
                {
                    return p != nullptr;
                }

            private:
                T p = nullptr;
            };
        } // namespace opensl
    } // namespace audio
} // namespace ouzel

#endif

#endif // OUZEL_AUDIO_OSLPOINTER_HPP
