#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);

/**
 * Uses Bresenham's algorithm to draw a straight line of a specified colour between
 * a set of two dimensional points on the supplied TGAImage.
 */
void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color) {
    for (float t=0; t<1.; t+=.01) {
        int x = x0 + (x1-x0)*t;
        int y = y0 + (y1-y0)*t;
        image.set(x, y, color);
    }
}

/**
 * Writes the supplied TGAImage with the specified filename. The image
 * is flipped vertically before being written so we can consider the
 * bottom-left corner to be the origin (0,0).
 */
void write_image(TGAImage &image, const char* filename) {
    image.flip_vertically();
    image.write_tga_file(filename);
}

int main(int argc, char** argv) {
    TGAImage image(100, 100, TGAImage::RGB);
    line(10, 10, 80, 80, image, red);
    write_image(image, "output.tga");
    return 0;
}
