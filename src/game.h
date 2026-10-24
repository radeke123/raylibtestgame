#pragma once
#include <raylib.h>
#include "assetManager.h"

class game {
    public:
        virtual void run();
        virtual ~game() = default;

    private:
        static constexpr int screenWidth = 800;
        static constexpr int screenHeight = 400;

        Vector2 playerPos = { static_cast<float>(screenWidth)/2, static_cast<float>(screenHeight)/2 };
        Vector2 ballPos = {20, 30};

        //images
        Image icon = assetManager::getAssetImage(1);

        Camera2D camera = Camera2D();
 };
