#ifndef CAMERA_H
#define CAMERA_H

#include "Define.h"
#include <algorithm>


class Camera
{
    public:
        Camera();
        Camera(int x, int y, int width, int height, int maxX, int maxY);
        static Camera camera_control;
        virtual ~Camera();
        void on_move(int move_x, int move_y);
        int get_x();
        int get_y();
        int get_w();
        int get_h();

    protected:

    private:
        int x;
        int y;
        int width;
        int height;
        int maxX;
        int maxY;
};

#endif // CAMERA_H
