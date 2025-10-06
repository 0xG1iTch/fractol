# fract-ol

Interactive fractal explorer in C using MiniLibX for the 42 Network. Render and navigate Mandelbrot, Julia, and Burning Ship sets with smooth zooming and coloring.

---

## Project Overview

`fract-ol` draws complex fractals by iterating the function _zₙ₊₁ = f(zₙ, c)_ per pixel and mapping escape times to colors. It focuses on event-driven graphics, precise floating‑point math, and performance with clean 42‑style C.

**Key Learning Topics**: MiniLibX, event loops, pixel buffers, complex arithmetic, color mapping, input handling, and algorithmic optimization.

---

## Features

- Sets: Mandelbrot, Julia (custom seeds), Burning Ship
- Smooth zoom centered at cursor, pan, and reset
- Iteration control and anti‑aliasing friendly coloring (smooth/continuous palette)
- Multiple color palettes and toggles
- Optional multi‑threaded rendering (bonus)
- Window resize and re-render (bonus if allowed by subject)

---

## Build

Requirements: `make`, `gcc/clang`, MiniLibX.

**macOS (Homebrew X11 not required for the default macOS mlx):**
```bash
make
```

**Linux (X11 + mlx):**
```bash
# Ensure X11 headers/libs are installed (e.g., libx11-dev libxext-dev)
make LINUX=1
```

This will produce the `fractol` binary in the project root.

---

## Usage

```bash
./fractol mandelbrot
./fractol julia <re> <im>        # example: ./fractol julia -0.8 0.156
./fractol burningship
```

Invalid args print a short help and exit with non‑zero status.

---

## Controls

- **Zoom**: Mouse wheel or `=`/`-` keys (cursor‑centric zoom)
- **Pan**: Arrow keys or drag with mouse (if implemented)
- **Iterations**: `[` decrease, `]` increase
- **Palettes**: `C` cycle colors, `V` invert
- **Julia seed live mode**: move mouse; press `J` to lock/unlock
- **Reset**: `R`
- **Exit**: `Esc` or window close

(Exact keymap may vary; update to match your implementation.)

---

## Project Structure

```
.
├── src/
│   ├── main.c            # arg parsing, init, event loop
│   ├── render.c          # per-pixel iteration + color
│   ├── controls.c        # input callbacks, zoom/pan
│   ├── fractals.c        # mandelbrot/julia/burning-ship
│   ├── color.c           # palettes and smooth coloring
│   ├── image.c           # mlx image buffer put/get
│   └── threads.c         # optional pthreads tiling (bonus)
├── include/
│   └── fractol.h
├── lib/mlx/              # MiniLibX
├── Makefile
└── README.md
```

---

## Math & Coloring

- Escape test with bailout radius `R = 2` (squared radius = 4)
- Smooth iteration count: `nu = i + 1 - log(log|z|)/log 2` for continuous gradients
- Map `nu` to a palette (HSV or gradient table) for banding‑free color

---

## Performance Notes

- Use `double` for speed; switch to `long double` or higher precision if you implement deep zoom
- Tile the image and render in N threads (bonus); avoid false sharing
- Recompute only on view changes; throttle redraws on continuous mouse events

---

## Error Handling

- Invalid arguments → usage message and `EXIT_FAILURE`
- MLX/init failures → print error and cleanly free resources
- No memory/file descriptor leaks (check with `valgrind` or `leaks`)

---

## Bonus Ideas

- Multiple windows or side‑by‑side fractals
- Screenshot/export to `.bmp`/`.ppm`
- UI overlay with stats (FPS, iterations, center, scale)
- Extra sets: Tricorn, Multibrot, Burning Ship variants

---

## Testing

- Compare Mandelbrot reference images at known coordinates
- Validate Julia seed locking and cursor‑centric zoom
- Leak checks: `valgrind --leak-check=full ./fractol mandelbrot`

---

## Author

Mohamed El hammouchi //G1iTch//  
42 Login: mel-hamm

