// Copyright 2015-2018 Elviss Strazdins. All rights reserved.

#pragma once

#include "input/InputDevice.hpp"

namespace ouzel
{
    namespace input
    {
        class InputSystemAndroid;

        class KeyboardAndroid: public InputDevice
        {
        public:
            KeyboardAndroid(InputSystemAndroid& initInputSystemAndroid,
                            uint32_t initDeviceId):
                InputDevice(initDeviceId),
                inputSystemAndroid(initInputSystemAndroid)
            {
            }

            virtual ~KeyboardAndroid() {}

        private:
            InputSystemAndroid& inputSystemAndroid;
        };
    } // namespace input
} // namespace ouzel
