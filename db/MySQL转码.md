数据库 GB2312/GBK/GB18030 to UTF-8 转换步骤

```
$mysqldump -uroot -p --quick --compatible=mysql40
	--default-character-set=latin1 --extended-insert=FALSE forum 
	| iconv -c -f GB18030 -t UTF-8 > forumutf8.sql 
mysql> CREATE DATABASE `forumutf8` 
	DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
$ mysql -uroot -p --default-character-set=utf8 forumutf8 
< forumutf8.sql
```

几百M的文件，肯定出问题，iconv修改比较实际 phpmyadmin修改的只是默认字符集，不是已经存入的文本字符集。