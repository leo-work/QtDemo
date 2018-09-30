# redis C++ 组建包含消息队列

# redis C++ 的demo、

## redis 组件介绍
	redis提供内存存储，支持hash,List,Set等数据结构的存储  


## 编译配置
```
  需要安装hiredis库   redis官方的操作库
  需要安装libuv 异步组件   
   redis消息队列的时候用到了 hiredis的依赖

  hiredis 安装：
    下载：
    git clone https://github.com/redis/hiredis.git 
    进入目录：
    cd hiredis
    编译：
    make
    安装:
    sudo make install 
  libuv 安装
    git clone https://github.com/libuv/libuv.git
    sh autogen.sh
    ./configure
    make
    make check
    make install
```
 


## 构建步骤
```
sh auto-build.sh
cd build
cmake ..
make
cd ../bin
ls
```


## redis 组件介绍
redis提供内存存储，支持hash,List,Set等数据结构的存储，

## redis_client 组件使用
```
1. Redis 使用：
    实例： redis::RedisClient  RedisClient_;
    
    創建鏈接：
    RedisClient_.Connect("127.0.0.1", "6379");
    
    做redis的SET操作;
    RedisClient_.Set("key", "value");
    
    鏈接在析構的時候會被釋放
    
2. RedisClientPool 本地池使用：
    实例化本地redis池： 
    redis:RedisClientPool RedisClientPool_;
    
    初始化操作：
    RedisClientPool_.Init("127.0.0.1", "6379", 10);
    
    获取redis连接实例：
    RedisClient * pRedisClient = RedisClientPool_.GetRedisPrc();
    
    Redis操作：
    pRedisClient->Set("key", "value");
    
    Redis操作完成放回池中：
    RedisClientPool_.FreeRedisPrc(pRedisClient);
        
 3.  GlobalRedisPool 全球池使用：

     实例化本地redis池： 
    redis:GlobalRedisPool GlobalRedisPool_;
    
    初始化操作：
   GlobalRedisPool_.Init("127.0.0.1");
    
    获取redis连接实例：
    RedisClient * pRedisClient = GlobalRedisPool_.GetRedisPrc();
    
    Redis操作：
    pRedisClient->Set("key", "value");
    
    Redis操作完成放回池中：
    GlobalRedisPool_.FreeRedisPrc(pRedisClient);
   
```
## redis_client接口説明



  
### String（字符串）操作
    1.Connect
```
 
/*
* 创建连接
*
* host   (string)    地址
* port               端口号
* return             操作是否成功（true or false）
*/

        bool Connect(std::string host, int port);

```
    2.Get

```
 
/*
* 获取指定的key值
*
* key     (string)   键值
* value              获取有效值的地址
* return             操作是否成功（true or false)
*/
        bool Get(std::string key, std::string &value);
        
```
>     3.Set
```

/* 
* 设置指定的key值
*
* key    (String) 键值
* value           有效值
* return          操作是否成功 true/false
*/
    bool Set(std::string key, std::string value);


```

    4.ExistKey
```

/*
* 通过KEY判断是存在
*
* key    （string)  键值
*return             操作是否成功（true or false)
*/

     bool ExistsKey(std::string key);

```

    5.RemoveKey
```

/*
* 删除key值
*
* key      (string)   键值
*return               操作是否成功（true or false）
*/

    bool RemoveKey(std::string key);
```

## 列表操作（List）

     6.ListLength
``` 

 /*
 * List长度
 *
 * list_name         列表长度的的值   
 * return            操作返回整型值 
 */

    int ListLength(std::string list_name);
```

     7.Rpush
```

/*
* 将一个或多个值插到列表的尾部（最右边）
*
* list_name         列表长度的的值  
* value             有效值
* return            操作是否成功（true or false）
*/

    bool Rpush(std::string list_name, std::string value);

```

     8.Lpop
```
     
/*
* 移出并获取列表的第一个元素
*
* list_name         列表长度的的值  
* value             有效的地址值
* return            操作是否成功（true or false）
*/

    bool Lpop(std::string list_name, std::string &value); 
```
##### Hash（哈希表）操作
     9. HExists
```


/*
* 查看哈希表 key 中，指定的字段是否存在
*
* list_name         列表长度的的值  
* field_name        指定的字段域
*  return            操作是否成功（true or false）
*/
 
bool HExists(std::string table_name, std::string field_name);
```

     10.HMSet
```

/*
* 为多个哈希字段分别设置它们的值
*
* table_name       map表
* field_group      字段组
* return           如果命令执行成功，返回 OK ,当 key 不是哈希表(hash)类型时，返回一个错误。（true or false）
*/

   bool HMSet(const std::string table_name, std::map<std::string, std::string> field_group);
```
     11.HDel
```
 
/*
* 删除哈希表 key 中的一个或多个指定域，不存在的域将被忽略(注意：在Redis2.4以下的版本里， HDEL 每次只能删除单个域，如果你需要在一个原子时间内删除多个域，请将命令包含在 MULTI / EXEC 块内。)
*
* table_name       列表
* field_list      所要删除的指定的域
* return      被成功移除的域的数量，不包括被忽略的域。(true or false)
*/
 
   bool HDel(const std::string table_name, std::list<std::string> field_list);
```

