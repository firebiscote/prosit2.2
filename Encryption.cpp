#include "pch.h"
#include "Encryption.h"

using namespace std;

Encryption::Encryption(string path, string newPath, int level, char XORkey, int caesarKey) : File(path), c_newPath(newPath) {
	switch (level) {
	case 1:
		level1(caesarKey);
		break;
	case 2:
		level2(XORkey);
		break;
	case 3:
		level3(XORkey, caesarKey);
		break;
	default:
		break;
	}
}

void Encryption::level2(char XORkey) {
	ofstream file(c_newPath);
	if (file) {
		c_file = doXOR(XORkey);
		file << c_file;
	}
	file.close();
}

void Encryption::level1(int Ckey) {
	ofstream file(c_newPath);
	if (file) {
		c_file = doCaesar(Ckey);
		file << c_file;
	}
	file.close();
}

void Encryption::level3(char XORkey, int Ckey) {
	ofstream file(c_newPath);
	if (file) {
		c_file = doCaesar(Ckey);
		c_file = doXOR(XORkey);
		file << c_file;
	}
	file.close();
}

string Encryption::doXOR(char XORkey) {
	string XORresult;
	for (int i = 0; i < c_file.size(); i++) {
		XORresult += (char)c_file[i] ^ XORkey;
	}
	return XORresult;
}

string Encryption::doCaesar(int Ckey) {
	if (Ckey > 27) {
		Ckey = 27;
	}
	else if (Ckey < 0) {
		Ckey = 0;
	}
	string caesarResult;
	for (int i = 0; i < c_file.size(); i++) {
		caesarResult += (char)((int)(char)c_file[i] + Ckey);
	}
	return caesarResult;
}