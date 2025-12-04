#include <raylib.h>
#include <iostream>

int main(){

    std::cout << "\033[2J\033[1;1H";
    int radius;
    std::cout << "enter circle radius --> ";
        std::cin >> radius;
    char op;
    std::cout << "\noperator (+/-) --> ";
    std::cin >> op;

    SetTargetFPS(60);
    InitWindow(900, 900, "bruh");
    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(BLUE);
            
            switch(op){
                case '+':
                    radius++;
                    break;
                case '-':
                    radius--;
                    break;
            }
            if(radius > 400){
                radius--;
            }
            if(radius < 10){
                radius++;
            }

            DrawCircle(100, 100, radius, RED);
             DrawCircle(800, 100, radius, GREEN);
            DrawCircle(800, 800, radius, WHITE);
             DrawCircle(100, 800, radius, YELLOW);
        EndDrawing();
    }
    std::cout << "\033[2J\033[1;1H";

    return 0;
}