>     12.HMGet
```

/*
* 返回哈希表 key 中，一个或多个给定域的值。（如果给定的域不存在于哈希表，那么返回一个 nil值。
  因为不存在的 key 被当作一个空哈希表来处理，所以对一个不存在的 key 进行 HMGET操作将返回一个只带有 nil 值的表。）
*
* table_name            列表
* field_list            给定列表的域
* key_value_map         哈希表中key有效值得地址
* return                操作是否成功（true or false）
*/

   bool HMGet(const std::string table_name, std::list<std::string> field_list, std::map<std::string, std::string> &key_value_map);
```
     13.HGetAll
```
/*
* 返回哈希表 key 中，所有的域和值。(在返回值里，紧跟每个域名(field name)之后是域的值(value)，所以返回值的长度是哈希表大小的两倍)
*
* table_name          列表
* key_value_map       哈希表中key有效值得地址
* return                操作是否成功（true or false）
*/

  bool HGetAll(const std::string table_name, std::map<std::string, std::string> &key_value_map); 
```
     14.HSet
```
 
/*
* 将哈希表 key 中的域 field 的值设为 value 。(如果 key 不存在，一个新的哈希表被创建并进行 HSET 操作.如果域 field 已经存在于哈希表中，旧值将被覆盖。)
*
* table_name            列表项
* key       （string）  键值
* value                 有效值
* return                操作是否成功（true or false）         
*/

   bool HSet(const std::string table_name, const std::string key, const std::string value);
```
     15.HGet
```
/*
* 获取存储在指定键的哈希字段的值
*
* table_name          列表项
* key       （string）键值
* value               有效值的地址
*  return                操作是否成功（true or false）         
*/
//
bool HGet(const std::string table_name, const std::string key, std::string &value);
```
 
     16. PublicMsg
```

 /*
* channel_name
* value         有效值
* return        操作是否成功（true or false）
*/
 bool PublicMsg(std::string channel_name, std::string value);
```
 

 
     17. DestroyReoly
```

/*
* 销毁reoly
*
* value          有效值的地址
* return         操作是否成功（true or false）
*/

bool DestroyReoly(std::string &value);
```
     18. DestroyReoly
 
```

/*
* 销毁指定的元素
* element      要删除的元素
* return       返回元素的整形值
*/

int DestroyReoly(const bool elements);
```
 
##   redis_client_pool（接口说明）

     1.Init
```
/*
* 初始化函数
*
* ip     (string)   ip地址
* port              端口号 
* pool_size         池的大小
*/

 void Init(std::string ip, int port, int pool_size);


```


     2.GetRedisPrc
```
/*
* 获取redis连接实例
*/

 RedisClient * GetRedisPrc();
 
```
     3.FreeRedisPrc
```
/*
* 删除获取的redis实例放回池中
* 
* pRedisClient 
*/

 void FreeRedisPrc(RedisClient * pRedisClient);
```
## global_redis_pool（接口说明）
    1.Init
```
/*
* global_redis_pool初始化函数
*
* map_redis_info     map表信息
*                    返回值为vide
*/

void Init(std::map<int, RedisInfo> map_redis_info);
```
    2.GetRedisPrc
```
/*
* 获取全球redis连接实例
* 
* id                  给定的id
*/

 RedisClient * GetRedisPrc(int id);
```
    3.FreeRedisPrc
```
/*
* 删除获取的redis实例放回池中
*
* pRedisClient          目标实例
* id                    给定的id
*/

void FreeRedisPrc(RedisClient * pRedisClientt, int id);
```




##redis-queue(接口说明)

### async_redis_client
```
1. redisqueuepool队列池使用：

    实例化本地的redisqueue池：
    redisqueue:redisqueuepool redisqueuepool_ 

    初始化操作：
    RedisqueuePool_.Init("127.0.0.1", "6379", chanelnamelist);
    
    操作完成后自动调用析构函数
    
```
### async_redis_client

    1.Init
```
/*
* 对异步线程初始化
*
* ip          ip地址
* port        指定的端口号
* chanel_name 所要初始化线程的名称
*/

bool Init(std::string ip, int port, std::string chanel_name);

```
2.SubCallback
```
/*
* 
*
* c              指针          
* r       (void) 指针
* priv    (void) 指针
* return         返回值为void
*/

 static void SubCallback(redisAsyncContext *c, void *r, void *priv);
```
    3.DisConnectCallback
```
/*
*
*
* c           （const）指针
* status
* return              返回值为void 
*/

static void DisConnectCallback(const redisAsyncContext *c, int status);

```
    4. ConnectCallback
```
/*
*
*
* c
* status
* return              返回值为void 
*/

static void ConnectCallback(const redisAsyncContext *c, int status);
```
    5.SubWork
```
 /*
 *子线程所要做的任务
 * return              返回值为void 
 */
 void SubWork();
 
```
## redis_queue_pool
    1.RedisQueuePool
```


/*
*队列池构造函数
*/
RedisQueuePool();
      
      
```
    2.RedisQueuePool
```
/*
* 队列池的析构函数
*/

  ~RedisQueuePool();
```
    3.Init
```
/*
* redisqueuepool的初始化函数
*
* ip              ip地址
* port            端口号
* chanel_name_list
* return              返回值为void 
*/

void Init(std::string ip, int port, std::list<std::string> chanel_name_list);
```




## test
 对bin 的可执行程序测试
 