<p align="center">

  <img src="full_colored_light.jpg" width="400\"/>

<br>


<h1><p align="center">A simple shell.</h1></p></font>



Compilation:

``gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh.``

# Testing

Your shell should work like this in interactive mode:

    $ ./hsh
    ($) /bin/ls
    hsh main.c shell.c
    ($)
    ($) exit
    $

Non-interactive mode:

    $ echo "/bin/ls" | ./hsh
    hsh main.c shell.c test_ls_2
    $
    $ cat test_ls_2
    /bin/ls
    /bin/ls
    $
    $ cat test_ls_2 | ./hsh
    hsh main.c shell.c test_ls_2
    hsh main.c shell.c test_ls_2
    $

Files contained and description:

1. builtin.c
    Handles builtin in the shell environment.

2. code.c
    Entry point to the program.

3. env.c 
    Handles envrionment variables

4. path.c
    Handles paths to be executed

5. shell.h
    Contains all Prototypes and struct variables

6. simple_shell.c
    Entry point to the main program.

7. man_3_simple_shell


Team:

*Adeboye Akingbelure* - [Github](https://github.com/Boye111)

*kabingu sammy* - [Github](https://github.com/kabingusam) || [Twitter](https://twitter.com/Kabingusammy)