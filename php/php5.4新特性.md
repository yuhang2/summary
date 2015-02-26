## php 5.4新特性
#### 1 内置一个简单的Web服务器

> \# php -S localhost:3300  
> \# php -S localhost:3300 -t /path/to/root

#### 2 Traits

> Traits提供了一种灵活的代码重用机制，即不像interface一样只能定义方法不能实现，又不像class一样只能单继承。

#### 3 数组简短语法

```php
$arr = [1, 'testing'];
$arr = [
	"foo" => "foo",
	"bar" => "bar"
];
```

#### 4 Array Dereferencing

```php
function myfunc() {
	return array(1, 'testing');
}
// 以前使用
$arr = myfunc();
echo $arr[1];
// php 5.4之后
echo myfunc()[1];
// 其它使用
$name = explode(",", "tsings,male")[0];
explode(",", "tsings,male")[3] = "phper";
```

#### 5 上传进度
Session提供了上传进度支持，使用$_SESSION["upload_progress_name"]获取进度

#### 6 JsonSerializable Interface
实现了JsonSerializable接口的类的实例在json_encode序列化的之前会调用jsonSerialize方法，而不是直接序列化对象的属性。

#### 7 Use mysqlnd by default
#### 8 实例化类

```php
class test
{
	public function show()
	{
		return "test";
	}
}
echo (new test())->show();
```

#### 9 支持Class::{expr}()语法
#### 10 Callable Typehint 函数类型提示
#### 11 函数类型提示的增强
#### 12 新增$_SERVER["REQUEST_TIME_FLOAT"]

> 用来统计服务请求时间，用ms表示

```php
echo "脚本执行时间:", round(microtime(true) - $_SERVER["REQUEST_TIME_FLOAT"], 2);
```

#### 13 让Json更懂中文(JSON_UNESCAPED_UNICODE)

> php -r "echo json_encode("中文", JSON_UNESCAPED_UNICODE);"  
> 输出:"中文"

#### 14 binary number format

```php
$bin  = 0b1101;
echo $bin;
//13
```
### 其它
* PHP 5.4.0 性能大幅提升， 修复超过100个bug.  
* 废除了register_globals, magic_quotes以及安全模式。  
* 另外值得一提的是多字节支持已经默认启用了，
default_charset从ISO-8859-1已经变为UTF-8.  
* 默认发送“Content-Type: text/html; charset=utf-8”，
你再也不需要在HTML里写meta tag，也无需为UTF-8兼容而传送额外的header了。

### 删除的特性
最后，我们集中整理了几年来标记为已弃用的多个特性。这些特性包括

> allow_call_time_pass_reference、define_syslog_variables、highlight.bg、register_globals、register_long_arrays、magic_quotes、safe_mode、zend.ze1_compatibility_mode、session.bug_compat42、session.bug_compat_warn 以及 y2k_compliance。

除了这些特性之外，magic_quotes 可能是最大的危险。在早期版本中，未考虑因 magic_quotes 出错导致的后果，简单编写且未采取任何举措使自身免受 SQL 注入攻击的应用程序都通过 magic_quotes 来保护。如果在升级到 PHP 5.4 时未验证已采取正确的 SQLi 保护措施，则可能导致安全漏洞。

### 其他改动和特性

* 有一种新的“可调用的”类型提示，用于某方法采用回调作为参数的情况。
htmlspecialchars() 和 htmlentities() 现在可更好地支持亚洲字符，如果未在 php.ini 文件中显式设置 PHP default_charset，这两个函数默认使用 UTF-8 而不是 ISO-8859-1。
* 会话 ID 现在默认通过 /dev/urandom（或等效文件）中的熵生成，而不是与早期版本一样成为必须显式启用的一个选项。
* mysqlnd 这一捆绑的 MySQL 原生驱动程序库现在默认用于与 MySQL 通信的各种扩展，除非在编译时通过 ./configure 被显式覆盖。
* 可能还有 100 个小的改动和特性。从 PHP 5.3 升级到 5.4 应该极为顺畅，但请阅读迁移指南加以确保。如果您从早期版本升级，执行的操作可能稍多一些。请查看以前的迁移指南再开始升级。

