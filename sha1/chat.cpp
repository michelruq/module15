#include "chat.h"
#include "iostream"
#include "string.h"

Chat::Chat() : oSha1()
{
    data_count = 0;
}
void Chat::reg(char _login[LOGINLENGTH], char _pass[], int pass_length) 
{
    data[data_count++] = AuthData(_login, oSha1.GetHash(_pass, pass_length));
    
}
bool Chat::login(char _login[LOGINLENGTH], char _pass[], int pass_length) 
{
    std::uint32_t i = static_cast<std::uint32_t>(0);
	
	for(; i < data_count; i++) 
	{
        AuthData& ad = data[i];
        if (!strcmp(ad.login, _login)) 
		{
            break;
        }
    }
	
    if(i >= data_count) return false;
    
    std::uint32_t* digest = oSha1.GetHash(_pass, pass_length);
    
    bool cmpHashes = !memcmp(data[i].pass_sha1_hash, digest, SHA1HASHLENGTHBYTES);
	
    delete[] digest;
	
    return cmpHashes;
}