/* Text Maze 3D
 * by Neil Roy
 *
 * Created in January, 2016, for old time sake. :)
 *
 * I tried to keep this cross platform compatible, but certain commands are more windows, this can't be helped.
 * If you wish to compile this on a non-windows system, just replace the system() call (to clear the screen) as
 * well as _getch() from conio.h may also have to be changed, it provides unbuffered input, and there isn't a 
 * cross-platform way to do this without using something like ncurses or SDL.  Just search and replace these if
 * you wish, there's only a couple instances of it.  You could use buffered input, I just preferred unbuffered.
 * This was originally compiled in C++14 (though I don't know if I used any C++14 specific  things in this,
 * this will probably compile without problems on ordinary, older C++).  
 * I added in *WIN32* next to everything that has Windows specific code, so if you search for "*WIN32*" you will
 * more easily be able to find and replace this Windows specific code.
 *
 * I am releasing this code for educational purposes (if you think you can learn from my code that is).
 */

#include <iostream>
#include <string>
#include <ctime>
#include <random>
#include <stdio.h>

#define MAZE_SIZE_X 20
#define MAZE_SIZE_Y 11
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

using namespace std;

struct Player
{
    int x, y; // Location in the maze
    int dir;  // direction player is facing (North, South, East or West)
};

struct Maze
{
    int n, s, e, w; // The four exits from each room, set to 1 if there is an exit in that direction, 0 if not.
    int isEntrance; // is this the entrance to the maze (not used yet, I may change this to an external variable)
    int isExit;     // is this the exit to the maze (not used yet, I may change this to an external variable)
    int visited;    // This is used when the maze is generated, and whether the player has been here when drawing the map
};

void drawHall(Maze maze[MAZE_SIZE_Y][MAZE_SIZE_X], const Player &player);
void generateMaze(Maze maze[MAZE_SIZE_Y][MAZE_SIZE_X], Player &player);
void drawMap(Maze maze[MAZE_SIZE_Y][MAZE_SIZE_X], Player &player);

int main(int arc, char **argv)
{
    unsigned char command = 0;
    Maze maze[MAZE_SIZE_Y][MAZE_SIZE_X] = {};
    Player player;
    srand((unsigned int)time(0));

    player.x = 0;
    player.y = 0;
    player.dir = EAST;

    generateMaze(maze, player);

    while (command != 27)
    { // Loop until ESC key (#27) is pressed
        drawHall(maze, player);
        cout << " COMMAND > ";
        command = getchar(); // *WIN32* unbuffered input, non-windows machines may have to change this

        // Characters 32 (space) to 127 are normal, printable ASCII characters
        if (command > 32 && command < 127)
            cout << command << endl;

        // When a special key, like a cursor key is pressed, two characters are sent,
        // first a zero or 224 to indicate a special command follows.
        // Then the code for teh command.  So if the first character you get is zero or
        // 224, than you immediately do another _getch() to get the next character which will
        // be waiting to be retrieved.  You can then act on it as you will see below.
        if (command == 0 || command == 224)
        { // special key pressed (cursor etc)
            command = getchar();

            switch (command)
            {
            case 77: // Right Arrow Key (turn right)
                cout << "Turn Right\n";
                player.dir++;
                if (player.dir > 3)
                    player.dir = 0;
                break;
            case 75: // Left Arrow Key (turn left)
                cout << "Turn Left\n";
                player.dir--;
                if (player.dir < 0)
                    player.dir = 3;
                break;
            case 72: // Up Arrow Key (move forward)
                cout << "Move Forward\n";
                switch (player.dir)
                {
                case NORTH:
                    if (player.y > 0 && maze[player.y][player.x].n)
                        player.y--;
                    break;
                case EAST:
                    if ((player.x < MAZE_SIZE_X - 1) && maze[player.y][player.x].e)
                        player.x++;
                    break;
                case SOUTH:
                    if ((player.y < MAZE_SIZE_Y - 1) && maze[player.y][player.x].s)
                        player.y++;
                    break;
                case WEST:
                    if (player.x > 0 && maze[player.y][player.x].w)
                        player.x--;
                    break;
                }
                break;
            case 80: // Down Arrow Key (move backward)
                cout << "Move Backward\n";
                switch (player.dir)
                {
                case NORTH:
                    if ((player.y < MAZE_SIZE_Y - 1) && maze[player.y][player.x].s)
                        player.y++;
                    break;
                case EAST:
                    if (player.x > 0 && maze[player.y][player.x].w)
                        player.x--;
                    break;
                case SOUTH:
                    if (player.y > 0 && maze[player.y][player.x].n)
                        player.y--;
                    break;
                case WEST:
                    if ((player.x < MAZE_SIZE_X - 1) && maze[player.y][player.x].e)
                        player.x++;
                    break;
                }
                break;
            }
        }
        else if (command == 'm')
        { // map
            drawMap(maze, player);
            cout << "\n Press ANY KEY To Continue";
            command = getchar(); // *WIN32*
            cout << endl;
        }
    }

    return 0;
}

