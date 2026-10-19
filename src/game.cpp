#include "game.h"

void game::run() {
    InitWindow(screenWidth, screenHeight, "Game");
    SetTargetFPS(60);
    SetWindowIcon(icon);

    while (!WindowShouldClose()) {
        if (!CheckCollisionRecs(ballRect, floorRect)) {
            ballPos.y += 250.0f * GetFrameTime();
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
}
