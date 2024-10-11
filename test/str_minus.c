#include <stdio.h>

int main(void)
{
	char str[5] = "abcd\0";
	char m_str[5] = "e\0";

	printf("%s, %s\n", str, m_str);
	printf("%ld\n", m_str - str);
	printf("%ld\n", m_str);
}
