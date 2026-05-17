#include <iostream> 
#include <memory> // required for smart pointer

int main (int argc, char *argv[]) {

  int* ptr = new int(42);

  delete ptr; // wtf is this
              // pointer can point to heap memory then we need to delete it?

  // MODERN MEMORY MANAGEMENT

  // RAII  resouce acquisition is initialization
  // this mean that a heap-allocated object is tied to a stack-allocated object
  // when the stack object dies (goes out of scope),
  // it automatically call delete on the heap object that its tied to 

  // Allocation: No 'new' keyword needed!
  std::unique_ptr<int> ptr1 = std::make_unique<int>(100);

  std::unique_ptr<int> ptr2 = ptr1; // ERROR: Cannot copy!
  // unique_ptr exclusively owned that memory, it cant share
  // Ownership can be transfer, but it will always have 1 owner
    
  // Ownership transfer (Like 'mv')
  // std::unique_ptr<int> ptr2 = std::move(ptr1); 

  if (!ptr1) {
    std::cout << "ptr1 is now null (moved out)\n";
  }


  return 0;
} // ptr2 goes out of scope here, memory is automatically freed
