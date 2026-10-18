#include <raylib.h>
#include "assetManager.h"

int main()
{
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "Gra");
    SetTargetFPS(60);

    Vector2 playerPosition = { static_cast<float>(screenWidth)/2, static_cast<float>(screenHeight)/2 };
    Vector2 ballPos = {20, 30};

    Texture2D background = assetManager::getAssetTexture2D(1);
    Texture2D player = assetManager::getAssetTexture2D(2);
    Texture2D ball = assetManager::getAssetTexture2D(3);
    Texture2D floor = assetManager::getAssetTexture2D(4);
    Image icon = assetManager::getAssetImage(1);

    Rectangle floorRect = { 0.0f, 380.0f, static_cast<float>(floor.width), static_cast<float>(floor.height) };

    SetWindowIcon(icon);

    while (!WindowShouldClose()) {
        Rectangle ballRect = { 0.0f, ballPos.y, static_cast<float>(ball.width), static_cast<float>(ball.height) };

        if (!CheckCollisionRecs(ballRect, floorRect)) {
            ballPos.y += 100.0f * GetFrameTime();
        }

        if (IsKeyDown(KEY_D)) playerPosition.x += 2.0f;
        if (IsKeyDown(KEY_A)) playerPosition.x -= 2.0f;
        if (IsKeyDown(KEY_W)) playerPosition.y -= 2.0f;
        if (IsKeyDown(KEY_S)) playerPosition.y += 2.0f;

        BeginDrawing();
        ClearBackground(PINK);
        DrawTexture(background, 0, 0, WHITE);
        DrawTexture(floor, 0, 380, WHITE);
        DrawTexture(player, playerPosition.x, playerPosition.y, WHITE);
        DrawTexture(ball, ballPos.x, ballPos.y, WHITE);
        EndDrawing();
    }
    assetManager::unload();
    CloseWindow();
    return 0;
}