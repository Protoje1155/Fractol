# Fractol Project
## Overview
- The Fractol project is a graphical exploration of fractals, mathematical sets that exhibit self-similar patterns at every scale.
- This project allows users to interactively explore and visualize various fractals.

## Objective
- The primary objective of the Fractol project is to implement a graphical application that generates and displays fractals in real-time.  
- The application should provide interactive controls for users to navigate and manipulate the fractals.

Features
- Supports visualization of the Mandelbrot set, Julia set, cubic Mandelbrot set, and Nova set(own creation).
- Interactive controls for zooming, panning, and adjusting parameters of the fractals.
- Multiple color schemes for visual customization.
- Error handling and informative messages for user guidance.

## Usage
To use the Fractol application, follow these steps:

1. Clone the repository:
```
git clone <repository-url>
```
2. Navigate to the Fractol directory:
```
cd fractol
```
3. Compile the program:
```
make all
```
4. Execute the program with the desired fractal type:
#### Mandelbrot Set:
```
./fractol mandelbrot
```
#### Julia Set
```
./fractol julia <value1> <value2>
```
#### Cubic Mandelbrot Set
```
./fractol cubic
```
#### Nova Set (Own Creation):
```
./fractol nova
```

