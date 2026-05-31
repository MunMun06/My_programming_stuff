-- This is a single-line comment

--[[
    This is a multi-line
    comment block.
--]]

local dynamic = 42        -- Currently a number
dynamic = "Now a string"  -- Perfectly valid

-- only 8 basic types. nil, boolean, number, string, function, userdata, thread, table

-- you should always default to local. global variable pollute global environment and namespace. And are slower to access

function scope_example()
    local local_var = "I am safe and scoped to this function"
    global_var = "I just leaked into the global scope!"
end

scope_example()
print(global_var) -- Output: I just leaked into the global scope!
print(local_var)  -- Output: nil (because it doesn't exist out here)

-- code block use keywords instead of curly braces or indentation 

local condition = true

if not condition then      -- { Block 1 opens after 'then'
    print("This won't run")
                           -- } Block 1 closes here because 'elseif' starts
elseif condition then      -- { Block 2 opens after 'then'
    print("This will run")
                           -- } Block 2 closes here because 'else' starts
else                       -- { Block 3 opens after 'else'
    print("Fallback")
end                        -- } Block 3 closes here, and the entire 'if' statement ends
                           -- end mean the control structure is ended

-- only nil and false are falsy. Everything else evalue to true
-- any number is true, an empty string is true.

-- Standard while loop
local i = 1
while i <= 3 do
    print("while:", i)
    i = i + 1
end

-- Numeric for loop: for variable = start, stop, [step]
for j = 1, 3 do -- going from 1 to 3
    print("for:", j)
end

-- Counting downwards with a step of -1
for j = 3, 1, -1 do -- going from 3 to 1 with step size -1
    print("countdown:", j)
end
