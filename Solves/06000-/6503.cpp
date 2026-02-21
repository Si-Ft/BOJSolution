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

		for (; sentence[end]; end++) {
			letters[sentence[end]] += 1;

			int cnt = 0;
			for (int i = 0; i < 257; i++) {
				if (letters[i] != 0) cnt += 1;
			}

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