# newcpp

`newcpp` is a command line tool to create a new C++ project.

It creates a new directory with the given project name and initializes a git repository. It also creates a `README.md` file with the project name and a `main.cpp` file with a simple hello world program.

## usage

```sh
% newcpp
Usage: newcpp <project-name>
```

```sh
newcpp % newcpp project-1
Initialized empty Git repository project-1/.git/
[main (root-commit) cf1f0eb] Initial commit
 3 files changed, 32 insertions(+)
 create mode 100644 .gitignore
 create mode 100644 README.md
 create mode 100644 main.cpp
Created new C++ project 'project-1'
cd into 'project-1' to get started
§
```

## details

This implementation:

- Uses modern C++ features like the filesystem library
- Creates the project directory
- Creates README.md with basic project information
- Creates a simple main.cpp with a "Hello, World!" program
- Creates a .gitignore file with common C++ ignores
- Initializes a git repository and makes an initial commit
- Includes basic error handling
- Uses system() for git operations (note: this is a simple approach; for a more robust solution, you might want to use libgit2 or similar)

The program checks for:

- Correct number of command line arguments
- Directory existence
- File operation errors

You could extend this by:

- Adding command line options for different project templates
- Creating more sophisticated project structures
- Adding CMake configuration
- Adding license file generation
- Adding dependency management setup
- Using a proper git library instead of system() calls
- Adding more error handling and validation
