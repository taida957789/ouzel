// Copyright (C) 2016 Elviss Strazdins
// This file is part of the Ouzel engine.

#pragma once

#include <memory>
#include <mutex>
#include "utils/Types.h"
#include "utils/Noncopyable.h"
#include "graphics/Resource.h"
#include "math/Color.h"
#include "math/Size2.h"
#include "math/Matrix4.h"

namespace ouzel
{
    namespace graphics
    {
        class Renderer;
        class Texture;

        class RenderTarget: public Resource, public Noncopyable
        {
            friend Renderer;
        public:
            virtual ~RenderTarget();
            virtual void free() override;

            virtual bool init(const Size2& newSize, bool useDepthBuffer);

            virtual void setClearColorBuffer(bool clear);
            virtual bool getClearColorBuffer() const { return clearColorBuffer; }

            virtual void setClearDepthBuffer(bool clear);
            virtual bool getClearDepthBuffer() const { return clearDepthBuffer; }

            virtual void setClearColor(Color color);
            virtual Color getClearColor() const { return clearColor; }

            void setFrameBufferClearedFrame(uint32_t clearedFrame) { frameBufferClearedFrame = clearedFrame; }
            uint32_t getFrameBufferClearedFrame() const { return frameBufferClearedFrame; }

            TexturePtr getTexture() const { return texture; }

        protected:
            RenderTarget();
            virtual void update() override;
            virtual bool upload() override;

            struct Data
            {
                Size2 size;
                Color clearColor;
                bool depthBuffer = false;
                bool clearColorBuffer = true;
                bool clearDepthBuffer = false;
            };

            Data uploadData;
            std::mutex uploadMutex;

            TexturePtr texture;

        private:
            Size2 size;
            Color clearColor;
            uint32_t frameBufferClearedFrame = 0;

            bool clearColorBuffer = true;
            bool clearDepthBuffer = false;
            bool depthBuffer = false;

            Data currentData;
        };
    } // namespace graphics
} // namespace ouzel
