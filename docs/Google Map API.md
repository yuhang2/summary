[TOC]

# Google Map API

> https://developers.google.com/maps/  

## iOS

> https://developers.google.com/maps/documentation/ios/  
> 将地图添加到iOS应用

## Android

> https://developers.google.com/maps/documentation/android/  
> 将地图添加到Android应用

## Web

### JavaScript

> https://developers.google.com/maps/documentation/javascript/  
> [例子][js-example]

* [简单折线][js-simple-polyline]
* [打标记][js-simple-marker]

### Embed

> https://developers.google.com/maps/documentation/embed  
> 将地图嵌入到页面，通过`iFrame`的`src`参数，不需要添加`<script>`标签  
> 没有使用限制

## Web Service

> https://developers.google.com/maps/documentation/webservices/

### Directions API

> https://developers.google.com/maps/documentation/directions  
> 已知地址，进行导航。包括公交，开车，步行和骑车  
> 免费api：每天2400个导航请求，每个请求最多8个waypoints，每秒2个请求  
> 合作伙伴：每天10w个请求，最多23个waypoints，每秒10个请求  
> 不允许只调用接口，不显示导航数据

### Roads API

> https://developers.google.com/maps/documentation/roads  
> 根据gps坐标返回车辆走的路线，限速

* <font color="#FF0000">Snap to rouds</font>

	> https://developers.google.com/maps/documentation/roads/snap  
	根据一组GPS坐标，返回最符合的路线。
	
* Speed Limits
	> https://developers.google.com/maps/documentation/roads/speed-limits

### Distance Matrix API

> https://developers.google.com/maps/documentation/distancematrix/  
> The Google Distance Matrix API is a service that provides travel distance and time for a matrix of origins and destinations. The information returned is based on the recommended route between start and end points, as calculated by the Google Maps API, and consists of rows containing duration and distance values for each pair.

### Elevation API

> https://developers.google.com/maps/documentation/elevation  
> 海拔信息

### Geocoding API

> https://developers.google.com/maps/documentation/geocoding  
> 地理编码(将地址转换为地理坐标)  
> 反向地理编码是将(坐标转换为地址)

### Geolocation API

> https://developers.google.com/maps/documentation/business/geolocation  
> 根据客户端探测到的基站、wifi节点，返回坐标、误差范围

### Static Maps API

> https://developers.google.com/maps/documentation/staticmaps  
> 生成静态图片

### Street View Image API

> https://developers.google.com/maps/documentation/streetview  
> 生成街景图片

### Time Zone API

> https://developers.google.com/maps/documentation/timezone  
> 返回时区

### Places API

> https://developers.google.com/places/documentation/  
> 返回商家信息

* 地方搜索 会根据用户的位置或搜索字符串返回商家信息列表。
* 地方详情 请求会返回有关某个特定地方的更加详细的信息，包括用户评价。
* 商家信息操作 可让您用自己应用中的数据补充 Google 商家信息数据库中的数据。您可以安排活动日程、添加和删除商家信息，或者根据用户的地方 Bump 活动衡量地方排名。
* 地方照片 可让您查看存储在 Google 商家信息数据库中的数百万张地方照片。
* 商家信息自动填充功能 可在您输入内容时自动填充地方名称和/或地址。
* 查询自动填充功能 可在您输入内容时返回建议的查询，从而为基于文字的地理搜索提供联想查询服务。

# 其他

* 查找需要的接口 [api-picker][api-picker]
* 开启接口 [console][console]
* 接口访问许可[licensing][licensing]


[api-picker]: https://developers.google.com/maps/documentation/api-picker
[console]: https://code.google.com/apis/console
[licensing]: https://developers.google.com/maps/licensing
[js-example]: https://developers.google.com/maps/documentation/javascript/examples/
[js-simple-polyline]: https://developers.google.com/maps/documentation/javascript/examples/polyline-simple
[js-simple-marker]: https://developers.google.com/maps/documentation/javascript/examples/marker-simple

