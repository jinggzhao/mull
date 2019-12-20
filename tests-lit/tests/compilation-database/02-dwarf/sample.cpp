/**
; RUN: cd / && %CLANG_EXEC -fembed-bitcode -g %s -o %s.exe
; RUN: cd %CURRENT_DIR
; RUN: (unset TERM; %MULL_EXEC -test-framework CustomTest -mutators=remove_void_function_mutator %s.exe 2>&1; test $? = 0) | %FILECHECK_EXEC %s --strict-whitespace --match-full-lines --check-prefix=WITHOUT-RECORD-COMMAND-LINE
; WITHOUT-RECORD-COMMAND-LINE-NOT:Found compilation flags in the input bitcode

; RUN: cd / && %CLANG_EXEC -fembed-bitcode -g -grecord-command-line %s -o %s.exe
; RUN: cd %CURRENT_DIR
; RUN: (unset TERM; %MULL_EXEC -test-framework CustomTest -mutators=remove_void_function_mutator %s.exe 2>&1; test $? = 0) | %FILECHECK_EXEC %s --strict-whitespace --match-full-lines --check-prefix=WITH-RECORD-COMMAND-LINE
; WITH-RECORD-COMMAND-LINE:Found compilation flags in the input bitcode
**/

static int globalVar = 1;
void voidFunction() {
  globalVar = 0;
}

void foo() {
  voidFunction();
};

int main() {
  foo();
  return globalVar;
}
