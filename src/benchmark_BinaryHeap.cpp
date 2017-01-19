#include "tastylib/util/io.h"
#include "tastylib/util/timer.h"
#include "tastylib/util/random.h"
#include "tastylib/util/convert.h"
#include "tastylib/BinaryHeap.h"
#include <string>
#include <queue>

using namespace tastylib;
using std::string;
using std::priority_queue;
using std::vector;

int main() {
    printLn("Benchmark of BinaryHeap running...\n");
    {
        const int SIZE = 40000000;
        vector<int> vals;
        priority_queue<int> stdHeap;
        BinaryHeap<int, std::less_equal<int>> libHeap;  // A max-root heap

        // Generate elements
        printLn("Generating " + toString(SIZE) + " elements to push...");
        for (int i = 0; i < SIZE; ++i) {
            vals.push_back(randInt(0, SIZE));
        }
        printLn("Finished.\n");

        {   // Benchmark push()
            printLn("Benchmarking push()...");
            printLn("Pushing " + toString(SIZE) + " elements to the heap...");
            auto stdTime = timing([&]() {
                for (int i = 0; i < SIZE; ++i) {
                    stdHeap.push(vals[i]);
                }
            });
            printLn("std finished.");
            auto libTime = timing([&]() {
                for (int i = 0; i < SIZE; ++i) {
                    libHeap.push(vals[i]);
                }
            });
            printLn("lib finished.");
            printLn("Avg time of std VS TastyLib: " + toString(stdTime / SIZE) + " ms / "
                    + toString(libTime / SIZE) + " ms");
            printLn("Benchmark of push() finished.\n");
        }

        {   // Benchmark pop()     
            printLn("Benchmarking pop()...");
            printLn("Poping " + toString(SIZE) + " elements from the heap...");
            auto stdTime = timing([&]() {
                for (int i = 0; i < SIZE; ++i) {
                    stdHeap.pop();
                }
            });
            printLn("std finished.");
            auto libTime = timing([&]() {
                for (int i = 0; i < SIZE; ++i) {
                    libHeap.pop();
                }
            });
            printLn("lib finished.");
            printLn("Avg time of std VS TastyLib: " + toString(stdTime / SIZE) + " ms / "
                    + toString(libTime / SIZE) + " ms");
            printLn("Benchmark of pop() finished.\n");
        }
    }
    printLn("Benchmark of BinaryHeap finished.");
    checkMemoryLeaks();
    return 0;
}
