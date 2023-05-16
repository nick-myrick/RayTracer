#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include "vec3.h"

//-------------------------------------------------------
// Translate and write r g b components to a given stream
//-------------------------------------------------------

void write_color(std::ostream &out, color pixel_color) {
    // Write value of each translated color component
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

#endif