import sys
import time
from io import StringIO

def main():
    passes = 0
    failures = 0
    remaining = len(ANSWERS)
    total_time = 0

    print(f"Running tests for {len(ANSWERS)} problems...")
    print("Problem\t\tTime Elapsed")
    for problem, answer in sorted(ANSWERS.items()):
        old_stdout = sys.stdout
        problem_output = sys.stdout = StringIO()

        elapsed_time = 0

        with open(f"problem{problem:03}.py") as file:
            file_contents = file.read()
            start_time = time.perf_counter_ns() // 1000000
            exec(file_contents, globals())
            elapsed_time = time.perf_counter_ns() // 1000000 - start_time or 1
            total_time += elapsed_time

        result = str(problem_output.getvalue()).strip()
        sys.stdout = old_stdout # reset stdout

        if result == answer:
            warning = ""
            passes += 1
        else:
            warning = f"*** FAIL ***  result: {result} expected: {answer}"
            failures += 1
        remaining -= 1

        print(f"\r{' '*70}\r", end="")
        print(f"Problem {problem:03}: {elapsed_time:7} ms  {warning}")

    print(f"Elapsed: {total_time} ms, Passed: {passes}, Failed: {failures}")


ANSWERS = {
    1: "233168",
    2: "4613732",
    3: "6857",
    4: "906609",
    5: "232792560",
    6: "25164150",
    7: "104743",
    8: "23514624000",
    9: "31875000",
    10: "142913828922",
    11: "70600674",
    12: "76576500",
    13: "5537376230",
    14: "837799",
    15: "137846528820",
    16: "1366",
    17: "21124",
    18: "1074",
    19: "171",
    20: "648",
    21: "31626",
    22: "871198282",
    23: "4179871",
    24: "2783915460",
}


if __name__ == "__main__":
    main()
