The Game of Fifteen is a puzzle played on a square, two-dimensional board with numbered tiles that slide. The goal of this puzzle is to arrange the board’s tiles from smallest to largest, left to right, top to bottom, with an empty space in board’s bottom-right corner, as in the below.

Game of Fifteen

Sliding any tile that borders the board’s empty space in that space constitutes a "move." Although the configuration above depicts a game already won, notice how the tile numbered 12 or the tile numbered 15 could be slid into the empty space. Tiles may not be moved diagonally, though, or forcibly removed from the board.

Although other configurations are possible, we shall assume that this game begins with the board’s tiles in reverse order, from largest to smallest, left to right, top to bottom, with an empty space in the board’s bottom-right corner. If, however, and only if the board contains an odd number of tiles (i.e., the height and width of the board are even), the positions of tiles numbered 1 and 2 must be swapped, as in the below. The puzzle is solvable from this configuration.

solvable configuration

Distribution

Downloading
$ wget https://github.com/cs50/problems/archive/fifteen.zip
$ unzip fifteen.zip
$ rm fifteen.zip
$ mv problems-fifteen fifteen
$ cd fifteen
$ ls
Makefile    fifteen.c   questions.txt
Understanding
Take a look at fifteen.c. Within this file is an entire framework for the Game of Fifteen. The challenge up next is to complete this game’s implementation.

But first go ahead and compile the framework. (Can you figure out how?) And, even though it’s not yet finished, go ahead and run the game. (Can you figure out how?) Odds are you’ll want to run it in a larger terminal window than usual, which you can open clicking the green plus (+) next to one of your code tabs and clicking New Terminal. Alternatively, you can full-screen the terminal window toward the bottom of CS50 IDE’s UI (within the UI’s "console") by clicking the Maximize icon in the console’s top-right corner.

Anyhow, it appears that the game is at least partly functional. Granted, it’s not much of a game yet. But that’s where you come in!

Checking for Understanding
Read over the code and comments in fifteen.c and then answer the questions below in questions.txt, which is a (nearly empty) text file that we included for you inside of the distribution’s fifteen directory. No worries if you’re not quite sure how fprintf or fflush work; we’re simply using those to automate some testing.

Besides 4 × 4 (which are Game of Fifteen’s dimensions), what other dimensions does the framework allow?

With what sort of data structure is the game’s board represented?

What function is called to greet the player at game’s start?

What functions do you apparently need to implement?

Specification

Implement the Game of Fifteen, per the comments in fifteen.c.

Implement init.

Implement draw.

Implement move.

Implement won.
