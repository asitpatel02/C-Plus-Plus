#include <simplecpp>

class Disk {
public:
    Disk(double cx, double cy, double r) : centerX(cx), centerY(cy), radius(r) {}
    double centerX, centerY, radius;
};

bool doDisksIntersect(const Disk& disk1, const Disk& disk2) {
    double distanceSq = (disk1.centerX - disk2.centerX) * (disk1.centerX - disk2.centerX) +
                        (disk1.centerY - disk2.centerY) * (disk1.centerY - disk2.centerY);
    double radiusSumSq = (disk1.radius + disk2.radius) * (disk1.radius + disk2.radius);
    return distanceSq < radiusSumSq;
}

int main() {
    initCanvas("Disks Intersection", 800, 600);

    // Create disks
    Disk disk1(100, 100, 50);
    Disk disk2(200, 200, 70);
    Disk disk3(300, 150, 40);
    Disk disk4(400, 300, 60);
    Disk disk5(500, 200, 50);

    // Draw disks
    Circle c1(disk1.centerX, disk1.centerY, disk1.radius);
    c1.imprint();
    Circle c2(disk2.centerX, disk2.centerY, disk2.radius);
    c2.imprint();
    Circle c3(disk3.centerX, disk3.centerY, disk3.radius);
    c3.imprint();
    Circle c4(disk4.centerX, disk4.centerY, disk4.radius);
    c4.imprint();
    Circle c5(disk5.centerX, disk5.centerY, disk5.radius);
    c5.imprint();

    // Check for intersections
    if (doDisksIntersect(disk1, disk2)) cout << "Disk 1 and Disk 2 intersect." << endl;
    if (doDisksIntersect(disk1, disk3)) cout << "Disk 1 and Disk 3 intersect." << endl;
    if (doDisksIntersect(disk1, disk4)) cout << "Disk 1 and Disk 4 intersect." << endl;
    if (doDisksIntersect(disk1, disk5)) cout << "Disk 1 and Disk 5 intersect." << endl;
    if (doDisksIntersect(disk2, disk3)) cout << "Disk 2 and Disk 3 intersect." << endl;
    if (doDisksIntersect(disk2, disk4)) cout << "Disk 2 and Disk 4 intersect." << endl;
    if (doDisksIntersect(disk2, disk5)) cout << "Disk 2 and Disk 5 intersect." << endl;
    if (doDisksIntersect(disk3, disk4)) cout << "Disk 3 and Disk 4 intersect." << endl;
    if (doDisksIntersect(disk3, disk5)) cout << "Disk 3 and Disk 5 intersect." << endl;
    if (doDisksIntersect(disk4, disk5)) cout << "Disk 4 and Disk 5 intersect." << endl;

    wait(5);
    return 0;
}
