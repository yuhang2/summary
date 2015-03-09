#### 1.更改表名

```
rename table table_name to new_table_name;
```

#### 2.修改auto_increment

```
mysql>show table status form 数据库 like '表名'
mysql>alter table 表名 auto_increment=200
```

查看db.table表的下一条记录auto_increment的值：

```
show table status from db like 'table';
```

#### 3.把表从一种引擎转移到另外一种引擎上。

##### 3.1 sql语句

```
ALTER TABLE mytable ENGINE = InnoDB;
```

优点：适合所有的存储引擎  
缺点：耗时，占I/O处理能力，在转换时，源表要被读加锁，原始引擎的专用特性会丢失（例如InnoDB转成MyISAM，再转回来，定义在原InnoDB表上的所有外键都会丢失）

##### 3.2 先用mysqldump工具把表先存储成一个文本文件，然后修改其中的CREATE TABLE语句。

##### 3.3 创建一个新表，使用MySQL的insert … select 语法来转移数据。

```
mysql> create table innodb_table like myisam_table;
mysql> alter table innodb_table engine=InnoDB
mysql> insert into innodb_table select * from myisam_table;
```

缺点：在填充数据块的时候都提交事务，这样就不会导致撤销日志（Undo Log）变的过于庞大。  
可以重复运行查询（每次逐次增大x 和 y的值），直到所有数据都复制到新表

```
mysql> start transaction;
mysql> insert into innodb_table select * from myisam_table
 where id between x and y;
mysql> commit;
```

可以给源表加锁，防止数据不一致。

#### 4.MySQL的Safe Update Mode
使用SQL：
update table_name set field_name=0;
返回错误信息：
You are using safe update mode and you tried to update a table without a where clause that  uses a KEY column.
问题原因：
MySQL在没有where或limit条件下，会拒绝执行update或delete query,即使是没有KEY column的where条件也会拒绝执行。

mysql>set sql_safe_updates=0;
mysql>update table_name set field_name=0;

重新开启safe update mode
mysql>set sql_safe_updates=1;

#### 5.用户管理

> 一般情况下，修改MySQL密码，授权，是需要有mysql里的root权限的。

##### 5.1.新建用户。

```
//登录MYSQL
@>mysql -u root -p
@>密码
//创建用户
mysql> insert into mysql.user(Host,User,Password) 
values("localhost","phplamp",password("1234"));
//刷新系统权限表
mysql>flush privileges;
```
这样就创建了一个名为：phplamp  密码为：1234  的用户。

然后登录一下。

```
mysql>exit;
@>mysql -u phplamp -p
@>输入密码
mysql>登录成功
```

##### 5.2.为用户授权。

```
//登录MYSQL（有ROOT权限）。我里我以ROOT身份登录.
@>mysql -u root -p
@>密码
//首先为用户创建一个数据库(phplampDB)
mysql>create database phplampDB;
//授权phplamp用户拥有phplamp数据库的所有权限。
>grant all privileges on phplampDB.* to 
phplamp@localhost identified by '1234';
//刷新系统权限表
mysql>flush privileges;
mysql>其它操作
```

```
/*
如果想指定部分权限给一用户，可以这样来写:
mysql>grant select,update on phplampDB.* to phplamp@localhost identified by '1234';
//刷新系统权限表。
mysql>flush privileges;
*/
```

##### 5.3.删除用户。

```
@>mysql -u root -p
@>密码
mysql>DELETE FROM user WHERE User="phplamp" 
and Host="localhost";
mysql>flush privileges;
//删除用户的数据库
mysql>drop database phplampDB;
```

##### 5.4.修改指定用户密码。

```
@>mysql -u root -p
@>密码
mysql>update mysql.user set password=password('新密码') 
where User="phplamp" and Host="localhost";
mysql>flush privileges;
```

#### 6 alter语句

```
//主键549830479
alter table tabelname add new_field_id int(5) unsigned 
default 0 not null auto_increment,
add primary key (new_field_id);
//增加一个新列549830479
alter table t2 add d timestamp;
alter table infos add ex tinyint not null default '0';
//删除列549830479
alter table t2 drop column c;
//重命名列549830479
alter table t1 change a b integer;
//改变列的类型549830479
alter table t1 change b b bigint not null;
alter table infos change list list tinyint not null default '0';
//重命名表549830479
alter table t1 rename t2;
```
加索引549830479

```
mysql> alter table tablename change depno depno int(5) not null;
mysql> alter table tablename add index 索引名 (字段名1[，字段名2 …]);
mysql> alter table tablename add index emp_name (name);
```

```
加主关键字的索引549830479
mysql> alter table tablename add primary key(id);
加唯一限制条件的索引549830479
mysql> alter table tablename add unique emp_name2(cardnumber);
删除某个索引549830479
mysql>alter table tablename drop index emp_name;
修改表：549830479

增加字段：549830479
mysql> ALTER TABLE table_name ADD field_name field_type;
修改原字段名称及类型：549830479
mysql> ALTER TABLE table_name CHANGE old_field_name new_field_name field_type;
删除字段：549830479
mysql> ALTER TABLE table_name DROP field_name; 
```   
