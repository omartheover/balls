#include <raylib.h>
#include <iostream>

int main(){


    int gambled_money = 0;
    int output = 0;

    InitWindow(900, 900, "mine");
    InitAudioDevice();
    SetTargetFPS(60);
    Texture2D back = LoadTexture("C:\\Users\\PCM\\Pictures\\bg\\hi3.jpg");
    Sound money = LoadSound("C:\\Users\\PCM\\Pictures\\bg\\mysound.wav");
    Texture2D crusor = LoadTexture("C:\\Users\\PCM\\Pictures\\Camera Roll\\crusor.png");
    Texture2D button = LoadTexture("C:\\Users\\PCM\\Pictures\\Camera Roll\\gamble.png");
    Vector2 crusorpos = {100.0f, 100.0f};
    int weight = 50;
    int hight = 50;
    Rectangle sourceRec = { 0.0f, 0.0f, (float)weight, (float)weight };
    Rectangle destRec = { crusorpos.x, crusorpos.y, weight*1.0f, hight*1.0f };
    Vector2 origin = { (float)weight, (float)hight };
    int rotation = 0;

    int button_x = 310;
    int button_y = 450;
    int button_height = 169;
    int button_width = 300;
    Rectangle btnbounds = { (float)button_x, (float)button_y, (float)button_width, (float)button_height };

    Vector2 mouse_place = {0.0f, 0.0f};

    while(!WindowShouldClose()){
        HideCursor();
        crusorpos = GetMousePosition();
        destRec = { crusorpos.x, crusorpos.y, weight*1.0f, hight*1.0f };
        mouse_place = GetMousePosition();

        BeginDrawing();
        ClearBackground(WHITE);
        DrawTexture(back, 0, 0, WHITE);
        DrawTexture(button, 310,450,WHITE);
        if(CheckCollisionPointRec(mouse_place, btnbounds)){
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                PlaySound(money);
                 gambled_money = (rand() % 300000) + 1;
                 output = (rand() % 400000);
                
            }
        }

        DrawText(TextFormat("you have gambled: %d    you got: %d", gambled_money, output), 100, 300, 30, GREEN);
        DrawText(TextFormat("Aint no way this C++ task took me 3 hours bruh"), 100, 200, 30, RED);
        DrawTexturePro(crusor, sourceRec, destRec, origin, (float)rotation, WHITE);

        EndDrawing();
    }

    UnloadSound(money);
    UnloadTexture(back);
    UnloadTexture(crusor);
    UnloadTexture(button);
    CloseAudioDevice();
    CloseWindow();
}
