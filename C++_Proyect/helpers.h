#pragma once

char* copyStr(const char* str)
{
	if (!str) return nullptr;

	int len = strlen(str) + 1;
	char* newStr = new char[len];
	strcpy_s(newStr, len, str);
	return newStr;
}
