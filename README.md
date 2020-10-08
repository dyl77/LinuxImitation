# Linux/Unix Directory Imitation

This is a simple program designed to mimic a simplified version of a linux style file directory.
This program uses traditional, and custom commands found in the linux environment.
This program is made with custom pointer based objects, and commands that perform operations on the structures they're contained in.
You will start with a blank command line, where you should start with creating a directory or file. Do this by using the command mkdir (name) or addf (name).

Commands can be entered in this format: command <modifier1> <modifier2>
Modifiers may or may not be optional based on the command you've chosen, and your command will be sent to the system upon pressing the enter key.
  
## Commands are as follows:
- mkdir <modifier1>: Adds a directory with the name entered for modifier 1
- addf <modifier1> : Adds a file with the name entered for modifier 1.
- pwd : Prints the path to the current directory you are in.
- ls : Lists all availible files and directories in your current directory.
- rm <modifier1> : Deletes a file or directory of name given by modifier 1 and all of it's children. (Must be accessable from your current directory)
- cd <modifier1> : Moves to a directory named by modifier1 if availible from the current directory. To go "up" in directories, two periods ("..") can be entered for modifier 1.
- cp <modifier1> <modifier2> : Copies a file or directory from its current name modifier1 to its new name modifier2, for directories this will also copy children.
- whereis <modifier1> : Searches the entire directory tree for the file name entered for modifier1, and returns its directory path.

Information on usage and documentation will be inserted here when availible.

![UML](/Project1DSA2.png)