void drawHall(Maze maze[MAZE_SIZE_Y][MAZE_SIZE_X], const Player &player)
{
    int wall = 0;
    int e1 = 0, e2 = 1;
    int exit[6] = {0, 0, 0, 0, 0, 0};
    int posy = player.y;
    int posx = player.x;

    // Any part of the hall that we can see, will be marked as "visited" for map drawing purposes
    // after all, if we can see the hall, than obviously we know the exits off of it without
    // having to actually enter those areas.  This will only mark halls we are actually looking
    // at as seen though.  To have them appear on the map, you have to turn around and look down
    // that hall, which makes perfect sense.
    maze[player.y][player.x].visited = 1; // Mark current location visited

    // TODO: The code below looks repetative, I need to improve it.

    switch (player.dir)
    {
    case NORTH:
        exit[e1] = maze[posy][posx].w;
        exit[e2] = maze[posy][posx].e;
        while (maze[posy][posx].n && wall < 3)
        {
            posy--;
            if (posy >= 0)
            {
                wall++;
                if (wall < 3)
                {
                    maze[posy][posx].visited = 1; // Mark location as visited as we can see it, so we know the hall layout
                    e1 += 2;
                    e2 += 2;
                    exit[e1] = maze[posy][posx].w;
                    exit[e2] = maze[posy][posx].e;
                }
            }
        }
        break;
    case EAST:
        exit[e1] = maze[posy][posx].n;
        exit[e2] = maze[posy][posx].s;
        while (maze[posy][posx].e && wall < 3)
        {
            posx++;
            if (posx < MAZE_SIZE_X)
            {
                wall++;
                if (wall < 3)
                {
                    maze[posy][posx].visited = 1; // Mark location as visited as we can see it, so we know the hall layout
                    e1 += 2;
                    e2 += 2;
                    exit[e1] = maze[posy][posx].n;
                    exit[e2] = maze[posy][posx].s;
                }
            }
        }
        break;
    case SOUTH:
        exit[e1] = maze[posy][posx].e;
        exit[e2] = maze[posy][posx].w;
        while (maze[posy][posx].s && wall < 3)
        {
            posy++;
            if (posy < MAZE_SIZE_Y)
            {
                wall++;
                if (wall < 3)
                {
                    maze[posy][posx].visited = 1; // Mark location as visited as we can see it, so we know the hall layout
                    e1 += 2;
                    e2 += 2;
                    exit[e1] = maze[posy][posx].e;
                    exit[e2] = maze[posy][posx].w;
                }
            }
        }
        break;
    case WEST:
        exit[e1] = maze[posy][posx].s;
        exit[e2] = maze[posy][posx].n;
        while (maze[posy][posx].w && wall < 3)
        {
            posx--;
            if (posx >= 0)
            {
                wall++;
                if (wall < 3)
                {
                    maze[posy][posx].visited = 1; // Mark location as visited as we can see it, so we know the hall layout
                    e1 += 2;
                    e2 += 2;
                    exit[e1] = maze[posy][posx].s;
                    exit[e2] = maze[posy][posx].n;
                }
            }
        }
        break;
    }

    // This is out BASE hall image.  We alter it after this with replace() commands to add in lines
    // for the side halls, turns etc.  The R"( and )" at either end of these strings tell it that
    // this is a literal string, there will be no commands like \n etc.
    string hall3D[23] = {
        R"( +-----------------------------------------+)",
        R"( | \_                                   _/ |)",
        R"( |   \_                               _/   |)",
        R"( |     \_____________________________/     |)",
        R"( |      |\_                       _/|      |)",
        R"( |      |  \_                   _/  |      |)",
        R"( |      |    \_________________/    |      |)",
        R"( |      |     |\_           _/|     |      |)",
        R"( |      |     |  \_________/  |     |      |)",
        R"( |      |     |   |\     /|   |     |      |)",
        R"( |      |     |   |       |   |     |      |)",
        R"( |      |     |   |       |   |     |      |)",
        R"( |      |     |   |       |   |     |      |)",
        R"( |      |     |   |/     \|   |     |      |)",
        R"( |      |     | _/         \_ |     |      |)",
        R"( |      |     |/             \|     |      |)",
        R"( |      |   _/                 \_   |      |)",
        R"( |      | _/                     \_ |      |)",
        R"( |      |/                         \|      |)",
        R"( |    _/                             \_    |)",
        R"( |  _/                                 \_  |)",
        R"( |_/                                     \_|)",
        R"( +-----------------------------------------+)"};

    switch (wall)
    {
    case 0: // Closest wall
        // erase the middle and end parts of the hall
        for (int i = 4; i <= 17; i++)
            hall3D[i].replace(9, 27, "                           ");
        // and draw a line near the floor, close up to form a close wall
        hall3D[18].replace(9, 27, "___________________________");
        break;
    case 1: // Middle wall
        // like the close wall, only we just erase the far end section.
        for (int i = 7; i <= 14; i++)
            hall3D[i].replace(15, 15, "               ");
        // we draw a line on the floor at the end of the middle to complete a wall.
        hall3D[15].replace(15, 15, "_______________");
        break;
    case 2: // Far wall
        // Erase  the very last little bit at the very end of the hall
        for (int i = 9; i <= 12; i++)
            hall3D[i].replace(19, 7, "       ");
        // and draw a line on the floor to indicate a wall at the end
        hall3D[13].replace(19, 7, "_______");
        break;
    default: // Wall 3+ away are out of sight, don't draw them.
        break;
    }

    // This is all the side halls, from the closest to the fathest,
    // we draw in wall lines for each hall and erase the angles lines near the floor.
    // Left close exit
    if (exit[0])
    {
        hall3D[3].replace(2, 5, "_____");
        hall3D[18].replace(2, 6, "______");
        hall3D[19].replace(6, 2, "  ");
        hall3D[20].replace(4, 2, "  ");
        hall3D[21].replace(2, 2, "  ");
    }

    // Right close exit
    if (exit[1])
    {
        hall3D[3].replace(38, 5, "_____");
        hall3D[18].replace(37, 6, "______");
        hall3D[19].replace(37, 2, "  ");
        hall3D[20].replace(39, 2, "  ");
        hall3D[21].replace(41, 2, "  ");
    }

    if (wall > 0)
    {
        // Left middle exit
        if (exit[2])
        {
            for (int i = 5; i <= 17; i++)
                hall3D[i].replace(9, 1, "|");
            hall3D[6].replace(10, 3, "___");
            hall3D[15].replace(10, 4, "____");
            hall3D[16].replace(12, 2, "  ");
            hall3D[17].replace(10, 2, "  ");
        }
        // Right middle exit
        if (exit[3])
        {
            for (int i = 5; i <= 17; i++)
                hall3D[i].replace(35, 1, "|");
            hall3D[6].replace(32, 3, "___");
            hall3D[15].replace(31, 4, "____");
            hall3D[16].replace(31, 2, "  ");
            hall3D[17].replace(33, 2, "  ");
        }
    }

    if (wall > 1)
    {
        // Left far exit
        if (exit[4])
        {
            for (int i = 8; i <= 14; i++)
                hall3D[i].replace(15, 1, "|");
            hall3D[8].replace(16, 1, "_");
            hall3D[13].replace(16, 2, "__");
            hall3D[14].replace(16, 2, "  ");
        }
        // Right far exit
        if (exit[5])
        {
            for (int i = 8; i <= 14; i++)
                hall3D[i].replace(29, 1, "|");
            hall3D[8].replace(28, 1, "_");
            hall3D[13].replace(27, 2, "__");
            hall3D[14].replace(27, 2, "  ");
        }
    }

    // Windows console clear screen command, non-windows will have to change this
    system("cls"); // *WIN32* - Note: Linux systems can probably print ANSI codes to achieve the same effect
                   // ANSI code to clear the screen is "\e[2J".
                   // ANSI to move cursor to home (upper left corner) is "\e[H".

    // Now that we altered our hall, we can draw the entire thing
    for (int i = 0; i < 23; i++)
        cout << hall3D[i] << endl;
}

