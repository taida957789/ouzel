// Copyright (C) 2016 Elviss Strazdins
// This file is part of the Ouzel engine.

#include "MeshBufferMetal.h"
#include "core/Engine.h"
#include "RendererMetal.h"
#include "IndexBufferMetal.h"
#include "VertexBufferMetal.h"
#include "utils/Utils.h"

namespace ouzel
{
    namespace graphics
    {
        MeshBufferMetal::MeshBufferMetal()
        {
        }

        MeshBufferMetal::~MeshBufferMetal()
        {
        }

        bool MeshBufferMetal::upload()
        {
            if (!MeshBuffer::upload())
            {
                return false;
            }

            return true;
        }
    } // namespace graphics
} // namespace ouzel
