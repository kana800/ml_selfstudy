#### [Automating C with Makefiles](https://www.youtube.com/watch?v=GExnnTaBELk)

##### [What happens when you compile a `.c` file ?](https://youtu.be/GExnnTaBELk?t=244)

`.c` file will go through a `preprocessor`, which will handle `#include`, `#define`  and strips out comments. After this the **preprocessed file** will go through the `compiler` which will translate the `c` code into `assembly` (`.s` ). This file is goes to the `assembler` which translate the `assembly` to `object file` (`.o`) and finally it will go through the `linker` which bring all the `object files` to produce a executable.

Each of these steps can be invoked. 

- `gcc -E helloworld.c` will go through the `preprocessor` and stop
- `gcc -S helloworld.c` will go through the `compiler` and stop
- `gcc -c helloword.c` will spit out the object file

##### Makefile 

> These notes are from a book called [21st Century C](https://www.oreilly.com/library/view/21st-century-c/9781449344382/)

Makefile is broken into *chunks*, each of these *chunks* are called as *recipes* 

```makefile
P=helloworld
OBJECTS=
CFLAGS = -g -Wall -O3
LDLIBS=
CC=c99

$(P): $(OBJECTS)
```

The above lines are setting variables, The shell and **make** use the `$` to indicate the value of a variable

There are several ways to tell `make` about a variable

- we can sue the export command to export variables and functions to child processes. Instead of having `P=helloworld` in the makefile we can execute `export P=helloworld`. If we need to use these variables repeatedly we can put them in the `.bashrc` file who it will be executed once a new session begins.

- `make` will let you set variables on the command line, independent of the shell. Thus these two lines are close to equivalent.

  > `make CFLAGS="-g -Wall"` Set a makefile variable
  >
  > `CFLAGS="-g -Wall" make` Set an environment variable visible to make and its children

`make` also offers several built-in variables. 

- `$@` The full target filename.
- `$*` The target file with the suffix cut off. If target is `prog.c`, `$*` would be `prog`.
- `$<` The name of the file that caused this target to get triggered and made. If we are making `prog.o`, it is probably because of `prog.c` so the `$<` would give us `prog.c`

> Your turn, create a `makefile` for `erf.c`
>
> ```c
> #include <math.h>
> #include <stdio.h>
> 
> int main() {
>     printf("The intergral of a Normal(0, 1) distribution"
>            "between -1.96 and 1.96 is %g\n", erf(1.96*sqrt(1/2.)));
> }
> ```

```makefile
CFLAGS = -g -Wall -O3
LDLIBS = -lm
CC = c99

make erf:
	$(CC) $@.c -o $@ $(LDLIBS) $(CFLAGS)
```

you can use `pkg-config`(Helps you find the location of the packages) when linking your libraries.

- `CFLAGS='pkg-config --cflags apopphenia glib-2.0' -g -Wall -std=gnu11 -O3 `
- `LDLIBS='pkg-config --libs apophenia glib-2.0'`