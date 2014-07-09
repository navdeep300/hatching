#include <cairo/cairo.h>
#include<iostream>
#include<cmath>	
int main(int argc, char** argv)
{
    cairo_surface_t *surface;
    cairo_t *cr;
    surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 1300, 760);
    cr = cairo_create (surface);

int w, h;
cairo_surface_t *image;

cairo_arc (cr, 128.0, 128.0, 76.8, 0, 2*M_PI);
cairo_clip (cr);
cairo_new_path (cr); /* path not consumed by clip()*/

image = cairo_image_surface_create_from_png ("new.png");
w = cairo_image_surface_get_width (image);
h = cairo_image_surface_get_height (image);

cairo_scale (cr, 256.0/w, 256.0/h);

cairo_set_source_surface (cr, image, 0, 0);
cairo_paint (cr);

cairo_surface_destroy (image);
    cairo_destroy (cr);
    cairo_surface_write_to_png (surface, "hello.png");
    cairo_surface_destroy (surface);

    return 0;
}
