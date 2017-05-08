这里主要实现的是后端，客户端可以用leapftp3.0

目前实现的功能：登陆校验、空闲断开、连接数限制、断点续传、断点下载、空闲断开

用到的技术：select模型超时检测，多进程模型处理数据连接和命令连接，主被动模式处理NAT影响，自定义nobody进程和服务进程间通信协议，ALARM信号实现空闲断开，封装writen/readn解决TCP粘包。双 Hash表解决ip最大连接数，开链法解决Hash冲突，内存池管理哈希节点内存。
		
整个项目主要有三个模块组成：ftp协议解析模块、内部协议解析模块、进程间通信模块
```
tree /f
└─ftp
    ├─miniftpd.conf					//配置文件
    ├─.h
    │      ftpproto.h                                   //ftp协议解析
    │      hash.h				        //哈希表
    │      memorypool.h					//内存池
    │	   parseconf.h					//载入配置文件
    │      priparent.h					//内部协议解析
    │      prisock.h					//内部进程通信
    │      str.h					//字符串操作封装
    │      sysutil.h					//系统操作封装
    │      tunable.h					//配置参数
    └─.cpp
            ftpproto.cpp            
            hash.cpp        
            memorypool.cpp            
            parseconf.cpp                 
            priparent.cpp
            prisock.cpp          
            str.cpp
            sysutil.cpp                
            tunable.cpp            
            main.cpp
```
```
【客户端】<-------->【用户界面】
                         |
                         |
                         |
```
