#pragma once
#include <unordered_map>

#include "raylib.h"

class assetManager {
    public:
        static Texture2D getAssetTexture2D(int id);
        static Image getAssetImage(int id);
        static void unload();
        virtual ~assetManager();
    private:
        static inline std::unordered_map<int, Texture2D> Texture2DMap;
        static inline std::unordered_map<int, Image> ImageMap;
};
