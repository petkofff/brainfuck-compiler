# brainfuck-compiler

Brainfuck compiler that uses double-ended vector.

## Clone and compile `bfc`

```
$ git clone https://github.com/petkofff/brainfuck-compiler.git
$ cd brainfuck-compiler
$ make
```

## Compile an example

```
$ ./bfc -i examples/helloworld.bf -o examples/helloworld
$ ./examples/helloworld
Hello World!
```

## How does it work?

`bfc` generates a .cpp file, which gets compiled to binary with `g++`.
