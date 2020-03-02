#!/bin/bash
err()
{
  echo "Fail"
}

# определитель матрицы равен 0
"cmake-build-release/matrix" "tests/matrix1.txt" > "tests/output.txt"
if [ $? -ne 0 ]; then err;
  else echo Test 1 passed;
fi

# в строке встречен 4 элемент
"cmake-build-release/matrix" "tests/matrix2.txt" > "tests/output.txt"
if [ $? -ne 1 ]; then err;
  else echo Test 2 passed;
fi

# проверка дробных отрицательных элементов
"cmake-build-release/matrix" "tests/matrix3.txt" > "tests/output.txt"
if [ $? -ne 0 ]; then err;
fi
if cmp -s "tests/output.txt" "tests/output3.txt"; then
  echo Test 3 passed;
fi

# встречен неизвестный символ
"cmake-build-release/matrix" "tests/matrix4.txt" > "tests/output.txt"
if [ $? -ne 1 ]; then err;
  else echo Test 4 passed;
fi

# проверка точки после числа (145.)
"cmake-build-release/matrix" "tests/matrix5.txt" > "tests/output.txt"
if [ $? -ne 1 ]; then err;
  else echo Test 5 passed;
fi

# проверка минуса после числа (145-)
"cmake-build-release/matrix" "tests/matrix6.txt" > "tests/output.txt"
if [ $? -ne 1 ]; then err;
  else echo Test 6 passed;
fi

# нехватка элементов в матрице
"cmake-build-release/matrix" "tests/matrix7.txt" > "tests/output.txt"
if [ $? -ne 1 ]; then err;
  else echo Test 7 passed;
fi

# встрчена точка, идущая сразу после минуса!
"cmake-build-release/matrix" "tests/matrix8.txt" > "tests/output.txt"
if [ $? -ne 1 ]; then err;
  else echo Test 8 passed;
fi

# Встречена отдельно стоящая точка
"cmake-build-release/matrix" "tests/matrix8.txt" > "tests/output.txt"
if [ $? -ne 1 ]; then err;
  else echo Test 9 passed;
fi

# еденичная марица
"cmake-build-release/matrix" "tests/matrix10.txt" > "tests/output.txt"
if [ $? -ne 0 ]; then err;
fi
if cmp -s "tests/output.txt" "tests/output10.txt"; then
  echo Test 10 passed;
fi







