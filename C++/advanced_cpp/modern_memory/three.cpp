#include <iostream>
#include <memory>

struct Entity {
    Entity() { std::cout << "Entity Created\n"; }
    ~Entity() { std::cout << "Entity Destroyed\n"; }
    void bark() { std::cout << "Woof!\n"; }
};

int main() {
    {
        // Allocation using make_unique (cleaner than 'new')
        std::unique_ptr<Entity> entity = std::make_unique<Entity>();
        
        entity->bark(); // Use it like a normal pointer
    } // <--- 'entity' goes out of scope HERE. 
      // The destructor is called automatically. No 'delete' required.
    
    std::cout << "End of scope.\n";

    std::shared_ptr<Entity> ptr1 = std::make_shared<Entity>();
    // shared pointer are slower than unique pointer 
    // they need to keep the count 
    // the size is 16 bytes rather than 8 in unique pointer
    
    {
        std::shared_ptr<Entity> ptr2 = ptr1; // This is ALLOWED (unlike unique_ptr)
        std::cout << "Count: " << ptr1.use_count() << "\n"; // Output: 2
    } // ptr2 goes out of scope, but the Entity is NOT destroyed.

    std::cout << "Count: " << ptr1.use_count() << "\n"; // Output: 1
                                                        
    return 0;
} // Last pointer (ptr1) dies, Entity is finally destroyed.
