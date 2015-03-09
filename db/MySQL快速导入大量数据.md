当数据量较大时，如上百万甚至上千万记录时，向MySQL数据库中导入数据通常是一个比较费时的过程。通常可以采取以下方法来加速这一过程：

#### 1.MyISAM表

```
ALTER TABLE tblname DISABLE KEYS;
loading the data ALTER TABLE tblname ENABLE KEYS;
```

这两个命令用来打开或者关闭Myisam表非唯一索引的更新。在导入大量的数据到一个非空的Myisam表时，通过设置这两个命令，可以提高导入的效率。对于导入大量数据到一个空的Myisam表，默认就是先导入数据然后才创建索引的，所以不用进行设置。

#### 2.Innodb表
有以下几种方式可以提高导入的效率：

- 因为Innodb类型的表是按照主键的顺序保存的，所以将导入的数据按照主键的顺序排列，可以有效的提高导入数据的效率。如果Innodb表没有主键，那么系统会默认创建一个内部列作为主键，所以如果可以给表创建一个主键，将可以利用这个优势提高导入数据的效率。
- 在导入数据前执行`SET UNIQUE_CHECKS=0`，关闭唯一性校验，在导入结束后执行``SET UNIQUE_CHECKS=1`，恢复唯一性校验，可以提高导入的效率。
- 如果应用使用自动提交的方式，建议在导入前执行`SET AUTOCOMMIT=0`，关闭自动提交，导入结束后再执行`SET AUTOCOMMIT=1`，打开自动提交，也可以提高导入的效率。

#### 3.如何提高`mysql load data infile`的速度
测试数据2.5G，共有数据9427567条。用的mysql的large服务器的配置。 load一次需要大概10分钟左右。 建的表用的是MYISAM，调整了几个session的参数值

```
SET SESSION BULK_INSERT_BUFFER_SIZE=256217728;
SET SESSION MYISAM_SORT_BUFFER_SIZE=256217728;
```

运行结果如下

```
Query OK, 9427567 rows affected, 1558 warnings
(3 min 55.21 sec)
Records: 9427567 Deleted: 0 Skipped: 0 Warnings: 0 
```

```
setg lobal KEY_BUFFER_SIZE=256217728;
alter table tablename disable keys;
```

#### 4.如何load数据里面带反斜杠(backslash)”\” 的数据
由于如果你没有指定FIELDS子句，则默认值为假设您写下如下语句时的值： `FIELDS TERMINATED BY ‘\t’ ENCLOSED BY ” ESCAPED BY ‘\\’` 所以，如果你的数据里面有反斜杠(backslash)”\”的时候，数据会出现被截断的问题。出现这种问题，只要写上如下的fields子句即可 FIELDS TERMINATED BY ‘\t’ ENCLOSED BY ” ESCAPED BY ”

#### 5.如何load不同编码的数据
原来用的4.X的mysql，我是select INTO OUTFILE ，只后用iconv,或者其他软件来做。可以参考这里，但是由于这次数据大，用ultraedit等软件打开都要半天。好在新版的mysql可以增加一个新的参数 CHARACTER SET gbk 我的文本数据是GBK的编码，数据表是utf8的，用这种方法测试成功。 如何load的时候只insert特定的列 比如表里面有比元数据多的列。可以在load的时候指定要插入的字段名字。

示例的代码如下：

```
LOAD DATA INFILE '~/data.txt'
INTO TABLE fb0505   
CHARACTER SET  gbk    
FIELDS TERMINATED BY '\t' ENCLOSED BY '' 
ESCAPED BY '' LINES TERMINATED BY '\n' 
STARTING BY ''  (seller_id,fb_type,fb_date,item_url);
其中表fb0505里面还有一列是id。
```

LOAD DATA INFILE语法

> http://dev.mysql.com/doc/refman/5.5/en/load-data.html