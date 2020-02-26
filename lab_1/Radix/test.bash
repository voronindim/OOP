#!/bin/bash
err()
{
  echo "Fail"
}

# Проверка вывода букв в 16-ричной СС (А)
"cmake-build-release/radix" 10 16 10 > "tests/output.txt"
if [ $? -ne 0 ]; then err;
fi
if cmp -s "tests/output.txt" "tests/output1.txt" ; then
  echo Test 1 passed;
  else err;
fi

# Проверка вывода букв в 36-ричной СС (F)
"cmake-build-release/radix" 10 36 35 > "tests/output.txt"
if [ $? -ne 0 ]; then err;
fi
if cmp -s "tests/output.txt" "tests/output2.txt" ; then
  echo Test 2 passed;
fi


# Проверка крайних значений (INT_MIN)
"cmake-build-release/radix" 10 2 -2147483648 > "tests/output.txt"
if [ $? -ne 0 ]; then err;
fi
if cmp -s "tests/output.txt" "tests/output3.txt" ; then
  echo Test 3 passed;
  else err;
fi

# Проверка крайних значений (INT_MAX)
"cmake-build-release/radix" 10 2 2147483647 > "tests/output.txt"
if [ $? -ne 0 ]; then err;
fi
if cmp -s "tests/output.txt" "tests/output4.txt" ; then
  echo Test 4 passed;
  else err;
fi

# Проверка переполнения со стороны INT_MIN
"cmake-build-release/radix" 10 2 -2147483649 > "tests/output.txt"
if [ $? -ne 1 ]; then err;
else
  echo Test 5 passed;
fi

# Проверка переполнения со стороны INT_MAX
"cmake-build-release/radix" 10 2 2147483648 > "tests/output.txt"
if [ $? -ne 1 ]; then err;
else
  echo Test 6 passed;
fi

# Проверка ввода 0
"cmake-build-release/radix" 10 2 0 > "tests/output.txt"
if [ $? -ne 0 ]; then err;
fi
if cmp -s "tests/output.txt" "tests/output7.txt" ; then
  echo Test 7 passed;
  else err;
fi

# Проверка неизвесного символа
"cmake-build-release/radix" 10 2 * > "tests/output.txt"
if [ $? -ne 1 ]; then err;
else echo Test 8 passed
fi

# Ошибка ввода недопустимых символов в данной СС
"cmake-build-release/radix" 10 2 A > "tests/output.txt"
if [ $? -ne 1 ]; then err;
else echo Test 9 passed
fi

# Проверка нижнего регистра
"cmake-build-release/radix" 16 10 f > "tests/output.txt"
if [ $? -ne 0 ]; then err;
fi
if cmp -s "tests/output.txt" "tests/output10.txt" ; then
  echo Test 10 passed;
  else err;
fi
