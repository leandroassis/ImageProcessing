#pragma once

#include <python3.10/Python.h>
#include <Magick++.h>
#include <string>
#include <vector>
#include "Pixel.h"

using namespace std;
using namespace Magick;

class ImageProcessing {
    private:
        string path;
        int altura, largura, max_color;

        Image MagickImage;

        vector<Pixel *> pixels;
        // numpy_array = NULL;

        // transforma uma imagem em um numpy_array de pixels
        int vectorToArray();

        int ppmToVector(ifstream *);


    public:
        // construtores e destrutores
        ImageProcessing();
        ImageProcessing(string);
        ImageProcessing(Pixel, int, int);
        ImageProcessing(int, int, string = "random");
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
        int resize(int, int = NULL);
        int compress();
        int filter(int, const ImageProcessing* = NULL);
        int convert(string = NULL);

        // funções extras
        int save(string = NULL);

        // operadores
        // += e *= para aplicar convolução e filtro
        // [] para acessar um pixel no vetor de pixels
        ImageProcessing& operator+=(Pixel);
        ImageProcessing& operator*=(const ImageProcessing&);
        ImageProcessing& operator*=(Pixel);
        Pixel& operator[](int);
};