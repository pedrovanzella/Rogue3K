#ifndef _RENDERER_H_
#define _RENDERER_H_
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string>

class Renderer
{
    private:
        static SDL_Surface* screen;
        static TTF_Font* font;

    public:
        static void apply_surface(int, int, SDL_Surface*, SDL_Surface*);
        static void Init();
        static int Update();
        static void CloseRenderer();
        static void write_message_to_screen(int, int, int, std::string, int, int);
        static void set_window_title(std::string);
};

#endif /* _RENDERER_H_ */
