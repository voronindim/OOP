#!/bin/bash
err()
{
  echo "Fail"
}

# разлив внутри поля
"cmake-build-release/Fill" "tests/input1.txt" "tests/output.txt"
if [ $? -ne 0 ]; then err;по
fi
if cmp -s "tests/output.txt" "tests/output1.txt" ; then
  echo Test 1 passed;
  else err;
fi

# Разлив краски в верхней половине
"cmake-build-release/Fill" "tests/input2.txt" "tests/output.txt"
if [ $? -ne 0 ]; then err;
fi
if cmp -s "tests/output.txt" "tests/output2.txt" ; then
  echo Test 2 passed;
  else err;
fi

#Разлив краски
"cmake-build-release/Fill" "tests/input3.txt" "tests/output.txt"
if [ $? -ne 0 ]; then err;
fi
if cmp -s "tests/output.txt" "tests/output3.txt" ; then
  echo Test 3 passed;
  else err;
fi

# Нехватка аргументов
"cmake-build-release/Fill"  "tests/output.txt" > "tests/output"
if [ $? -ne 1 ]; then err;
else echo Test 4 passed;
fi

