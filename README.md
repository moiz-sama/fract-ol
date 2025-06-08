# fract'ol  
**Computer Graphics Fractals**

## 🎯 Overview  
Fract’ol is a fractal rendering program written in C using the MiniLibX graphical library. It allows real-time visualization and interaction with complex mathematical sets like Mandelbrot and Julia, helping users explore the infinite beauty of fractals.

## 🧩 Features  

### ✅ Mandatory
- Display the **Mandelbrot** and **Julia** fractals.
- Use **MiniLibX** to open a graphical window and render images.
- Zoom in and out using the **mouse wheel** (deep zoom into fractals).
- Generate different Julia sets using command-line arguments.
- Display appropriate usage instructions if invalid or missing parameters are given.
- Use colors to illustrate fractal depth (custom and psychedelic palettes encouraged).
- Handle window events:
  - **ESC** exits the program cleanly.
  - Clicking the **window close** button exits cleanly.
- No global variables.

### 🧠 Math and Graphics
- Uses **complex number mathematics** for fractal calculations.
- Uses **MiniLibX** and **math library** (`-lm`).
- Uses a custom implementation of `printf` (e.g. `ft_printf`).

## ⚙️ Compilation & Usage
```bash
make
./fractol mandelbrot
./fractol julia 0.285 0.01

