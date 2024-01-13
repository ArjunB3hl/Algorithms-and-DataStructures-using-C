Check the StateMachine.png to check how it works

For StateMachine execute by using the following commandline argument 

gcc -o State simState.c 

You can now run the program with the command:

.\State

and then run commands. Here are the following commands to run

No Commands:

Before any commands are issued to your program, it should print out the starting state.

One/Zero Commands:

These commands (a `0' or a `1' on a line by itself) must print to stdout the name of the next state given the supplied input, and update the current state.

Change command:

The change command is invoked by the letter `c' followed by a `1' or a `0' followed by the name of a state (i.e. a single letter in the range A–H). This command modifies the state machine such that the `0' (or `1') command applied to the current state will cause the machine to change to the named state and that this change is the state machine configuration will continue. This command should produce no output.

Print command:

The print command is invoked with the single letter `p'. It should print to stdout the state machine configuration as currently specified (i.e. including changes that may have been made with change commands) in the same format that your state machine was specified with.

Garbage Identify command:

This command is invoked with the single letter `g'. It should identify all states that are reachable or unreachable from the current state. It always produces output to stdout.

If all states are reachable, it should output No garbage. Otherwise, it should output

Garbage: <unreachable states> where <unreachable states> is the list of the state names that are no longer reachable.

Delete command:

This command is invoked with `d', optionally followed by the name of a state to delete. When the ‘d’ command is invoked without the optional argument, it should delete (i.e. mark as “deleted”) all un-deleted states that are unreachable. If there are no such unreachable un-deleted states, it should print:
