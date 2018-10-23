#include "Bitmap/bitmap.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//argc - number of arguments in command
//argv - each argument word, stored in an array
int main(int argc, char* argv[])
{
    string filename;
    Bitmap image;
    Pixel color;
    
    if(argc != 2)
    {
        cout << "Please specify one image file!\n";
    }

    if(argc == 2)
    {
        filename =  argv[1];
    }

    image.open(filename);

    if(image.isImage())
    {
        vector <vector <Pixel> > imagePixels = image.toPixelMatrix();
        cout << "" << filename << " is " << imagePixels.size() << " pixels high and " << imagePixels[0].size() << " pixels wide" << endl;

       for(int r = 0; r < imagePixels.size(); r++)
       {
           for(int c = 0; c < imagePixels[r].size(); c++)
           {
                Pixel color = imagePixels[r][c];
                color.green = 0;
                color.blue = 0;
                imagePixels[r][c] = color;
           }
       }
       image.fromPixelMatrix( imagePixels );
       image.save("redness.bmp");
    }
    else
    {
        cout << "Image file must be a bitmap with 24-bit color depth. \n";
    }

  return 0;
}
