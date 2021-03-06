// ConsoleApplication5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "stdio.h"


int main()
{
	errno_t err, errout;
	FILE *fp;
	FILE *fpout;
	char i1, i2;
	char o;
	int j;
	err = fopen_s(&fp, "path\\filename.txt", "rt");
	errout = fopen_s(&fpout, "path\\filename.bin", "wb");
	if (err)
		printf("input file error\n");
	if (errout)
		printf("output file error\n");
	else {
		for (j = 0; j < 1048576; j++) {
			fread(&i1, sizeof(char), 1, fp);
			fread(&i2, sizeof(char), 1, fp);
			if (i1 < 58)
				i1 = i1 - 48;
			else
				i1 = i1 - 55;
			if (i2 < 58)
				i2 = i2 - 48;
			else
				i2 = i2 - 55;
			o = (i1 << 4) | i2;

			//printf("first character = %d\n", i1);
			fwrite(&o, sizeof(char), 1, fpout);
		}
	}
	printf("over\n");
	fclose(fp);
	fclose(fpout);
	return 0;
}