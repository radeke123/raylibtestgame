#include "game.h"
#include <raymath.h>
#include <string>

void game::run() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(screenWidth, screenHeight, "Game");
    SetTargetFPS(240);
    SetWindowIcon(icon);

    Texture2D background = assetManager::getAssetTexture2D(1);
    const Texture2D player = assetManager::getAssetTexture2D(2);
    const Texture2D ball = assetManager::getAssetTexture2D(3);
    Texture2D floor = assetManager::getAssetTexture2D(4);

    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    while (!WindowShouldClose()) {
        background.height = GetScreenHeight();
        background.width = GetScreenWidth();

        floor.width = GetScreenWidth();

        Rectangle floorRect = { -800.0f, 380.0f, static_cast<float>(floor.width) + 800 * 2, static_cast<float>(floor.height) };
        Rectangle ballRect = { ballPos.x, ballPos.y, static_cast<float>(ball.width), static_cast<float>(ball.height) };
        Rectangle playerRect = { playerPos.x, playerPos.y, static_cast<float>(player.width), static_cast<float>(player.height) };

        if (IsKeyPressed(KEY_F11)) {
            ToggleFullscreen();
        }
        if (IsWindowResized()) {
            playerPos.x = 0;
            playerPos.y = 0;
            ballPos.x = 0;
            ballPos.y = 0;
        }
        floorRect.y = static_cast<float>(GetScreenHeight()) - 20;

        //collisions
        if (!CheckCollisionRecs(ballRect, floorRect)) {
            ballPos.y += 250.0f * GetFrameTime();
        }
        if (!CheckCollisionRecs(playerRect, floorRect)) {
            playerPos.y += 250.0f * GetFrameTime();
        }

        if (IsKeyDown(KEY_D)) playerPos.x += 1;
        if (IsKeyDown(KEY_A)) playerPos.x -= 1;
        if (CheckCollisionRecs(playerRect, floorRect)) {
            if (IsKeyDown(KEY_SPACE)) playerPos.y -= 100;
        }

        playerPos.x = Clamp(playerPos.x, -20, static_cast<float>(GetScreenWidth()) - player.width + 25);

        BeginDrawing();
        ClearBackground(PINK);
        BeginMode2D(camera);

        camera.target = {0, 0};
        camera.offset = {0, 0};

        DrawTexture(background, 0 - camera.offset.x, 0, WHITE);
        DrawTexture(floor, 0, GetScreenHeight() - 20, WHITE);
        DrawTexture(player, static_cast<int>(playerPos.x), static_cast<int>(playerPos.y), WHITE);
        DrawTexture(ball, static_cast<int>(ballPos.x), static_cast<int>(ballPos.y), WHITE);

        DrawText(("FPS: " + std::to_string(GetFPS())).c_str(), 0, 0, 20, BLACK);

        EndMode2D();
        EndDrawing();
    }
    assetManager::unload();
    CloseWindow();
}
