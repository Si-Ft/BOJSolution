# X 성분(CX) 판별 함수
def is_CX(s):
    if s == "X":
        return True
    if len(s) > 1 and s[-1] == 'X':
        return is_SX(s[:-1])
    return False

# Y 성분(CY) 판별 함수
def is_CY(s):
    if s == "Y":
        return True
    if len(s) > 1 and s[-1] == 'Y':
        return is_SY(s[:-1])
    return False

# X성분을 포함하는 용액(SX) 판별 함수
def is_SX(s):
    if not s.endswith('O'):
        return False
    
    body = s[:-1] 
    
    if is_CX(body):
        return True
    
    for k in range(1, len(body)):
        left, right = body[:k], body[k:]
        if (is_CX(left) and is_CY(right)) or (is_CY(left) and is_CX(right)):
            return True
            
    return False

# Y성분을 포함하는 용액(SY) 판별 함수
def is_SY(s):
    if not s.endswith('O'):
        return False
    
    body = s[:-1]
    
    if is_CY(body):
        return True
    
    for k in range(1, len(body)):
        left, right = body[:k], body[k:]
        if (is_CX(left) and is_CY(right)) or (is_CY(left) and is_CX(right)):
            return True
            
    return False

T = int(input())
for tc in range(1,T+1):
    N = int(input())
    s = input().strip()
    if is_SX(s) or is_SY(s):
        print(f"#{tc} YES")
    else:
        print(f"#{tc} NO")