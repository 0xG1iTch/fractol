# fract-ol

Interactive fractal explorer in C using MiniLibX library. Render and navigate Mandelbrot, Julia, and Burning Ship sets with smooth zooming and colouring.

---

## Project Overview

`fract-ol` draws complex fractals by iterating the function *zₙ₊₁ = f(zₙ, c)* per pixel and mapping escape times to colours. It focuses on event-driven graphics, precise floating‑point math, and performance with clean 42‑style C.

**Key Learning Topics**: MiniLibX, event loops, pixel buffers, complex arithmetic, colour mapping, input handling, and algorithmic optimisation.

---

## Features

- Sets: Mandelbrot, Julia (custom seeds), Burning Ship
- Smooth zoom centred at the cursor, pan, and reset
- Iteration control and anti‑aliasing friendly colouring (smooth/continuous palette)
- Multiple colour palettes and toggles
- Optional multi‑threaded rendering (bonus)
- Window resize and re-render (bonus if allowed by subject)

---

## Build

Requirements: `make`, `gcc/clang`, MiniLibX.

**macOS:**

```bash
make
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
- **Palettes**: `C` cycle colours, `V` invert
- **Julia seed live mode**: move the mouse; press `J` to lock/unlock
- **Reset**: `R`
- **Exit**: `Esc` or window closed

(Exact keymap may vary; update to match your implementation.)

---

## Math & Coloring

- Escape test with bailout radius `R = 2` (squared radius = 4)
- Smooth iteration count: `nu = i + 1 - log(log|z|)/log 2` for continuous gradients
- Map `nu` to a palette (HSV or gradient table) for banding‑free colour

---

## Author

Mohamed El hammouchi //G1iTch//\
42 Login: mel-hamm

