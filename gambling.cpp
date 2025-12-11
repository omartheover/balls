#include <raylib.h>
#include <iostream>

int gambled_money = 0;
int output = 0;
int inventory = 250000;
bool rolling = false;
auto rolling_frames = 0;
auto rolling_value = 0;


int main(){


    InitWindow(900, 900, "Lucky Gamble");
    InitAudioDevice();
    SetTargetFPS(60);
    Image imag = LoadImage("C:\\Users\\PCM\\Pictures\\bg\\backe.jpg");
    ImageResize(&imag, 900, 900);
    Texture2D back = LoadTextureFromImage(imag);
    Sound money = LoadSound("C:\\Users\\PCM\\Pictures\\bg\\mysound.wav");
    Texture2D crusor = LoadTexture("C:\\Users\\PCM\\Pictures\\Camera Roll\\crusor.png");
    Texture2D button = LoadTexture("C:\\Users\\PCM\\Pictures\\Camera Roll\\gamble.png");
    Sound roll = LoadSound("C:\\Users\\PCM\\Pictures\\Camera Roll\\slot.mp3");
    Sound fail = LoadSound("C:\\Users\\PCM\\Pictures\\Camera Roll\\fail.mp3");
    Texture2D button2 = LoadTexture("C:\\Users\\PCM\\Pictures\\Camera Roll\\gamble2.png");
    Vector2 crusorpos = {100.0f, 100.0f};
    int weight = 50;
    int hight = 50;
    Rectangle sourceRec = { 0.0f, 0.0f, (float)weight, (float)weight };
    Rectangle destRec = { crusorpos.x, crusorpos.y, weight*1.0f, hight*1.0f };
    Vector2 origin = { (float)weight/2.0f, (float)hight/2.0f };
    int rotation = 0;

    int button_x = 310;
    int button_y = 450;
    int button_height = 169;
    int button_width = 300;
    Rectangle btnbounds = { (float)button_x, (float)button_y, (float)button_width, (float)button_height };
    


    while(!WindowShouldClose()){
        HideCursor();
        crusorpos = GetMousePosition();
        destRec = { crusorpos.x, crusorpos.y, weight*1.0f, hight*1.0f };
        Rectangle crusorv = {crusorpos.x, crusorpos.y, 50.0f, 50.0f};

        if(rolling){
                rolling_value = (rand() % 250000) + 1;
                rolling_frames--;

                if(rolling_frames <= 0){
                rolling = false;
                gambled_money = rolling_value;
                if(gambled_money > inventory){
                    continue;
                }
                inventory = inventory - gambled_money;
                output = (rand() % 300000);
                if(output >= gambled_money){
                    PlaySound(money);
                }
                else{PlaySound(fail);}
                inventory = inventory + output;
                }
            }

        BeginDrawing();
        ClearBackground(WHITE);
        DrawTexture(back, 0, 0, WHITE);
        DrawTexture(button, 310,450,WHITE);
        if(CheckCollisionRecs(crusorv, btnbounds)){
            DrawTexture(button2, 310,450,WHITE);
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){

                rolling_frames = 215;
                rolling = true;
                PlaySound(roll);
                
            }
        }

        if(rolling){
            DrawText(TextFormat("You have gambled: %d$", rolling_value), 300, 170, 32, YELLOW);
        }else{
        DrawText(TextFormat("You have gambled: %d$", gambled_money), 300, 170, 32, YELLOW);}
        if(output > gambled_money){
            DrawText(TextFormat("You earned: %d$", output), 330, 220, 32, GREEN);
        }
        else{
            DrawText(TextFormat("You earned: %d$", output), 330, 220, 32, RED);}
        DrawText(TextFormat("Wallet: %d$", inventory), 330, 270, 32, GOLD);
        DrawTexturePro(crusor, sourceRec, destRec, origin, (float)rotation, WHITE);

        EndDrawing();
    }

    UnloadSound(money);
    UnloadTexture(back);
    UnloadTexture(crusor);
    UnloadTexture(button);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}
