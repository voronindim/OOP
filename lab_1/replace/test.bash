#!/bin/bash
err(){
  echo "Fail"
}
# Замена в начале файла.
"cmake-build-release/replace" "input1.txt" "output.txt" "read" "**"
if [ $? -ne 0 ]; then err;
fi
if cmp -s output.txt output1.txt ; then
  echo Test 1 passed;
  else err;
fi
# Замена подстроки "1231234" в "12312312345"
"cmake-build-release/replace" "input2.txt" "output.txt" "1231234" "**"
if [ $? -ne 0 ]; then err;
fi
if cmp -s output.txt output2.txt ; then
  echo Test 2 passed;
  else err;
fi
# Замена пустой строки
"cmake-build-release/replace" "input3.txt" "output.txt" "" "**"
if [ $? -ne 0 ]; then err;
fi
if cmp -s output.txt output3.txt ; then
  echo Test 3 passed;
  else err;
fi
# Замена подстроки на пустую строку.
"cmake-build-release/replace" "input4.txt" "output.txt" "_" ""
if [ $? -ne 0 ]; then err;
fi
if cmp -s output.txt output4.txt ; then
  echo Test 4 passed;
  else err;
fi
# проверка на многократную замену
"cmake-build-release/replace" "input5.txt" "output.txt" "12" "1212"
if [ $? -ne 0 ]; then err;
fi
if cmp -s output.txt output5.txt ; then
  echo Test 5 passed;
  else err;
fi
# Замена всего файла
"cmake-build-release/replace" "input6.txt" "output.txt" "hello" "*"
if [ $? -ne 0 ]; then err;
fi
if cmp -s output.txt output6.txt ; then
  echo Test 6 passed;
  else err;
fi
# Замена подстроки, которой нет.
"cmake-build-release/replace" "input7.txt" "output.txt" "123" "*"
if [ $? -ne 0 ]; then err;
fi
if cmp -s output.txt output7.txt ; then
  echo Test 7 passed;
  else err;
fi
# Несуществующий input
echo Test 8;
"cmake-build-release/replace" "noFile" "output.txt" "123" "*"
if [ $? -ne 1 ]; then err;
fi
# Задан пустой файл
"cmake-build-release/replace" "input9.txt" "output.txt" "123" "*"
if [ $? -ne 0 ]; then err;
fi
if cmp -s output.txt output9.txt ; then
  echo Test 9 passed;
  else err;
fi
# Неверно заданные аргументы командной строки: нет одной из строк
echo Test 10;
"cmake-build-release/replace" "input10.txt" "output.txt" "123"
if [ $? -ne 1 ]; then err;
fi
# Неверно заданные аргументы командной строки: нет ни одного аргумента
echo Test 11;
"cmake-build-release/replace"
echo $?
if [ $? -ne 1 ]; then err;
fi