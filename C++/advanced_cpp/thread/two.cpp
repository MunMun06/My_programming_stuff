#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

// --- Global Shared Communication Context ---
std::mutex g_loading_mutex; // the mutex lock (only have one mutex lock)
std::condition_variable g_loading_cv; // the shared conditional variable
bool g_asset_loaded = false;

// The shared asset (Read-Only once loaded)
std::vector<int> g_raw_pixel_buffer;

// --- The Worker Thread Function ---
void render_worker(int thread_id, int total_threads) {
    std::cout << "[Thread " << thread_id << "] Spawned and waiting for asset loading...\n";

    // 1. Wait until the asset is fully loaded
    {
        std::unique_lock<std::mutex> lock(g_loading_mutex); // can be lock and unlock manually 
                                                            // while lock_guard can only lock upon creation and unlock upon destruction
        
        // This loop handles "spurious wakeups" (the kernel waking a thread accidentally)
        // cv.wait automatically UNLOCKS the mutex while sleeping, and RE-LOCKS it upon waking up.
        g_loading_cv.wait(lock, [] { return g_asset_loaded; });
        // second parameter is bool function with no parameter.
        // [] { return g_asset_loaded }; is a lambda or helper function.
        
    } // Lock goes out of scope here. The mutex is released BEFORE rendering starts!

    // 2. The Critical-Section-Free Processing Phase
    // Because g_raw_pixel_buffer is now entirely READ-ONLY, all threads can read it safely.
    int total_pixels = g_raw_pixel_buffer.size();
    
    // Divide the screen/buffer rows among threads evenly
    for (int i = thread_id; i < total_pixels; i += total_threads) {
        // Simulating heavy image processing calculation
        g_raw_pixel_buffer[i] = g_raw_pixel_buffer[i] * 2; 
        
        // Note: Writing to individual, completely distinct array indices 
        // does not cause a race condition because threads never touch the SAME index.
    }

    std::cout << "[Thread " << thread_id << "] Finished processing its section.\n";
}

int main() {
    const int NUM_THREADS = 4;
    std::vector<std::thread> workers;

    // 1. Spawn our worker threads. They will immediately go to sleep waiting for the asset.
    for (int i = 0; i < NUM_THREADS; ++i) {
        workers.push_back(std::thread(render_worker, i, NUM_THREADS));
    }

    // Simulate the main thread doing heavy Disk IO loading
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Initialize our asset with dummy pixel data (e.g., 16 gray pixels)
    std::cout << "\n[MAIN] Disk Asset completely loaded into RAM!\n";
    g_raw_pixel_buffer = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160};

    // 2. Signal the workers that it is safe to proceed
    {
        std::lock_guard<std::mutex> lock(g_loading_mutex);
        g_asset_loaded = true;
    }
    std::cout << "[MAIN] Notifying all rendering threads to wake up...\n\n";
    g_loading_cv.notify_all(); // Wake up ALL threads waiting on this condition variable

    // 3. Wait for all renderers to complete their chunks
    for (auto& worker : workers) {
        worker.join();
    }

    // 4. Print results out to verify zero data corruption occurred
    std::cout << "\n[MAIN] Final Processed Pixel Buffer:\n";
    for (int pixel : g_raw_pixel_buffer) {
        std::cout << pixel << " ";
    }
    std::cout << "\n";

    return 0;
}
