# Long-Arithmetic-Lib
## Software requirements
CMake, GoogleTests and at least C++14  

## Software requirements
CMake, GoogleTests and at least C++14  

## Short project description
The project contains 5 different folders:  
1. `include` - the library header is stored here
2. `rc` - stores the library implementation
3. `examples` - stores the main.cpp where you can use the library
4. `tests` - contains the tests using the GoogleTests framework
5. `measurments` - contains the program that I used to measure the average execution time and report file
## Build and Usage

Follow these steps to build and run LongArithmeticLib, including tests and examples:

1. Clone the LongArithmeticLib repository to your local machine:
```bash
https://github.com/prumat4/Long-Arithmetic-Lib.git
```

2. Navigate to the project directory:
```bash 
cd Long-Arithmetic
```

3. Create a build directory:
```bash
mkdir build
cd build
```
   
4. Generate the build system using CMake:
```bash
cmake ..
```

5. Build the library:
```bash
make
```
   
### Run Tests

1. After building the library, you can run the tests using the following command:
```bash
./test/LongArithmeticLibTests
```
   
### Run Example Program

1. Once the library is built, you can run the example program by executing:
```bash
./example/main
```
   This program demonstrates the usage of LongArithmeticLib for long arithmetic operations.

### Usage

To use LongArithmeticLib in your own project, follow these steps:

1. Include the necessary header files in your C++ code:
```c++
#include "Long-Arithmetic/LongNumMod.hpp"
```

2. Link your project with the LongArithmeticLib library:
```cmake
target_link_libraries(YourProjectName LongArithmeticLib)
```

3. Use the provided functions for long arithmetic operations in your code.
