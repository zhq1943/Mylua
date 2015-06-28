extern "C"
{
#include "lua/src/lua.h"
#include "lua/src/lualib.h"
#include "lua/src/lauxlib.h"
} 

#include <iostream>
#include <string>

using namespace std;

void TestLua()

{

	lua_State *L = luaL_newstate();

	luaopen_base(L); //

	luaopen_table(L); //

	luaopen_package(L); //

	luaopen_io(L); //

	luaopen_string(L); //



	luaL_openlibs(L); //打开以上所有的lib



	string str;





	while (true)

	{

		cout << "请输入Lua代码:" << endl;

		getline(cin, str, '\n');

		if (luaL_loadstring(L, str.c_str())

			|| lua_pcall(L, 0, 0, 0) )

		{

			const char * error = lua_tostring(L, -1) ;

			cout << string(error) << endl;

		}

	}

	lua_close(L);

}

int main()
{
	TestLua();
	return 0;
}