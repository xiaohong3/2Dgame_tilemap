#include "Camera.h"

Camera Camera::camera_control;

Camera::Camera()
{
    //ctor
}

Camera::Camera(int x, int y, int width, int height, int maxX, int maxY)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->maxX = maxX;
    this->maxY = maxY;
}

void Camera::on_move(int move_x, int move_y)
{
    x += move_x;
    y += move_y;

    x = std::max(0, std::min(x, maxX));
    y = std::max(0, std::min(y, maxY));
}

int Camera::get_x()
{
    return x;
}

int Camera::get_y()
{
    return y;
}

int Camera::get_w()
{
    return width;
}

int Camera::get_h()
{
    return height;
}

Camera::~Camera()
{
    //dtor
}