void generateMaze(Maze maze[MAZE_SIZE_Y][MAZE_SIZE_X], Player &player)
{
    // The following code generates a maze using the depth-first search algorithm (using backtracking)
    // It is a nice little algorithm, but it produces long halls, so I plan to change it to
    // something like "Prim's Randomized Algorithm" which produces more interesting halls.

    // Location struct
    struct Location
    {
        int x, y;
    };
    Location loc = {MAZE_SIZE_X / 2, MAZE_SIZE_Y / 2}; // Set our starting location to center of map.

    // We'll store a history of visited locations with unvisited paths here
    vector<Location> history;

    // We'll loop as long as there is a valid location to visit in the history stack
    do
    {
        maze[loc.y][loc.x].visited = 1;
        vector<char> check;
        if (loc.x > 0 && maze[loc.y][loc.x - 1].visited == 0)
            check.push_back('W'); // Check west exit.
        if (loc.y > 0 && maze[loc.y - 1][loc.x].visited == 0)
            check.push_back('N'); // Check north exit.
        if (loc.x < (MAZE_SIZE_X - 1) && maze[loc.y][loc.x + 1].visited == 0)
            check.push_back('E'); // Check east exit.
        if (loc.y < (MAZE_SIZE_Y - 1) && maze[loc.y + 1][loc.x].visited == 0)
            check.push_back('S'); // Check south exit.

        if (check.size())
        {                                                      // If there were unvisited exits available
            history.push_back(loc);                            // add the current location to the history stack
            char moveDirection = check[rand() % check.size()]; // Randomly pick one of the available directions
            switch (moveDirection)
            {
            case 'W':
                maze[loc.y][loc.x].w = 1; // Mark west path open
                loc.x--;                  // move west one cell
                maze[loc.y][loc.x].e = 1; // mark east path of new cell open
                break;
            case 'N':
                maze[loc.y][loc.x].n = 1; // Mark north path open
                loc.y--;                  // move north one cell
                maze[loc.y][loc.x].s = 1; // mark south path of new cell open
                break;
            case 'E':
                maze[loc.y][loc.x].e = 1; // Mark east path open
                loc.x++;                  // move east one cell
                maze[loc.y][loc.x].w = 1; // mark west path of new cell open
                break;
            case 'S':
                maze[loc.y][loc.x].s = 1; // Mark south path open
                loc.y++;                  // move south one cell
                maze[loc.y][loc.x].n = 1; // mark north path of new cell open
            }
        }
        else
        { // If there are no valid cells to move to.
            // retrace one step back in history if no move is possible
            loc.x = history.back().x; // Grab the last x co-ordinate off the history stack
            loc.y = history.back().y; // Grab the last y co-ordinate off the history stack
            history.pop_back();       // Remove the last co-ordinate off the history stack (dead end)
        }
    } while (history.size()); // Continue until we have no more locations to visit (back at the start)

    // Open the walls at the start and finish
    maze[0][0].isEntrance = 1;
    maze[MAZE_SIZE_Y - 1][MAZE_SIZE_X - 1].isExit = 1;

    // Reset visited flag so we can use it to draw our map
    for (int y = 0; y < MAZE_SIZE_Y; y++)
        for (int x = 0; x < MAZE_SIZE_X; x++)
            maze[y][x].visited = 0;

    // Set player starting position and direction
    player.x = 0;
    player.y = 0;
    if (maze[0][0].e)
        player.dir = EAST;
    else
        player.dir = SOUTH;
}

