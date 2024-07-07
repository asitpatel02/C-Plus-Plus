#include <simplecpp>

int main() {
    initCanvas("Projectile", 500, 500);

    Circle c1(100,100,100);
    Text t(100,100,"ASit");
    Rectangle r(100,100,textWidth("Asit")+4,textHeight()+4);
    c1.moveTo(500,500);
    wait(5);
}
