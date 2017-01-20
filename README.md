# TastyLib

TastyLib is a c++ library of data structures and algorithms.

It is also a **header-only** library, which means that you could just copy the `include/tastylib` directory to your project's include path and use it without caring about the issues related to link libraries.

## Build Status

| Linux | Windows | Coverage |
|:-----:|:-------:|:--------:|
|[![Build Status](https://travis-ci.org/stevennL/TastyLib.svg?branch=master)](https://travis-ci.org/stevennL/TastyLib)|[![Build Status](https://ci.appveyor.com/api/projects/status/kbpwdij5qpyw2vs7?svg=true)](https://ci.appveyor.com/project/stevennL/tastylib)|[![Coverage Status](https://coveralls.io/repos/github/stevennL/TastyLib/badge.svg?branch=master)](https://coveralls.io/github/stevennL/TastyLib?branch=master)|

## Outline

Contents below show the data structures and algorithms available in this project. Just click the links at the `name` column to see the details of their usages and benchmarks.

### Data Structures

| Name | Source | Benchmarked | Note | Reference |
|:----:|:------:|:-----------:|------|-----------|
|[DoublyLinkedList](#doublylinkedlist)|[Unit test](./test/test_DoublyLinkedList.cpp)<br />[DoublyLinkedList.h](./include/tastylib/DoublyLinkedList.h)|:heavy_check_mark:|A linked data structure that consists of a set of sequentially linked records. It also supports merge sort.|[Wikipedia](https://en.wikipedia.org/wiki/Doubly_linked_list)|
|[BinaryHeap](#binaryheap)|[Unit test](./test/test_BinaryHeap.cpp)<br />[BinaryHeap.h](./include/tastylib/BinaryHeap.h)|:heavy_check_mark:|A heap data structure taking the form of a complete binary tree. A common way of implementing [priority queue](https://en.wikipedia.org/wiki/Priority_queue).|[Wikipedia](https://en.wikipedia.org/wiki/Binary_heap)|
|[HashTable](#hashtable)|[Unit test](./test/test_HashTable.cpp)<br />[HashTable.h](./include/tastylib/HashTable.h)|:heavy_multiplication_x:|A data structure that stores unique elements in no particular order, and which allows for fast retrieval of individual elements based on their values. Similar to [std::unordered_set](http://www.cplusplus.com/reference/unordered_set/unordered_set).|[Wikipedia](https://en.wikipedia.org/wiki/Hash_table)|

### Algorithms

| Name | Source | Benchmarked | Note | Reference |
|:----:|:------:|:-----------:|------|-----------|
|[MD5](#md5)|[Unit test](./test/test_MD5.cpp)<br />[MD5.h](./include/tastylib/MD5.h)|:heavy_check_mark:|A widely used hash function producing a 128-bit hash value.|[Wikipedia](https://en.wikipedia.org/wiki/MD5) [Baike](http://baike.baidu.com/link?url=ZjuEzUZEfPbCX7smQOsY4lGu1lF6i5xPIwRqmWsTCRc8EdtLV_lRGDpEOOGE3OCgkMZuQp-kQ3lZdM_z6rTczq)|

## Installation

1. Install [CMake](https://cmake.org/download/).

2. Generate build files using the commands below:

    * Build benchmarks only

        ```bash
        $ mkdir build
        $ cd build
        $ cmake ..
        ```

    * Build benchmarks and unit tests

        ```bash
        $ mkdir build
        $ cd build
        $ git submodule init
        $ git submodule update
        $ cmake -DTASTYLIB_BUILD_TEST=ON ..
        ```

3. Build files will be generated in the `build` directory based on your operating system. Use them to build this project:

    | Linux | OS X | Windows |
    |:-----:|:----:|:-------:|
    |Makefile|Makefile|Visual Studio Project|

4. All executables(benchmarks and unit tests) will be generated in the `bin` directory. To run all unit tests together, use command below:

    ```bash
    $ ctest --verbose
    ```

## Details

### DoublyLinkedList

#### Usage

```c++
#include "tastylib/DoublyLinkedList.h"

using namespace tastylib;

int main() {
    DoublyLinkedList<int> list;

    auto isEmpty = list.isEmpty();  // isEmpty == true

    list.insertBack(1);   // List content: 1
    list.insertFront(2);  // List content: 2 1
    list.insert(1, 3);    // List content: 2 3 1
    list.insert(3, 4);    // List content: 2 3 1 4
    list.sort();          // List content: 1 2 3 4

    auto p1 = list.find(3);  // p1 == 2

    list.remove(p1);     // List content: 1 2 4
    list.removeFront();  // List content: 2 4
    list.removeBack();   // List content: 2

    auto p2 = list.find(3);  // p2 == -1

    auto size = list.getSize();  // size == 1

    return 0;
}
```

#### Benchmark

##### Cost in theory

| Operation | Time |
|:---------:|:----:|
|[insertFront()](./include/tastylib/DoublyLinkedList.h#L146)|O(1)|
|[removeFront()](./include/tastylib/DoublyLinkedList.h#L212)|O(1)|
|[insertBack()](./include/tastylib/DoublyLinkedList.h#L162)|O(1)|
|[removeBack()](./include/tastylib/DoublyLinkedList.h#L229)|O(1)|
|[insert()](./include/tastylib/DoublyLinkedList.h#L112)|O(n)|
|[remove()](./include/tastylib/DoublyLinkedList.h#L179)|O(n)|
|[find()](./include/tastylib/DoublyLinkedList.h#L94)|O(n)|
|[sort()](./include/tastylib/DoublyLinkedList.h#L246)|O(nlogn)|

##### Cost in practice

Source: [benchmark_DoublyLinkedList.cpp](./src/benchmark_DoublyLinkedList.cpp)

The program compares the time cost of `DoublyLinkedList` with `std::list`. When benchmarking `find()` and `sort()`, the size of the list is **100,000** and **5,000,000**, respectively. Here are the results under different environments:

###### Ubuntu 16.04 64-bit / g++ 5.4

| Operation | std::list | DoublyLinkedList |
|:---------:|:---------:|:----------------:|
|insertFront()|29 ns|36 ns|
|removeFront()|15 ns|12 ns|
|insertBack()|31 ns|28 ns|
|removeBack()|14 ns|12 ns|
|find()|165 µs|230 µs|
|sort()|3432 ms|**3011 ms**|

###### Windows 10 64-bit / Visual Studio 14 2015

| Operation | std::list | DoublyLinkedList |
|:---------:|:---------:|:----------------:|
|insertFront()|57 ns|46 ns|
|removeFront()|42 ns|49 ns|
|insertBack()|55 ns|48 ns|
|removeBack()|48 ns|51 ns|
|find()|112 µs|114 µs|
|sort()|3534 ms|**3138 ms**|

###### OS X 10.11.3 / AppleClang 7.3.0

| Operation | std::list | DoublyLinkedList |
|:---------:|:---------:|:----------------:|
|insertFront()|65 ns|66 ns|
|removeFront()|70 ns|82 ns|
|insertBack()|69 ns|68 ns|
|removeBack()|73 ns|79 ns|
|find()|10 ns*|9 ns*|
|sort()|3717 ms|3729 ms|

**(Items marked with * may be unreliable.)**

### BinaryHeap

#### Usage

```c++
#include "tastylib/BinaryHeap.h"

using namespace tastylib;

int main() {
    BinaryHeap<int> heap;  // Create a min-root heap

    auto isEmpty = heap.isEmpty();  // isEmpty == true

    heap.push(50);
    heap.push(20);
    heap.push(30);

    auto size1 = heap.getSize();  // size1 == 3

    auto val1 = heap.top();  // val1 == 20
    heap.pop();
    auto val2 = heap.top();  // val2 == 30
    heap.pop();
    auto val3 = heap.top();  // val3 == 50
    heap.pop();

    auto size2 = heap.getSize();  // size2 == 0

    return 0;
}
```

#### Benchmark

##### Cost in theory

| Operation | Time |
|:---------:|:----:|
|[push()](./include/tastylib/BinaryHeap.h#L63)|O(nlogn)|
|[top()](./include/tastylib/BinaryHeap.h#L79)|O(1)|
|[pop()](./include/tastylib/BinaryHeap.h#L87)|O(nlogn)|

##### Cost in practice

Source: [benchmark_BinaryHeap.cpp](./src/benchmark_BinaryHeap.cpp)

The program compares the time cost of `BinaryHeap` with `std::priority_queue`. It calculates the average time cost of each operation. Here are the results under different environments:

###### Ubuntu 16.04 64-bit / g++ 5.4

| Operation | std::priority_queue | BinaryHeap |
|:---------:|:-------------------:|:----------:|
|push()|17 ns|16 ns|
|pop()|294 ns|293 ns|

###### Windows 10 64-bit / Visual Studio 14 2015

| Operation | std::priority_queue | BinaryHeap |
|:---------:|:-------------------:|:----------:|
|push()|23 ns|22 ns|
|pop()|498 ns|**254 ns**|

### HashTable

#### Usage

```c++
#include "tastylib/HashTable.h"
#include <string>

using namespace tastylib;

int main() {
    HashTable<std::string> table;

    auto isEmpty = table.isEmpty();  // isEmpty == true

    table.insert("Alice");
    table.insert("Darth");

    auto size1 = table.getSize();  // size1 == 2

    auto hasAlice = table.has("Alice");  // hasAlice == true
    auto hasDarth = table.has("Darth");  // hasDarth == true

    table.remove("Darth");

    hasAlice = table.has("Alice");  // hasAlice == true
    hasDarth = table.has("Darth");  // hasDarth == false

    auto size2 = table.getSize();  // size2 == 1

    return 0;
}
```

#### Benchmark

##### Cost in theory

| Operation | Time |
|:---------:|:----:|
|[insert()](./include/tastylib/HashTable.h#L88)|O(1)|
|[has()/find()](./include/tastylib/HashTable.h#L76)|O(1)|
|[remove()](./include/tastylib/HashTable.h#L102)|O(1)|
|[rehash()](./include/tastylib/HashTable.h#L117)|O(n)|

##### Cost in practice

Note that there are many different ways to implement the hash table. The C++ standard library implements the `std::unordered_set` as a **dynamic** hash table, which means that its bucket amount changes dynamically when performing `insert()` and `remove()/erase()` operations(i.e., using [extendible hashing](https://en.wikipedia.org/wiki/Extendible_hashing) or [linear hashing](https://en.wikipedia.org/wiki/Linear_hashing)). While in TastyLib, for simplicity, the hash table is **static** so its bucket amount is fixed after initialized. Since different implementations have different pros and cons, it's hard to give a convincing benchmark result.

### MD5

#### Usage

```c++
#include "tastylib/MD5.h"

using namespace tastylib;

int main() {

    // hashedMsg == "2dabbfd553b67530e4892eb9481121fa",
    // which is the MD5 value of the message "TastyLib"
    std::string hashedMsg = MD5<>::getInstance()->hash("TastyLib");

    return 0;
}
```

#### Benchmark

Source: [benchmark_MD5.cpp](./src/benchmark_MD5.cpp)

The program uses the MD5 algorithm to hash a fixed message of 200 MB for several times and calculates the average time cost. Here are the results:

| Environment | Average Time |
|-------------|:------------:|
|Ubuntu 16.04 64-bit / g++ 5.4|899 ms|
|Windows 10 64-bit / Visual Studio 14 2015|1229 ms|

## License

See the [LICENSE](./LICENSE) file for license rights and limitations.
