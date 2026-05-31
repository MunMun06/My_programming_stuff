-- to use a module in another file. you call the require() function. pass it the file name as a string wihout the .lua extension

-- main.lua
local math_stuff = require("math_utils")

print(math_stuff.add(10, 5))         -- Output: 15
print(math_stuff.get_golden_ratio()) -- Output: 1.618

-- Trying to access the private variable fails:
print(math_stuff.phi)                -- Output: nil

-- if the files arent in the same directory.
-- lua use dots to represent directory separator in the require path 
-- (the path is based on where you run lua not where the main.lua is)
-- ├── main.lua
-- └── utils
--    └── string_helpers.lua
--  to import string_helpers.lua in main.lua 
--  local helpers = require("utils.string_helpers")

-- the first time you call require("module_name"). lua search your system path, find the file. And execute it top to bottom.
-- and caches the returned table inside a global tracking structure called packages.loaded
-- when you call require("module_name") again. lua reach into the cache and use the same table instance from the first time.

-- main.lua
local mod1 = require("execution_test") -- Prints: "File executed!"
local mod2 = require("execution_test") -- Prints nothing! (Pulled from cache)

mod1.status = "CHANGED"
print(mod2.status) -- Output: CHANGED (Both point to the exact same table in memory)

-- in neovim setup or open-source libraries. you will frequently see developers return an anonymous table containing everything directly 
--[[ 
return {
    parse = function(raw_data)
        -- parsing logic here
    end,
    
    validate = function(config)
        -- validation logic here
    end
}
--]]
