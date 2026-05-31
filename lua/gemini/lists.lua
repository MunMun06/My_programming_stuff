-- disgustingly create linked list from nesting tables

-- singly linked list 
-- Create the tail node first
local list = { value = "Node C", next = nil }

-- Prepend Node B
list = { value = "Node B", next = list }

-- Prepend Node A (This becomes our head pointer)
list = { value = "Node A", next = list }
-- the raw structure
-- { value = "Node A", next = { value = "Node B", next = { value = "Node C", next = nil } } }

-- traversing a linked list 
-- intiailze a "pointer" head and update it to point to node.next in a while loop until it hit nil
local current = list

while current ~= nil do
    print(current.value)
    current = current.next -- Move pointer to the next table reference
end

--[[ Output:
Node A
Node B
Node C
--]]

-- a proper deque
-- gemini goes crazy and wrote 4 function for managing a deque with "pointer" first and last 
-- but i think lilbro ran out of memory. Broski made pop_left but not pop_right
-- push are both O(1)
-- lua allow negative integer keys

local List = {}

-- Create a fresh, empty list structure
function List.new()
    return { first = 0, last = -1 }
end

-- Push an item to the front of the list
function List.push_left(list, value)
    local first = list.first - 1
    list.first = first
    list[first] = value
end

-- Push an item to the back of the list
function List.push_right(list, value)
    local last = list.last + 1
    list.last = last
    list[last] = value
end

-- Pop an item from the front of the list
function List.pop_left(list)
    local first = list.first
    if first > list.last then error("List is empty") end
    
    local value = list[first]
    list[first] = nil -- Clean up the slot for garbage collection
    list.first = first + 1
    return value
end
