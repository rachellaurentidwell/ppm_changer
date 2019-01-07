#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <istream>
#include <ostream>
#include <sstream>
#include "PpmDocument.h"
#include "Pixel.h"
#include "ImageEffect.h"
#include "RemoveRedImageEffect.h"
#include "RemoveGreenImageEffect.h"
#include "RemoveBlueImageEffect.h"
#include "NegateRedImageEffect.h"
#include "NegateBlueImageEffect.h"
#include "NegateGreenImageEffect.h"
#include "AddNoiseImageEffect.h"
#include "HighContrastImageEffect.h"
#include "GrayscaleImageEffect.h"
#include "FlipHorizontalImageEffect.h"
#include "FlipVerticalImageEffect.h"
#include "ChainImageEffect.h"



using namespace std;

enum colors_t { RED = 0, GREEN, BLUE };
enum menu_options_t {REMOVE_RED = 1, REMOVE_GREEN, REMOVE_BLUE,
NEGATE_RED, NEGATE_GREEN , NEGATE_BLUE, ADD_NOISE, 
HIGH_CONTRAST, GRAYSCALE, FLIP_HORIZONTAL, FLIP_VERTICAL, 
ROTATE_90, BLUR, PIXELATE, CHAIN}; //PA1 TODO: fill in the rest
PpmDocument ppmDocumentFromFile(string file_name);
void ppmDocumentToFile(PpmDocument &doc, string file_name);
menu_options_t getMenuSelection();
void applyImageEffect(PpmDocument &doc, menu_options_t effect);

int main(void)
{
	//grab source PPM from the user
	cout << "Enter input file: ";
	string input_file_name = "";
	getline(cin, input_file_name);

    //grab destination file from user
    cout << "Enter destination file: ";
    string output_file_name = "";
    getline(cin, output_file_name);

    PpmDocument doc = ppmDocumentFromFile(input_file_name);
    menu_options_t selection = REMOVE_RED;
    while (selection > 0)
    {
        selection = getMenuSelection();
        if (selection > 0)
        {
            applyImageEffect(doc, selection);
        }
    }
    ppmDocumentToFile(doc, output_file_name);
	return 0;
}

PpmDocument ppmDocumentFromFile(string file_name)
{
    PpmDocument doc{ "P3"};

    //open PPM for file processing
    ifstream source_ppm{ file_name };

    //were we able to open the file?
    if (source_ppm.is_open() == true)
    {
        //grab basic PPM info before starting file
        //loop
        string ppm_type = "";
        string dimensions = "";
        string max_rgb = "";
        getline(source_ppm, ppm_type);
        getline(source_ppm, dimensions);
        getline(source_ppm, max_rgb);

        //convert strings into INTs for PPM document
        int width = 0;
        int height = 0;
        int rgb = 0;
        istringstream dimensions_stream{ dimensions };
        dimensions_stream >> width;
        dimensions_stream >> height;
        rgb = stoi(max_rgb);
        doc = PpmDocument{ ppm_type, width, height, rgb };

        //convert PPM
        while (source_ppm.good() == true)
        {
            int next_value = 0;
            int color_counter = 0;
            int row_counter = 0;
            int col_counter = 0;

            //grab next number irrespective of
            //line
            Pixel temp_pixel{};
            while (source_ppm >> next_value)
            {
                if (color_counter == RED)
                {
                    temp_pixel.setRed(next_value);
                }
                else if (color_counter == GREEN)
                {
                    temp_pixel.setGreen(next_value);
                }
                else if (color_counter == BLUE)
                {
                    //BLUE represents a finished pixel
                    temp_pixel.setBlue(next_value);

                    //save finished pixel to document
                    doc.setPixel(row_counter, col_counter, temp_pixel);

                    col_counter++;
                    if (col_counter >= doc.getWidth())
                    {
                        col_counter = 0;
                        row_counter++;
                    }
                }
                color_counter++;
                color_counter %= 3;
            }
        }
    }
    source_ppm.close();
    return doc;
}
void ppmDocumentToFile(PpmDocument &doc, string file_name)
{
    ofstream output_ppm{ file_name };
    output_ppm << doc.getDocType() << endl;
    output_ppm << doc.getWidth() << " " << doc.getHeight() << endl;
    output_ppm << doc.getMaxRgb() << endl;
    for (int i = 0; i < doc.getHeight(); i++)
    {
        for (int j = 0; j < doc.getWidth(); j++)
        {
            output_ppm << doc.getPixel(i, j).toString() << " ";
        }
        output_ppm << endl;
    }
    output_ppm.close();
}
menu_options_t getMenuSelection()
{
    cout << "***Effect Menu***" << endl;
    cout << REMOVE_RED << ". Remove red" << endl;
    cout << REMOVE_GREEN << ". Remove green" << endl;
    cout << REMOVE_BLUE << ". Remove blue" << endl; 
    cout << NEGATE_RED << ". Negate red" << endl;
    cout << NEGATE_GREEN << ". Negate green" << endl;
    cout << NEGATE_BLUE << ". Negate blue" << endl;
    cout << ADD_NOISE << ". Add random noise" << endl;
    cout << HIGH_CONTRAST << ". High contrast" << endl;
    cout << GRAYSCALE << ". Grayscale" << endl;
    cout << FLIP_HORIZONTAL << ". Flip horizontally" << endl;
    cout << FLIP_VERTICAL << ". Flip vertically" << endl;
    cout << ROTATE_90 << ". Rotate 90 degrees" << endl;
    cout << BLUR << ". Blur the image" << endl;
    cout << PIXELATE << ". Pixelate" << endl;
	cout << CHAIN  << ". Chain" << endl;
	
    
       
    

    //PA1 TODO: fill in the rest
    cout << "-1. Done applying effects" << endl;
    cout << "Apply which effect: ";
    string selection;
    getline(cin, selection);
    int result = stoi(selection);
    return (menu_options_t)result;
}
void applyImageEffect(PpmDocument &doc, menu_options_t option)
{
    ImageEffect *effect = nullptr;
    switch (option)
    {
    case REMOVE_RED:
        effect = new RemoveRedImageEffect();
        break;

    case REMOVE_GREEN:
        effect = new RemoveGreenImageEffect();
        break;
        
    case REMOVE_BLUE:
        effect = new RemoveBlueImageEffect();
        break;
        
    case NEGATE_RED:
        effect = new NegateRedImageEffect();
        break;
        
    case NEGATE_GREEN:
        effect = new NegateGreenImageEffect();
        break;
        
    case NEGATE_BLUE:
        effect = new NegateBlueImageEffect();
        break;
      
    case ADD_NOISE:
        effect = new AddNoiseImageEffect();
        break;
        
    case HIGH_CONTRAST:
        effect = new HighContrastImageEffect();
        break;
       
    case GRAYSCALE:
        effect = new GrayscaleImageEffect();
        break;
   
         
    case FLIP_HORIZONTAL:
        effect = new FlipHorizontalImageEffect();
        break;
        

        
    case FLIP_VERTICAL:
        effect = new FlipVerticalImageEffect();
        break;
        
        
    case CHAIN:
        effect = new ChainImageEffect();
        break;

   

    }

    if (effect != nullptr)
    {
        effect->processImage(doc);
    }
    delete effect;
}
