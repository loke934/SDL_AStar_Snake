# SDL A* Snake
(Not full project, only scripts).

Since most of the C++ game programming I have done is in Unreal, the aim with this project was to focus on and practice C++ outside of Unreal, 
but still within game development. I also thought it would be fun to do pathfinding and choose the A* algorithm. 
The code is divided and structured after some primary features. 

- Game class that handles the overall state of the game.
- Shape class for rendering and an "engine" class for handling time and the SDL setup.
- Grid-based movement, with a grid cell class that stores information needed for pathfinding etc.
- Finding the shortest path to a target with A*, using heap sort. 
- Growing snake with a linked-list approach. 

![DrawPath](https://user-images.githubusercontent.com/76095991/204778272-fbc30ddc-b492-4666-a582-5e3459d3711b.png)

Found path to target, outlined in light-purple.

![LongSnake](https://user-images.githubusercontent.com/76095991/204779115-30e5fe83-c9af-4539-bef3-435d068ec8b6.gif)
