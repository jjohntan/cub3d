```text
 _  _  ____                 _    _____ ____  
| || ||___ \ _    ___ _   _| |__|___ /|  _ \ 
| || |_ __) (_)  / __| | | | '_ \ |_ \| | | |
|__   _/ __/ _  | (__| |_| | |_) |__) | |_| |
   |_||_____(_)  \___|\__,_|_.__/____/|____/    
```

### **Overview**

A pseudo-3D game engine inspired by Wolfenstein 3D.

---

### **Key Learnings**
- Applying mathematical concepts in real code
- Implementing the raycasting rendering technique

---

### **About**

👉 [**Project requirement**](\demo\en.subject.pdf)


A game engine manages the game state, handles keyboard and mouse input, and renders the game scene.
All of these systems are implemented in this project.

What’s interesting is that the “3D” world here isn’t truly 3D.
It’s actually a 2D game that uses the raycasting technique to simulate a 3D environment.

![figure-1](https://github.com/Mecha-Coder/42-cub3D/blob/main/demo/figure-1.png)

Raycasting relies on the DDA (Digital Differential Analyzer) algorithm - trigonometry we used during our school-day, plane projection concepts, and a few assumptions about the 3D world — to render the scene.

Once the 3D walls are rendered, they look flat and dull. To bring them to life, we use texture mapping to paint the walls with detailed textures. 

This project also includes a minimap and sprite animations, including door open/close mechanics for added interactivity

![figure-2](https://github.com/Mecha-Coder/42-cub3D/blob/main/demo/figure-2.png)

![figure-3](https://github.com/Mecha-Coder/42-cub3D/blob/main/demo/figure-3.png)


--- 

### Demo

![demo](https://github.com/Mecha-Coder/42-cub3D/blob/main/demo/demo.gif)

---

### **My contribution**
- Developed the raycasting algorithm
- Prepared assets and handled game initialization after parsing input
- Implemented keyboard and mouse event handling
- Added door open/close mechanics
- Created sprite animations
- Implemented the minimap system

### **Teammate**
- **John Tan** (https://github.com/jjohntan)

---

### **How to run**

System requirement: **Debian/Ubuntu/WSL2**


```bash
# Install dependencies
sudo apt-get install libx11-dev libxext-dev libbsd-dev libxrandr-dev libxfixes-dev

# Clone the repository
git clone https://github.com/Mecha-Coder/42-cub3D
cd 42-cub3D

# Compile the program (bonus version includes minimap and doors)
make bonus

# Launch the program and specify the game map
# Try different maps in the map/good folder
./cub3D ./map/good/cheese_maze.cub

```

---

### **Resource**
- https://permadi.com/1996/05/ray-casting-tutorial-1/
- https://medium.com/@abdelhadi-salah/ray-casting-cub3d-bb5d99de742d
- https://lodev.org/cgtutor/raycasting.html

