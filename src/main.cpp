#include <raylib.h>
#include "assetManager.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "Gra");
    SetTargetFPS(60);

    Vector2 playerPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    Texture2D background = assetManager::getAssetTexture2D(1);
    Texture2D player = assetManager::getAssetTexture2D(2);
    Texture2D player2 = assetManager::getAssetTexture2D(2);
    Image icon = assetManager::getAssetImage(1);
    SetWindowIcon(icon);

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_D)) playerPosition.x += 2.0f;
        if (IsKeyDown(KEY_A)) playerPosition.x -= 2.0f;
        if (IsKeyDown(KEY_W)) playerPosition.y -= 2.0f;
        if (IsKeyDown(KEY_S)) playerPosition.y += 2.0f;

        BeginDrawing();
        ClearBackground(PINK);
        DrawTexture(background, 0, 0, WHITE);
        DrawTexture(player, playerPosition.x, playerPosition.y, WHITE);
        DrawTexture(player2, 20, 30, WHITE);
        EndDrawing();
    }
    assetManager::unload();
    CloseWindow();
    return 0;
}