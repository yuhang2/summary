## php 5.3新特性
### 1 php 5.3新特性
#### 1.1 支持命名空间(Namespace)

> 使用命名空间，避免不同包中的类名和变量名重复

#### 1.2 支持延迟静态绑定(Late Static Binding)

> php 5.3.0新增了static关键字来引用当前类，即实现了延迟静态绑定

```php
<?php
class A
{
	public static function who()
	{
		echo __CLASS__;
	}
	
	public static function test()
	{
		self::who();
	}
}
class B extends A
{
	public static function who()
	{
		echo __CLASS__;
	}
}
B::test()
```

结果输出：

```php
A
```

但是我们期望是B，修改下代码

```php
<?php
class A
{
	public static function who()
	{
		echo __CLASS__;
	}
	
	public static function test()
	{
		static::who();
	}
}
class B extends A
{
	public static function who()
	{
		echo __CLASS__;
	}
}
B::test()
```

结果输出:

```php
B
```

#### 1.3 支持goto语句
#### 1.4 支持闭包、Lambda/Anonymous函数

> 闭包、Lambda函数的概念来自函数式编程领域  
在php中，可以通过create_function()在代码运行时创建函数。但是，创建的函数只在运行时才被编译，而不与其它代码同时被编译为执行码，无法使用APC这样的执行码缓存提高执行效率。 

在php 5.3中，可以使用Lambda/匿名函数，来定义一些临时使用的函数

```php
<?php
echo preg_replace_callback('~-([a-z])~', function ($match) {
    return strtoupper($match[1]);
}, 'hello-world');

// 输出 helloWorld
$greet = function($name) {
    printf("Hello %s\r\n", $name);
};
$greet('World');
$greet('PHP');

//...在某个类中
$callback = function ($quantity, $product) use ($tax, &$total) {
	$pricePerItem = constant(__CLASS__ . "::PRICE_"
   		. strtoupper($product));
   	$total += ($pricePerItem * $quantity) * ($tax + 1.0);
};
array_walk($products, $callback);
```

#### 1.5 新增两个魔术方法__callStatic()和__invoke()
__call() 调用对象的某个不存在的方法时，方法被自动调用
__callStatic() 用于静态类方法
__invoke() 以函数形式调用对象时，方法被自动调用
#### 1.6 新增Nowdoc语法
#### 1.7 在类外也可以使用const来定义常量

```php
<?php
define("CONSTANT", "Hello World");
// 新的声明常量语句
const CONSTANT = "Hello World";
```

#### 1.8 三元运算符增加了快捷书写方式
原格式: expr1 ? expr2 : expr3;
如果expr1结果为真，返回expr2的结果。
新格式: expr1 ?: expr3;
如果expr1结果为真，返回expr1的结果。
#### 1.9 HTTP状态码在200-399范围内，均被认为访问成功
#### 1.10 支持动态调用静态方法

```php
<?php
class Test
{
    public static function testgo()
    {
         echo "gogo!";
    }
}
$class = 'Test';
$action = 'testgo';
$class::$action(); //输出 "gogo!"
```

#### 1.11 支持嵌套处理异常
#### 1.12 新的垃圾收集器，并默认启用

### 其它值得注意的

* 修复了大量bug
* PHP性能提高
* php.ini中可使用变量
* mysqlnd进入核心扩展 理论上说该扩展访问mysql速度会较之前的MySQL 和 MySQLi 扩展快（参见http://dev.mysql.com/downloads/connector/php-mysqlnd/）
* ext/phar、ext/intl、ext/fileinfo、ext/sqlite3和ext/enchant等扩展默认随PHP绑定发布。其中Phar可用于打包PHP程序，类似于Java中的jar机制。
* ereg 正则表达式函数 不再默认可用，请使用速度更快的PCRE 正则表达式函数

