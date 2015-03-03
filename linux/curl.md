## curl

> curl是一个命令行工具，作用是发出网络请求，然后得到和提取数据，显示在"stdout"上

### 1 常用功能

1. 查看网页源码
	
	```
	curl 网址
	```
	如果想保存网址
	
	```
	curl -o [文件名] 网址
	```

2. 自动跳转

	有的网址是自动跳转的，使用-L参数，curl会跳转到新的网址

	```
	curl -L 会跳转的网址
	```

3. 显示头信息

	-i参数可以显示http response的头信息，连同网页一起  
	-I参数只显示http response的头信息
	
	```
	curl -i 网址
	```
	
4. 显示通信过程

	-v参数可以显示一次http通信的整个过程，包括端口连接和http request头信息  
	如果觉的信息还不够，可以使用 --trace --trace-ascii查看更详细的通信过程
	
	```
	curl -v www.sina.com
	curl --trace output.txt www.sina.com
	curl --trace-ascii output.txt www.sina.com
	```
	
	返回:
	
	```
	* Rebuilt URL to: www.sina.com/
	* Hostname was NOT found in DNS cache
	*   Trying 218.30.108.232...
	* Connected to www.sina.com (218.30.108.232) port 80 (#0)
	> GET / HTTP/1.1
	> User-Agent: curl/7.37.1
	> Host: www.sina.com
	> Accept: */*
	>
	< HTTP/1.1 301 Moved Permanently
	* Server nginx is not blacklisted
	< Server: nginx
	< Date: Tue, 03 Mar 2015 03:18:19 GMT
	< Content-Type: text/html
	< Location: http://www.sina.com.cn/
	< Expires: Tue, 03 Mar 2015 03:20:19 GMT
	< Cache-Control: max-age=120
	< Age: 107
	< Content-Length: 178
	< X-Cache: HIT from ja180-186.sina.com.cn
	<
	<html>
	<head><title>301 Moved Permanently</title></head>
	<body bgcolor="white">
	<center><h1>301 Moved Permanently</h1></center>
	<hr><center>nginx</center>
	</body>
	</html>
	* Connection #0 to host www.sina.com left intact
	```
	
5. 发送表单信息

	有Get和Post两种方法，GET直接把数据附加在网址后，POST需要使用--data参数。如果数据没有经过表单编码，还可以使用--data-urlencode进行编码
	
	```
	curl 网址?data=参数
	curl --data "data=参数" 网址
	curl --data-urlencode "data=参数" 网址
	```

6. 文件上传

	假定表单格式:
	
	```html
	<form method="POST" enctype='multipart/form-data' action="url">
　　　　<input type=file name=upload>
　　　　<input type=submit name=press value="OK">
　　</form>
	```
	使用curl上传
	```
	curl --form upload=@localfilename --form press=OK [url]
	```
	
7. referer

	```
	curl --referer http://example.com http://example.com
	```

8. user agent

	```
	curl --user-agent "[User Agent]" [URL]
	```
	
9. cookie

	```
	curl --cookie "name=xxx" www.example.com
	```

10. 增加头信息

	```
	curl --header "xxx: xxxx" [URL]
	```
	
11. http认证

	```
	curl --user name:password [URL]
	```