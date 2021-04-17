#include <iostream>
#include <fstream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(int argc, char* argv [])
{
    int width, hight, bpp;
    unsigned char* data;
    char* filePath = argv[1];
    data = stbi_load(filePath, &width, &hight, &bpp, 0);
	std::cout << "Image " << width << " " << hight << " "  << bpp << std::endl;
    
    //output image to triangle
    std::ofstream outF("./output.tri");
    for (int y =0;y<hight;++y) {
        for (int x = 0;x <width;++x) {
            if (data[y*width*bpp + x*bpp + 3] > 0) {
                outF << 1.0*x/(width+1) << "," << 1.0*y/(hight+1) << " "
                << 1.0*(x+1)/(width+1) << "," << 1.0*y/(hight+1) << " "
                << 1.0*(x+1)/(width+1) << "," << 1.0*(y+1)/(hight+1) << " "
                << 1.0*(x+1)/(width+1) << "," << 1.0*(y+1)/(hight+1) << " "
                << 1.0*x/(width+1) << "," << 1.0*(y+1)/(hight+1) << " "
                << 1.0*x/(width+1) << "," << 1.0*y/(hight+1) << std::endl;
            }
        }
    }
    
    stbi_image_free(data);
	return 0;
}
