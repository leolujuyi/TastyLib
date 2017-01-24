# TastyLib

TastyLib is a c++ library of data structures and algorithms.

It is also a **header-only** library, which means that you could just copy the `include/tastylib` directory to your project's include path and use it without caring about the issues related to link libraries.

## Build Status

| Linux | Windows | Coverage |
|:-----:|:-------:|:--------:|
|[![Build Status](https://travis-ci.org/stevennL/TastyLib.svg?branch=master)](https://travis-ci.org/stevennL/TastyLib)|[![Build Status](https://ci.appveyor.com/api/projects/status/kbpwdij5qpyw2vs7?svg=true)](https://ci.appveyor.com/project/stevennL/tastylib)|[![Coverage Status](https://coveralls.io/repos/github/stevennL/TastyLib/badge.svg?branch=master)](https://coveralls.io/github/stevennL/TastyLib?branch=master)|

## Outline

Contents below show the data structures and algorithms available in this project. Just click the links at the `name` column to see the details of their usages and benchmarks. All benchmarks are run with the `-O2` compiler flag under the `Release` version.

### Data Structures

| Name | Source | Benchmarked | Note | Reference |
|:----:|:------:|:-----------:|------|-----------|
|[DoublyLinkedList](#doublylinkedlist)|[Unit test](./test/test_DoublyLinkedList.cpp)<br />[DoublyLinkedList.h](./include/tastylib/DoublyLinkedList.h)|Yes|A linked data structure that consists of a set of sequentially linked records. It also supports merge sort.|[Wikipedia](https://en.wikipedia.org/wiki/Doubly_linked_list)|
|[BinaryHeap](#binaryheap)|[Unit test](./test/test_BinaryHeap.cpp)<br />[BinaryHeap.h](./include/tastylib/BinaryHeap.h)|Yes|A heap data structure taking the form of a complete binary tree. A common way of implementing [priority queue](https://en.wikipedia.org/wiki/Priority_queue).|[Wikipedia](https://en.wikipedia.org/wiki/Binary_heap)|
|[HashTable](#hashtable)|[Unit test](./test/test_HashTable.cpp)<br />[HashTable.h](./include/tastylib/HashTable.h)|No|A data structure that stores unique elements in no particular order, and which allows for fast retrieval of individual elements based on their values. Similar to [std::unordered_set](http://www.cplusplus.com/reference/unordered_set/unordered_set).|[Wikipedia](https://en.wikipedia.org/wiki/Hash_table)|
|[AVLTree](#avltree)|[Unit test](./test/test_AVLTree.cpp)<br />[AVLTree.h](./include/tastylib/AVLTree.h)|Yes|A self-balancing binary search tree.|[Wikipedia](https://en.wikipedia.org/wiki/AVL_tree)|
|[Graph](#graph)|[Unit test](./test/test_Graph.cpp)<br />[Graph.h](./include/tastylib/Graph.h)|No|A data structure to implement the directed/undirected graph concepts from mathematics. It stores a graph in an adjacency list or matrix.|[Wikipedia](https://en.wikipedia.org/wiki/Graph_(abstract_data_type))|

### Algorithms

| Name | Source | Benchmarked | Note | Reference |
|:----:|:------:|:-----------:|------|-----------|
|[MD5](#md5)|[Unit test](./test/test_MD5.cpp)<br />[MD5.h](./include/tastylib/MD5.h)|Yes|A widely used hash function producing a 128-bit hash value.|[Wikipedia](https://en.wikipedia.org/wiki/MD5)|
|[NPuzzle](#npuzzle)|[Unit test](./test/test_NPuzzle.cpp)<br />[NPuzzle.h](./include/tastylib/NPuzzle.h)|Yes|A classic searching problem solved with [A* search](https://en.wikipedia.org/wiki/A*_search_algorithm). A [GUI demo](https://github.com/stevennL/Puzzle) has been provided.|[Wikipedia](https://en.wikipedia.org/wiki/15_puzzle)|
|[Sort](#sort)|[Unit test](./test/test_Sort.cpp)<br />[Sort.h](./include/tastylib/Sort.h)|Yes|Including [insertion sort](https://en.wikipedia.org/wiki/Insertion_sort), [selection sort](https://en.wikipedia.org/wiki/Selection_sort), [heapsort](https://en.wikipedia.org/wiki/Heapsort), [quicksort](https://en.wikipedia.org/wiki/Quicksort), [quickselect](https://en.wikipedia.org/wiki/Quickselect). For [merge sort](https://en.wikipedia.org/wiki/Merge_sort), please refer to [DoublyLinkedList.sort()](#cost-in-theory).|[Wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm)|

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
|[sort()](./include/tastylib/DoublyLinkedList.h#L246) (merge sort)|O(nlogn)|

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

### AVLTree

#### Usage

```c++
#include "tastylib/AVLTree.h"
#include <string>

using namespace tastylib;

int main() {
    AVLTree<int> tree;

    auto isEmpty = tree.isEmpty();  // isEmpty == true

    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(3);

    std::string str1 = tree.preorder();   // str1 == "{2, 1, 3, 3}"
    std::string str2 = tree.inorder();    // str2 == "{1, 2, 3, 3}"
    std::string str3 = tree.postorder();  // str3 == "{1, 3, 3, 2}"

    auto size1 = tree.getSize();  // size1 == 4
    auto found1 = tree.has(3);    // found1 == true

    tree.remove(3);

    std::string str4 = tree.preorder();  // str4 == "{2, 1}"

    auto size2 = tree.getSize();  // size2 == 2
    auto found2 = tree.has(3);    // found2 == false

    return 0;
}
```

#### Benchmark

##### Cost in theory

| Operation | Time |
|:---------:|:----:|
|[find()](./include/tastylib/AVLTree.h#L191)|O(logn)|
|[insert()](./include/tastylib/AVLTree.h#L253)|O(logn)|
|[remove()](./include/tastylib/AVLTree.h#L287)|O(logn)|

##### Cost in practice

Source: [benchmark_AVLTree.cpp](./src/benchmark_AVLTree.cpp)

The program compares the time cost of `AVLTree` with `std::multiset`. It calculates the average time cost of each operation. Note that the `std::multiset` is implemented as a [red-black tree](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree), which is faster than the AVL tree when performing `insert()` and `remove()` operations(but slower when performing `find()`). Here are the results under different environments:

###### Ubuntu 16.04 64-bit / g++ 5.4

| Operation | std::multiset | AVLTree |
|:---------:|:-------------:|:-------:|
|find()|1245 ns|1056 ns|
|insert()|1241 ns|1447 ns|
|remove()|1289 ns|1728 ns|

###### Windows 10 64-bit / Visual Studio 14 2015

| Operation | std::multiset | AVLTree |
|:---------:|:-------------:|:-------:|
|find()|1597 ns|168 ns*|
|insert()|1570 ns|1260 ns|
|remove()|233 ns|436 ns|

**(Items marked with * may be unreliable.)**

### Graph

#### Usage

```c++
#include "tastylib/Graph.h"
#include <string>

using namespace tastylib;

int main() {

    // Create a graph that has three vertices.
    // Each vertex stores a string object.
    Graph<std::string> graph(3);

    // Modify the string object in each vertex
    graph[0] = "I am vertex 0.";
    graph[1] = "I am vertex 1.";
    graph[2] = "I am vertex 2.";

    // Add edges
    graph.setWeight(0, 1, 10);
    graph.setWeight(0, 2, 20);
    graph.setWeight(1, 2, 30);

    // Get edge weights
    auto w0 = graph.getWeight(0, 1);  // w0 == 10
    auto w1 = graph.getWeight(0, 2);  // w1 == 20
    auto w2 = graph.getWeight(1, 2);  // w2 == 30

    // Get adjacent vertices
    auto n0 = graph.getNeighbors(0);  // n0 == [1, 2]
    auto n1 = graph.getNeighbors(1);  // n1 == [2]
    auto n2 = graph.getNeighbors(2);  // n2 == []

    return 0;
}
```

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

### NPuzzle

#### Usage

```c++
#include "tastylib/NPuzzle.h"

using namespace tastylib;

int main() {

    // The beginning node and the ending node of a 3*3 puzzle problem.
    // Number '0' indicates the empty grid and number '1-8' denote other eight grids.
    PuzzleNode<> beg({0, 2, 3, 1, 4, 5, 6, 7, 8}, 3, 3);
    PuzzleNode<> end({1, 2, 3, 4, 0, 5, 6, 7, 8}, 3, 3);

    // Solve the problem
    NPuzzle<> puzzle(beg, end);
    puzzle.solve();

    // List 'path' stores the move directions from the beginning node
    // to the ending node. Its contents must be [DOWN, RIGHT].
    std::list<Direction> path = puzzle.getPath();

    return 0;
}
```

#### Benchmark

Source: [benchmark_NPuzzle.cpp](./src/benchmark_NPuzzle.cpp)

The program solves `3*3`, `4*4`, `5*5` and `6*6` puzzle problems respectively and generates the information of overheads. Here are the outputs of the benchmark under different environments:

###### Ubuntu 16.04 64-bit / g++ 5.4

```
Benchmark of NPuzzle running...

Benchmarking 3*3 puzzle...
Beg: {0, 6, 4, 3, 8, 2, 7, 5, 1}
End: {6, 5, 7, 3, 1, 2, 8, 4, 0}
Searching...
Searched nodes: 161
     Time cost: 1 ms
    Efficiency: 102.092581 node/ms
   Path length: 52
Solution check: pass
Benchmark of 3*3 puzzle finished.

Benchmarking 4*4 puzzle...
Beg: {3, 0, 2, 13, 9, 1, 5, 6, 14, 11, 4, 10, 12, 7, 15, 8}
End: {4, 2, 9, 3, 13, 0, 5, 6, 15, 12, 11, 14, 8, 10, 1, 7}
Searching...
Searched nodes: 1330
     Time cost: 13 ms
    Efficiency: 98.089830 node/ms
   Path length: 117
Solution check: pass
Benchmark of 4*4 puzzle finished.

Benchmarking 5*5 puzzle...
Beg: {6, 16, 17, 0, 8, 3, 2, 11, 5, 9, 4, 21, 13, 23, 18, 15, 7, 1, 20, 14, 22, 12, 10, 19, 24}
End: {12, 10, 19, 22, 2, 5, 0, 20, 3, 4, 21, 6, 18, 13, 24, 11, 1, 8, 9, 7, 15, 14, 17, 16, 23}
Searching...
Searched nodes: 3676
     Time cost: 43 ms
    Efficiency: 84.968680 node/ms
   Path length: 275
Solution check: pass
Benchmark of 5*5 puzzle finished.

Benchmarking 6*6 puzzle...
Beg: {15, 3, 1, 4, 5, 13, 18, 2, 14, 0, 9, 10, 8, 27, 20, 24, 23, 16, 26, 30, 6, 34, 25, 21, 31, 28, 11, 12, 7, 29, 32, 19, 35, 17, 22, 33}
End: {13, 6, 9, 2, 27, 16, 11, 14, 12, 15, 21, 17, 7, 20, 32, 4, 5, 3, 10, 18, 8, 19, 29, 23, 1, 26, 25, 24, 34, 33, 31, 35, 30, 0, 22, 28}
Searching...
Searched nodes: 69271
     Time cost: 1088 ms
    Efficiency: 63.638602 node/ms
   Path length: 450
Solution check: pass
Benchmark of 6*6 puzzle finished.

Benchmark of NPuzzle finished.
```

### Sort

#### Usage

```c++
#include "tastylib/Sort.h"

using namespace tastylib;

int main() {
    const unsigned n = 5;
    int arr[n] = {5, 4, 3, 2, 1};

    {   // Sort.
        // Aftering running each of the function below,
        // the array's content will be: [1, 2, 3, 4, 5]
        insertionSort(arr, n);
        selectionSort(arr, n);
        heapSort(arr, n);
        quickSort(arr, 0, n - 1);
    }

    {   // Find the kth smallest element.
        // After running the function below, the kth
        // smallest element will be stored at arr[k].
        int k = 1;  // Find the second smallest element
        quickSelect(arr, 0, n - 1, k);
    }

    return 0;
}
```

#### Benchmark

##### Cost in theory

| Operation | Time | Stable |
|:---------:|:----:|:------:|
|[insertionSort()](./include/tastylib/Sort.h#L18)|O(n^2)|Yes|
|[selectionSort()](./include/tastylib/Sort.h#L40)|O(n^2)|No|
|[heapSort()](./include/tastylib/Sort.h#L62)|O(nlogn)|No|
|[mergeSort()](#cost-in-theory)|O(nlogn)|Yes|
|[quickSort()](./include/tastylib/Sort.h#L110)|O(nlogn)|No|
|[quickSelect()](./include/tastylib/Sort.h#L144)|O(n)|-|

##### Cost in practice

Source: [benchmark_Sort.cpp](./src/benchmark_Sort.cpp)

The program calculates the average time cost to sort or find the kth element in an array of `100000` elements. Here are the results under different environments:

###### Ubuntu 16.04 64-bit / g++ 5.4

| Operation | Time |
|:---------:|:----:|
|std::sort()|6.41 ms|
|insertionSort()|1691.64 ms|
|selectionSort()|12220.25 ms|
|heapSort()|10.61 ms|
|quickSort()|7.07 ms|
|std::nth_element()|0.79 ms|
|quickSelect()|0.86 ms|

###### Windows 10 64-bit / Visual Studio 14 2015

| Operation | Time |
|:---------:|:----:|
|std::sort()|8.34 ms|
|insertionSort()|1559.92 ms|
|selectionSort()|4355.90 ms|
|heapSort()|11.56 ms|
|quickSort()|6.79 ms|
|std::nth_element()|1.08 ms|
|quickSelect()|0.88 ms|

## License

See the [LICENSE](./LICENSE) file for license rights and limitations.
