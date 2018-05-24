#include <iostream>

enum color { red, white, blue, green, pink };

class point{
public:
	point() {}
	point(int _x, int _y) :x(_x), y(_y) {};
	int x;
	int y;
};

void paint_circle(point center, int radius, color _color) {
	std::cout << "Painting circle w/ center at (" << center.x << "," << center.y << ") and a radius of " << radius << ". (" << _color << ")" << std::endl;
}

void paint_rec(point center, color _color,int radius) {
	if (radius > 12) {
		paint_circle(center, radius, _color);
		_color != pink ? paint_rec(center, static_cast<color>(_color+1), radius - 5) : paint_rec(center, static_cast<color>(_color -4), radius - 5);
	}
}

int main() {
	paint_rec(point(6, 8),red, 100);
	system("pause");
}