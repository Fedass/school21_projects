#!/bin/bash
file1="text1.txt"

echo -e "\n | WITHOUT_FLAGS |"
echo "diff <(cat $file1) <(./s21_cat $file1)"
diff <(cat $file1) <(./s21_cat $file1)

echo -e "\n | WITHOUT_FLAGS |"
echo "diff <(cat $file1) <(./s21_cat $file1)"
diff <(cat $file1 $file2) <(./s21_cat $file1 $file2)

echo -e "\n | b_FLAG |"
echo "diff <(cat -b $file1) <(./s21_cat -b $file1)"
diff <(cat -b $file1) <(./s21_cat -b $file1)

echo -e "\n | e_FLAG |"
echo "diff <(cat -e $file1) <(./s21_cat -e $file1)"
diff <(cat -e $file1 $file2) <(./s21_cat -e $file1 $file2)

# echo -e "\n | E_FLAG |"
# echo "diff <(cat -E $file1) <(./s21_cat -E $file1)"
# diff <(cat -E $file1 $file2) <(./s21_cat -E $file1 $file2)

echo -e "\n | t_FLAGS |"
echo "diff <(cat -t $file1) <(./s21_cat -t $file1)"
diff <(cat -t $file1 $file2) <(./s21_cat -t $file1 $file2)

# echo -e "\n | T_FLAGS |"
# echo "diff <(cat -T $file1) <(./s21_cat -T $file1)"
# diff <(cat -T $file1 $file2) <(./s21_cat -T $file1 $file2)

echo -e "\n | n_FLAGS |"
echo "diff <(cat -n $file1) <(./s21_cat -n $file1)"
diff <(cat -n $file1) <(./s21_cat -n $file1)

# echo -e "\n | s_FLAGS |"
# echo "diff <(cat -s $file1) <(./s21_cat -s $file1)"
# diff <(cat -s $file1 ) <(./s21_cat -s $file1)

