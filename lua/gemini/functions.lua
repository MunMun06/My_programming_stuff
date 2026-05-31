-- a function is a value with a type function
-- you can store functions in variables, pass them as arguments, return them from functions. And store them in data structures.

-- Style 1: Standard definition
local function add(a, b)
    return a + b
end

-- Style 2: Functional assignment (Shows that functions are just values)
-- local add = function(a, b)
--    return a + b
-- end

local j,k = 42,342

print(add(j,k))

-- lua native support returning multiple values without needing other object.
local function get_bounds()
    local min = 1
    local max = 100
    return min, max -- Returning two distinct values
end

-- Receiving the values
local low, high = get_bounds()
print(low)  -- Output: 1
print(high) -- Output: 100

-- how lua handle mismatch with returned and received variables.
-- if received too many, extra values are discarded 
-- if received too few, extra variables are assigned to nil
local low = get_bounds()      -- 'max' is discarded; low = 1
local x, y, z = get_bounds()  -- z gets no matching value; z = nil

-- variadic functions (vararg)
-- when a function accept an unknown amount of arguments 
-- use the elipse ... 

local function sum_all(...)
    -- Pack the arguments into an array block to count them
    local args = {...}
    local total = 0

    for i = 1, #args do
        total = total + args[i]
    end

    return total
end

print(sum_all(10, 20, 30)) -- Output: 60

-- closure and lexical scoping 
-- in lua. if an inner function hold on to local variable. That variable is move to the heap.
-- each function has a fresh instance of the local variable

local function create_counter(start_value)
    local count = start_value -- This variable becomes an "upvalue"

    -- Returning an anonymous inner function
    return function()
        count = count + 1 -- Modifies the upvalue
        return count
    end
end

-- Create two completely isolated counters
local counter_a = create_counter(0)
local counter_b = create_counter(100)

print(counter_a()) -- Output: 1
print(counter_a()) -- Output: 2

print(counter_b()) -- Output: 101 (Independent from counter_a)
