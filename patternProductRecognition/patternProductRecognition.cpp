#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/core/ocl.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp> // imshow
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp> // feature detector 
#include <opencv2/opencv.hpp> // Homografía y transformacion perspectiva


using namespace cv;
using namespace std;


int main()
{
    String folderpath = "C://imgs//*.bmp";
    vector<String> filenames;

    glob(folderpath, filenames);
    for (size_t i = 0; i < filenames.size(); i++)
    {
        // Imagen donde se detectaran los patrones
        Mat img = imread(filenames[i], IMREAD_COLOR);
        imshow("Imagen", img);
        waitKey();
    }

    return 0;
}