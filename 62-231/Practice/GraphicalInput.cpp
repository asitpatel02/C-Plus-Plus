#include <simplecpp>

int main() {
    initCanvas("Projectile", 500, 500);

    int w = getClick();
    Circle p(w / 65536, w % 65536, 5); // at click position
    p.penDown(); // let us see its path

    double vx = 1, vy = -1, gravity = 0.01;

    repeat(500) {
        p.move(vx, vy);
        vy += gravity;
        wait(0.01);
    }

    getClick(); // wait for the user to click. Only then terminate.

    return 0;
}
