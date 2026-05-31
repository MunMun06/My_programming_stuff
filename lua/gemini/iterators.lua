-- because lua's tables can be messy. You need a iterator to loop through them 
-- lua have 2 built-in iterators. ipairs and pair 

-- ipairs 
-- only use this when you treat your table as a strict, sequential array 
-- iterate from 1 until it hit nil. Even if there are value behind the nil
-- return the integer index and the value..
local tools = { "neovim", "tmux", [4] = "fzf", terminal = "kitty" }
-- Internal layout: 1:"neovim", 2:"tmux", 3:nil, 4:"fzf", "terminal":"kitty"

-- for value, index in ipairs(tools) do -- this also work, just use print(index, value)
for index, value in ipairs(tools) do
    print(index, value)
end

--[[ Output:
1   neovim
2   tmux

(It stopped at index 3 because it was nil, ignoring index 4 and the string key!)
--]]

-- pairs 
-- use this when you want to look at everything in a table.
-- the order of iteration is random. You only know that it would iterate over the entire table, not its order

for index, value in pairs(tools) do
    print(index, value)
end

-- custom iterator 
-- a for loop using iterator expect the iterator to return nil then it would end the iteration through the table.
local function reverse_iterator(t)
    local index = #t + 1 -- Start outside the upper bound
    
    -- Return the actual worker function that the 'for' loop will call
    return function()
        index = index - 1
        if index > 0 then
            return index, t[index] -- Return key and value
        end
        -- Returns nil implicitly when index hits 0, which breaks the loop
    end
end

local list = { "a", "b", "c" }

for i, v in reverse_iterator(list) do
    print(i, v)
end
--[[ Output:
3   c
2   b
1   a
--]]

-- some example of why not to trust pair's ordering
local config = {
    theme = "gruvbox",
    opacity = 0.85,
    font_size = 14,
    line_numbers = true
}

for k, v in pairs(config) do
    print(k, v)
end
