-- lua strings are completely immutable. When a string changes, lua create an entirely new one in memory

local single = 'Hello'
local double = "World"

-- Multi-line / Raw string using double square brackets
local multi_line = [[
    This is a raw string.
    Escape sequences like \n won't evaluate here.
    It preserves line breaks exactly as written.
]]

-- .. is the concat operator
-- concatenating multiple strings together in a performance nightmare

local framework = "Hypr"
local tool = "land"

-- Coercion example:
print("10" + 2) -- Output: 12 (Lua converts "10" to a number)

-- Correct concatenation:
local full_name = framework .. tool
print(full_name) -- Output: Hyprland

-- # is the length operator for string. It measure byte not character.
-- in ASCII its is 1-1 match. But in UTF-8 we will see some mismatch
local text = "Neovim"
print(#text) -- Output: 6

-- lua have a bulit-in string library. You can call these functions or call the methods directly on the string with : syntax
local message = "  Hello, Lua User!  "

-- 1. Case Manipulation
print(string.upper(message)) -- Output: "  HELLO, LUA USER!  "
print(message:lower())       -- Output: "  hello, lua user!  " (Cleaner syntax)

-- 2. Substrings: string.sub(s, start, end)
-- Note: Lua uses 1-based indexing!
local word = "Configuration"
print(word:sub(1, 4))        -- Output: Conf
print(word:sub(-5))          -- Output: ation (Negative indices count from the end)

-- 3. Formatting (Similar to C's sprintf)
local status = string.format("Item: %s, Count: %d, Error Rate: %.2f%%", "Packet", 5, 0.123)
print(status) -- Output: Item: Packet, Count: 5, Error Rate: 0.12%

-- patern matching. lua dont support standard POSIX regex.
-- instead of \, it uses % as its escape character 
-- %d       any digit 
-- %a       any letter 
-- %s       any whitespace 
-- %w       any alphanumeric character 
-- %x       any hexadecimal 

local log = "Error code: 404 at line 23"

-- string.match returns the captures if a pattern is found
local code = log:match("%d+")
print(code) -- Output: 404 (Matches the first sequence of digits)

-- string.gsub replaces occurrences (Global Substitution)
local clean_log = log:gsub("%d+", "[REDACTED]")
print(clean_log) -- Output: Error code: [REDACTED] at line [REDACTED]
                 -- WHAT THE HELL IS THIS, THE EPSTEIN FILE?????
