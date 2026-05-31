-- define local variables
-- all variable have a value nil by default
local i, j
local i
local a,c

-- variable scope 
-- global. All variable are global by default 
-- local. limited to the function or code block scope 
-- table fields. special type of variable that can hold anything except nil.

local d , f = 5 ,10     --declaration of d and f as local variables. 
d , f = 5, 10;          --declaration of d and f as global variables. 
d, f = 10               --[[declaration of d and f as global variables. 
                           Here value of f is nil --]]

