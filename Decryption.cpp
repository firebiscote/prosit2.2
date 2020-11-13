#include "pch.h"
#include "Decryption.h"

using namespace std;

Decryption::Decryption(string path, string newPath, int level, char XORkey, int caesarKey) : File(path), c_newPath(newPath) {
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

void Decryption::level2(char XORkey) {
	ofstream file(c_newPath);
	if (file) {
		c_file = undoXOR(XORkey);
		file << c_file;
	}
	file.close();
}

void Decryption::level1(int Ckey) {
	ofstream file(c_newPath);
	if (file) {
		c_file = undoCaesar(Ckey);
		file << c_file;
	}
	file.close();
}

void Decryption::level3(char XORkey, int Ckey) {
	ofstream file(c_newPath);
	if (file) {
		c_file = undoXOR(XORkey);
		c_file = undoCaesar(Ckey);
		file << c_file;
	}
	file.close();
}

string Decryption::undoXOR(char XORkey) {
	string XORresult;
	for (int i = 0; i < c_file.size(); i++) {
		XORresult += (char)c_file[i] ^ XORkey;
	}
	return XORresult;
}

string Decryption::undoCaesar(int Ckey) {
	if (Ckey > 27) {
		Ckey = 27;
	}
	else if (Ckey < 0) {
		Ckey = 0;
	}
	string caesarResult;
	for (int i = 0; i < c_file.size(); i++) {
		caesarResult += (char)((int)(char)c_file[i] - Ckey);
	}
	return caesarResult;
}