bomb = 'O'
block = 'X'
empty = ' '
propag = '*'
breakable = '~'

GO_RIGHT = 0
GO_LEFT = 1
GO_UP = 2
GO_DOWN = 3
DROP_BOMB = 4


dir_y = {-1,0,1,0}
dir_x = {0,-1,0,1}
dir = {"UP", "LEFT", "DOWN", "RIGHT"}


function replace_char(pos, str, r)
   return str:sub(1, pos-1) .. r .. str:sub(pos+1)
end

function in_danger(map, x, y)
   local a, b = map:find("\n")
   if map:sub(a * y + x + 1, a * y + x + 1) == propag then
      return true
   else
      return false
   end
end

function getMapValue(map, x, y)
   local a, b = map:find("\n")
   return map:sub(a * y + x + 1, a * y + x + 1)
end

function ai(map, x, y)
   local max_x, max_y = map:find('\n')
   return math.random(5)
end
