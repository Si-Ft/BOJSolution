import random
import sys

# 재귀 깊이 설정 (N <= 30이므로 소량으로 충분)
sys.setrecursionlimit(2000)


# ==========================================
# 1. AST (추상 구문 트리) 노드 및 엄격 검증 클래스
# ==========================================
class BaseComponent:

  def __init__(self, comp_type: str):
    assert comp_type in ('X', 'Y')
    self.comp_type = comp_type
    self.str = comp_type
    self.length = 1


class ExtractedComponent:

  def __init__(self, solution, extract_type: str):
    assert extract_type in ('X', 'Y')

    # [핵심 검증]: 추출하려는 성분이 실제 해당 용액에 존재하는지 검사
    if extract_type == 'X':
      assert (
          solution.has_x
      ), "X가 들어있지 않은 용액에서는 X를 추출할 수 없습니다!"
    else:
      assert (
          solution.has_y
      ), "Y가 들어있지 않은 용액에서는 Y를 추출할 수 없습니다!"

    self.solution = solution
    self.comp_type = extract_type
    self.str = solution.str + extract_type
    self.length = solution.length + 1


class OneCompSolution:

  def __init__(self, component):
    self.component = component
    self.str = component.str + "O"
    self.length = component.length + 1
    self.has_x = component.comp_type == "X"
    self.has_y = component.comp_type == "Y"


class TwoCompSolution:

  def __init__(self, comp1, comp2):
    # [핵심 검증]: 2성분 용액은 반드시 서로 다른 두 성분(X, Y)의 조합이어야 함
    assert (comp1.comp_type == "X" and comp2.comp_type == "Y") or (
        comp1.comp_type == "Y" and comp2.comp_type == "X"
    ), "동일한 성분 2개로는 용액을 만들 수 없습니다!"

    self.comp1 = comp1
    self.comp2 = comp2
    self.str = comp1.str + comp2.str + "O"
    self.length = comp1.length + comp2.length + 1
    self.has_x = True
    self.has_y = True


# ==========================================
# 2. 보장된 올바른(YES) AST 생성기
# ==========================================
def build_component(length: int, comp_type: str):
  if length == 1:
    return BaseComponent(comp_type)
  if length == 2:
    raise ValueError("길이 2짜리 추출 성분은 존재할 수 없습니다.")

  sol = build_solution(length - 1, req_type=comp_type)
  return ExtractedComponent(sol, comp_type)


def build_solution(length: int, req_type: str = "ANY"):
  if length < 2:
    raise ValueError("용액의 최소 길이는 2 이상이어야 합니다.")

  if length == 2:
    c_type = req_type if req_type in ("X", "Y") else "X"
    c = build_component(1, c_type)
    return OneCompSolution(c)

  if length == 3:
    c1 = build_component(1, "X")
    c2 = build_component(1, "Y")
    return (
        TwoCompSolution(c1, c2)
        if random.random() < 0.5
        else TwoCompSolution(c2, c1)
    )

  if length == 4:
    c_type = (
        req_type
        if req_type in ("X", "Y")
        else ("X" if random.random() < 0.5 else "Y")
    )
    c = build_component(3, c_type)
    return OneCompSolution(c)

  # length >= 5
  total_comp = length - 1

  # 1성분 용액으로 구성할지 2성분 용액으로 구성할지 결정
  use_1comp = (
      (random.random() < 0.3)
      if req_type == "ANY"
      else (random.random() < 0.2)
  )

  if use_1comp:
    target_comp_type = (
        req_type
        if req_type in ("X", "Y")
        else ("X" if random.random() < 0.5 else "Y")
    )
    c = build_component(total_comp, target_comp_type)
    return OneCompSolution(c)
  else:
    # 2성분 용액 구성 (total_comp = c1 + c2, c1 != 2, c2 != 2)
    mid = total_comp // 2
    candidates = [
        c
        for c in range(1, total_comp)
        if c != 2 and (total_comp - c) != 2
    ]
    c1 = random.choice(candidates) if candidates else 1
    c2 = total_comp - c1

    t1, t2 = ("X", "Y") if random.random() < 0.5 else ("Y", "X")
    comp1 = build_component(c1, t1)
    comp2 = build_component(c2, t2)
    return TwoCompSolution(comp1, comp2)


# ==========================================
# 3. 정교한 NO 변형(Mutation) 함수
# ==========================================
def mutate_to_no(valid_str: str) -> str:
  mutation_type = random.randint(0, 4)
  s_list = list(valid_str)

  if mutation_type == 0:
    # 맨 끝 O를 지워 추출 상태로 남김 (미완성 용액)
    s_list[-1] = "X" if random.random() < 0.5 else "Y"
  elif mutation_type == 1:
    # 중복 성분 투입 (XYO -> XXO)
    idx = valid_str.find("XYO")
    if idx != -1:
      s_list[idx + 1] = "X"
    else:
      s_list[-1] = "X"
  elif mutation_type == 2:
    # 존재하지 않는 성분 추출 유도 (XO -> XOY)
    idx = valid_str.find("XO")
    if idx != -1 and idx + 2 < len(s_list):
      s_list[idx + 2] = "Y"
    else:
      s_list[0] = "O"
  elif mutation_type == 3:
    # 문법을 깨부수기 위해 맨 앞에 O 배치
    s_list[0] = "O"
  else:
    # 맨 끝 글자 잘라내기
    return valid_str[:-1]

  return "".join(s_list)


# ==========================================
# 4. 메인 테스트케이스 생성기 (T=40, N<=30)
# ==========================================
def generate_testcases():
  random.seed(42)  # 재현성을 위한 시드 고정

  # T=40, N<=30을 위한 그룹 배치
  groups = [
      {"count": 10, "min_len": 2, "max_len": 10},
      {"count": 15, "min_len": 11, "max_len": 20},
      {"count": 15, "min_len": 21, "max_len": 30},
  ]

  total_cases = 40

  with (
      open("input.txt", "w", encoding="utf-8") as f_in,
      open("output.txt", "w", encoding="utf-8") as f_out,
  ):

    f_in.write(f"{total_cases}\n")
    tc_num = 1

    for group in groups:
      yes_count = int(group["count"] * 0.4)  # 그룹당 40% YES 배정

      for i in range(group["count"]):
        target_len = random.randint(group["min_len"], group["max_len"])
        is_yes = i < yes_count

        # 1. AST 생성을 통한 100% 유효한 YES 문자열 제작
        ast_root = build_solution(target_len, req_type="ANY")
        string_data = ast_root.str

        # 2. NO 케이스일 경우 정교한 훼손 적용
        if not is_yes:
          string_data = mutate_to_no(string_data)

        actual_len = len(string_data)
        result_str = "YES" if is_yes else "NO"

        f_in.write(f"{actual_len}\n{string_data}\n")
        f_out.write(f"#{tc_num} {result_str}\n")

        tc_num += 1

  print(
      f"생성 완료: {total_cases}개의 테스트케이스(N <= 30)가 성공적으로 생성되었습니다."
  )


if __name__ == "__main__":
  generate_testcases()