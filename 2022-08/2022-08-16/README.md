### 雅虎军规
- 尽量减少HTTP请求次数
浏览器一次最多并发7个请求，超过就会pending
雪碧图
- 减少DNS的查找次数
dns-prefetch
- 避免跳转
301或302都不会被缓存，除非有额外的头部
- 可缓存的ajax
Expires 和 Cache-control 以及 Last-Modified 头部
- 推迟加载内容
图片资源滚动加载，懒加载
- 预加载
prefetch onload
- 减少dom元素的数量
- 根据域名划分内容
html，css，图片，js，cdn，不同的域，即不同的服务器
- 避免iframe
- 避免404
- 使用cdn
- gzip压缩
- Etag
- 样式至于顶部
- 避免使用css表达式
expression
- 用link代替@import
- IE滤镜
- 不要重复引入
- 减少dom访问
- 事件代理
- 少用cookie
用localstorage，图片的其他资源使用无cookie域名
- 保持单个内容小于25k
- (hack)利用注释把css和js文件写在一起，减少HTTP请求