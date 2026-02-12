#pragma once

class Vector2{
    public:
        Vector2(float x = 0, float y = 0);
        float x, y;

};

class Vector2I : public Vector2{
    public:
        Vector2I(int x = 0, int y = 0);
        int x;
        int y;
};