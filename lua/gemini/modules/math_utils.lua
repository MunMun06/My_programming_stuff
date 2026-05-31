-- modules are how to manage a multi-file workflow in lua 
-- it use a single built-in function require() and the table(s)

-- a module is a lua file that populates a table with functions and variables, and then returns that table at the end of the file
-- math_utils.lua
local M = {} -- Create a local table to hold module functions

-- A private variable (not exported because it's local to the file)
local phi = 1.618

-- A public function (exported because it's attached to the table)
function M.add(a, b)
    return a + b
end

function M.get_golden_ratio()
    return phi
end

return M -- Crucial: You MUST return the table at the end
