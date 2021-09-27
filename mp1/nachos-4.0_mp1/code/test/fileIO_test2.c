#include "syscall.h"
int main()
{
	char test[12];
	char check[] = "hello world!";
	OpenFileId fid;
	int count, success, i;
	fid = Open("file1.test");
	if (fid < 0) MSG("Failed on opening file");
	count = Read(test, 12, fid);
	if (count != 12) MSG("Failed on reading file");
	success = Close(fid);
	if (success != 1) MSG("Failed on closing file");
	for (i = 0; i < 12; ++i) {
		if (test[i] != check[i]) MSG("Failed: reading wrong result"); 
	}
	MSG("Passed! ^_^");

	Halt();
}

