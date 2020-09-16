# 0x18. C - Stacks, Queues - LIFO, FIFO

This project explores the concepts of stacks (LIFO) and queues (FIFO) through the lens of a Monty 0.98 bytecode interpreter.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

You should install the following to get this project up and running. This program has only been tested on Ubuntu 14.04 LTS using `gcc 4.8.4` compiled with `-Wall -Werror -Wextra and -pedantic` flags.

```
$ gcc --versiong
  gcc version 4.8.4
```

### Installing

Building and installing this Monty interpreter is simple. 

Start by cloning the repo from github into your desired directory.

```
$ git clone https://github.com/Haroldov/monty.git
```

Next, build the files using `gcc`.

```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

After the program has been compiled, you can run it using a monty file as an argument.

```
$ cat -e a_monty_file.m
push 1$
push 2$
push 3$
pall$
$ ./monty a_monty_file.m
3
2
1
```

## Authors

Haroldo Vélez - [Haroldov](https://github.com/Haroldov)

Ryan Hudson - [ryanhudson](https://github.com/ryanhudson)
