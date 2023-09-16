# Long-Arithmetic

## To do (maybe)
create a script to run build commands automatically 

## Building and running
1. Generate build files 
```
mkdir build
cd build
cmake ..
```

2. Build library
```
cmake --build . --target MyLongArithmeticLib
```

3. Build tests executable 
```
cmake --build . --target test_LongNumber
```

4. To run main.cpp
```
./main
```
