# SkyProcessor hallway demo

Minimal raylib prototype with flying controls, hallway grids, wall notes, and a small choice table.

## Build (macOS, real raylib)
1) Install raylib (Homebrew): `brew install raylib`
2) Compile:  
   `g++ -std=c++17 main.cpp -o skyproc -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib -framework Cocoa -framework IOKit -framework CoreVideo -framework OpenGL`
3) Run: `./skyproc`

## Build with bundled stub (no raylib installed)
```
g++ -std=c++17 main.cpp raylib_stub.cpp -o skyproc_stub
./skyproc_stub
```
(Stub uses no-op rendering—use only for quick sanity checks.)

## Double-click runner (stub)
1) Make the script executable once: `chmod +x run_stub.command`
2) Double-click `run_stub.command` in Finder; it opens Terminal, compiles with the stub, and runs the app window.

## Controls
- `WASD` move, mouse look, `Space` up, `Shift` down
- `/` start typing a note, `Enter` pin to wall, `Esc` cancel
- Notes save to `notes.json`

## Web/mobile preview (touch sticks)
- Open `web.html` in a modern browser (or host locally). Uses Three.js via CDN.
- Left stick: movement. Right stick: look. Button bottom-right: add note (opens mini input).
- Pointer lock is requested on click for desktop mouse look.
