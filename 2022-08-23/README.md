### 单体应用架构
Apache + MySQL + PHP

### 服务与数据分离
- 应用服务器 CPU配置高
- 数据库服务器 磁盘快、稳，内存足够大
- 文件服务器 磁盘足够大

### 引入缓存
- 本地缓存  和应用服务器共享内存，访问快
- 分布式缓存    通过网络访问
### 应用服务器水平拓展
负载均衡调度服务器（也可以是多台）
- Apache HTTP Server
- Nginx
- HaProxy
- LVS
- 硬件F5
### 数据库读写分离
一主（写） 多 从（读）
Mycat等中间件
### 分布式文件系统
小文件  FastDFS、TFS
大文件  HDFS
### 分库分表（sharding）
分库分表的最后一招，不到不得已不使用，因为一份数据，多份拷贝是所有罪恶的根源
### 海量异构数据检索
- Lucence 开发工具包类似 libuv
- Solr
- Elasticsearch 既可以做search engine也可以做NoSQL数据库
### 消息中间件
- ActiveMQ    功能全面、历史悠久
- RabbitMQ    Spring 同一团队维护
- Kafka   高性能、大吞吐量场景、消息可靠性比较弱
- Rocket    阿里旗下，取其精华，去其糟粕，相互借鉴
### 服务化架构
- SOA 异构系统的服务化
- 微服务 快速交付
###  运行与运营
- 系统监控
- 日志收集
- 数据挖掘
### CAP分布式不可能三角
- Consistency
- Availability
- Partition tolerance
网络是不可靠的、单个节点随时是可能宕机的
## 权衡与选择
一般牺牲了Consistency，仅实现eventual consistency 除非业务对一致性要求很高

软件架构最终反映的是团队组织架构，中小团队不要盲目的服务化

### 一致性模型
- Strict consistency
- Sequential consistency
- Eventual consistency
### BASE
- Basic Available
- Soft State
- Eventual consistency
