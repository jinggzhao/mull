/**
; RUN: cd / && %CLANG_EXEC -fembed-bitcode -g -grecord-command-line %s -o %s.exe
; RUN: cd %CURRENT_DIR
; RUN: (unset TERM; %MULL_EXEC -test-framework CustomTest -mutators=cxx_add_to_sub %s.exe 2>&1; test $? = 0) | %FILECHECK_EXEC %s --strict-whitespace --match-full-lines --check-prefix=WITHOUT-DEBUG; exit 1
; WITHOUT-DEBUG:No mutants found. Mutation score: infinitely high
**/

int main() {
  return 0;
}
