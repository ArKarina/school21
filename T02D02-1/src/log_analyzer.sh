#!/bin/bash
if [ -z "$1" ]
then
echo "Укажите путь к файлу относительно корневой директории в качестве параметра."
exit 1
fi

cd ..
if [ ! -f $1 ]
then
echo "Файл лога не найден!"
exit 1
fi

records=`wc -l < $1`
records=${records// /}

unic_files=`awk '{print $1}' "$1" | uniq | wc -l`
unic_files=${unic_files// /}

hashes=`awk '{print $1,$8}' "$1" | uniq | wc -l`
hashes=${hashes// /}
hashes=$[$hashes - 1]

echo "$records $unic_files $hashes"
