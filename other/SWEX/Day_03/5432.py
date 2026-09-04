import sys
sys.stdin = open('input.txt', 'r')
T=int(input())
for tc in range(1, T+1):
    ans = 0
    st=0
    string = input()
    for i in range(len(string)):
        if string[i] == '(':
            st += 2
        st -= 1

        # 레이저일 경우
        if string[i] == ')' and string[i-1] == '(':
            ans += st
        elif string[i] == ')':
            ans += 1
    print(f"#{tc} {ans}")