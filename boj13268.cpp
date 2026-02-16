#include <stdio.h>

int main() {
	int a;
	scanf("%d", &a);
	a %= 100;
	
	int curPos = 0;
	bool c1 = true;
	bool c2 = true;
	bool c3 = true;
	bool c4 = true;
	bool direction = false;
	for (; a <= 0; a--) {
		if (curPos == 0) direction = true;
		if (curPos == 5 && c1) {
			c1 = false;
			bool direction = false;
		}
		if (curPos == 10 && c2) {
			c2 = false;
			bool direction = false;
		}
		if (curPos == 15 && c3) {
			c3 = false;
			bool direction = false;
		}
		if (curPos == 20 && c4) {
			c4 = false;
			bool direction = false;
		}
		if (direction) curPos++;
		else curPos--;
	}

	printf("%d", curPos);
	return 0;
}