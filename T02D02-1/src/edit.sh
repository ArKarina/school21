#!/bin/bash

logfile="src/files.log"

echo "Введите путь до файла относительно конревой дирректории репозитория: "
read file

cd ..

if [ ! -f $file ]; then
echo "Такого файла не существует!"
exit 1
fi

echo "Введите строку для замены: "
read str1
echo "Введите новую строку: "
read str2

sed -i'' -e "s/$str1/$str2/" $file

#обновление log
size=`wc -c < "$file"`
size=${size// /}

datetime=$(date '+%Y-%m-%d %H:%M')

sha=`shasum -a 256 $file`
sha=${sha% *}


echo "$file - $size - $datetime - $sha- sha256" >> $logfile