void drawMap(Maze maze[MAZE_SIZE_Y][MAZE_SIZE_X], Player &player)
{
    system("cls"); // *WIN32*
    for (int y = 0; y < MAZE_SIZE_Y; y++)
    {
        for (int r = 0; r < 2; r++)
        {
            for (int x = 0; x < MAZE_SIZE_X; x++)
            {
                char mark = ' ';
                if (player.y == y && player.x == x)
                {
                    // This draws where we are in the maze and the direction we are facing
                    switch (player.dir)
                    {
                    case NORTH:
                        mark = '^';
                        break;
                    case EAST:
                        mark = '>';
                        break;
                    case SOUTH:
                        mark = 'V';
                        break;
                    case WEST:
                        mark = '<';
                    }
                }
                char N1 = ' ', N2 = ' ';
                switch (r)
                {
                case 0:
                    // North
                    if (x)
                    {
                        if (maze[y][x].visited || maze[y][x - 1].visited)
                            N1 = '+';
                        if (y)
                        {
                            if (maze[y - 1][x].visited || maze[y - 1][x - 1].visited)
                                N1 = '+';
                        }
                    }
                    else
                        N1 = '+';

                    if (y)
                    {
                        if (maze[y][x].visited && !maze[y][x].n)
                            N2 = '-';
                        if (maze[y - 1][x].visited && !maze[y - 1][x].s)
                            N2 = '-';
                    }
                    else
                    {
                        N1 = '+';
                        N2 = '-';
                    }
                    cout << N1 << N2;
                    break;
                case 1:
                    // West
                    if (x > 0)
                    {
                        if (!maze[y][x].w && maze[y][x].visited)
                            cout << '|' << mark;
                        else if (!maze[y][x - 1].e && maze[y][x - 1].visited)
                            cout << '|' << mark;
                        else
                            cout << ' ' << mark;
                    }
                    else
                        cout << '|' << mark;
                    break;
                }
            }
            if (r)
                cout << "|\n";
            else
                cout << "+\n";
        }
    }
    for (int x = 0; x < MAZE_SIZE_X; x++)
        cout << "+-";
    cout << '+';
}