//Consider using Anonymous Namespaces instead of these Singletons/Static methods!

#pragma once

#include "../Quad.hpp"

extern "C"
{ 
	#include <lua5.1/lua.h>
	#include <lua5.1/lauxlib.h>
	#include <lua5.1/lualib.h>
}

class lua_quad
{
    static void lua_CreateQuad()
    {
        
    }

    private:
        lua_quad();
        ~lua_quad();
};

