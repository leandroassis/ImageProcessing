#pragma once

#include <python3.10/Python.h>
#include <Magick++.h>
#include <string>
#include <vector>
#include "Pixel.h"

using namespace std;
using namespace Magick;

#define DEBUG

class ImageProcessing {
    private:
        string path;
        int altura, largura, max_color;

        Image MagickImage;

        vector<vector<Pixel *>> pixels;
        // numpy_array = NULL;

        int vectorToArray();
        int ppmToVector();

    public:
        // construtores e destrutores
        ImageProcessing();
        ImageProcessing(string);
        ImageProcessing(vector<Pixel> &, int, int);
        ImageProcessing(int, int, string = "random");
        ImageProcessing(ImageProcessing &);
        ~ImageProcessing();

        // getters e setters
        string getPath();
        int getAltura();
        int getLargura();
        void getPixels();

        // operações com imagens das funções em python
        int mirror(bool = false);
        int rotate(float);
        int to_ASCII();
        int to_pixel(int = 16);

        // operações com imagens das funções em c++
        int resize(int = 0, int = 0);
        int compress(size_t = 1);
        int noise(Magick::NoiseType);
        int convolve(size_t, const double *);
        int blur(const double);
        int denoise();
        int remap(Image &);
        int negative();
        int grayscale();
        int convert(string = NULL, string = NULL);

        // funções extras
        int save(string = NULL);

        // operadores
        ImageProcessing& operator+=(Pixel&);
        vector<Pixel *>& operator[](int);
};

struct RGB {
    unsigned char r, g, b;
};

void eat_comment(ifstream &);