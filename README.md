## csvlib

A C++ static library to handle csv files and the data. It provides the basic features of pandas Python library. Currently supported on Linux.

### Integration

Refer to below steps to use this library:

1. ```git clone https://github.com/hrishibawane/csvlib.git```
2. ```cd csvlib```
3. ```make build```
4. Now, ```csv.hpp``` is the **single required header file** for usage.

### Usage

- Inclusion:

```cpp
#include <csvlib/src/csv.hpp>

// for convenience
using namespace hcsv;
```

### Compilation

1. ```g++ <file_name>.cpp -c```
2. ```g++ <file_name>.o -lcsv``` (Optional -o <executable_name>).
3. Run the generated executable.

