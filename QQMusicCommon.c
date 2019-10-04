#include "des.h"

#pragma comment(linker, "/export:?des@qqmusic@@YAHPAE0H@Z=des")
int des(unsigned char* buff, unsigned char* key, int len) {
	BYTE schedule[16][6];
	des_key_setup(key, schedule, DES_ENCRYPT);
	for (int i = 0; i < len; i += 8)
		des_crypt(buff + i, buff + i, schedule);
	return 0;
}

#pragma comment(linker, "/export:?Ddes@qqmusic@@YAHPAE0H@Z=Ddes")
int Ddes(unsigned char* buff, unsigned char* key, int len) {
	BYTE schedule[16][6];
	des_key_setup(key, schedule, DES_DECRYPT);
	for (int i = 0; i < len; i += 8)
		des_crypt(buff + i, buff + i, schedule);
	return 0;
}
