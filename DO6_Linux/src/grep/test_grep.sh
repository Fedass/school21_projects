#!/bin/bash
valg1="--leak-check=full --track-origins=yes -s"
file1="file1.txt"
file2="file2.txt"

echo -e "\n | WITHOUT_FLAGS |"
echo "diff <(grep str1 $file1) <(./s21_grep str1 $file1)"
diff <(grep str1 $file1) <(./s21_grep str1 $file1)


echo -e "\n\n-e | TEMPLATE separate and united | / 1 flag / 1 file"
echo "diff <(grep -e str2 $file1) <(./s21_grep -e str2 $file1)"
diff <(grep -e str2 $file1) <(./s21_grep -e str2 $file1)
#
echo "diff <(grep -estr2 $file1) <(./s21_grep -estr2 $file1)"
diff <(grep -estr2 $file1) <(./s21_grep -estr2 $file1)

echo -e "\n-e | TEMPLATES separate and united | / some templates / 1 file and some files"
echo "diff <(grep -e str2 $file1 -e str23) <(./s21_grep -e str2 $file1 -e str23)"
diff <(grep -e str2 $file1 -e str23) <(./s21_grep -e str2 $file1 -e str23)
#
echo "diff <(grep -estr2 $file1 -e str23 -estr11 $file2) <(./s21_grep -estr2 $file1 -e str23 -estr11 $file2)"
diff <(grep -estr2 $file1 -e str23 -estr11 $file2) <(./s21_grep -estr2 $file1 -e str23 -estr11 $file2)

echo -e "\n\n-i -e | REGISTER | some flags / some templates / some files"
echo "diff <(grep -eSTR2 $file1 -e sTr23 -estr11 $file2 -i) <(./s21_grep -eSTR2 $file1 -e sTr23 -estr11 $file2 -i)"
diff <(grep -eSTR2 $file1 -e sTr23 -estr11 $file2 -i) <(./s21_grep -eSTR2 $file1 -e sTr23 -estr11 $file2 -i)

echo -e "\n-ie | REGISTER | some flags / some templates / some files"
echo "diff <(grep -ieSTR2 $file1 -e sTr23 -estr11 $file2) <(./s21_grep -ieSTR2 $file1 -e sTr23 -estr11 $file2)"
diff <(grep -ieSTR2 $file1 -e sTr23 -estr11 $file2) <(./s21_grep -ieSTR2 $file1 -e sTr23 -estr11 $file2)


echo -e "\n\n-eic | COUNT_ONLY |some flags / some templates / 1 file"
echo "diff <(grep -estr2 $file1 -iestr22 -c) <(./s21_grep -estr2 $file1 -iestr22 -c)"
diff <(grep -estr2 $file1 -iestr22 -c) <(./s21_grep -estr2 $file1 -iestr22 -c)


echo -e "\n-eiv | some flags / some templates / some files"
echo "diff <(grep -e Str2 $file1 -iv -e str22 $file2) <(./s21_grep -e Str2 $file1 -iv -e str22 $file2)"
diff <(grep -e Str2 $file1 -iv -e str22 $file2) <(./s21_grep -e Str2 $file1 -iv -e str22 $file2)


echo -e "\n\n-ei -l | FILE_NAMES_ONLY | some flags / some templates / some files"
echo "diff <(grep -estr2 $file1 -iestr22 $file2 -l) <(./s21_grep -estr2 $file1 -iestr22 $file2 -l)"
diff <(grep -estr2 $file1 -iestr22 $file2 -l) <(./s21_grep -estr2 $file1 -iestr22 $file2 -l)


echo -e "\n\n-e -n | NUMERATION | some templates / some files"
echo "diff <(grep -estr1 -estr2 $file1 $file2 -n) <(./s21_grep -estr1 -estr2 $file1 $file2 -n)"
diff <(grep -estr1 -estr2 $file1 $file2 -n) <(./s21_grep -estr1 -estr2 $file1 $file2 -n)

echo -e "\n-e -n | NUMERATION | some templates / 1 file"
echo "diff <(grep -estr1 -estr2 $file1 -n) <(./s21_grep -estr1 -estr2 $file1 -n)"
diff <(grep -estr1 -estr2 $file1 -n) <(./s21_grep -estr1 -estr2 $file1 -n)


echo -e "\n\n-e -h | WITHOUT_FILE_NAMES | some templates / some files"
echo "diff <(grep -estr1 -estr2 $file1 $file2 -h) <(./s21_grep -estr1 -estr2 $file1 $file2 -h)"
diff <(grep -estr1 -estr2 $file1 $file2 -h) <(./s21_grep -estr1 -estr2 $file1 $file2 -h)

echo -e "\n\n-e -h | WITH_F_FLAG | some templates / some files"
echo "diff <(grep -estr1 -f grep.patterns $file1 $file2 -h) <(./s21_grep -estr1 -f grep.patterns $file1 $file2 -h)"
diff <(grep -estr1 -f grep.patterns $file1 $file2 -h) <(./s21_grep -estr1 -f grep.patterns $file1 $file2 -h)

echo -e "\n\n-e -h | WITH_F_FLAG_AND WRONG FILE | some templates / some files"
echo "diff <(grep -estr1 -f grep.patterns1 $file1 $file2 -h) <(./s21_grep -estr1 -f grep.patterns1 $file1 $file2 -h)"
diff <(grep -estr1 -f grep.patterns1 $file1 $file2 -h) <(./s21_grep -estr1 -f grep.patterns1 $file1 $file2 -h)

echo -e "\n-e -hc | WITHOUT_FILE_NAMES | some templates / some files"
echo "diff <(grep -estr1 -estr2 $file1 $file2 -hc) <(./s21_grep -estr1 -estr2 $file1 $file2 -hc)"
diff <(grep -estr1 -estr2 $file1 $file2 -hc) <(./s21_grep -estr1 -estr2 $file1 $file2 -hc)

echo -e "\n-e -hn | WITHOUT_FILE_NAMES | some templates / some files"
echo "diff <(grep -estr1 -estr2 $file1 $file2 -hn) <(./s21_grep -estr1 -estr2 $file1 $file2 -hn)"
diff <(grep -estr1 -estr2 $file1 $file2 -hn) <(./s21_grep -estr1 -estr2 $file1 $file2 -hn)


echo -e "\n\n-e -s | NO_MESSAGE_FILE_NON_FOUND | some templates / some files"
echo "diff <(grep -estr1 $file1 test99.txt test0.txt -s) <(./s21_grep -estr1 $file1 test99.txt test0.txt -s)"
diff <(grep -estr1 $file1 test99.txt test0.txt -s) <(./s21_grep -estr1 $file1 test99.txt test0.txt -s)

echo -e "\n\n-e -s | FILE_NON_FOUND | some templates / some files"
echo "diff <(grep -estr1 $file1 test99.txt test0.txt) <(./s21_grep -estr1 $file1 test99.txt test0.txt)"
diff <(grep -estr1 $file1 test99.txt test0.txt) <(./s21_grep -estr1 $file1 test99.txt test0.txt)

echo -e "\n\n-e -o | PRINT_ONLY_MATCHES | some templates / 1 file"
echo "diff <(grep -estr11 $file1 -o) <(./s21_grep -estr11 $file1 -o)"
diff <(grep -estr11 $file1 -o) <(./s21_grep -estr11 $file1 -o)


