-- in lua. an array is a table that use sequential integers as keys 
-- index start at 1 not 0

-- Creating a literal array
local terminals = { "alacritty", "kitty", "wezterm" }

-- Under the hood, Lua interprets the above exactly like this:
-- local terminals = { [1] = "alacritty", [2] = "kitty", [3] = "wezterm" }

print(terminals[1]) -- Output: alacritty
print(terminals[0]) -- Output: nil (Index 0 empty by default)

-- lua manage table by using a hybrid structure 
-- a hash map part using non-integer keys 
-- an array part using sequential integers from 1. These are mapped to C-style array behind the scene 
--    so it more performant

-- length operator (#) with array
-- when use with an array. return the amount of element in the array 
local compilers = { "gcc", "clang", "g++" }

-- compilers = { ["this"] = "gcc", ["is"] = "clang", ["the"] = "g++" }
-- length operator only work when the table only consisted of array part 
-- or # will always return 0
print(#compilers) -- Output: 3

-- Finding the last element dynamically
print(compilers[#compilers]) -- Output: g++


-- sparse table
-- The `#` operator is implemented as a binary search designed to find a boundary where `table[n] ~= nil` and `table[n+1] == nil`. 
-- If your data contains internal `nil` values, the binary search will get confused and return the wrong boundary, 
-- completely breaking any standard loops relying on `#`.
-- ~= is the logical "not equal" in lua or the equivalent of != in other languages

-- Never store literal `nil` values inside an ordered array sequence. 
-- If you need to represent an empty slot, use a placeholder string or boolean like `"none"` or `false`.


-- Multi-dimensional Arrays
-- To create a matrix or a multi-dimensional array, you simply nest tables inside integer indices.

-- A 2x2 grid matrix
local matrix = {
    { 10, 20 }, -- Row 1
    { 30, 40 }  -- Row 2
}

print(matrix[2][1]) -- Output: 30 (Row 2, Column 1)

