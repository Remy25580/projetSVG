# SVG Project

## Overview

SVG Project is a C-based editor capable of creating, editing, styling, saving, loading, and visualizing SVG shapes.  
It allows users to generate valid SVG files and manipulate graphical elements entirely from the command line using structured and modular C code.

The program manages a complete list of SVG objects, supports saving and reloading from text-based files, and can export valid SVG structures.

---

## Main Features

### Shapes that can be created
- **Rectangle**
- **Square**
- **Circle**
- **Ellipse**
- **Line**
- **Polyline**
- **Polygon**
- **Path**

### Editing & Styling
- Modify or move shapes by coordinates  
- Change fill and stroke colors  
- Apply rotation and transformations  
- Invert the shapes from x-axis or y-axis 

### File Management
- Save all shapes to a text file  
- Load shapes from a previous save   

### Visualization
- Clean visualization of your shapes in the powershell

---

## Compilation and Execution

The project includes a **Makefile** for easy build automation.

### Commands
```bash
# Build the project
make build

# Run the program
./main

# Clean object files
make clean
