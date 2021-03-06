
# Final project for CSCE 440 - Fall 2021

## Group Members:
- Bethany Krull
- Sajal Risal
- David Ryan

## Youtube Video Link
https://youtu.be/8kE6lxpiKIg
NOTE: There is a downloadable mp4 file included in case the youtube link does not work.

## How to Run the scripts

### Sajal Risal
1. In `Interpolation Algorithms` open main.py and algorithms.py
2. Install necessary libraries listed at the top if it says "x module not found" using `pip install x`
3. Run Jupyter notebook cells in main.py from top to bottom

### Bethany Krull
1. Under 'Interpolation Algorithms' open alg.m 
2. In order to run the program you should only need to click 'Run' (if on Matlab) - however it communicates with the data.xlsx file under 'Interpolation Algorithms' so make sure those are in the same directory when you try to run the alg.m file
3. As is, the program is set up to plot a graph of the interpolation and display the r-squared value - there are sections commented out that store the piecewise function into a matrix for further calculations - but I have commented them out to help the programs run time/keep it from crashing/etc.

### David Ryan
1. In `Integration Algorithms\monte` directory run make which should compile a fresh version of the program
2. This was developed for mac which uses the `.out` extension. If Windows is desired change the extension in the make file to `.exe` and run make again
3. The executable can then be run using `./monte.out` or `./monte.exe` for windows.
4. The accuracy variable at the top of the file can be changed to increase or decrease the number of guesses. The file must be re-compiled if this is done.  





## Data:

This data is from the SpaceX CRS-16 launch of the Falcon 9 rocket. 

### Mission Details: 
| Attribute | Value |
| ------------- | ------------- |
| Vehicle | Falcon 9  |
| Duration | 538.3 Seconds |
| Max Altitude | 209 km |


![Altitude annotated](https://github.com/shahar603/Telemetry-Data/blob/master/SpaceX%20CRS-16/Graphs/Altitude%20annotated.png)






## Project Details
This project can be done as a group project with two or three students in a group.
1. (15 points) **Data Collection:** Select any topic that you are interested in. Regarding this topic find some suitable data. This could be any data of your own, or published data from a book or journal, or some data downloaded from any website. The size of the data should be neither too small nor too large. Cite the source of your data including any webpage address. 
2. (100 points) **Experimental Comparison of Numerical Algorithms:** Implement (in MATLAB or another high-level programming language) at least two alternative algorithms (or three for groups of three students) to process your data. You can select algorithms from any of the following groups (as suitable to your data):
    - Function interpolation methods. [Open for undergraduates only] (These include Lagrange Interpolation Method, Newton???s Divided Differences Method, Piecewise Linear Interpolation, Piecewise Linear Approximation, Piecewise Quadratic Interpolation, Cubic Spline Interpolation). (Note: If you use Lagrange Interpolation or Newton???s Divided Differences Method, which were implemented in an earlier homework, then you need to implement two new methods beside those.)
    - Spatial interpolation methods. (These include Shape Function Interpolation, Inverse Distance Weighting, and Bezier Interpolation.)
    - Numerical integration methods. (These include the Upper and Lower Bound Sum of Rectangles Methods, the Trapezoid Method, Simpson???s Method, Romberg???s Method, and the Monte Carlo Method.) In the comparison, compare the accuracy using the same number of intervals and/or the computational complexity.
    - Methods of evaluating systems of linear equations. (These include the naive Gaussian Method, and the Partial Pivoting Method.) In the comparison of these methods, give the residual errors and the condition numbers.
    - Least squares approximation methods. (These include, linear, polynomial and exponential least squares approximations.)
    - Any other pair of numerical algorithms. (For example, root finding methods. These need to be checked and approved by the instructor).
3. (25 points) Suppose your boss in a company asks you to evaluate the above methods and write a summary and recommendation about which method to use. In your slides, please include a summary of your computational experiments??? results. Present your findings in a table, bar chart, or other visual methods. Include in the comparison and discussion of any relevant information about accuracy and computational complexity. Finally, include in your summary a statement about which algorithm you would recommend to others and the reason for your recommendation.
4. (10 points) Make a class presentation about your project using powerpoint slides. Before you upload your final project to Canvas, record your presentation separately and provide a link to your video. Earlier class videos can be found at class project examples. Some projects explicitly say ???440 class.??? Some other projects may be related to the 413 class but are interesting to see because there are some overlaps.
- **Note:** The source code submitted should be executed on CSE server. Provide a "README" file that describes the source code for each problem and indicates how to compile and execute each of your programs.
