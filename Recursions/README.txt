Create the executable towers with the command:
gcc -o towers towers.c towersMain.c
You can now run the program with the command:
towers

The program behaves as follows depending on the arguments given on the command line:
No arguments
If no arguments are given, the problem is solved for moving 3 disks from Tower 1 to
Tower 2.
One argument (numberDisks)
If only one argument is given, the problem is solved for moving numberDisks disks
from Tower 1 to Tower 2.
Three arguments (numberDisks fromID toID)
If all three arguments are given, the problem is solved for moving numberDisks
disks from Tower fromID to Tower toID. The tower IDs must be either '1', '2' or '3'
and the two IDs must be different. 