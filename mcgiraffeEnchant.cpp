#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLESS_PRICE 10000
#define LOOP_COUNT 5000
#define START_LEVEL 0
#define FINAL_LEVEL 10

#define LLD long long int

void oneTapResult(int* level, int* stackPrice);
int compare(const void* a, const void* b);

int main() {
	srand(time(NULL));

	int eachPrice[LOOP_COUNT] = { 0, };
	LLD totalPrice = 0;

	printf("Bless Price : %d\nStartLv : %d\nFinalLv : %d\n========================\n", BLESS_PRICE, START_LEVEL, FINAL_LEVEL);
	
	for (int i = 0; i < LOOP_COUNT; i++) {
		int curLevel = START_LEVEL;
		int curPrice = 0;
		while (true) {
			oneTapResult(&curLevel, &curPrice);
			if (curLevel >= FINAL_LEVEL) {
				totalPrice += curPrice;
				eachPrice[i] = curPrice;
				break;
			}
		}
	}

	qsort(eachPrice, LOOP_COUNT, sizeof(int), compare);

	totalPrice /= LOOP_COUNT;
	printf("Estimate Price : %lld\n\n", totalPrice);

	printf("Top 1%% : %d\n", eachPrice[LOOP_COUNT / 100]);
	for (int i = 0; i < 9; i++) {
		printf("Top %d0%% : %d\n", i + 1, eachPrice[LOOP_COUNT / 10 * (i + 1)]);
	}
	printf("Top 99%% : %d\n", eachPrice[LOOP_COUNT / 100 * 99]);
}

int compare(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}

void oneTapResult(int* level, int* stackPrice) {
	int tapPrice = BLESS_PRICE + 3000 * (*level) / 4;
	int successPercentage = 10000 - (7000 * (*level) / 9);
	if (*level >= 10) successPercentage = 3000 - 290 * ((*level) - 9);
	int dice = rand() % 10000;

	if (dice <= successPercentage) { // ¼º°ø½Ã
		*level += 1;
	}
	*stackPrice += tapPrice;
}