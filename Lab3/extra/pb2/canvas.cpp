#include <iostream>
#include <cstring>
#include <cstdarg>
#include <stdlib.h>
#include <tuple>
#include "Canvas.h"
using namespace std;
Canvas::Canvas(int width, int height)
{
	this->matrice = new char* [height];

	for (int i = 0; i < height; i++)
		this->matrice[i] = new char[width];
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			this->matrice[i][j] = ' ';
		this->matrice[i][width] = '\0';
	}
	this->w = width;
	this->h = height;

}
void Canvas::set_pixel(int x, int y, char ch)
{
	if (x >= 0 && x < w && y >= 0 && y < h)
		matrice[x][y] = ch;
}

void Canvas::print() const
{
	for (int i = 0; i < h; i++)
		cout << this->matrice[i] << endl;
}
void Canvas::clear()
{
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			matrice[i][j] = ' ';
}
void Canvas::set_pixels(int count, ...)
{
	va_list p;
	va_start(p, count);

	while (count)
	{
		int x = va_arg(p, int);
		int y = va_arg(p, int);
		char z = va_arg(p,char);
		set_pixel(x, y, z);
		count--;

	}
	va_end(p);
}
