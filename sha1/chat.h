#pragma once
#include <cstdint>

#include "sha1.h"
#include "string.h"
#include "sha1.h"

#define SHA1HASHLENGTHBYTES 20
#define SHA1HASHLENGTHUINTS 5

#define SIZE 10
#define LOGINLENGTH 10

class Chat {
    public:
        Chat();
        void reg(char _login[LOGINLENGTH], char _pass[], int pass_length);
        bool login(char _login[LOGINLENGTH], char _pass[], int pass_length);

    private:
        struct AuthData {
            AuthData(): 
                login(""),
                pass_sha1_hash(0) {
            }
            ~AuthData() {
                if(pass_sha1_hash != 0 )
                    delete [] pass_sha1_hash;
            }
            AuthData(char _login[LOGINLENGTH], std::uint32_t* sh1) {
                strcpy(login, _login);
                pass_sha1_hash = sh1;
            }
            AuthData& operator = (const AuthData& other) {
                strcpy(login, other.login);
                
                if(pass_sha1_hash != 0)
                    delete [] pass_sha1_hash;
                pass_sha1_hash = new std::uint32_t[SHA1HASHLENGTHUINTS];
                
                memcpy(pass_sha1_hash, other.pass_sha1_hash, SHA1HASHLENGTHBYTES);
                
                return *this;
            }           
            char login[LOGINLENGTH];
            std::uint32_t* pass_sha1_hash;
        };
    AuthData data[SIZE];
    std::uint32_t data_count;
	Sha1 oSha1;
};