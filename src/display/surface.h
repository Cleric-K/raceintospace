#ifndef DISPLAY_SURFACE_H
#define DISPLAY_SURFACE_H

#include <SDL.h>

namespace display {

class Surface {
public:
	Surface( unsigned int width, unsigned int height );
	~Surface();

	enum Operation {
		Set,
		Xor
	};

	SDL_Surface * surface() const;
	char * pixels() const;
	void clear(int colour);
	void fillRect(int x1, int y1, int x2, int y2, char color);
	void fillRect(const SDL_Rect &area, char color);
	void setPixel(int x, int y, char color);
	char getPixel(int x, int y);
	void outlineRect(int x1, int y1, int x2, int y2, char color);
	void line(int x1, int y1, int x2, int y2, char color);
	void copyFrom( Surface * surface, int x1, int y1, int x2, int y2 );
	void copyTo(Surface * surface, int mode, int x, int y, Surface::Operation operation);
	void Surface::scaleTo(Surface * surface);

	unsigned int width() const {
		return _width;
	}

	unsigned int height() const {
		return _height;
	}

private:
	unsigned int _width;
	unsigned int _height;
	SDL_Surface *_screen;
	bool _dirty;
};

} // namespace display

#endif // DISPLAY_SURFACE_H