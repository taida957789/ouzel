// Copyright 2015-2019 Elviss Strazdins. All rights reserved.

#ifndef RTSAMPLE_HPP
#define RTSAMPLE_HPP

#include "ouzel.hpp"

class RTSample: public ouzel::scene::Scene
{
public:
    RTSample();

private:
    ouzel::scene::Layer layer;
    ouzel::scene::Camera camera;
    ouzel::scene::Actor cameraActor;

    ouzel::scene::Layer rtLayer;

    ouzel::scene::Camera rtCamera;
    ouzel::scene::Actor rtCameraActor;
    ouzel::scene::Camera camera1;
    ouzel::scene::Actor camera1Actor;
    ouzel::scene::Camera camera2;
    ouzel::scene::Actor camera2Actor;

    ouzel::scene::SpriteRenderer characterSprite;
    ouzel::scene::Actor rtCharacter;

    ouzel::scene::SpriteRenderer rtSprite;
    ouzel::scene::Actor rtActor;

    ouzel::EventHandler handler;

    ouzel::scene::Layer guiLayer;
    ouzel::scene::Camera guiCamera;
    ouzel::scene::Actor guiCameraActor;
    ouzel::gui::Menu menu;
    ouzel::gui::Button backButton;
};

#endif // RTSAMPLE_HPP
