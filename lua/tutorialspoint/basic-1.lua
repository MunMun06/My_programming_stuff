-- this is a comment 

--[[ 
  this 
  is 
  a 
  multi-
  line
  comment 
  -- and [] need to be next to each other with not gaps
--]]

io.write("Hello world, from ",_VERSION,"!\n")

-- you can run lua file in 3 ways. 
-- Repl mode on the terminal 
-- Passing a lua file to lua to interpret 
-- using a shebang and run it as ./test.lua kinda like a shell script

-- identifier 
-- are name to identify any user-defined object
-- An identifier starts with a letter ‘A to Z’ or ‘a to z’ or an underscore ‘_’ followed by zero or more letters, underscores, and digits (0 to 9).
-- lua is case sensitive with identifier.

-- Lua reserved keywords (21 keywords)
-- and, break, do, else, elseif, end, false, for, function, if, in, local, nil, not, or, repeat, return, then, true, until, while

-- lua is written in C and uses C library for some function

-- lua require less memory because its very small.

-- z = 10
print(z) -- unassigned variable or identifier are nil by default

x = 11
-- print(x)

-- ans

--[[
print(110)
--]]

---[[
print("str")
--]]

print("Hello, World!")



-- define local variables
-- all variable have a value nil by default
local i, j
local i
local c

-- variable scope 
-- global. All variable are global by default 
-- local. limited to the function or code block scope 
-- table fields. special type of variable that can hold anything except nil.

local d , f = 5 ,10     --declaration of d and f as local variables. 
d , f = 5, 10;          --declaration of d and f as global variables. 
d, f = 10               --[[declaration of d and f as global variables. 
                           Here value of f is nil --]]

local a, b  -- declaration

-- definition
a = 10
b = 30

print("value of a:", a)
print("value of b:", b)

-- Swapping of variables
b, a = a, b

print("value of a:", a)
print("value of b:", b)

f = 70.0/3.0
print("value of f", f)

-- just finished the lua-Basic:Variables
