#!/bin/bash

export UBSAN_OPTIONS=print_stacktrace=1
export ASAN_OPTIONS=strict_string_checks=1:detect_stack_use_after_return=1:check_initialization_order=1:strict_init_order=1
export TSAN_OPTIONS=force_seq_cst_atomics=1


CALL="clang++ -g -lpthread -std=c++17 -fno-omit-frame-pointer -fno-limit-debug-info -Wall -Werror main.cpp"

function build_release() {
  echo No Sanitizer Release Build:
  ${CALL} -O3 2>&1 && ./a.out 2>&1
  echo -ne \\n\\n
}

function build_asan() {
  echo Address Sanitizer:
  ${CALL} -O0 -fsanitize=address,leak 2>&1 && ./a.out 2>&1
  echo -ne \\n\\n
}

function build_ubsan() {
  echo Undefined Behaviour Sanitizer:
  ${CALL} -O0 -fsanitize=undefined 2>&1 && ./a.out 2>&1
  echo -ne \\n\\n
}

function build_tsan() {
  echo Thread Sanitizer:
  ${CALL} -O0 -fsanitize=thread -nostdinc++ -isystem /usr/tsan/include/c++/v1/ -nostdlib++ -L/usr/tsan/lib -lc++ -Wl,-rpath,/usr/tsan/lib 2>&1 && ./a.out 2>&1
  echo -ne \\n\\n
}

function build_msan() {
  echo Memory Sanitizer:
  ${CALL} -O0 -fsanitize=memory -fsanitize-memory-track-origins=2  -nostdinc++ -isystem /usr/msan/include/c++/v1/ -nostdlib++ -L/usr/msan/lib -lc++ -Wl,-rpath,/usr/msan/lib 2>&1 && ./a.out 2>&1
  echo -ne \\n\\n
}


build_release
build_asan
build_tsan
build_msan

build_ubsan
