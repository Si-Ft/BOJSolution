import sys
sys.stdin = open('input.txt', 'r')

def is_triplet_or_run(cards):
    for i in range(10):
        if cards[i] >= 3:
            return True
    for i in range(8):
        if cards[i] >= 1 and cards[i+1] >= 1 and cards[i+2] >= 1:
            return True
    return False

T = int(input())
for tc in range(1, T + 1):
    deck = list(map(int, input().split()))
    winner = 0
    # idx : 각 카드의 번호 / value : 카드 번호의 카드 장 수
    p1 = [0] * 10
    p2 = [0] * 10

    # 조건을 1p -> 2p 순서대로 확인, 먼저 완성대는 대로 중지하고 출력
    for i in range(0,12,2):
        p1[deck[i]] += 1
        p2[deck[i+1]] += 1
        if is_triplet_or_run(p1):
            winner = 1
            break
        if is_triplet_or_run(p2):
            winner = 2
            break
    print(f'#{tc} {winner}')