#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

int main() {

	for (;;) {
		int input;
		scanf("%d", &input);
		if (input == 0) break;

		char sentence[1000001];
		char letters[257] = { 0, };
		getchar();
		scanf("%[^\n]s", sentence);

		int start = 0;
		int end = 0;
		int best = 0;

		//글자 하나하나봄
		for (; sentence[end]; end++) {
			letters[sentence[end]] += 1;

			//cnt는 글자의 종류
			int cnt = 0;
			for (int i = 0; i < 257; i++) {
				if (letters[i] != 0) cnt += 1;
			}

			//글자종류가 너무 많으면 제거하는 코드
			if (cnt > input) {
				for (;;) {
					letters[sentence[start]] -= 1;
					if (letters[sentence[start]] == 0)
					{
						start++;
						break;
					}
					start++;
				}
			}

			best = max(best, end - start + 1);
		}

		printf("%d\n", best);
	}
	return 0;
}