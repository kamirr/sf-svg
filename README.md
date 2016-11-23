# SF-Curves
SFML-based library to draw curves.

## What it does:
- Classes inherit sf::Shape;
- Implements Square- and Cubic curves;
- Provides interface for Bézier curves;
- Provides debug-friendly features like "helper lines" etc.

## What it lacks (yet):
- Curves other than Bézier ones;
- Some parts of documentation.

## Documentation
You can find docs [here](https://koczurekk.github.io/SF-Curves/).<br />
Generated using doxygen, It's not good-looking, but I don't have time to change doxygen's .css files.

## Usage:
### Compilation
```
$ git clone https://github.com/KoczurekK/sf-curves.git
$ cd sf-curves
$ qmake curves-shared.pro
$ make
```
### Installation & usage
Copy SFC headers to /usr/include/SFC or to any other path supported on your OS. Then copy .so files wherever you want to and remember to pass linker option -lsfcurves.
