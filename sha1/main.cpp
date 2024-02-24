#include <iostream>
#include <cstdint>
#include <iomanip>
#include "sha1.h"
#include "chat.h"

Sha1 oSha1;
Chat oChat;

void throwHere(const std::string& text) 
{
    std::cout << "Throw text: " << text.c_str() << std::endl;
    throw 1;
}

int main(int argc, char* argv[])
{
	char typ[] = "qwerty12345";
	
	std::uint32_t* digest = oSha1.GetHash(typ, sizeof(typ) - 1);
	
	for(int i = 0; i < 5; i++) 
	{
        std::cout << std::hex << std::setw(8) << std::setfill('0') << digest[i] << " ";
    }
	
    delete[] digest;
	
	bool good = false;
	
	try 
	{
		oChat.reg((char*)"user1", (char*)"qwerty12345", sizeof("qwerty12345"));
		oChat.reg((char*)"user2", (char*)"asdfg", sizeof("asdfg"));
		oChat.reg((char*)"user3", (char*)"zsdrt", sizeof("zsdrt"));
		oChat.reg((char*)"user4", (char*)"pasgas", sizeof("pasgas"));
		oChat.reg((char*)"dfd11111", (char*)"pasgas", sizeof("pasgas"));
		oChat.reg((char*)"sdgss", (char*)"pasgas", sizeof("pasgas"));
		oChat.reg((char*)"xzxvxcccc", (char*)"pasgas", sizeof("pasgas"));
		oChat.reg((char*)"123", (char*)"pasgas", sizeof("pasgas"));
		oChat.reg((char*)"34", (char*)"pasgas", sizeof("pasgas"));
		oChat.reg((char*)"111", (char*)"pasgas", sizeof("pasgas"));
		
		if (!oChat.login((char*)"user1", (char*)"qwerty12345", sizeof("qwerty12345")))  throwHere("in c.login() user1");
        if (!oChat.login((char*)"user2", (char*)"asdfg", sizeof("asdfg")))  throwHere("in c.login() user2");
        if (!oChat.login((char*)"user3", (char*)"zsdrt", sizeof("zsdrt")))  throwHere("in c.login() user3");
        if (!oChat.login((char*)"user3", (char*)"zsdrt", sizeof("zsdrt")))  throwHere("in c.login() user3");
        if (!oChat.login((char*)"user4", (char*)"pasgas", sizeof("pasgas")))  throwHere("in c.login() user4");
        if (!oChat.login((char*)"xzxvxcccc", (char*)"pasgas", sizeof("pasgas")))  throwHere("in c.login() xzxvxcccc");
        if (!oChat.login((char*)"123", (char*)"pasgas", sizeof("pasgas")))  throwHere("in c.login() 123");
        if (!oChat.login((char*)"34", (char*)"pasgas", sizeof("pasgas")))  throwHere("in c.login() 34");

        if (!oChat.login((char*)"111", (char*)"pasgas", sizeof("pasgas")))  throwHere("in c.login() 111");
        if (!oChat.login((char*)"dfd11111", (char*)"pasgas", sizeof("pasgas")))  throwHere("in c.login() dfd11111");

        if (oChat.login((char*)"user2", (char*)"qwerty12345", sizeof("qwerty12345"))) throwHere("in test() user2 bad pass");
        if (!oChat.login((char*)"non-exuser", (char*)"pass", sizeof("pass"))) throwHere("in test() non-ex_user");
	
	    good = true;
	
	}
	catch (...) 
	{
        good = false;
    }
	
	if (good) {
        std::cout << "Tests have been passed" << std::endl;
    }
    else {
        std::cout << "Tests have been failed" << std::endl;
    }
	
    return 0;
}