function bar(a, b, c)
  print(a, b, c)
  return 4, 8, 15, 16, 23, 42
end

x, y = bar('zaphod')  --> prints "zaphod  nil nil"
-- x, y = bar('zaphod')  --> prints "zaphod  nil nil"

print(x);
print(y);

lmao = nil 

print(lmao);
io.write("apparently write expect string so nil wont work");

if x == 10 then 
  local y = 65
  print(y)
else 
  local y = 13 
  print(y)
end 

print(y) -- global 


-- A one-table-param function call needs no parens:
function h(x) print(x.key1) end
h{key1 = 'Sonmi~451'}  -- Prints 'Sonmi~451'.

function h(y) print(y.key1, y.key2) end
h{key1 = 'Sonmi~451', key2 = "mdsmkkm"}  -- Prints 'Sonmi~451'.

u = {['@!#'] = 'qbert', [{}] = 1729, [6.28] = 'tau'}

for key, val in pairs(u) do  -- Table iteration.
  print(key, val)
end
