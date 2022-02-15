/**
 * @author DALLAGI Sami (p1807154) GHODHBANI Chouaïb(p1914024) JEBNOUNI Mohamed (p1712808)
 * @version 0.1
 */
#include "Image.h"
#include "Pixel.h"
#include <cassert>
#include <string>
#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>


Image::Image() : tab(nullptr), dimx(0), dimy(0)
{

}

Image::Image(int dimensionX, int dimensionY) : tab(new Pixel[dimensionX * dimensionY]), dimx(dimensionX), dimy(dimensionY)
{

}

Image::~Image()
{
    if (tab != nullptr)
    {
        delete[] tab;
        tab = nullptr;
        dimx=0;
        dimy=0;
    }
}

Pixel& Image::getPix(int x, int y) const
{
    assert(x < dimx&& y < dimy);
    return tab[dimx * y + x]; //pixel à la position (x,y)
}

void Image::setPix(int x, int y, const Pixel& couleur)
{
    assert(x < dimx&& y < dimy);
    tab[dimx * y + x] = couleur;
}

void Image::dessinerRectangle(int Xmin, int Ymin, int Xmax, int Ymax, const Pixel& couleur)
{
    assert(Xmin < dimx&& Ymin < dimy);
    assert(Xmax < dimx&& Ymax < dimy);
    assert(Xmin <= Xmax && Ymin <= Ymax);

    for (int x = Xmin; x <= Xmax; x++) {
        for (int y = Ymin; y <= Ymax; y++) {
            tab[dimx * y + x] = couleur;
        }
    }
}

void Image::effacer(const Pixel& couleur)
{
    if (dimx > 0 && dimy > 0) {
        dessinerRectangle(0, 0, dimx - 1, dimy - 1, couleur); // trace un rectangle plein de la couleur choisie sur tout l'écran
    }
}

void Image::sauver(const std::string& filename) const
{
    std::ofstream fichier(filename.c_str());
    assert(fichier.is_open());
    fichier << "P3" << std::endl;
    fichier << dimx << " " << dimy << std::endl;
    fichier << "255" << std::endl;
    for (int y = 0; y < dimy; y++)
    {
        for (int x = 0; x < dimx; x++)
        {
            Pixel pix = getPix(x, y);
            fichier << pix.getRouge() << " " << pix.getVert() << " " << pix.getBleu() << " ";
        }
    }
    std::cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}

void Image::ouvrir(const std::string& filename)
{
    std::ifstream fichier(filename.c_str());
    assert(fichier.is_open());
    char r, g, b;
    std::string mot;
    dimx = dimy = 0;
    fichier >> mot >> dimx >> dimy >> mot;
    assert(dimx > 0 && dimy > 0);
    if (tab != nullptr)
    {
        delete[] tab;
    }
    tab = new Pixel[dimx * dimy];

    for (int y = 0; y < dimy; y++)
    {
        for (int x = 0; x < dimx; x++)
        {
            fichier >> r >> g >> b;
            getPix(x, y).setRouge(r);
            getPix(x, y).setVert(g);
            getPix(x, y).setBleu(b);
        }
    }
    fichier.close();
    std::cout << "Lecture de l'image " << filename << " ... OK\n";
}

void Image::afficherConsole()
{
    std::cout << dimx << " " << dimy << std::endl;
    for (int y = 0; y < dimy; y++)
    {
        for (int x = 0; x < dimx; x++)
        {
            Pixel pix = getPix(x, y);
            std::cout << (int)pix.getRouge() << " " << (int)pix.getVert() << " " << (int)pix.getBleu() << " ";
        }
        std::cout << std::endl;
    }
}

void Image::testRegression()
{
    Pixel pix(255, 0, 0);
    Image img1(4, 4);
    img1.setPix(2, 2, pix);
    img1.afficherConsole();
    assert(true);
    assert(true);
    assert(true);
    assert(true);
    assert(true);
    assert(true);
}

void Image::afficher()
{
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* texture = nullptr;
    SDL_Event event;
    int winW, winH;
    SDL_Rect srcR{}, destR{};
    float zoom = 1;
    bool quit = false;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Échec de l'initialisation de la SDL: " << SDL_GetError() << std::endl;
        assert(false);
    }

    window = SDL_CreateWindow(
        "TP Module Image",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        200,
        200,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        std::cerr << "Erreur de création de la fenêtre: " << SDL_GetError() << std::endl;
        assert(false);
    }

    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED
    );

    if (!renderer) {
        std::cerr << "Erreur de création du renderer: " << SDL_GetError() << std::endl;
        assert(false);
    }

    texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_TARGET,
        dimx,
        dimy
    );

    if (!texture) {
        std::cerr << "Erreur de création de la texture: " << SDL_GetError() << std::endl;
        assert(false);
    }

    SDL_SetWindowResizable(window, SDL_TRUE);

    while (!quit)
    {
        while (SDL_PollEvent(&event)) // Récupération des actions de l'utilisateur
        {
            switch (event.type)
            {
            case SDL_QUIT: // Clic sur la croix
                quit = true;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode)
                {
                case SDL_SCANCODE_ESCAPE: // quitter
                    quit = true;
                    break;
                case SDL_SCANCODE_T: // zoomer
                    zoom += 0.1f * zoom;
                    break;
                case SDL_SCANCODE_G: // dézoomer
                    zoom -= 0.1f * zoom;
                    if (zoom < 0) {
                        zoom = 0;
                    }
                    break;
                default:
                    std::cout << "Touche pressée: " << event.key.keysym.scancode << std::endl;
                }
            }
        }

        assert(SDL_SetRenderTarget(renderer, NULL) == 0);
        SDL_SetRenderDrawColor(renderer, 190, 190, 190, 255);
        SDL_RenderClear(renderer);

        assert(SDL_SetRenderTarget(renderer, texture) == 0);

        for (int y = 0; y < dimy; y++)
        {
            for (int x = 0; x < dimx; x++)
            {
                Pixel pix = getPix(x, y);
                SDL_SetRenderDrawColor(renderer, (int)pix.getRouge(), (int)pix.getVert(), (int)pix.getBleu(), 255);
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }

        assert(SDL_SetRenderTarget(renderer, NULL) == 0);

        SDL_GetWindowSize(window, &winW, &winH);

        srcR.w = dimx;
        srcR.h = dimy;
        srcR.x = 0;
        srcR.y = 0;

        destR.w = int(dimx * zoom);
        destR.h = int(dimy * zoom);
        destR.x = winW / 2 - destR.w / 2;
        destR.y = winH / 2 - destR.h / 2;

        SDL_RenderCopy(renderer, texture, &srcR, &destR);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}
