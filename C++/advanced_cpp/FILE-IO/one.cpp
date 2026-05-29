#include <iostream> 
#include <fstream>
#include <string>

// fstream have 3 main classes 
//    std::ifstream. input file stream.
//    std::ofstream. output file stream.
//    std::fstream. file stream. (both reading and writing)

// Text mode 
//   some character might get encoded from the OS or compiler 

// Binary mode 
//   no meddling from OS or compiler.

void write_config() {
    std::ofstream out_file("config.txt"); // Opens in text mode by default
    if (out_file.is_open()) {
        out_file << "username=arch_user69\n";
        out_file << "theme=dracula\n";
        out_file.close(); // Good practice, though destructor does it too
    }
}

void read_config() {
    std::ifstream in_file("config.txt");
    std::string line;
    if (in_file.is_open()) {
       while (std::getline(in_file, line)) { // std::getLine iterate for us, i think.
            std::cout << "Read line: " << line << "\n";
        }
    }
}

struct PlayerState {
    int id;
    float x_pos;
    float y_pos;
    int health;

    // when reading or writing struct to a file. DO NOT use pointer.
    // you will get undefined behaviour or segmentation fault.
    
    // this approach only works with static data. Ifs its a reference. reinterpret_cast will write those address to file.
    // which will contain different value the next time we run the program.
};

int main() {

  write_config();
  read_config();
  std::cout << "\n";

  PlayerState save_player = {1337, 45.5f, -12.2f, 100};

  // 1. Save to binary file
  std::ofstream out_file("save.dat", std::ios::binary); // this is how to do binary mode
  if (out_file.is_open()) {
      // Cast the struct pointer to a byte pointer (char*)
      out_file.write(reinterpret_cast<const char*>(&save_player), sizeof(PlayerState));
      out_file.close();
      std::cout << "Binary data saved successfully.\n";
  }

  // 2. Load from binary file back into a clean struct
  PlayerState loaded_player;
  std::ifstream in_file("save.dat", std::ios::binary);
  if (in_file.is_open()) {
      in_file.read(reinterpret_cast<char*>(&loaded_player), sizeof(PlayerState));
      in_file.close();
  }

  // Verify it worked
  std::cout << "Loaded Player ID: " << loaded_player.id << "\n";
  std::cout << "Loaded Player health: " << loaded_player.health << "\n";
  std::cout << "Loaded Position: (" << loaded_player.x_pos << ", " << loaded_player.y_pos << ")\n";

  // in the real world. people usually write custom data via JSON or library. Not creating some custom type/struct

  return 0;
}
