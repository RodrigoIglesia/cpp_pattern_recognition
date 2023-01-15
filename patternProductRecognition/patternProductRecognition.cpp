#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/core/ocl.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp> // imshow
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp> // feature detector 
#include <opencv2/opencv.hpp> // Homography and perspective transform


using namespace cv;
using namespace std;


int main()
{
    String folderpath = "C://imgs//*.bmp";
    vector<String> filenames;

    glob(folderpath, filenames);
    for (size_t i = 0; i < filenames.size(); i++)
    {
        // Image where patterns will be recognised.
        Mat img = imread(filenames[i], IMREAD_COLOR);

        if (img.empty())
        {
            cout << "Could not read image." << endl;
            return 1;
        }
        //imshow("Imagen", img);
        //waitKey();
        
        // Sliding window in image.
        int window_rows = 400;
        int window_cols = 530;
        int step_size_rows = 400;
        int step_size_cols = 530;

        Mat img_slides = img.clone(); // Image for showing sliding window.

        for (int row = 0; row <= img.rows - window_rows; row += step_size_rows)
        {
            for (int col = 0; col <= img.cols - window_cols; col += step_size_cols)
            {
                // For each step, create a Rect window.
                Rect window(col, row, window_cols, window_rows);
                
                // Draw sliding window in original image copy.
                rectangle(img_slides, window, Scalar(0, 255, 0), 2);
                imshow("Sliding window", img_slides);
                waitKey(100);

                // Extract the ROI from the original image with the window.
                Mat roi = img(window);

                imshow("ROI", roi);
                waitKey(100);
            }
        }
    }

    return 0;
}