#!/usr/bin/env bash

declare -A ANSWERS=(
  [1]="233168"
  [2]="4613732"
  [3]="6857"
  [4]="906609"
  [5]="232792560"
  [6]="25164150"
  [7]="104743"
  [8]="23514624000"
  [9]="31875000"
  [10]="142913828922"
  [11]="70600674"
  [12]="76576500"
  [13]="5537376230"
  [14]="837799"
  [15]="137846528820"
  [16]="1366"
  [17]="21124"
  [18]="1074"
  [19]="171"
)

ms() { awk "BEGIN {printf \"%d\", $EPOCHREALTIME * 1000}"; }

passes=0
failures=0
errors=0
total_time=0

DIR="$(cd "$(dirname "$0")" && pwd)"

printf "%-12s %-10s %s\n" "Problem" "Time(ms)" "Status"
printf "%-12s %-10s %s\n" "-------" "--------" "------"

for problem in $(echo "${!ANSWERS[@]}" | tr ' ' '\n' | sort -n); do
  src="$DIR/problem$(printf '%03d' $problem).c"
  bin="/tmp/euler_$(printf '%03d' $problem)"
  expected="${ANSWERS[$problem]}"

  if ! cc -o "$bin" "$src" -lm 2>/dev/null; then
    printf "%-12s %-10s %s\n" "Problem $problem" "-" "ERROR (compile failed)"
    ((errors++))
    continue
  fi

  start=$(ms)
  result=$("$bin" 2>/dev/null | tail -1 | tr -d '[:space:]')
  elapsed=$(( $(ms) - start ))
  total_time=$(( total_time + elapsed ))

  if [ "$result" = "$expected" ]; then
    printf "%-12s %-10s %s\n" "Problem $problem" "${elapsed}ms" "PASS"
    ((passes++))
  else
    printf "%-12s %-10s %s\n" "Problem $problem" "${elapsed}ms" "FAIL  got=$result expected=$expected"
    ((failures++))
  fi
done

echo ""
echo "Total: ${total_time}ms  Passed: $passes  Failed: $failures  Errors: $errors"
