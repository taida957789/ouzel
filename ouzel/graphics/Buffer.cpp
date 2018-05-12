// Copyright (C) 2018 Elviss Strazdins
// This file is part of the Ouzel engine.

#include "Buffer.hpp"
#include "BufferResource.hpp"
#include "Renderer.hpp"
#include "RenderDevice.hpp"
#include "core/Engine.hpp"

namespace ouzel
{
    namespace graphics
    {
        Buffer::Buffer()
        {
            resource = engine->getRenderer()->getDevice()->createBuffer();
        }

        Buffer::~Buffer()
        {
            if (engine && resource) engine->getRenderer()->getDevice()->deleteResource(resource);
        }

        bool Buffer::init(Usage newUsage, uint32_t newFlags, uint32_t newSize)
        {
            usage = newUsage;
            flags = newFlags;
            size = newSize;

            engine->getRenderer()->executeOnRenderThread(std::bind(static_cast<bool(BufferResource::*)(Usage, uint32_t, const std::vector<uint8_t>&, uint32_t)>(&BufferResource::init),
                                                                   resource,
                                                                   newUsage,
                                                                   newFlags,
                                                                   std::vector<uint8_t>(),
                                                                   newSize));

            return true;
        }

        bool Buffer::init(Usage newUsage, uint32_t newFlags, const void* newData, uint32_t newSize)
        {
            return init(newUsage,
                        newFlags,
                        std::vector<uint8_t>(static_cast<const uint8_t*>(newData),
                                             static_cast<const uint8_t*>(newData) + newSize),
                        newSize);
        }

        bool Buffer::init(Usage newUsage, uint32_t newFlags, const std::vector<uint8_t>& newData, uint32_t newSize)
        {
            if (!newData.empty() && newSize != newData.size())
                return false;

            usage = newUsage;
            flags = newFlags;
            size = newSize;

            engine->getRenderer()->executeOnRenderThread(std::bind(static_cast<bool(BufferResource::*)(Buffer::Usage, uint32_t, const std::vector<uint8_t>&, uint32_t)>(&BufferResource::init),
                                                                   resource,
                                                                   newUsage,
                                                                   newFlags,
                                                                   newData,
                                                                   newSize));

            return true;
        }

        bool Buffer::setData(const void* newData, uint32_t newSize)
        {
            return setData(std::vector<uint8_t>(static_cast<const uint8_t*>(newData),
                                                static_cast<const uint8_t*>(newData) + newSize));
        }

        bool Buffer::setData(const std::vector<uint8_t>& newData)
        {
            if (!(flags & Buffer::DYNAMIC))
                return false;

            if (newData.empty()) return false;
            
            if (newData.size() > size) size = static_cast<uint32_t>(newData.size());

            engine->getRenderer()->executeOnRenderThread(std::bind(&BufferResource::setData,
                                                                   resource,
                                                                   newData));

            return true;
        }
    } // namespace graphics
} // namespace ouzel
