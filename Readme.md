#Push_swap

##Overview
Push_swap is a project designed to sort a stack of integers using a specific set of operations. The goal is to sort the stack with the minimum number of moves possible, using two stacks and a limited set of commands.
Features

-   Implements sorting algorithms optimized for a minimal number of moves.
-   Utilizes two stacks and predefined operations for sorting.
-   Includes an implementation of quick sort to solve the problem.
-   Designed for performance and efficiency in a constrained environment.

##Prerequisites

-   A Unix-like operating system.
-   GCC (GNU Compiler Collection) installed.
-   Basic knowledge of C programming.

##Installation

-   git clone https://github.com/jbettini/Push_swap.git
-   cd Push_swap
-   make

##Usage

Run the compiled executable with a list of integers or just use sh op.sh :
-   ./push_swap <list_of_integers>
-   sh op.sh

###Example:
./push_swap 4 67 3 87 23

##Project Structure

-   src/: Source files.
-   include/: Header files.
-   libft/: Custom library functions.
-   Makefile: Build configuration.