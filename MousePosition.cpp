#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

int main(){
    int actualPos = 0;
    int speed = 0; 

    POINT Vec;
    POINT LastMouse = {0, 0};
    DWORD oldTime = GetTickCount();

    while(true){
        GetCursorPos(&Vec);

        DWORD currentTime = GetTickCount();
        DWORD runTime = currentTime - oldTime;

        if(Vec.x != LastMouse.x || Vec.y != LastMouse.y){
            int deltaX = Vec.x - LastMouse.x;
            int deltaY = Vec.y - LastMouse.y;

            double distance = sqrt(deltaX * deltaX + deltaY * deltaY);

            double speed = (runTime > 0) ? (distance / (runTime / 1000.0)) : 0;

            printf("Pixeis/s: %.1f\n", speed);

            LastMouse = Vec;
            oldTime = currentTime;
        }

    Sleep(1);
    }

}