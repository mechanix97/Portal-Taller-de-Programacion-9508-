#ifndef _AREA_H_
#define _AREA_H_

class Area{
public:
	explicit Area(int x, int y, int width, int height);
	int getX() const;
	int getY() const;
	int getWidth() const;
	int getHeight() const;
private:
	int x, y;
	int width, height;
};

#endif
