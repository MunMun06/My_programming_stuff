#include <iostream>
#include <vector>
#include <string>

class MyResource {
public:
    int* data;

    // Constructor
    MyResource() {
        data = new int[100]; // Allocate some "heavy" memory
        std::cout << "Resource Allocated at " << data << '\n';
    }

    // Destructor
    ~MyResource() {
        if (data != nullptr) {
            std::cout << "Resource Freed at " << data << '\n';
            delete[] data;
        } else {
            std::cout << "Destructor called on empty resource (nothing to free)." << '\n';
        }
    }

    // Move Constructor (The "Stealer")
    // It takes an R-value reference (&&)
    MyResource(MyResource&& other) noexcept {
        std::cout << "Moving resource from  " << other.data << '\n';
        this->data = other.data; // Steal the pointer
        other.data = nullptr;    // Set the old one to null so it doesn't delete our data!
    }

    // Disable copying for this experiment
    MyResource(const MyResource& other) = delete;
};

int main() {
  // L-value anre R-value 
  // left value is something that has a name and a persistent memory address 
  //  int x = 5. x is an L-value
  // right value is temporary data that dont have a name or about to be destroyed.
  //  x = 5. 5 is an R-value. result of x + 10 is an R-value

    MyResource res1; 
    
    // This will trigger the Move Constructor
    MyResource res2 = std::move(res1); 

    std::cout << "res1.data is now: " << res1.data << '\n';
    std::cout << "res2.data is now: " << res2.data << '\n';

    return 0;
}
