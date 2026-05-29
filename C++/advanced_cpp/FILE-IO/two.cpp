#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct GameSession {
    int player_id;
    float solve_time;
    std::vector<std::string> scramble_moves; // Dynamic data!
};

void save_session(const std::string& filename, const GameSession& session) {
    std::ofstream out(filename, std::ios::binary);
    if (!out.is_open()) return;

    // 1. Write the fixed-size primitive data directly
    out.write(reinterpret_cast<const char*>(&session.player_id), sizeof(session.player_id));
    out.write(reinterpret_cast<const char*>(&session.solve_time), sizeof(session.solve_time));

    // 2. Write the NUMBER of moves in the vector so the loader knows how many loops to do
    size_t total_moves = session.scramble_moves.size();
    out.write(reinterpret_cast<const char*>(&total_moves), sizeof(total_moves));

    // 3. Serialize each string individually
    for (const std::string& move : session.scramble_moves) {
        // Write the length of this specific string
        size_t str_len = move.size();
        out.write(reinterpret_cast<const char*>(&str_len), sizeof(str_len)); // write the length of each moves 
                                                                             // useful cuz of R2 is one move.
        
        // Write the actual characters directly from the HEAP, not the stack wrapper!
        out.write(move.data(), str_len); // so in the file, it would be something like. [1][F][2][R2]...
    }
}

GameSession load_session(const std::string& filename) {
    std::ifstream in(filename, std::ios::binary);
    GameSession session{};
    if (!in.is_open()) return session;

    // 1. Read fixed-size data back into place
    in.read(reinterpret_cast<char*>(&session.player_id), sizeof(session.player_id));
    in.read(reinterpret_cast<char*>(&session.solve_time), sizeof(session.solve_time));

    // 2. Read how many moves are waiting for us
    size_t total_moves = 0;
    in.read(reinterpret_cast<char*>(&total_moves), sizeof(total_moves));
    
    // Resize our vector ahead of time to avoid multiple reallocations
    session.scramble_moves.resize(total_moves);

    // 3. Read each string out sequentially
    for (size_t i = 0; i < total_moves; ++i) {
        size_t str_len = 0;
        in.read(reinterpret_cast<char*>(&str_len), sizeof(str_len)); // read the length value into str_len. 
                                                                     // which will be read as size_t (integer for array size)

        // Create a temporary string and allocate space for incoming characters
        std::string temp_string;
        temp_string.resize(str_len);

        // Read the characters directly into the string's internal memory buffer
        in.read(&temp_string[0], str_len); // &temp_string[0] to get the address of the first character. 

        // Move the finished string into our vector without copying
        session.scramble_moves[i] = std::move(temp_string); // transfer ownership from temp_string to session.scramble_moves[i]
    }

    return session;
}

int main() {
    // Setup a session with dynamic string lengths and vector lengths
    GameSession my_game = {42, 14.25f, {"R", "U", "R", "F2", "B", "L"}};

    std::cout << "Saving game session...\n";
    save_session("game.dat", my_game);

    std::cout << "Loading game session into a completely fresh struct...\n";
    GameSession loaded_game = load_session("game.dat");

    // Verify everything matches up perfectly
    std::cout << "\n--- LOADED DATA ---" << std::endl;
    std::cout << "Player ID: " << loaded_game.player_id << std::endl;
    std::cout << "Solve Time: " << loaded_game.solve_time << "s" << std::endl;
    std::cout << "Scramble Moves: ";
    for (const auto& move : loaded_game.scramble_moves) {
        std::cout << move << " ";
    }
    std::cout << std::endl;

    return 0;
}
