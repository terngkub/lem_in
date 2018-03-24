# lem_in
École 42 assignment in C - graph data structure, shortest path algorithm

### About the project
* This is an individual/group project at [École 42](https://42.fr). I choosed to do it alone because the project isn't that big.
* The project objective is to move all the ants from the start to the end.

* All the ants will start at the start room. Other room than start and end room can only have one ant at a time.
* The input is in text format.
  * number of ants
  * rooms (room under ##start will be a start room and ##end will be an end room)
  * links
  * ![map](/screenshot/map.png?raw=true)
* From above input, we can visualize it as below graph.
![graph](/screenshot/graph.png?raw=true)
* The program will calculate how to move ants each turn and output it line by line. It will tell ant number (for example, L1 is ant number 1) and the room name that this ant went in this turn. 
![output](/screenshot/output.png?raw=true)
* I created 4 bonus flag to make it easier to debug the program.
  * flag p - show possible paths
    * ![flag_p](/screenshot/flag_p.png?raw=true)
  * flag a - show amount of allocated ants in each path
    * ![flag_a](/screenshot/flag_a.png?raw=true)
  * flag c - show the color of each paths
    * ![flag_c](/screenshot/flag_c.png?raw=true)
  * flag k - show the color of each ants
    * ![flag_k](/screenshot/flag_k.png?raw=true)
  * flags can be combined together in any combinations
    * ![flag_pack](/screenshot/flag_pack.png?raw=true)

### How to run the program
* Run Makefile to create an executable file called lem-in.
  ```
  make
  ```
* The command to run the program is
  ```
  ./lem-in [flag -p|a|c|k]] < [map file]
  ```
  for example:
  ```
  ./lem-in -pa < map
  ```
  
### The algorithm I used
* I used breadth-first search to find the shortest path.
* Then, I block that path and use breadth-first seach to found another shortest path.
* I block and run breadth-first search again and again until there is no path left.
* After that, I allocate the ants to each paths to make it fastest to go from a start room to an end room.
