-- table is the only built-in data structure in lua.
-- a table is an associative array that can act as class, struct, object, list, dictionary, array

-- table is created with curly braces. 
-- a table is a collection of key-value pairs. key can be anything except nil 

-- Creating an empty table
local config = {}

-- Assigning keys and values (Dictionary style)
config["theme"] = "gruvbox"
config["font_size"] = 14

-- Shortcut dot syntax (Works only if the key is a valid string identifier)
config.opacity = 0.85

print(config.theme)      -- Output: gruvbox
print(config["opacity"]) -- Output: 0.85 (just another style)
print(config.non_existent) -- Output: nil (Accessing an undefined key never crashes; it returns nil)
print(config.opacity) 

-- mixed table 
-- a single table can store values of completely different types simultaneously. 
-- More importantly, it can map string keys and numeric keys inside the exact same structure.

local session = {
    user = "munmun06",    -- String key
    active = true,        -- Boolean value
    [1] = "First item",   -- Explicit numeric key
    [2] = "Second item",
}

print(session.user)  -- Output: munmun06
print(session[1])    -- Output: First item

-- table module 
-- the global "table" library provides built-in utilities to manipulate tables. 
local plugins = { "lazy.nvim", "telescope.nvim" }

-- 1. table.insert(table, [position], value)
table.insert(plugins, "treesitter") -- Appends to the end
table.insert(plugins, 1, "harpoon") -- Inserts at index 1 and shifts the rest down

-- 2. table.remove(table, [position])
local removed = table.remove(plugins, 2) -- Removes index 2 ("lazy.nvim") and shifts down
print("Removed: " .. removed)

-- 3. table.concat(table, separator)
-- Efficient string building! This bypasses the memory overhead of the '..' operator.
local pipeline = table.concat(plugins, " -> ")
print(pipeline) -- Output: harpoon -> telescope.nvim -> treesitter

-- reference vs value 
-- like function, table are passed by reference. When you assign a table to a new variable. you pass by reference.
local original = { x = 10, y = 20 }
local reference = original

reference.x = 99

print(original.x) -- Output: 99 (Changing 'reference' altered 'original')
-- if you want to copy by value. You need to manually create a new table. 

-- nested tables
-- table's value can be other tables. So you can have multi-dimensional arrays, matrixes. And deep configuration
local window_manager = {
    name = "Hyprland",
    settings = {
        gaps_in = 5,
        gaps_out = 20,
        animations = {
            enabled = true,
            speed = 7,
        }
    }
}

print(window_manager.settings.animations.speed) -- Output: 7



local my_key = "opacity" -- using it this way is more flexible and versatile
print(config[my_key]) -- Works! Looks up "opacity" dynamically

config["font-size"] = 14  -- Works! (Dashes are allowed in strings)
config["user name"] = "alarm" -- Works! (Spaces are allowed in strings)

-- This will cause a syntax error:
print(config.font-size) -- Error! Lua thinks you are trying to subtract 'size' from 'config.font'

-- This will look for a literal key named "my_key", NOT "opacity":
local my_key = "opacity"
print(config.my_key)   -- Returns nil (unless you literally have a key named "my_key")
