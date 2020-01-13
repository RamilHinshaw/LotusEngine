-- local quad = require("scripts.Lotus.quad")

print ("Hello World!")

local person = {}

person.name = "Joe"
person.age = 25

function person:display()
    print(person.name)
    print(person.age)    
end

person:display()
print(Double(100))
CreateQuad();

--------------------------------------

function Init(dt)
	print("[LUA] "..dt.." initializing...")

	-- Create sprite object (give pic)

end

function Update(dt)
	print("[LUA] updating...")
	-- Should execute registered c++ calls here!

	-- can move sprite object
end

-- Possibly LateUpdate and FixedUpdate?

function Draw(dt)
	print("[LUA] drawing...")


	-- Draw Sprite Object
end