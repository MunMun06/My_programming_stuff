#include <iostream>
#include <thread>
#include <mutex>

// mutex lock use futex (fast userspace mutex)
// slow-path
//   the thread that doesnt hold the lock do futex() syscall to be placed in a futex queue 
//   the kernel then put the thread in BLOCKED/SLEEPING state. (so no spinlock or spin-waiting.)
//                                                             (no wasting cpu cycles)
//
// fast-path 
//   the thread that take the lock execute its critical secion. 
//   once finished. it call mutex.unlock(). 
//   which tell the kernel to wake up one of the sleeping task in the futex queue
//
//  and we use RAII with mutexes. So a thread cant take the lock and dies from exception or crashes.
//  leaving all other threads permanently sleeping.


std::mutex g_num_mutex; // Protects g_counter
int g_counter = 0; // shared variable

// std::lock_guard<std::mutex> lock(g_num_mutex);
//
// std::lock_guard    helper class that only manage a lock 
// <std::mutex>       tells std::lock_guard what lock its managing 
// lock               variable name. 
// g_num_mutex        std::lock_guard's constructor argument 
void increment_counter() {
    for (int i = 0; i < 100000; ++i) {
        // RAII Lock Guard: Locks the mutex on creation
        std::lock_guard<std::mutex> lock(g_num_mutex); // auto call g_num_mutex.lock()
        // the lock_guard's scope is in this code block. So it protect all codes inside this for loop
        
        // --- CRITICAL SECTION START ---
        g_counter++; 
        // --- CRITICAL SECTION END ---
        
    } // <--- The guard goes out of scope here. 
      // auto call g_num_mutex.unlock() even if the code crashes or returns
}

int main() {
    std::thread t1(increment_counter);
    std::thread t2(increment_counter);

    t1.join(); 
    t2.join();
    
    // join() force the thread to finish executing before the main thread can resume its execution

    std::cout << "Final Counter Value: " << g_counter << "\n"; // Will be exactly 200000
    return 0;
}
