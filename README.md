# Object_Files_Tutorial_343

A demonstration of compilation into object files first and linking into an executable.

## Steps

To see how we can compile files separately and then link them, first clone the project.  Once this is done you may perform the following steps.

### Overview

The code shows us how to create a (very) simple library that we can use in a banking system.  This library is code that might be used in a variety of applications around our banking office, so we don't want to have generic code that could be used elsewhere mixed in with code for a specific application.  Instead, we want each specific application to include our code when they need it.  This is what we do with standard libraries like stdio; there is no reason to rewrite this library code for every application.  We merely need to include when we wish to use it.

### Different Types of Libraries

The process of including other code libraries into our own code is called "linking".  We can either link library code to our code Statically or Dynamically.  If we link statically the entirety of the library code is included in our final executable.  This means that our final executable can run stand-alone on any compatible system without worry of missing libraries, but it also means that our final executable is larger than it needs to be.  By linking dynamically we can keep the size of our executable small, but we have to trust that users have the required libraries on their systems, or know how to install them.  This is rarely a problem for libraries like stdio.h or stdlib.h which are standard on most systems we compile for.

### Compiling

We write our code in *.c files.  To turn these *.c files into code the computer can execute we compile our code.  The process of compilation is sometimes confusing for students, because we usually see an input phase of a file or files and an output of a single executable.  What gets lost in this process is the linking.  We tend to think of the compilation process as the process which creates the executable, but this isn't really the case.  What really happens is more like this:

- The compiler compiles each of our *.c files separately
	- This means that the compiler needs to know if we are using a function or data type correctly so it can warn us of any problems.
	- *.h files (header files) tell the compiler about function descriptions, data structures, etc. that are not defined in our current *.c file.  This gives the compiler the chance to check our syntax and ensure we are using these entities correctly. 
	- If our code is compilable it will be turned into object files (*.o).
	- The linker links the object files together either statically or dynamically and produces an executable.

We can view this process more closely by asking the compiler to create the object files but skip the linking phase.

### Exercise

At this point you should have cloned this project.  Navigate into the project directory and do the following:

```
clang -c library.c
```

The ```-c``` flag tells the compiler to compile only; no linking is performed.  You should now have a ```library.o``` file in your directory.  This is the compiled object file for the code from ```library.c```.  Similarly, execute the following command:

```
clang -c banking.c
```

You should now have a ```banking.o``` object file for the banking.c code.  Both files of *.c code have now been compiled.  Each file was compiled without the other files code, yet the compiler could tell us of any errors in usage due to the fact that we included the header (*.h) file.

Now, we can complete the process.  If we run the command

```
clang -o banking_app banking.o library.o
```

an executable will be created by linking the object files.  This executable, called ```banking_app``` may be run with the command

```
./banking_app
```
