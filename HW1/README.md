# HW1

// with 0 shuffles
[cssuwbstudent@LinuxMachine HW1]$ ./runit.sh 0
Removing previous executable: rm -f ./a
Compiling: clang++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare main.cpp
Executing: ./a.out
Please input 9 digits to be randomly shuffled: 123456789

Done.

// with 1 shuffles
[cssuwbstudent@LinuxMachine HW1]$ ./runit.sh 1
Removing previous executable: rm -f ./a
Compiling: clang++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare main.cpp
Executing: ./a.out
Please input 9 digits to be randomly shuffled: 123456789

+-------+
| 2 1 3 |
| 8 7 6 |
| 4 5 9 |
+-------+
Done.

// with 2 shuffles
[cssuwbstudent@LinuxMachine HW1]$ ./runit.sh 2
Removing previous executable: rm -f ./a
Compiling: clang++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare main.cpp
Executing: ./a.out
Please input 9 digits to be randomly shuffled: 123456789

+-------+
| 9 1 4 |
| 6 5 7 |
| 8 3 2 |
+-------+
+-------+
| 8 3 4 |
| 5 6 2 |
| 9 1 7 |
+-------+
Done.

//TESTING ERRORS BELOW
[cssuwbstudent@LinuxMachine HW1]$ ./runit.sh c
Removing previous executable: rm -f ./a
Compiling: clang++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare main.cpp
Executing: ./a.out
Invalid command line argument.

[cssuwbstudent@LinuxMachine HW1]$ ./runit.sh 1c //if characters follow number, ignores characters
Removing previous executable: rm -f ./a
Compiling: clang++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare main.cpp
Executing: ./a.out
Please input 9 digits to be randomly shuffled: 123456789

+-------+
| 2 5 6 |
| 3 1 7 |
| 4 9 8 |
+-------+
Done.

[cssuwbstudent@LinuxMachine HW1]$ ./runit.sh 23
Removing previous executable: rm -f ./a
Compiling: clang++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare main.cpp
Executing: ./a.out
Invalid number. Please enter a number less than 10

[cssuwbstudent@LinuxMachine HW1]$ ./runit.sh 2
Removing previous executable: rm -f ./a
Compiling: clang++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare main.cpp
Executing: ./a.out
Please input 9 digits to be randomly shuffled: c12345678

Invalid number. Please input 9 digits to be randomly shuffled: 1c2345678

Invalid number. Please input 9 digits to be randomly shuffled: 12c345678 

Invalid number. Please input 9 digits to be randomly shuffled: 123c45678

Invalid number. Please input 9 digits to be randomly shuffled: 1234c5678

Invalid number. Please input 9 digits to be randomly shuffled: 12345c678 

Invalid number. Please input 9 digits to be randomly shuffled: 123456c78

Invalid number. Please input 9 digits to be randomly shuffled: 1234567c8

Invalid number. Please input 9 digits to be randomly shuffled: 12345678c

Invalid number. Please input 9 digits to be randomly shuffled: 1

Invalid number. Please input 9 digits to be randomly shuffled: 12

Invalid number. Please input 9 digits to be randomly shuffled: 123

Invalid number. Please input 9 digits to be randomly shuffled: 1234

Invalid number. Please input 9 digits to be randomly shuffled: 12345

Invalid number. Please input 9 digits to be randomly shuffled: 123456

Invalid number. Please input 9 digits to be randomly shuffled: 1234567

Invalid number. Please input 9 digits to be randomly shuffled: 12345678

Invalid number. Please input 9 digits to be randomly shuffled: 1234567890

Invalid number. Please input 9 digits to be randomly shuffled: 123456789

+-------+
| 2 1 5 |
| 3 6 7 |
| 4 8 9 |
+-------+
+-------+
| 7 6 4 |
| 9 8 3 |
| 1 2 5 |
+-------+
Done.