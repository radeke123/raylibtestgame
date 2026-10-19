#pragma once
#include <raylib.h>
#include "assetManager.h"

class game {
    public:
        void run();

    private:
        static constexpr int screenWidth = 800;
        static constexpr int screenHeight = 400;

        Vector2 playerPosition = { static_cast<float>(screenWidth)/2, static_cast<float>(screenHeight)/2 };
        Vector2 ballPos = {20, 30};

        //textures
        Texture2D background = assetManager::getAssetTexture2D(1);
        Texture2D player = assetManager::getAssetTexture2D(2);
        Texture2D ball = assetManager::getAssetTexture2D(3);
        Texture2D floor = assetManager::getAssetTexture2D(4);

        //images
        Image icon = assetManager::getAssetImage(1);

        //rectangles
        Rectangle floorRect = { 0.0f, 380.0f, static_cast<float>(floor.width), static_cast<float>(floor.height) };
        Rectangle ballRect = { ballPos.x, ballPos.y, static_cast<float>(ball.width), static_cast<float>(ball.height) };
 };
