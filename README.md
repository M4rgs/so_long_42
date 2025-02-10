# So Long - 2D Game

A Simple 2D adventure game where you navigate through a maze-like world, collecting coins and searching for the exit. Built with MiniLibX, this project showcases clean game development practices with a focus on effective resource management and engaging gameplay.

## 🎮 Game Overview

Navigate your character through a grid-based world where every move counts! Your mission is to:
- Collect all coins scattered throughout the level
- Find and reach the exit
- Avoid walls and obstacles
- Complete the level in as few moves as possible

## ✨ Key Features

### Mandatory
- Smooth, responsive controls using WASD or arrow keys
- Dynamic coin collection system
- Victory tracking and move counter
- Intelligent map validation and pathfinding
- Clean, pixel-perfect graphics
- Robust error handling and memory management

## 🚀 Getting Started

### Prerequisites

- MiniLibX library
- X11 (for Linux systems)
- GCC compiler
- Make

### Installation

1. Clone the repository:
```bash
git clone https://github.com/M4rgs/so_long.git
cd so_long
```

2. Compile the game:
```bash
make        # For mandatory part
```

### Running the Game

Launch with any valid map file:
```bash
./so_long maps/level1.ber
```

## 🕹️ Controls

| Key | Action |
|-----|--------|
| W / ↑ | Move up |
| A / ← | Move left |
| S / ↓ | Move down |
| D / → | Move right |
| ESC | Quit game |

## 🗺️ Map Creation

Create your own levels using these tile types:

| Tile | Description |
|------|-------------|
| 1 | Wall |
| 0 | Empty space |
| C | Collectible coin |
| P | Player starting position |
| E | Exit |

### Map Requirements

- Must be rectangular
- Fully enclosed by walls (1)
- Contains exactly one player (P)
- Contains exactly one exit (E)
- Contains at least one collectible (C)
- Must have a valid path to all coins and exit

Example map:
```
111111
1P0C01
10T001
1E0C11
111111
```

## 🏗️ Project Structure

### Mandatory Version (`/src`)
```
src/
├── check.c            # Map && Path validation functions 
├── map.c              # Map loading and processing
├── render.c           # Graphics rendering
├── init.c             # Main program entry
├── include/so_long.h  # Header definitions
└── utils.c            # Helper Functions
```

## 🐛 Error Handling

The game performs extensive validation and will display helpful error messages for:
- Invalid map files or formats
- Memory allocation failures
- Unreachable coins or exits
- Invalid game states

## 📚 Development Notes

This project demonstrates several key programming concepts:
- Dynamic memory management
- Recursive algorithms (flood fill)
- Event-driven programming
- Graphics rendering
- File I/O operations
