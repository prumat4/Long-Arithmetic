# Long-Arithmetic-Lib

##Build and Usage

Follow these steps to build and run LongArithmeticLib, including tests and examples:

1. Clone the LongArithmeticLib repository to your local machine:

   git clone <repository_url>

2. Navigate to the project directory:

   cd LongArithmeticLib

3. Create a build directory:

   mkdir build
   cd build

4. Generate the build system using CMake:

   cmake ..

5. Build the library:

   cmake --build .

Run Tests

1. After building the library, you can run the tests using the following command:

   ./test/LongArithmeticLibTests

Run Example Program

1. Once the library is built, you can run the example program by executing:

   ./example/main

   This program demonstrates the usage of LongArithmeticLib for long arithmetic operations.

Usage

To use LongArithmeticLib in your own project, follow these steps:

1. Include the necessary header files in your C++ code:

   #include "LongArithmeticLib/add.hpp"
   #include "LongArithmeticLib/subtract.hpp"

2. Link your project with the LongArithmeticLib library:

   target_link_libraries(YourProjectName LongArithmeticLib)

3. Use the provided functions for long arithmetic operations in your code.

For detailed documentation on the available functions and their usage, refer to the comments in the header files.

License

This project is licensed under the MIT License - see the LICENSE file for details.
