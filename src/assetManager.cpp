#include "assetManager.h"
#include <iostream>

Texture2D assetManager::getAssetTexture2D(int id) {
    Texture2D asset = Texture2D();
    switch (id) {
        default: {
            std::cerr << "assetManager::getAssetTexture2D - unknown id: " << id << std::endl;
            break;
        }
        case 1: {
            if (!Texture2DMap.contains(id)) {
                asset = LoadTexture("./assets/background.png");
                Texture2DMap[id] = asset;
            }else {
                return Texture2DMap[id];
            }
            break;
        }
        case 2: {
            if (!Texture2DMap.contains(id)) {
                asset = LoadTexture("./assets/player.png");
                Texture2DMap[id] = asset;
            }else {
                return Texture2DMap[id];
            }
            break;
        }
        case 3: {
            if (!Texture2DMap.contains(id)) {
                asset = LoadTexture("./assets/ball.png");
                Texture2DMap[id] = asset;
            }else {
                return Texture2DMap[id];
            }
            break;
        }
        case 4: {
            if (!Texture2DMap.contains(id)) {
                asset = LoadTexture("./assets/floor.png");
                Texture2DMap[id] = asset;
            }else {
                return Texture2DMap[id];
            }
            break;
        }
    }
    return asset;
}

Image assetManager::getAssetImage(int id) {
    Image asset = Image();
    switch (id) {
        default: {
            std::cerr << "assetManager::getAssetImage - unknown id: " << id << std::endl;
            break;
        }
        case 1: {
            if (!ImageMap.contains(id)) {
                asset = LoadImage("./assets/icon.png");
                ImageMap[id] = asset;
            }else {
                return ImageMap[id];
            }
            break;
        }
    }
    return asset;
}

void assetManager::unload() {
    for (auto& pair : Texture2DMap) {
        UnloadTexture(pair.second);
    }
    Texture2DMap.clear();

    for (auto& pair : ImageMap) {
        UnloadImage(pair.second);
    }
    ImageMap.clear();
}

assetManager::~assetManager() = default;
