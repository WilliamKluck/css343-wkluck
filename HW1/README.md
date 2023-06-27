# HW1

Screenshot contains output of programs based on some correct inputs and some erroneous inputs

![Screenshot (277)](https://github.com/WilliamKluck/css343-wkluck/assets/92551689/d8ec5962-ba21-4c8c-bcd9-dafe00b149cc)
![Screenshot (278)](https://github.com/WilliamKluck/css343-wkluck/assets/92551689/ff4aad5d-4487-43ff-8f28-07eee96a6e7f)

some clang-tidy warnings I ran show different errors, some I fixed prior but the ones that I didn't fix were intentional. There are 11:

1: /home/cssuwbstudent/css343-wkluck/HW1/main.cpp:44:3: error: kernel performance could be improved by unrolling this loop with a '#pragma unroll' directive [altera-unroll-loops,-warnings-as-errors]
  for (int iterator = 0; iterator < stringOfDigits.length(); iterator++) {
  ^
This error can be solved by using all_of. I didn't implement this change for clarity.

2: /home/cssuwbstudent/css343-wkluck/HW1/main.cpp:57:22: error: do not declare C-style arrays, use std::array<> instead [cppcoreguidelines-avoid-c-arrays,hicpp-avoid-c-arrays,modernize-avoid-c-arrays,-warnings-as-errors]
bool isInteger(const char array[]) {
                     ^

I prefer using this type of array, I am not familiar with array<>

3: /home/cssuwbstudent/css343-wkluck/HW1/main.cpp:58:3: note: inferred assignment of ID-dependent value from ID-dependent  [altera-id-dependent-backward-branch]
  int size = strlen(array);
  ^

C++ does not like using strlen for arrays, in this case it works as intended. Alternatively, I could have used a formula including the use of size_of to get the bit size of the array and then convert a ratio.

4: /home/cssuwbstudent/css343-wkluck/HW1/main.cpp:58:14: error: narrowing conversion from 'size_t' (aka 'unsigned long') to signed type 'int' is implementation-defined [bugprone-narrowing-conversions,cppcoreguidelines-narrowing-conversions,-warnings-as-errors]
  int size = strlen(array);
             ^

I chose not the static_cast this value, I see that some errors could arise if the array is of significant size.

5: /home/cssuwbstudent/css343-wkluck/HW1/main.cpp:59:3: error: kernel performance could be improved by unrolling this loop with a '#pragma unroll' directive [altera-unroll-loops,-warnings-as-errors]
  for (int i = 0; i < size; i++) {
  ^

same as 1.

6: /home/cssuwbstudent/css343-wkluck/HW1/main.cpp:59:19: error: backward branch (for loop) is ID-dependent due to variable reference to 'size' and may cause performance degradation [altera-id-dependent-backward-branch,-warnings-as-errors]
  for (int i = 0; i < size; i++) {
                  ^

same as 4.

7: /home/cssuwbstudent/css343-wkluck/HW1/main.cpp:76:26: error: 'atoi' used to convert a string to an integer value, but function will not report conversion errors; consider using 'strtol' instead [cert-err34-c,-warnings-as-errors]
  int numberOfShuffles = atoi(argValue[1]);
                         ^

I check this before but clang doesn't realize

8: /home/cssuwbstudent/css343-wkluck/HW1/main.cpp:86:3: error: kernel performance could be improved by unrolling this loop with a '#pragma unroll' directive [altera-unroll-loops,-warnings-as-errors]
  do {
  ^

same as 1.

9: /home/cssuwbstudent/css343-wkluck/HW1/main.cpp:76:3: note: inferred assignment of ID-dependent value from ID-dependent  [altera-id-dependent-backward-branch]
  int numberOfShuffles = atoi(argValue[1]);
  ^

honestly not sure why this happens

10: /home/cssuwbstudent/css343-wkluck/HW1/main.cpp:100:3: error: do not declare C-style arrays, use std::array<> instead [cppcoreguidelines-avoid-c-arrays,hicpp-avoid-c-arrays,modernize-avoid-c-arrays,-warnings-as-errors]
  string loopNames[] = {"first", "second",  "third",  "fourth", "fifth",
  ^

same as 2.

11: /home/cssuwbstudent/css343-wkluck/HW1/main.cpp:102:3: error: kernel performance could be improved by unrolling this loop with a '#pragma unroll' directive [altera-unroll-loops,-warnings-as-errors]
  for (int i = 0; i < numberOfShuffles; i++) {
  ^

same as 1.

12: /home/cssuwbstudent/css343-wkluck/HW1/main.cpp:102:19: error: backward branch (for loop) is ID-dependent due to variable reference to 'numberOfShuffles' and may cause performance degradation [altera-id-dependent-backward-branch,-warnings-as-errors]
  for (int i = 0; i < numberOfShuffles; i++) {
                  ^

same as 9.
