#include "pch.h"
#include "File.h"

using namespace std;

File::File() {
}

File::File(string path) {
	ifstream file(path);
	if (file) {
		char tmp;
		while (file.get(tmp)) {
			c_file += tmp;
		}
		c_path = path;
	}
	file.close();
}